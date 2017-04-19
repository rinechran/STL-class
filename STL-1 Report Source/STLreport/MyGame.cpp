#include "MyGame.h"

MyGame::MyGame() : mIs_update(true),mIs_loop(true) , mInputer(this){
	init();
	mInputer.setUserUid(mUser[0].mUid);
	RankInsert();	//Map insert
	RankSort();
}

void MyGame::init() {
	bool fileIsOpen;{
			std::ifstream in;
			in.open("Data.dat", std::ios::binary | std::ios::in);
			fileIsOpen = in.is_open();}
	if (fileIsOpen) {
		//in.read()
		size_t readUserSize;
		std::ifstream in;
		in.open("Data.dat", std::ios::binary | std::ios::in);
		in.read(reinterpret_cast<char*>(&readUserSize), sizeof(readUserSize));
		//std::cout << "file open " << readUserSize << std::endl;;
		mUser.resize(readUserSize); // size malloc
		in.read(reinterpret_cast<char*>(&mUser[0]), readUserSize * sizeof(User));
	}
	else {
		mUser.reserve(20000); //default capacity = 20000
		newUser(); //default 20000
	}

}

void MyGame::newUser() {
	std::unordered_set<int> is_uid;
	for (auto &i : Range(0, 20000)) {
		std::unordered_set<int> is_uid;
		std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());
		std::uniform_int_distribution<> dis(1, 25000000);
		while (true) {
			int dre = dis(re);
			auto iter = is_uid.find(dre);
			if (iter == is_uid.end()) { // Not find
				is_uid.insert(dre); // prevant Mutl Value
				size_t Score[5] = { dis(re), dis(re), dis(re), dis(re), dis(re) };
				mUser.push_back(User(dre, Score));
				break;
			}
		}
	}

}

void MyGame::RankInsert()
{
	for (auto &i : mUser) {
		arenas.totalArean.push_back(&i);
		for (auto &j : Range(0, 5)) {
			arenas.arean[j].push_back(ScoreUid{&i.mScore[j], &i.mUid});
		}
	}

}

void MyGame::RankSort() {
	for (auto &j : Range(0, 5)) {
		std::sort(arenas.arean[j].begin(), arenas.arean[j].end(), [](ScoreUid & oth1, ScoreUid & oth2) {
			return *oth1.mScore > *oth2.mScore;
		});
	}


	for (auto &i : this->arenas.totalArean) {
		i.refreash();
	}
	std::sort(arenas.totalArean.begin(), arenas.totalArean.end(), [](TotalScore & oth1, TotalScore & oth2) {
		return oth1.totalScore > oth2.totalScore;
	});

}

void MyGame::RankChange() {
	for (auto &i : Range(0, 5)) {
		for (auto j = arenas.arean[i].begin(); j != arenas.arean[i].end();++j) {
			if (j->mPastRank == 0) {
				j->mPastRank = std::distance(arenas.arean[i].begin(), j);
			}
			else {
				j->mCurrentRank = j->mPastRank- std::distance(arenas.arean[i].begin(), j);
				j->mPastRank = std::distance(arenas.arean[i].begin(), j);

			}
		}
	}

}

void MyGame::update() {
	if (mIs_update) {
		RankSort();
		RankChange();
		mIs_update = 0;
	}

}

void MyGame::input() {

	mInputer.input();
}

void MyGame::reder() {
	mInputer.render();
}

bool MyGame::is_loop() {
	return mIs_loop;
}

MyGame::~MyGame() {
	std::ofstream out("Data.dat", std::ios::binary);
	size_t i = mUser.size();
	//std::fwrite() // first User save
	out.write(reinterpret_cast<char*>(&i), sizeof(i)); // User Size
	out.write(reinterpret_cast<char*>(&mUser[0]) // User data
		, mUser.size() * sizeof(User));


}
