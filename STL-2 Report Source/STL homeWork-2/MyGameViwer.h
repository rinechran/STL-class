
#pragma once
#include <iostream>
#include <Windows.h>
#include "MygameFrameWork.h"
struct MyGameViwer {
public:
	void mainMenuView();
	void displayClear();
	void gameMapView(char pa);
	void goalView();
	void fileSaveView();
	void fileReadView();


	template <class T, int H, int W>
	void MapIterator(T(&pa)[H][W],Player & oth);

};

template<class T, int H, int W>
void MyGameViwer::MapIterator(T(&pa)[H][W], Player & oth) {
	displayClear();
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (oth.y == i && oth.x == j) {
				gameMapView(static_cast<char>(-1));
				continue;
			}
			gameMapView(pa[i][j]);
		}
		std::cout << std::endl;

	}

}
