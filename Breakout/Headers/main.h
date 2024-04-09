#pragma once


//forward declaring

struct SDL_Window;
struct SDL_Renderer;
class Game;
class TextureManager;

namespace Breakout {

	//WINDOW / SCREEN CONFIG
	const int g_WindowWidth = 1280;
	const int g_WindowHeight = 720;
	//#define FULLSCREEN

	SDL_Window* g_Window = nullptr;
	SDL_Renderer* g_Renderer = nullptr;
	Game* g_breakout = nullptr;

	TextureManager* g_TextureManager = nullptr;


	//Is the Application running ?
	bool g_IsRunning = true;
	//Is it the first fram the game is running ?
	bool g_FirstFrame = false;

	void Initialize();
	void Render();
	void ShutDown();
	void PollEvents();
}

