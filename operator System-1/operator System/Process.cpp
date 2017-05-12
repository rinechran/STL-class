#include "Process.h"



Process::Process() :mCurrentTime(0) , mIsRun(false){
	fileRead();
}

void Process::fileRead() {
	std::ifstream in("data.txt");

	if (!in.is_open()) { throw std::exception("data file not Find"); }

	std::vector<dataObject> temper;

	while (!in.eof()) {
		dataObject temp;
		in >> temp;
		temper.push_back(temp);
	}

	for (int i = 0; i < temper.size(); i += 3) {
		if (temper[i] == 0) break;

		mArrProcessData.push_back(
			ProcessData{ (temper[i]), (temper[i + 1]), (temper[i + 2]) }
		);
	}

}

Process::~Process() {}

