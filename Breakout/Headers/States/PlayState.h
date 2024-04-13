#pragma once
#include "GameState.h"

class StateManager;

class Vaus;
class Entity;
class EnergyBall;

class PlayState : public GameState
{
public:
	void Init(StateManager* manager);
	void Tick(StateManager* manager,float deltaTime);
	void Shutdown();
	void Render(StateManager* manager);
	void HandleEvents(StateManager* manager);

	static PlayState* Instance() { return &m_PlayState; }

	//Game Functions
	void CheckCollisions();
	//Reset position of ball and player
	void ResetGame();


	//Terrain
	Entity* m_Background = nullptr;
	Entity* m_TopLine = nullptr;
	Entity* m_LeftLine = nullptr;
	Entity* m_RightLine = nullptr;


	Vaus* m_Player = nullptr;
	EnergyBall* m_EnergyBall = nullptr;

protected:
	PlayState() {}

private:
	static PlayState m_PlayState;
	bool m_GameStarted = false;
};