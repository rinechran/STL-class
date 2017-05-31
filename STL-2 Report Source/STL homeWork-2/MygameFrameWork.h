#pragma once
#include "GameFrameWork.h"
#include <vector>
#include <fstream>
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
	std::chrono::duration<double> clock;
	Player Player;
};
struct ReplayStore {
	ReplayStore() = default;
	
	void pushData(Player &player, std::chrono::duration<double> diff);
	void fileSave(std::string &filename);
	void fileRead(std::string &filename);
	std::vector<ReplayData> mGameData;

	using ReplayerIter = std::vector<ReplayData>::iterator;
	ReplayerIter mReplateriter;
protected:

};


struct Stage {
	char mMap[10][10]{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 0, 1, 1, 1 },
		{ 1, 1, 0, 1, 0, 1, 0, 1, 1, 1 },
		{ 1, 0, 0, 1, 0, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 1, 0, 1, 0, 0, 0, 1 },
		{ 1, 1, 2, 1, 0, 0, 0, 0, 1, 1 },
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

	virtual bool isLoop();
	void setChangeLoop();
protected:
	bool mIsLoop;
	bool isMove(int x, int y);
	bool move(int x, int y);
	void timerStart();
	auto timerDiff();

	MyGame * pMygame;
	Player mPlayer;
	Stage mStage;
	ReplayStore mReplayStroe;

	std::chrono::system_clock::time_point mEnd;
	std::chrono::system_clock::time_point mStart;


};
class ReplayLoop : public  GameLoopFrameWork {
public:
	ReplayLoop(MyGame * othGame);
	virtual void gameLoop();
	virtual void update();;
	virtual void input();;
	virtual bool isLoop();
	virtual void render();


};
class GameLoop : public GameLoopFrameWork {
public:
	GameLoop(MyGame * othGame);

	virtual void gameLoop();
	virtual void update();
	virtual void input();
	virtual void render();

private:


	
};

