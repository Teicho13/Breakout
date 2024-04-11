#include <SDL.h>
#include <iostream>

#include "Core/Game.h"
#include "Entities/Vaus.h"
#include "Entities/EngergyBall.h"
#include "Managers/BrickManager.h"
#include "Core/Collision.h"

BrickManager brickManager;

Game::Game(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

void Game::Init()
{
	m_Background = new Entity("Assets/Images/Maps/BackgroundBlue.png", GetRenderer(), 1280.f, 720.f, 0.f, 0.f);
	
	m_Player = new Vaus("Assets/Images/Entities/Vaus.png", GetRenderer(),135.f,24.f,600.f,686.f);

	m_EnergyBall = new EnergyBall("Assets/Images/Entities/EnergyBall.png", GetRenderer(), 25.f, 25.f, 655.f, 666.f);

	brickManager.SetRenderer(GetRenderer());
	brickManager.CreateBricks(54,18);
}

void Game::Shutdown()
{
	delete m_Background;
	delete m_Player;
	delete m_EnergyBall;
}

void Game::Tick(double deltaTime, const Uint8* keyboard)
{
	if (keyboard[SDL_SCANCODE_D])
	{
		m_Player->Move(1,deltaTime);
	}

	if (keyboard[SDL_SCANCODE_A])
	{
		m_Player->Move(-1, deltaTime);
	}

	m_EnergyBall->Move(deltaTime);

	brickManager.CheckCollision(m_EnergyBall);

	//Check for circle collision with player.
	if (Breakout::Collision::CircleRect(m_EnergyBall->GetTransform(), m_Player->GetTransform())) {
		m_EnergyBall->BouncePlayer(m_Player);
	}
}

void Game::Render()
{
	m_Background->Draw();
	m_Player->Draw();
	m_EnergyBall->Draw();
	brickManager.DrawBricks();
}

SDL_Renderer* Game::GetRenderer()
{
	return m_Renderer;
}
