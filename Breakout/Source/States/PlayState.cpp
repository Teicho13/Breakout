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

	m_Player = new Vaus("Assets/Images/Entities/Vaus.png", manager->GetRenderer(), 135.f, 24.f, 600.f, 686.f);

	m_EnergyBall = new EnergyBall("Assets/Images/Entities/EnergyBall.png", manager->GetRenderer(), 25.f, 25.f, 655.f, 666.f);

	brickManager.SetRenderer(manager->GetRenderer());
	brickManager.CreateBricks(54, 18);

}

void PlayState::Tick(StateManager* manager,float deltaTime)
{
	if (manager->GetKeyboardState()[SDL_SCANCODE_D])
	{
		m_Player->Move(1,deltaTime);
	}

	if (manager->GetKeyboardState()[SDL_SCANCODE_A])
	{
		m_Player->Move(-1, deltaTime);
	}

	m_EnergyBall->Move(deltaTime);

	CheckCollisions();
}

void PlayState::Shutdown()
{
	brickManager.ClearBricks();

	delete m_Background;
	delete m_Player;
	delete m_EnergyBall;
}

void PlayState::Render(StateManager* manager)
{
	m_Background->Draw();
	m_Player->Draw();
	m_EnergyBall->Draw();
	brickManager.DrawBricks();
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
