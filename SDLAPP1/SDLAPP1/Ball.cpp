#include <iostream>
#include "Ball.h"
#include <cmath>

using namespace std;

Ball::Ball() {
	this->defaultX = 400;
	this->defaultY = 100;
	this->width = 20;
	this->height = 20;
	this->moveX = 4;
	this->moveY = 4;
}

void Ball::ballChangeXY(float& dX, float& dY) {
	this->defaultX = dX;
	this->defaultY = dY;
	if (this->defaultX + this->width > Screen::screenWidth) {
		float checkLength = this->defaultX + this->width - Screen::screenWidth;
		this->defaultX -= checkLength;
	}
}

void Ball::shapeInit(SDL_Renderer* renderer) {
	SDL_Rect fillRect = { this->defaultX, this->defaultY, this->width, this->height };
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &fillRect);
}

void Ball::ballMove(Bat &b) {
	if (this->defaultX + this->width >= Screen::screenWidth) this->moveX = -this->moveX;
	if (this->defaultX <= 0) this->moveX = -this->moveX;
	if (this->defaultY <= 0) this->moveY = -this->moveY;
	if (this->defaultY + this->height >= b.defaultY && (this->defaultX + this->width >= b.defaultX && this->defaultX <= b.defaultX + b.width)) {
		this->moveY = -this->moveY;
		float hitPoint, middleBat = b.width / 2, middleBall = this->width / 2;
		hitPoint = fabs(((this->defaultX + middleBall) - (b.defaultX + middleBat)) / 10);
		if (this->defaultX + middleBall > b.defaultX + middleBat) {
			if (this->moveX < 0) this->moveX *= -1;
			this->moveX = hitPoint / 1.5;
		}
		if (this->defaultX + middleBall < b.defaultX + middleBat) {
			if (this->moveX > 0) this->moveX *= -1;
			this->moveX = -hitPoint / 1.5;
		}
	}
	this->defaultX += this->moveX;
	this->defaultY += this->moveY;
}

bool Ball::ballGround() {
	if (this->defaultY + this->height >= Screen::screenHeight) return true;
	return false;
}