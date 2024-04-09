#include <SDL.h>

#include "Core/Game.h"
#include "Entities/Entity.h"

Game::Game(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

void Game::Init()
{
	Player = new Entity("Assets/Images/TestAsset.png", GetRenderer());
}

void Game::Shutdown()
{
	delete Player;
}

void Game::Tick(double DeltaTime)
{

}

void Game::Render()
{
	Player->Draw();
}

SDL_Renderer* Game::GetRenderer()
{
	return m_Renderer;
}
