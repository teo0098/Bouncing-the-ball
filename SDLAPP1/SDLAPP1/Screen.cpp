#include "Screen.h"
#include <iostream>

using namespace std;

Screen::Screen() {
	this->window = NULL;
	this->renderer = NULL;
	this->texture = NULL;
	this->buffer = NULL;
}

SDL_Renderer* Screen::getRenderer() {
	return this->renderer;
}

bool Screen::windowInit() {
	this->window = SDL_CreateWindow("HIT THE RUNNING SQUARE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		this->screenWidth, this->screenHeight, SDL_WINDOW_SHOWN);
	if (this->window == NULL) {
		SDL_DestroyWindow(this->window);
		SDL_Quit();
		return false;
	}
	return true;
}

bool Screen::rendererInit() {
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (this->renderer == NULL) {
		SDL_DestroyRenderer(this->renderer);
		SDL_DestroyWindow(this->window);
		SDL_Quit();
		return false;
	}
	return true;
}

bool Screen::textureInit() {
	this->texture = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 
		this->screenWidth, this->screenHeight);
	if (this->texture == NULL) {
		SDL_DestroyTexture(this->texture);
		SDL_DestroyRenderer(this->renderer);
		SDL_DestroyWindow(this->window);
		SDL_Quit();
		return false;
	}
	return true;
}

bool Screen::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "\nSDL INITIALIZATION HAS FAILED " << SDL_GetError() << endl;
		return false;
	}
	else {
		if (!this->windowInit()) {
			cout << "\nCREATING A WINDOW HAS FAILED " << SDL_GetError() << endl;
			return false;
		}
		if (!this->rendererInit()) {
			cout << "\nCREATING A RENDERER HAS FAILED " << SDL_GetError() << endl;
			return false;
		}
		if (!this->textureInit()) {
			cout << "\nCREATING A TEXTURE HAS FAILED " << SDL_GetError() << endl;
			return false;
		}
	}
	this->buffer = new Uint32[this->screenWidth * this->screenHeight];
	memset(this->buffer, 0x00, this->screenWidth * this->screenHeight * sizeof(Uint32));
	return true;
}

void Screen::update() {
	SDL_RenderPresent(this->renderer);
	SDL_UpdateTexture(this->texture, NULL, this->buffer, this->screenWidth * sizeof(Uint32));
	SDL_RenderClear(this->renderer);
	SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);
}

void Screen::end() {
	delete[] this->buffer;
	SDL_DestroyTexture(this->texture);
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}
