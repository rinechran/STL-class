#include "MygameInputer.h"
#include "MyGame.h"
#include "MygameFrameWork.h"
#include <conio.h>

MygameInputer::MygameInputer(MyGame * pMygame) : pMyGmae(pMygame) {
}

void MygameInputer::menu() {
	pMyGmae->mViwer.mainMenuView();
	GAMEMODE n;
	int sel;
	std::cin >> sel;
	pMyGmae->mMode = static_cast<GAMEMODE>(sel);
	switch (pMyGmae->mMode)
	{
	case GAMEMODE::PLAY:
		pMyGmae->mlooper.reset(new GameLoop(pMyGmae));
		break;
	case GAMEMODE::REPLAY:
		pMyGmae->mlooper.reset(new ReplayLoop(pMyGmae));
		break;
	case GAMEMODE::EXIT:
		break;
	default:
		break;
	}

}

int MygameInputer::getChar() {

	return getch();
}

int MygameInputer::keyBoardMapping() {
	while (true) {
		int i = getChar();
		switch (i)
		{
		case KEYBOARD::DOWN:
		case KEYBOARD::UP:
		case KEYBOARD::LEFT:
		case KEYBOARD::RIGHT:
			mLastKey = i;
			return i;
		}
	}
}

int MygameInputer::getLastKey() {
	return mLastKey;
}
