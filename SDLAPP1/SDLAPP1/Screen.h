#pragma once
#include <SDL.h>
class Screen
{
public:
	static const int screenWidth = 800;
	static const int screenHeight = 600;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	Uint32* buffer;
public:
	Screen();
	SDL_Renderer* getRenderer();
	bool windowInit();
	bool rendererInit();
	bool textureInit();
	bool init();
	void update();
	void end();
};

