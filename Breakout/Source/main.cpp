#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


#include "main.h"

#include "./Managers/StateManager.h"
#include "./States/PlayState.h"

#include "./Core/TextureManager.h"


int main(int argc, char** argv)
{
	//Create State Manager
	StateManager stateManager;

	//Initialize Game
	stateManager.Init(false);

	//Load Play State singelton
	stateManager.ChangeState(PlayState::Instance());

	while (stateManager.GetIsRunning())
	{		
		stateManager.HandleEvents();
		stateManager.Update();
		stateManager.Render();
	}

	stateManager.Shutdown();

	return 0;
}




