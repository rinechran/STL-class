#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Processer.h"
#include <stack>



class Process {


public:
	Process();
	void fileRead();
	virtual bool update() = 0;
	bool getProcess() {
		if (mArrProcessData.size() == 0) return false;


		for (auto i = mArrProcessData.begin();i!= mArrProcessData.end();){
			if (i->arrivalTime <= this->mCurrentTime) {
				mPrecessBuffer.push_back(ProcessData{
					i->id,
					i->arrivalTime,
					i->serviceTime
				});
				i = mArrProcessData.erase(i);
			} else {
				break;
			}
		}
		mCurrentTime++;
		return true;

	}
	void run() {
		while (update()) {

		}
	}
	virtual ~Process();

protected:

	std::vector<ProcessData> mPrecessBuffer;
	currentTime mCurrentTime;
protected:
	std::vector<ProcessData> mArrProcessData;
	bool mIsRun;

};