#pragma once
#include <SDL.h>

class Game 
{
public:

	void Init();
	void Shutdown();
	void Tick(double DeltaTime);
	void Render();
	bool IsRunning() { return m_IsRunning; }

private:

	bool m_IsRunning = false;
	
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};