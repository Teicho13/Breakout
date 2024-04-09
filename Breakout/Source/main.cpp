#include <SDL.h>
#include <SDL_image.h>

#include "main.h"
#include "Core/Game.h"
#include "Core/TextureManager.h"
#include "Entities/Entity.h"

Entity* Player = nullptr;

namespace Breakout
{
	void Initialize()
	{
		//Setup SDL and create window
		SDL_Init(SDL_INIT_EVERYTHING);

#ifdef FULLSCREEN
		Window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, g_WindowWidth, g_WindowHeight, SDL_WINDOW_FULLSCREEN);
#else
		g_Window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, g_WindowWidth, g_WindowHeight, SDL_WINDOW_SHOWN);
#endif

		//Create renderer for SDL and set defaul background color
		g_Renderer = SDL_CreateRenderer(g_Window, -1, 0);
		SDL_SetRenderDrawColor(g_Renderer, 27, 146, 214, 255);

		Player = new Entity("Assets/Images/TestAsset.png", g_Renderer);

		//Initialize game
		g_breakout = new Game();

		g_breakout->Init();
	}

	void PollEvents()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		if (event.type == SDL_QUIT)
		{
			g_IsRunning = false;
		}
	}

	void Render()
	{
		//Clear render screen for new frame
		SDL_RenderClear(g_Renderer);

		//Temp create texture and render to screen
		Player->Draw(g_Renderer);

		//Render everything to the screen
		SDL_RenderPresent(g_Renderer);
	}

	void ShutDown()
	{
		SDL_DestroyRenderer(g_Renderer);
		SDL_DestroyWindow(g_Window);
	}

}

//Timer
Uint64 time = SDL_GetPerformanceCounter();
Uint64 lastTime = 0;
double deltaTime = 0;

int main(int argc, char** argv)
{
	//Create and initialize the renderer and window
	Breakout::Initialize();



	while (Breakout::g_IsRunning)
	{
		Breakout::PollEvents();

		//Calculate Delta time in seconds
		lastTime = time;
		time = SDL_GetPerformanceCounter();

		deltaTime = ((time - lastTime) / static_cast<double>(SDL_GetPerformanceFrequency()));

		//Update Game
		Breakout::g_breakout->Tick(deltaTime);

		Breakout::Render();
	}

	Breakout::g_breakout->Shutdown();
	delete Breakout::g_breakout;

	//Destroy created window and renderer
	Breakout::ShutDown();

	return 0;
}

