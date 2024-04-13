#include <iostream>
#include <SDL.h>

#include "States/PlayState.h"
#include "States/MenuState.h"

#include "Entities/Vaus.h"
#include "Entities/EngergyBall.h"
#include "Managers/BrickManager.h"
#include "Core/Collision.h"

PlayState PlayState::m_PlayState;
BrickManager brickManager;

void PlayState::Init(StateManager* manager)
{
	std::cout << "Init PlayState \n";

	m_Background = new Entity("Assets/Images/Maps/BackgroundBlue.png", manager->GetRenderer(), 1280.f, 720.f, 0.f, 0.f);
	m_TopLine = new Entity("Assets/Images/Maps/TopLine.png", manager->GetRenderer(), 1280.f, 16.f, 0.f, 0.f);
	m_LeftLine = new Entity("Assets/Images/Maps/SideLine.png", manager->GetRenderer(), 17.f, 720.f, 0.f, 0.f);
	m_RightLine = new Entity("Assets/Images/Maps/SideLine.png", manager->GetRenderer(), 17.f, 720.f, static_cast<float>(manager->m_WindowWidth) - 17.f, 0.f);

	m_Player = new Vaus("Assets/Images/Entities/Vaus.png", manager->GetRenderer(), 135.f, 24.f, 600.f, 636.f);

	m_EnergyBall = new EnergyBall("Assets/Images/Entities/EnergyBall.png", manager->GetRenderer(), 25.f, 25.f, 655.f, 611.f);

	brickManager.SetRenderer(manager->GetRenderer());
	brickManager.CreateBricks(54, 18);

}

void PlayState::Tick(StateManager* manager,float deltaTime)
{
	if(m_GameStarted)
	{
		if (manager->GetKeyboardState()[SDL_SCANCODE_D])
		{
			m_Player->Move(1, deltaTime);
		}

		if (manager->GetKeyboardState()[SDL_SCANCODE_A])
		{
			m_Player->Move(-1, deltaTime);
		}

		m_EnergyBall->Move(deltaTime);

		if (m_EnergyBall->GetTransform().y + m_EnergyBall->GetTransform().h >= 720.f)
		{
			m_GameStarted = false;
			ResetGame();
		}

		CheckCollisions();
	}
}

void PlayState::Shutdown()
{
	brickManager.ClearBricks();

	delete m_Background;
	delete m_Player;
	delete m_EnergyBall;

	delete m_LeftLine;
	delete m_RightLine;
	delete m_TopLine;
}

void PlayState::Render(StateManager* manager)
{
	m_Background->Draw();
	m_Player->Draw();
	brickManager.DrawBricks();
	m_EnergyBall->Draw();

	m_LeftLine->Draw();
	m_RightLine->Draw();
	m_TopLine->Draw();
}

void PlayState::HandleEvents(StateManager* manager)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//Window "X" is clicked
		case SDL_QUIT:
			manager->Shutdown();
			break;

			//key is pressed
		case SDL_KEYDOWN:
			//If Escape is clicked exit out
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				manager->Shutdown();
				return;
			}
			if (event.key.keysym.sym == SDLK_p)
			{
				manager->ChangeState(MenuState::Instance());
				return;
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_GameStarted = true;
			}
			break;
		}
	}
}

void PlayState::CheckCollisions()
{
	brickManager.CheckCollision(m_EnergyBall);
	
	//Check for circle collision with player.
	if (Breakout::Collision::CircleRect(m_EnergyBall->GetTransform(), m_Player->GetTransform())) 
	{
		m_EnergyBall->BouncePlayer(m_Player);
	}
}

void PlayState::ResetGame()
{
	m_Player->SetPosition(600.f, 636.f);
	m_EnergyBall->SetPosition(655.f, 611.f);
}
