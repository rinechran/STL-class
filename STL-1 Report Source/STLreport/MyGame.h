#pragma once
#include <iostream>
#include <unordered_set>
#include <map>
#include <random>
#include <fstream>
#include <chrono>
#include <functional>
#include "Range.hpp"
#include "GameFrameWork.h"
#include "Object.h"
#include "MygameInputer.h"


class MyGame : public GmaeFrameWork {
public:
	MyGame() ;
	virtual void update();
	virtual void input();
	virtual void reder();
	
	virtual ~MyGame();

	bool is_loop();

private://owen function
	void init();
	void newUser();
	void RankInsert();
	void RankSort();
	void RankChange();

private:
	bool mIs_update;
	std::vector<User> mUser;
	bool mIs_loop;
	MygameInputer  mInputer;
	friend MygameInputer;
	Arenas arenas;
};




