#include <SDL.h>

#include "./Managers/ScoreManager.h"
#include "./Managers/StateManager.h"
#include "./States/GameState.h"
#include "Managers/AudioManager.h"


//Timer
Uint64 g_Time = 0;
Uint64 g_LastTime = 0;

//Key States
const Uint8* g_KeyStates = nullptr;

//Scoring Manager
ScoreManager scoreManager;

//Audio Manager
AudioManager audioManager;

void StateManager::Init(bool isFullscreen)
{
	//Setup SDL and create window
	SDL_Init(SDL_INIT_EVERYTHING);

	if (isFullscreen)
	{
		m_Window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_WindowWidth, m_WindowHeight, SDL_WINDOW_FULLSCREEN);
	}
	else
	{
		m_Window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_WindowWidth, m_WindowHeight, SDL_WINDOW_SHOWN);
	}

	//Create renderer for SDL and set defaul background color
	m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
	SDL_SetRenderDrawColor(m_Renderer, 27, 146, 214, 255);

	//Set Current Time
	g_Time = SDL_GetPerformanceCounter();

	//Pointer to keyboard button states
	g_KeyStates = SDL_GetKeyboardState(nullptr);

	scoreManager.Init();

	audioManager.LoadSound("Assets/Audio/Hit.wav");

	m_IsRunning = true;
}

void StateManager::Update()
{
	//Calculate Delta time in seconds
	g_LastTime = g_Time;
	g_Time = SDL_GetPerformanceCounter();
	m_DeltaTime = ((g_Time - g_LastTime) / static_cast<double>(SDL_GetPerformanceFrequency()));

	m_States.back()->Tick(this,m_DeltaTime);
}

void StateManager::Shutdown()
{
	m_IsRunning = false;

	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

void StateManager::HandleEvents()
{
	m_States.back()->HandleEvents(this);
}

void StateManager::Render()
{
	//Clear render screen for new frame
	//SDL_SetRenderDrawColor(m_Renderer, 27, 146, 214, 255);
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);

	m_States.back()->Render(this);

	//Render everything to the screen
	SDL_RenderPresent(m_Renderer);
}

void StateManager::ChangeState(GameState* state)
{
	//Remove current state
	if (!m_States.empty())
	{
		m_States.back()->Shutdown();
		m_States.pop_back();
	}

	m_States.push_back(state);
	m_States.back()->Init(this);
}

void StateManager::RemoveState()
{
	//Remove current state
	if (!m_States.empty())
	{
		m_States.back()->Shutdown();
		m_States.pop_back();
	}
}

bool StateManager::GetIsRunning()
{
	return m_IsRunning;
}

const Uint8* StateManager::GetKeyboardState()
{
	return g_KeyStates;
}

SDL_Renderer* StateManager::GetRenderer()
{
	return m_Renderer;
}

ScoreManager* StateManager::GetScoreManager()
{
	return &scoreManager;
}

AudioManager* StateManager::GetAudioManager()
{
	return &audioManager;
}
