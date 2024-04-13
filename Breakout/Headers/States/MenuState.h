#pragma once
#include "GameState.h"

class Entity;
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

	//UI
	void CheckButtonClicked(StateManager* manager, const float x, const float y);
	void UpdateStars(float dt);
	void RenderStars();

	Entity* m_Title = nullptr;
	Entity* m_StartButton = nullptr;
	Entity* m_QuitButton = nullptr;


protected:
	MenuState() {}

private:
	static MenuState m_MenuState;

};