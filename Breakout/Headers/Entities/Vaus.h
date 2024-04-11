#pragma once
#include "Entity.h"
#include "Core/Math.h"


class Vaus : public Entity
{
public:
	Vaus(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY);

	void Move(int direction, float dt);

	void SetSpeed(float speed);
	float GetSpeed();

	Breakout::vec2 GetNormal();

private:
	float m_Speed = 600.f;
};