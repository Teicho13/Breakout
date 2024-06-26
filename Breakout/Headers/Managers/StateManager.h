#pragma once
#include <vector>

struct SDL_Window;
struct SDL_Renderer;

class GameState;
class ScoreManager;
class AudioManager;

class StateManager
{
public:
	void Init(bool isFullscreen);
	void Update();
	void Shutdown();
	void Render();
	void HandleEvents();

	void ChangeState(GameState* state);
	void PushState(GameState* state) {}
	void RemoveState();

	bool GetIsRunning() const;
	const Uint8* GetKeyboardState() const;

	SDL_Renderer* GetRenderer() const;
	ScoreManager* GetScoreManager() const;
	AudioManager* GetAudioManager() const;


	//WINDOW / SCREEN CONFIG
	const int m_WindowWidth = 1280;
	const int m_WindowHeight = 720;

	double m_DeltaTime = 0;

private:
	std::vector<GameState*> m_States;
	bool m_IsRunning;

	//SDL related variables
	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
};