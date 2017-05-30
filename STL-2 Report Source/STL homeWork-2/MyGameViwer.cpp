#include "MyGameViwer.h"
#include "MyGame.h"

void MyGameViwer::mainMenuView() {
	displayClear();
	std::cout << GAMEMODE::PLAY << " : Game Play" << std::endl;
	std::cout << GAMEMODE::REPLAY << " : REPLAY " << std::endl;
	std::cout << GAMEMODE::EXIT << " : EXIT " << std::endl;
}

void MyGameViwer::displayClear() {
	system("cls");
}

void MyGameViwer::gameMapView(char  pa) {
	switch (pa)
	{
	case -1:
		printf("��");
		break;
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 0:
		printf("��");
	}

}

void MyGameViwer::goalView() {
	std::cout << "Goal" << std::endl;
	system("pause");
}
