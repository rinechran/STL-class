#pragma once
#include "GameFrameWork.h"
#include "MygameInputer.h"
#include "MyGameViwer.h"
#include "MygameFrameWork.h"
#include <memory>
#include <vector>
#include <chrono>



enum GAMEMODE
{
	PLAY = 1,
	REPLAY,
	EXIT
};
class MyGame  {
public:
	MyGame();

	void run() {
		while (true) {
			mInputer.menu();
			if (mMode == GAMEMODE::EXIT)
				return;
			mlooper->gameLoop();
		}
	}


	MygameInputer mInputer;
	MyGameViwer mViwer;
	std::shared_ptr<GameLoopFrameWork> mlooper;
	GAMEMODE mMode;



};









