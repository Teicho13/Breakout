#include "Core/Game.h"


void Game::Init()
{
	//Setup Rendering

	SDL_Init(SDL_INIT_EVERYTHING);
	m_Window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
	SDL_SetRenderDrawColor(m_Renderer, 27, 146, 214, 255);

	m_IsRunning = true;
}

void Game::Shutdown()
{
	//Destroy created window and renderer

	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
}

void Game::Tick(double DeltaTime)
{
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
	{
		m_IsRunning = false;
	}
}

void Game::Render()
{
	SDL_RenderClear(m_Renderer);
	SDL_RenderPresent(m_Renderer);
}
