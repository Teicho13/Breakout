#pragma once
#include <SDL.h>

class Game 
{
public:

	void Init();
	void Shutdown();
	void Tick(float DeltaTime);
	void Render();
	bool IsRunning() { return isRunning; }

private:

	bool isRunning = false;
	
	SDL_Window* window;
	SDL_Renderer* renderer;
};