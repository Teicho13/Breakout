#pragma once

class Game 
{
public:
	void Init();
	void Shutdown();
	void Tick(double DeltaTime);

	void KeyDown(int keycode) {}
	void KeyUp(int keycode) {}
	void MouseButtonUp(int keycode) {}
	void MouseButtondDown(int keycode) {}
};