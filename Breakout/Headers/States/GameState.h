#pragma once
#include "Managers/StateManager.h"

class GameState
{
public:
	virtual void Init(StateManager* manager) = 0;
	virtual void Tick(StateManager* manager,float deltaTime) = 0;
	virtual void Shutdown() = 0;
	virtual void Render(StateManager* manager) = 0;
	virtual void HandleEvents(StateManager* manager) = 0;

	void ChangeState(StateManager* manager, GameState* state) { manager->ChangeState(state); }
};