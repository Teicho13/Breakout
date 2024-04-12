#include <iostream>
#include <SDL.h>

#include "States/MenuState.h"
#include "States/PlayState.h"

MenuState MenuState::m_MenuState;

void MenuState::Init(StateManager* manager)
{
	std::cout << "Init Menu State \n";
}

void MenuState::Tick(StateManager* manager, float deltaTime)
{
	
}

void MenuState::Shutdown()
{
}

void MenuState::Render(StateManager* manager)
{

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
			if (event.key.keysym.sym == SDLK_p)
			{
				manager->ChangeState(PlayState::Instance());
				return;
			}
			break;
		}
	}
}
