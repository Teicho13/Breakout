#pragma once
#include "GameState.h"

class StateManager;
class MenuState : public GameState
{
public:
	void Init(StateManager* manager);
	void Tick(StateManager* manager,float deltaTime);
	void Shutdown();
	void Render(StateManager* manager);
	void HandleEvents(StateManager* manager);

	static MenuState* Instance() { return &m_MenuState; }

protected:
	MenuState() {}

private:
	static MenuState m_MenuState;

};