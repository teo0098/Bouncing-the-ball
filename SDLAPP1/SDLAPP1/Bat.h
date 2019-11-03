#pragma once
#include "Shape.h"
#include "Ball.h"

using namespace std;

class Bat :public Shape
{
private:
	float originalWidth;
	friend class Ball;
public:
	Bat();
	~Bat() {};
	void shapeInit(SDL_Renderer* renderer);
	void batMove(float m);
	void batCut();
};

