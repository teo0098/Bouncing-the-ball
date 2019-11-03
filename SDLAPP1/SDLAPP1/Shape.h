#pragma once
#include "Screen.h"

class Shape
{
protected:
	float defaultX;
	float defaultY;
	float width;
	float height;
public:
	virtual void shapeInit(SDL_Renderer* renderer) = 0;
	virtual ~Shape() {};
};

