#include "Bat.h"
#include <iostream>
#include <string>

using namespace std;

Bat::Bat() {
	this->width = Screen::screenWidth / 4;
	this->height = Screen::screenHeight / 6 - 90;
	this->defaultX = Screen::screenWidth / 2.5;
	this->defaultY = Screen::screenHeight - (Screen::screenHeight / 6 - 80);
	this->originalWidth = this->width;
}

void Bat::shapeInit(SDL_Renderer* renderer) {
	SDL_Rect fillRect = { this->defaultX, this->defaultY, this->width, this->height };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}

void Bat::batMove(float m) {
	if (this->defaultX + this->width < Screen::screenWidth && this->defaultX > 0) this->defaultX += m;
	if (this->defaultX <= 0) this->defaultX += 5;
	if (this->defaultX + this->width >= Screen::screenWidth) this->defaultX -= 5;
}

void Bat::batCut() {
	if (this->width > this->originalWidth / 2) this->width -= 20;
}