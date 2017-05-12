#include <vector>
#include <array>
#include "Process.h"

#include "Processer.h"

#pragma once

template <int N, int STEP>
class Feeback : public Process {
public:
	struct SeriveTemp {
		ProcessData mProcess;
		serviceTime mLimitTime;
		int mStep;

	};
	Feeback();
	bool isBiasTime();
	bool update();
	void run();
	int getStep();
	void upStep();
	std::array<std::vector<ProcessData>, STEP > mBiasTime;
protected:
	int mCurrentStep;
	SeriveTemp mServiceTemp;

};

template<int N, int STEP>
inline Feeback<N, STEP>::Feeback() : Process(), mCurrentStep(0) {

}

template<int N, int STEP>
inline bool Feeback<N, STEP>::isBiasTime() {
	for (auto i = 0; i < mBiasTime.size(); ++i) {
		if (mBiasTime[i].size()) return true;

	}
	return false;
}

template<int N, int STEP>
inline bool Feeback<N, STEP>::update() {
	if (this->getProcess() || this->mPrecessBuffer.size() || isBiasTime() || mIsRun) {
		for (auto & i = this->mPrecessBuffer.begin(); i != mPrecessBuffer.end();) {
			mBiasTime[0].push_back(*i);
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
				int tempStep = std::min(mServiceTemp.mStep, STEP - 2);
				tempStep++;
				mBiasTime[tempStep].push_back(mServiceTemp.mProcess);
				mIsRun = false;
			}
		}

		if (mIsRun == false) {
			int loop = getStep();
			while (true) {
				if (mBiasTime[getStep()].size() != 0) {
					mServiceTemp.mProcess = *mBiasTime[getStep()].begin();
					mServiceTemp.mLimitTime = static_cast<int>(std::pow(N, getStep()));
					mServiceTemp.mStep = getStep();


					mBiasTime[getStep()].erase(mBiasTime[getStep()].begin());
					mIsRun = true;
					upStep();
				}

				upStep();
				if (loop == getStep() || mIsRun == true) break;
			}
		}

		return true;
	}
	return false;
}

template<int N, int STEP>
inline void Feeback<N, STEP>::run() {
	while (update()) {
		if (mIsRun == true) {
			std::cout << "ID :" << mServiceTemp.mProcess.id << " Rpocess Time : " << mServiceTemp.mProcess.serviceTime
				<< "  service Time : " << mServiceTemp.mLimitTime << std::endl;

		}
	}
}

template<int N, int STEP>
inline int Feeback<N, STEP>::getStep() {
	return mCurrentStep % STEP;
}

template<int N, int STEP>
inline void Feeback<N, STEP>::upStep() {
	++mCurrentStep;
}
