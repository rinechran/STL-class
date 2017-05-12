#pragma once
#include "Process.h"
#include "Processer.h"

template <int RTIME>
class RR : public Process {
public:
	struct SeriveTemp {
		ProcessData mProcess;
		serviceTime mLimitTime;

	};
	RR();
	bool isBiasTime();
	bool update();
	void run();

	std::vector<ProcessData> mArrProcessData;
protected:


	int mCurrentStep;
	SeriveTemp mServiceTemp;

};

template<int RTIME>
RR<RTIME>::RR() : Process(), mCurrentStep(0) {

}

template<int RTIME>
bool RR<RTIME>::isBiasTime() {
	return mArrProcessData.size() != 0 ? true : false;
}

template<int RTIME>
bool RR<RTIME>::update() {
	if (this->getProcess() || this->mPrecessBuffer.size() || isBiasTime() || mIsRun ) {
		for (auto & i = this->mPrecessBuffer.begin(); i != mPrecessBuffer.end();) {
			mArrProcessData.push_back(*i);
			i = mPrecessBuffer.erase(i);

		}

		//안돌아가고 있다..

		if (mIsRun == true) {
			//타이머 종료?

			--mServiceTemp.mProcess.serviceTime;
			--mServiceTemp.mLimitTime;
			if (mServiceTemp.mProcess.serviceTime == 0) {
				mIsRun = false;
			}
			else if (mServiceTemp.mLimitTime == 0) {
				mArrProcessData.push_back(mServiceTemp.mProcess);
				mIsRun = false;
			}
		}

		if (mIsRun == false) {

			if (mArrProcessData.size() != 0) {
				mServiceTemp.mProcess = *mArrProcessData.begin();
				mServiceTemp.mLimitTime = RTIME;


				mArrProcessData.erase(mArrProcessData.begin());
				mIsRun = true;
			}
		}

		return true;
	}
	return false;
}

template<int RTIME>
void RR<RTIME>::run() {
	while (update()) {
		if (mIsRun == true) {
			std::cout << "ID : " << mServiceTemp.mProcess.id << " Rpocess Time : " << mServiceTemp.mProcess.serviceTime
				<< "  service Time : " << mServiceTemp.mLimitTime << std::endl;

		}
	}
}
