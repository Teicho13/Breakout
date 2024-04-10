#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "main.h"
#include "Core/Game.h"
#include "Core/TextureManager.h"

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

		//Pointer to keyboard button states
		g_KeyStates = SDL_GetKeyboardState(nullptr);
 
		//Initialize game
		g_breakout = new Game(g_Renderer);

		g_breakout->Init();
	}

	void PollEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type)
			{
				//Window "X" is clicked
			case SDL_QUIT:
				g_IsRunning = false;
				break;

				//key is pressed
			case SDL_KEYDOWN:
				//If Escape is clicked exit out
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					g_IsRunning = false;
					return;
				}
				g_breakout->KeyDown(event.key.keysym.scancode);
				break;

				//Key is let go
			case SDL_KEYUP:
				g_breakout->KeyUp(event.key.keysym.scancode);
				break;

				//Mouse clicked
			case SDL_MOUSEBUTTONDOWN:
				g_breakout->MouseButtondDown(event.button.button);
				break;

				//Mouse Let go
			case SDL_MOUSEBUTTONUP:
				g_breakout->MouseButtonUp(event.button.button);
				break;
			}
		}
	}

	void Render()
	{
		//Clear render screen for new frame
		SDL_RenderClear(g_Renderer);

		//Temp create texture and render to screen
		g_breakout->Render();

		//Render everything to the screen
		SDL_RenderPresent(g_Renderer);
	}

	void ShutDown()
	{
		SDL_DestroyRenderer(g_Renderer);
		SDL_DestroyWindow(g_Window);
	}

}


int main(int argc, char** argv)
{
	//Create and initialize the renderer and window
	Breakout::Initialize();

	while (Breakout::g_IsRunning)
	{
		Breakout::PollEvents();

		//Calculate Delta time in seconds
		Breakout::g_LastTime = Breakout::g_Time;
		Breakout::g_Time = SDL_GetPerformanceCounter();

		Breakout::g_DeltaTime = ((Breakout::g_Time - Breakout::g_LastTime) / static_cast<double>(SDL_GetPerformanceFrequency()));

		//Update Game
		Breakout::g_breakout->Tick(Breakout::g_DeltaTime,Breakout::g_KeyStates);

		Breakout::Render();
	}

	Breakout::g_breakout->Shutdown();
	delete Breakout::g_breakout;

	//Destroy created window and renderer
	Breakout::ShutDown();

	return 0;
}

