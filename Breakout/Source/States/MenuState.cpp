#include <iostream>
#include <SDL.h>

#include "States/MenuState.h"
#include "States/PlayState.h"

#include "./Entities/Entity.h"
#include "Core/Collision.h"
#include "Entities/MenuStar.h"

MenuState MenuState::m_MenuState;

MenuStar* stars[60];

void MenuState::Init(StateManager* manager)
{
	std::cout << "Init Menu State \n";

	//Create all UI for the menu

	m_Title = new Entity("Assets/Images/UI/Title.png", manager->GetRenderer(), 582.f, 126.f, (static_cast<float>(manager->m_WindowWidth) / 2.f) - (582.f / 2.f), 50.f);
	m_StartButton = new Entity("Assets/Images/UI/Start.png", manager->GetRenderer(), 262.f, 88.f, (static_cast<float>(manager->m_WindowWidth) / 2.f) - (262.f / 2.f), 300.f);
	m_QuitButton = new Entity("Assets/Images/UI/Quit.png", manager->GetRenderer(), 229.f, 77.f, (static_cast<float>(manager->m_WindowWidth) / 2.f) - (229.f / 2.f), 500.f);

	//Create background stars and randomize positions
	srand((unsigned)time(NULL));

	for (int i = 0; i < sizeof(stars) / sizeof(stars[0]); i++)
	{
		stars[i] = new MenuStar(manager->GetRenderer());
	}
}

void MenuState::Tick(StateManager* manager, float deltaTime)
{
	UpdateStars(deltaTime);
}

void MenuState::Shutdown()
{

	//Remove all stars

	for (int i = 0; i < sizeof(stars) / sizeof(stars[0]); i++)
	{
		delete stars[i];
	}

	delete m_Title;
	delete m_StartButton;
	delete m_QuitButton;
}

void MenuState::Render(StateManager* manager)
{
	RenderStars();

	m_Title->Draw();
	m_StartButton->Draw();
	m_QuitButton->Draw();
}

void MenuState::HandleEvents(StateManager* manager)
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
			if (event.key.keysym.sym == SDLK_RETURN)
			{
				manager->ChangeState(PlayState::Instance());
				return;
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			if(event.button.button == SDL_BUTTON_LEFT)
			{
				int mouseX, mouseY;
				SDL_GetMouseState(&mouseX, &mouseY);

				CheckButtonClicked(manager, static_cast<float>(mouseX), static_cast<float>(mouseY));
			}
			break;
		}
	}
}

void MenuState::CheckButtonClicked(StateManager* manager, const float x, const float y)
{
	//On Mouse click check mouse position and check if it overlaps with either of the 2 buttons

	SDL_FRect tempRect(x, y, 1.f, 1.f);
	if (Breakout::Collision::AABB(tempRect, m_StartButton->GetTransform()))
	{
		manager->ChangeState(PlayState::Instance());
	}

	if (Breakout::Collision::AABB(tempRect, m_QuitButton->GetTransform()))
	{
		manager->Shutdown();
	}
}

void MenuState::UpdateStars(float dt)
{
	for (int i = 0; i < sizeof(stars) / sizeof(stars[0]); i++)
	{
		stars[i]->Update(dt);
	}
}

void MenuState::RenderStars()
{
	for (int i = 0; i < sizeof(stars) / sizeof(stars[0]); i++)
	{
		stars[i]->Draw();
	}
}
