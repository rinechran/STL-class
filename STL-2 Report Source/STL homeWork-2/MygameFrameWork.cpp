#include "MygameFrameWork.h"
#include "MyGame.h"


GameLoopFrameWork::GameLoopFrameWork(MyGame * othGame) : mIsLoop(true), pMygame(othGame) {
	mPlayer = { 1,1 };
}

void GameLoopFrameWork::update() {}

void GameLoopFrameWork::input() {}

void GameLoopFrameWork::render() {}

void GameLoopFrameWork::gameLoop() {}

bool GameLoopFrameWork::isLoop() { return mIsLoop; }

void GameLoopFrameWork::setChangeLoop() {
	mIsLoop = mIsLoop == true ? false : true;
}

bool GameLoopFrameWork::isMove(int x, int y) {
	if (mStage.mMap[y][x] == 1)
		return false;
	return true;
}

bool GameLoopFrameWork::move(int x, int y) {
	if (isMove(x, y) == true) {
		mPlayer.x = x;
		mPlayer.y = y;
		return true;
	}
	return false;
}

void GameLoopFrameWork::timerStart() {
	mStart = std::chrono::system_clock::now();
}

auto GameLoopFrameWork::timerDiff() {
	mEnd = std::chrono::system_clock::now();
	auto timer = mEnd - mStart;
	return mEnd - mStart;
}

ReplayLoop::ReplayLoop(MyGame * othGame) : GameLoopFrameWork(othGame) {
}

void ReplayLoop::gameLoop() {
	//file Read
	pMygame->mViwer.fileReadView();
	this->mReplayStroe.fileRead(pMygame->mInputer.getString());
	timerStart();
	
	//this->pMygame->mViwer.MapIterator(mStage.mMap, mPlayer);

	//for (auto i = mReplayStroe.mGameData.begin();
	//	i != mReplayStroe.mGameData.end();++i) {
	//	while (timerDiff() <= i->clock) {
	//		continue;
	//	}
	//	this->mPlayer = i->Player;
	//	render();
	//}
	//mReplateriter = this->mReplayStroe.mGameData.begin();
	while (this->isLoop()) {
		render();
		input();
		update();

	}
	this->pMygame->mViwer.goalView();
	this->pMygame->mInputer.getChar();


}

void ReplayLoop::update() {
	mPlayer = mReplayStroe.mReplateriter->Player;
	++mReplayStroe.mReplateriter;
}

void ReplayLoop::input() {
	while (this->timerDiff() <= mReplayStroe.mReplateriter->clock) {
		continue;
	}
}

bool ReplayLoop::isLoop() {
	return mReplayStroe.mReplateriter
		== mReplayStroe.mGameData.end() ? false : true;
}

void ReplayLoop::render() {
	this->pMygame->mViwer.MapIterator(mStage.mMap, mPlayer);
}

GameLoop::GameLoop(MyGame * othGame) : GameLoopFrameWork(othGame) {
}

void GameLoop::gameLoop() {
	timerStart();
	while (isLoop()) {
		render();
		input();
		update();
	}
	pMygame->mViwer.fileSaveView();
	mReplayStroe.fileSave(pMygame->mInputer.getString());


}

void GameLoop::update() {
	int n = pMygame->mInputer.getLastKey();
	//ReplayStore(mPlayer);
	switch (n)
	{
		case KEYBOARD::UP:
			move(mPlayer.x, mPlayer.y-1);
			break;
		case KEYBOARD::DOWN:
			move(mPlayer.x, mPlayer.y+1);
			break;
		case KEYBOARD::LEFT:
			move(mPlayer.x-1, mPlayer.y);
			break;
		case KEYBOARD::RIGHT:
			move(mPlayer.x+1, mPlayer.y);
			break;
	}
	mReplayStroe.pushData(mPlayer, timerDiff());
	if (isGoal() == true) {
		this->pMygame->mViwer.goalView();
		setChangeLoop();
	}

}

void GameLoop::input() {
	pMygame->mInputer.keyBoardMapping();
}

void GameLoop::render() {
	this->pMygame->mViwer.MapIterator(mStage.mMap,mPlayer);

}

void ReplayStore::pushData(Player & player, std::chrono::duration<double> diff) {
	auto end = std::chrono::system_clock::now();

	mGameData.push_back(ReplayData
	{ diff,player }
	);
}

void ReplayStore::fileSave(std::string & filename) {
	std::ofstream outer(filename + ".dat", std::ios::binary);
	size_t i = mGameData.size();
	outer.write(
		reinterpret_cast<char*>(&i),
		sizeof(i)
	);
	outer.write(
		reinterpret_cast<char*>(&mGameData[0]),
		sizeof(ReplayData) *mGameData.size()
	);
}

void ReplayStore::fileRead(std::string & filename) {
	std::ifstream inputer(filename + ".dat", std::ios::binary);
	std::size_t size = 0;
	inputer.read(reinterpret_cast<char*>(&size), sizeof(size));
	mGameData.resize(size);
	inputer.read(reinterpret_cast<char*>(&mGameData[0]), size * sizeof(ReplayData));

	mReplateriter = mGameData.begin();
}
