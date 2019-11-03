#include <iostream>
#include <time.h>
#include <SDL.h>
#include "Bat.h"
#include "Ball.h"
#include "Square.h"
#include "Shape.h"

using namespace std;

void getShapeInit(Shape* shape, SDL_Renderer* renderer) {
	shape->shapeInit(renderer);
}

int main(int argc, char **argv) {
	srand(time(NULL));
	Screen screen;
	if (screen.init()) {
		Bat bat;
		Ball ball;
		Square square;
		SDL_Event e;
		float squareX, squareY, ballX, ballY;
		bool quit = false;
		int score = 0;
		squareX = rand() % (Screen::screenWidth + 1);
		squareY = rand() % ((Screen::screenHeight / 2) + 1);
		do {
			ballX = rand() % (Screen::screenWidth + 1);
			ballY = rand() % ((Screen::screenHeight / 2 - 200) + 1);
		} while (ballX != squareX && ballY != squareY);
		ball.ballChangeXY(ballX, ballY);
		square.squareChangeXY(squareX, squareY);
		while (!quit) {
			getShapeInit(&bat, screen.getRenderer());
			getShapeInit(&ball, screen.getRenderer());
			ball.ballMove(bat);
			if (ball.ballGround()) {
				const char* title = "SCORE:";
				char message[1000];
				sprintf_s(message, "%d", score);
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title, message, NULL);
				break;
			}
			getShapeInit(&square, screen.getRenderer());
			if (square.squareTouched(ball)) {
				score++;
				do {
					squareX = rand() % (Screen::screenWidth + 1);
					squareY = rand() % ((Screen::screenHeight / 2) + 1);
				} while (squareX != ballX && squareY != ballY);
				square.squareChangeXY(squareX, squareY);
				getShapeInit(&square, screen.getRenderer());
				if (score % 3 == 0) bat.batCut();
			}
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_QUIT) quit = true;
				else if (e.type == SDL_KEYDOWN) {
					switch (e.key.keysym.sym) {
					case SDLK_LEFT: bat.batMove(-10);
						break;
					case SDLK_RIGHT: bat.batMove(10);
					}
				}
			}
			screen.update();
		}
		screen.end();
	}
	else SDL_Quit();
	return 0;
}