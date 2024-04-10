#include <SDL.h>

#include "Core/Game.h"
#include "Entities/Vaus.h"
#include "Entities/Brick.h"
#include "Managers/BrickManager.h"


BrickManager brickManager;

Game::Game(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

void Game::Init()
{
	m_Background = new Entity("Assets/Images/Maps/BackgroundBlue.png", GetRenderer(), 1280.f, 720.f, 0.f, 0.f);
	Player = new Vaus("Assets/Images/Entities/Vaus.png", GetRenderer(),160.f,24.f,600.f,100.f);

	brickManager.SetRenderer(GetRenderer());
	brickManager.CreateBricks(54,18);
}

void Game::Shutdown()
{
	delete m_Background;
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
	m_Background->Draw();
	Player->Draw();
	brickManager.DrawBricks();
}

SDL_Renderer* Game::GetRenderer()
{
	return m_Renderer;
}
