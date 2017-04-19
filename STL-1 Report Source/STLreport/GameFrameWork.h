#pragma once
class GmaeFrameWork {
public:
	virtual void update() = 0;
	virtual void input() = 0;
	virtual void reder() = 0;
	virtual ~GmaeFrameWork() {};
};