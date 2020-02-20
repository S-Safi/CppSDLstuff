#include "SDL.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("finally", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetWindowResizable(window, SDL_TRUE);
	SDL_SetWindowBordered(window, SDL_TRUE);
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	int h = DM.h;
	int flag = true;
	int count = 0;
	SDL_Rect rect;
		rect.x = 0;
		rect.y = 2;
		rect.w = 20;
		rect.h = 120;
	SDL_Rect rect2;
		rect2.x = SDL_GetWindowSurface(window)->w - 20;
		rect2.y = 300;
		rect2.w = 20;
		rect2.h = 120;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderFillRect(renderer,&rect);
	SDL_RenderDrawRect(renderer, &rect2);
	SDL_RenderFillRect(renderer, &rect2);
	SDL_RenderPresent(renderer);
	SDL_Event event;
	while (1) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					//rect.x -= 5;
					break;
				case SDLK_RIGHT:
					//rect.x += 5;
					break;
				case SDLK_UP:
					rect.y -= 5;
					break;
				case SDLK_DOWN:
					rect.y += 5;
					break;
				case SDLK_ESCAPE:
					SDL_DestroyWindow(window);
					break;
				default:
					break;
				}
			}
		}
		if (rect2.y == 0) {
			flag = true;
		}
		else if (rect2.y == h - 120) {
			flag = false;
		}
		if (count % 4 == 0) {
			if (flag == false) {
				rect2.y -= 1;
			}
			else if (flag == true) {
				rect2.y += 1;
			}
		}
		

		count += 1;

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(renderer, &rect);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderDrawRect(renderer, &rect2);
		SDL_RenderFillRect(renderer, &rect2);
		SDL_RenderPresent(renderer);
	}
	return 0;
}