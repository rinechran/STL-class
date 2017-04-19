#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include "Object.h"
//prefat
class MyGame;


enum  GAMEMODE  {
	USERPRINT=1,REFESH,SEARCH,EXIT
};

class MygameInputer {
public:

	MygameInputer(MyGame *) ;
	void input();
	void setUserUid(size_t userIndex);
	void render();


private:
	std::vector<User>::iterator findUser(int uid);
	void ratePrint(int ,int );
	void UserPrint();
	void menuPrint();
	void refresh();
	void exit();
	void serarch();
	size_t mUserUid;
	MyGame * mPgame;
};
