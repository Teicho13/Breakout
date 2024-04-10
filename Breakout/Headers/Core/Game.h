#pragma once

class SDL_Renderer;
class Entity;
class Game 
{
public:
	Game(SDL_Renderer* renderer);

	void Init();
	void Shutdown();
	void Tick(double deltaTime, const Uint8* keyboard);
	void Render();

	SDL_Renderer* GetRenderer();

	void KeyDown(int keycode) {}
	void KeyUp(int keycode) {}
	void MouseButtonUp(int keycode) {}
	void MouseButtondDown(int keycode) {}

	Entity* Player = nullptr;

private:
	SDL_Renderer* m_Renderer;
};