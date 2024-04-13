#pragma once
#include "GameState.h"

class Entity;
class StateManager;
class Number;
class GameOverState : public GameState
{
public:
	void Init(StateManager* manager);
	void Tick(StateManager* manager, float deltaTime);
	void Shutdown();
	void Render(StateManager* manager);
	void HandleEvents(StateManager* manager);

	static GameOverState* Instance() { return &m_GameOverState; }


	void CreateNumberArray(int score, int highScore);
		
	void CreateNumbers();
	void CreateHighScoreNumbers();
	void RenderNumbers();

	Number* m_ScoreText[9];
	int m_ScoreNumber[9];

	Number* m_HighScoreText[9];
	int m_HighScoreNumber[9];

	Entity* m_Score = nullptr;
	Entity* m_HighScore = nullptr;

protected:
	GameOverState() {}

private:
	static GameOverState m_GameOverState;

	SDL_Renderer* m_Renderer = nullptr;

};