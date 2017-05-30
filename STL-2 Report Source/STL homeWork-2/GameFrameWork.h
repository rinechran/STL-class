#pragma once
struct GameFrameWork {
public:
	virtual void update() = 0;
	virtual void input() = 0;
	virtual void render() = 0;
	virtual void gameLoop() = 0;

	virtual ~GameFrameWork() {};


};