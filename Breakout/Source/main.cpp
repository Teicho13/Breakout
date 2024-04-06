#include <Core/Game.h>

#undef main

int main()
{

	Game* breakout = new Game();

	breakout->Init();

	while (breakout->IsRunning())
	{
		breakout->Tick(0.f);
		breakout->Render();
	}

	breakout->Shutdown();

	return 0;
}