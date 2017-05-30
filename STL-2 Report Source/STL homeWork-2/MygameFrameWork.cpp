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

ReplayLoop::ReplayLoop(MyGame * othGame) : GameLoopFrameWork(othGame) {}

void ReplayLoop::gameLoop() {
	while (isLoop()) {
		render();
		input();
		update();
	}
}

void ReplayLoop::render() {

}

GameLoop::GameLoop(MyGame * othGame) : GameLoopFrameWork(othGame) {}

void GameLoop::gameLoop() {
	while (isLoop()) {
		render();
		input();
		update();
	}
}

void GameLoop::update() {
	int n = pMygame->mInputer.getLastKey();

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
	default:
		break;
	}
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
