#include "Core/Game.h"

void Game::Init()
{
	//Setup Rendering

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 27, 146, 214, 255);

	isRunning = true;
}

void Game::Shutdown()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Game::Tick(float DeltaTime)
{
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
	{
		isRunning = false;
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}
