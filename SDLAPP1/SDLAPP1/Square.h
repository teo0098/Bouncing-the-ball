#pragma once
#include "Shape.h"
#include "Ball.h"

class Ball;

class Square :public Shape
{
private:
	float moveX;
	float moveY;
public:
	Square();
	~Square() {};
	void squareChangeXY(float& dX, float& dY);
	void shapeInit(SDL_Renderer* renderer);
	bool squareTouched(Ball &b);
};

