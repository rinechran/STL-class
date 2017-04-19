#include <iostream>
#include "MyGame.h"

int main() {

	MyGame mygame;
	
	while (mygame.is_loop()) {
		mygame.reder();
		mygame.input();
		mygame.update();
	}


}