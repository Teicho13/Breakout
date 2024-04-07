#include <SDL.h>
#undef main

#include <Core/Game.h>

const int WindowWidth = 1280;
const int WindowHeight = 720;
//#define FULLSCREEN

SDL_Window* Window = nullptr;
SDL_Renderer* Renderer = nullptr;
Game* breakout = nullptr;

//Timer
Uint64 time = SDL_GetPerformanceCounter();
Uint64 lastTime = 0;
double deltaTime = 0;

//Is the Application running ?
bool IsRunning = true;
//Is it the first fram the game is running ?
bool FirstFrame = false;


void Initialize()
{
	SDL_Init(SDL_INIT_EVERYTHING);

#ifdef FULLSCREEN
	Window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, SDL_WINDOW_FULLSCREEN);
#else
	Window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN);
#endif

	Renderer = SDL_CreateRenderer(Window, -1, 0);
	SDL_SetRenderDrawColor(Renderer, 27, 146, 214, 255);
}

void PollEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
	{
		IsRunning = false;
	}
}

void Render()
{
	SDL_RenderClear(Renderer);
	SDL_RenderPresent(Renderer);
}

void ShutDown()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
}


int main()
{
	//Create and initialize the renderer and window
	Initialize();

	breakout = new Game();

	breakout->Init();

	while (IsRunning)
	{
		PollEvents();

		//Calculate Delta time in seconds
		lastTime = time;
		time = SDL_GetPerformanceCounter();

		deltaTime = ((time - lastTime) / static_cast<double>(SDL_GetPerformanceFrequency()));

		//Update Game
		breakout->Tick(deltaTime);

		Render();
	}

	breakout->Shutdown();
	delete breakout;

	//Destroy created window and renderer
	ShutDown();

	return 0;
}