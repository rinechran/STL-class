#include <vector>
#include <array>
#include "Process.h"
#include "Processer.h"

class SJF : public Process {
public:
	struct SeriveTemp {
		ProcessData mProcess;
	};
	SJF();
	bool isBiasTime();
	bool update();
	void run();

	std::vector<ProcessData> mArrProcessData;
protected:


	int mCurrentStep;
	SeriveTemp mServiceTemp;

};

SJF::SJF() : Process(), mCurrentStep(0) {

}

bool SJF::isBiasTime() {
	return mArrProcessData.size() != 0 ? true : false;
}

bool SJF::update() {
	if (this->getProcess() || this->mPrecessBuffer.size() || isBiasTime() || mIsRun) {
		for (auto & i = this->mPrecessBuffer.begin(); i != mPrecessBuffer.end();) {
			mArrProcessData.push_back(*i);
			i = mPrecessBuffer.erase(i);

		}

		//안돌아가고 있다..

		if (mIsRun == true) {
			//타이머 종료?
			--mServiceTemp.mProcess.serviceTime;
			if (mServiceTemp.mProcess.serviceTime == 0) {
				mIsRun = false;
			}
		}

		if (mIsRun == false) {

			if (mArrProcessData.size() != 0) {

				auto it = std::min_element(mArrProcessData.begin(), mArrProcessData.end(),
					[=](ProcessData &obj1, ProcessData &obj2) {return obj1.serviceTime < obj2.serviceTime; }
				);

				mServiceTemp.mProcess = *it;
				mArrProcessData.erase(it);
				mIsRun = true;
			}
		}

		return true;
	}
	return false;
}

void SJF::run() {
	while (update()) {
		if (mIsRun == true) {
			std::cout << "ID : " << mServiceTemp.mProcess.id << " Rpocess Time : " << mServiceTemp.mProcess.serviceTime
				<< std::endl;

		}
	}
}
