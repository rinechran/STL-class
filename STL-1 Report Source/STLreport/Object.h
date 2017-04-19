#pragma once

#include <iostream>
#include <map>
#include <utility>
#include "Range.hpp"

//Score Uid


struct User {
public:
	User() {

	}
	User(size_t uid) : mUid(uid) {

	}
	User(size_t uid, size_t * arr) : mUid(uid){
		memcpy(mScore,arr,sizeof(size_t) * sizeof(mScore)/sizeof(mScore[0]));

	}
	void SetScore() {

	}

	//private:
	size_t mUid;
	size_t mScore[5];

};


struct ScoreUid
{
	ScoreUid(size_t * score, size_t * uid) 
		:mScore(score), mUid(uid), mPastRank(0), mCurrentRank(0){

	}
	size_t *mScore;
	size_t *mUid;
	int mPastRank;
	int mCurrentRank;

};
struct TotalScore {
	TotalScore(User * uid) : 
		mUser(uid), totalScore(0), mPastRank(0), mCurrentRank(0){
		
	}
	void refreash() {
		totalScore = 0;
		for (auto &i : Range(0, 5)) {
			totalScore += mUser->mScore[i];
		}
	}
	User * mUser;
	size_t totalScore;
	int mPastRank;
	int mCurrentRank;
};
struct Arenas {
	Arenas()  {

	}
	//score uid
	std::vector<TotalScore> totalArean;
	std::vector<ScoreUid> arean[5];
};
