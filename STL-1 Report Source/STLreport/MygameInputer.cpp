
#include "MygameInputer.h"
#include "MyGame.h"

MygameInputer::MygameInputer(MyGame * oth) :mPgame(oth){

}

void MygameInputer::input() {


	GAMEMODE selMode;
	int sel;
	std::cin >> sel;
	selMode = static_cast<GAMEMODE>(sel);
	switch (selMode)
	{
	case GAMEMODE::USERPRINT:
		UserPrint();
		return;
	case GAMEMODE::REFESH:
		refresh();
		break;
	case GAMEMODE::EXIT:
		exit();
		break;
	case GAMEMODE::SEARCH:
		serarch();
		break;
	default:
		break;
	}



}




void MygameInputer::setUserUid(size_t userIndex) {
	mUserUid = userIndex;
}
void MygameInputer::UserPrint() {
	std::cout << "------------------------" << std::endl;

	auto iterUser = findUser(mUserUid);
	auto iterTotal = std::find_if(mPgame->arenas.totalArean.begin(), mPgame->arenas.totalArean.end(),
		[=](TotalScore& oth) {return oth.mUser->mUid == mUserUid; });

	auto ranking = std::distance(mPgame->arenas.totalArean.begin(), iterTotal);

	std::cout << "Total Score : " << iterTotal->totalScore << "  Rank : " << ranking << std::endl;
	std::cout << "User Uid : " << iterUser->mUid << std::endl;

	for (auto &i : Range(0,5) ) {
		std::cout << "----------------" <<std::endl;

		std::cout << i+1 <<" Arenas Schore : " << iterUser->mScore[i] << std::endl;

		auto it = std::find_if(mPgame->arenas.arean[i].begin(), 
			mPgame->arenas.arean[i].end(),
			[this](ScoreUid &oth) {
			return *oth.mUid == mUserUid;
		});
		auto index = std::distance(mPgame->arenas.arean[i].begin(), it);
		ratePrint(i,index);
		

	}
}
void MygameInputer::render() {
	menuPrint();
}
std::vector<User>::iterator MygameInputer::findUser(int uid) {
	auto iterUser = std::find_if(mPgame->mUser.begin(), mPgame->mUser.end(),
		[=](User & oth) {
		return oth.mUid == uid;
	});
	//std::cout << "User Uid : " << iterUser->mUid << std::endl;
	return iterUser;
}
void MygameInputer::ratePrint(int Where, int index) {
	double rankRate = static_cast<double>(index) / static_cast<double>(mPgame->mUser.size()) * 100;
	std::cout <<"Ranking : " <<index <<" "<< "rate Percent : " << rankRate << std::endl;

	auto i = std::min(std::max(index - 5, 0), 
		static_cast<int>(mPgame->mUser.size()-5));

	//*mPgame->arenas.arean[Where][i].mUid
	int start,end;
	if (i == 0) {
		start= 0;
		end = 5;
	}
	else if (i == mPgame->mUser.size() - 5) {
		start = 19995;
		end = 20000;
	}
	else {
		start = index - 2;
		end = index + 3;
	}
		for (auto &i : Range(start, end)) {
			std::cout << "Score : " << *mPgame->arenas.arean[Where][i].mScore
				<< " User id : " << *mPgame->arenas.arean[Where][i].mUid
				<< "  Rank Change : " << mPgame->arenas.arean[Where][i].mCurrentRank << std::endl;
		}


}

void MygameInputer::menuPrint() {
	
	std::cout << GAMEMODE::USERPRINT << ":USERPRINT" << std::endl;
	std::cout << GAMEMODE::REFESH << ":REFESH"<< std::endl;
	std::cout << GAMEMODE::SEARCH << ":SERACH" << std::endl;
	std::cout << GAMEMODE::EXIT <<  ":EXIT"<<std::endl;
	std::cout << "input: ";

}

void MygameInputer::refresh() {
	std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());


	std::unordered_set<int> users;
	//other refresh
	while (true) {
		std::uniform_int_distribution<> dis(0, mPgame->mUser.size()-1);
		if (users.size() >= mPgame->mUser.size() * 0.1) break;
		users.insert(mPgame->mUser[dis(re)].mUid);
	}
	users.insert(mUserUid); // User

	std::uniform_int_distribution<> dis(1, 25000000);
	for (auto &i : users) {
		auto iterUser = std::find_if(mPgame->mUser.begin(), mPgame->mUser.end(),
			[=](User & oth) {
			return oth.mUid == i;
		});
		for (auto &i : iterUser->mScore) {
			i = std::max(dis(re), (int)i);
		}//User refresh
	}
	mPgame->mIs_update = true;
}

void MygameInputer::exit() {
	this->mPgame->mIs_loop = false;

}

void MygameInputer::serarch() {
	int sel;
	std::cout << "input Sel : ";
	std::cin >> sel;
	auto it = findUser(sel);
	if (it != mPgame->mUser.end()) {
		std::cout << "UID : " << it->mUid << std::endl;
		for (auto &i : Range(0, 5)) {
			std::cout << "----------------" << std::endl;

			std::cout << i + 1 << " Arenas Schore : " << it->mScore[i] << std::endl;
			//round print

			auto it = std::find_if(mPgame->arenas.arean[i].begin(),
				mPgame->arenas.arean[i].end(),
				[=](ScoreUid &oth) {
				return *oth.mUid == sel;
			});
			auto index = std::distance(mPgame->arenas.arean[i].begin(), it);
			ratePrint(i, index);


		}
	}
	else {
		std::cout << "Not find Uid" << std::endl;
	}

}



