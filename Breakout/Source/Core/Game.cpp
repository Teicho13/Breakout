#include <SDL.h>

#include "Core/Game.h"
#include "Entities/Entity.h"

Game::Game(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

void Game::Init()
{
	Player = new Entity("Assets/Images/TestAsset.png", GetRenderer(),64.f,64.f,0,500.f);
}

void Game::Shutdown()
{
	delete Player;
}

void Game::Tick(double deltaTime, const Uint8* keyboard)
{
	if (keyboard[SDL_SCANCODE_D])
	{
		SDL_FRect tmpRec = Player->GetPosition();
		tmpRec.x += 300.f * deltaTime;
		Player->SetPosition(tmpRec);
	}

	if (keyboard[SDL_SCANCODE_A])
	{
		SDL_FRect tmpRec = Player->GetPosition();
		tmpRec.x -= 300.f * deltaTime;
		Player->SetPosition(tmpRec);
	}

}

void Game::Render()
{
	Player->Draw();
}

SDL_Renderer* Game::GetRenderer()
{
	return m_Renderer;
}
