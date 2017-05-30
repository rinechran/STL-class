#pragma once
#include "GameFrameWork.h"
#include <vector>
#include <chrono>

class MyGame;
//virtual void update() = 0;
//virtual void input() = 0;
//virtual void render() = 0;
//virtual ~GmaeFrameWork() {}
struct Player {
	int x;
	int y;
};
struct ReplayData {
	std::chrono::system_clock clock;
	Player mPlayer;
};
struct ReplayStore {
	std::vector<ReplayData> mGameData;
};


struct Stage {
	char mMap[10][10]{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 1, 0, 0, 0, 1 },
		{ 1, 1, 2, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
};



class GameLoopFrameWork : public GameFrameWork {
public:
	GameLoopFrameWork(MyGame * othGame);
	void update();;
	virtual void input();;
	virtual void render();;
	virtual void gameLoop();;
	bool isGoal() {
		if (mStage.mMap[mPlayer.y][mPlayer.x] == 2)
			return true;
		return false;
	}

	bool isLoop();
	void setChangeLoop();
protected:
	bool mIsLoop;
	bool isMove(int x, int y);
	bool move(int x, int y);

	MyGame * pMygame;
	Player mPlayer;
	Stage mStage;
	ReplayStore mReplayStroe;

};
class ReplayLoop : public  GameLoopFrameWork {
public:
	ReplayLoop(MyGame * othGame);
	virtual void gameLoop();
	virtual void update() {};
	virtual void input() {};
	virtual void render();;

	int mCurrentStage;

};
class GameLoop : public GameLoopFrameWork {
public:
	GameLoop(MyGame * othGame);

	virtual void gameLoop();
	virtual void update();
	virtual void input();
	virtual void render();
};

