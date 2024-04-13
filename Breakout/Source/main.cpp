#include <SDL.h>

#include "./Managers/StateManager.h"
#include "States/MenuState.h"


int main(int argc, char** argv)
{
	//Create State Manager
	StateManager stateManager;

	//Initialize Game
	stateManager.Init(false);

	//Load Play State singelton
	stateManager.ChangeState(MenuState::Instance());

	while (stateManager.GetIsRunning())
	{		
		stateManager.HandleEvents();
		stateManager.Update();
		stateManager.Render();
	}

	stateManager.Shutdown();

	return 0;
}




