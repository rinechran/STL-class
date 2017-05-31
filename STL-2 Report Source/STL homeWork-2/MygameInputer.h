#pragma once
#include <iostream>
#include <string>

class MyGame;


enum KEYBOARD {
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};


class MygameInputer
{

public:
	MygameInputer(MyGame * pMygame);
	void menu();
	int getChar();
	int keyBoardMapping();
	int getLastKey();
	std::string getString();

private:
	MyGame * pMyGmae;
	int mLastKey;

};

