#include <Core/Game.h>

#undef main

int main()
{

	Game* breakout = new Game();

	//Timer
	Uint64 time = SDL_GetPerformanceCounter();
	Uint64 lastTime = 0;
	double deltaTime = 0;

	breakout->Init();

	while (breakout->IsRunning())
	{
		//Calculate Delta time in seconds
		lastTime = time;
		time = SDL_GetPerformanceCounter();

		deltaTime = ((time - lastTime) / static_cast<double>(SDL_GetPerformanceFrequency()));

		breakout->Tick(deltaTime);
		breakout->Render();
	}

	breakout->Shutdown();

	delete breakout;

	return 0;
}