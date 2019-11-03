#include "Square.h"

Square::Square() {
	this->defaultX = 400;
	this->defaultY = 200;
	this->width = 15;
	this->height = 15;
	this->moveX = 2;
	this->moveY = 2;
}

void Square::squareChangeXY(float& dX, float& dY) {
	this->defaultX = dX;
	this->defaultY = dY;
	if (this->defaultX + this->width > Screen::screenWidth) {
		float checkLength = this->defaultX + this->width - Screen::screenWidth;
		this->defaultX -= checkLength;
	}
}

void Square::shapeInit(SDL_Renderer* renderer) {
	SDL_Rect fillRect = { this->defaultX, this->defaultY, this->width, this->height };
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &fillRect);
}

bool Square::squareTouched(Ball &b) {
	if ((b.defaultY >= this->defaultY && b.defaultY <= this->defaultY + this->height)
		&& (b.defaultX + b.width >= this->defaultX && b.defaultX + b.width <= this->defaultX + this->width)) return true;
	if ((b.defaultY + b.height >= this->defaultY && b.defaultY + b.height <= this->defaultY + this->height)
		&& (b.defaultX + b.width >= this->defaultX && b.defaultX + b.width <= this->defaultX + this->width)) return true;
	if ((b.defaultY + b.height >= this->defaultY && b.defaultY + b.height <= this->defaultY + this->height)
		&& (b.defaultX >= this->defaultX && b.defaultX <= this->defaultX + this->width)) return true;
	if ((b.defaultY >= this->defaultY && b.defaultY <= this->defaultY + this->height)
		&& (b.defaultX >= this->defaultX && b.defaultX <= this->defaultX + this->width)) return true;
	return false;
}
