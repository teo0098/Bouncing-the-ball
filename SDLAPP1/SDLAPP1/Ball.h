#pragma once
#include "Shape.h"
#include "Bat.h"
#include "Square.h"

class Bat;

class Ball :public Shape
{
private:
	float moveX;
	float moveY;
	friend class Square;
public:
	Ball();
	~Ball() {};
	void ballChangeXY(float& dX, float& dY);
	void shapeInit(SDL_Renderer* renderer);
	void ballMove(Bat &b);
	bool ballGround();
};

