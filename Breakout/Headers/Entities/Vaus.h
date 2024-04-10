#pragma once
#include "Entity.h"

class Vaus : public Entity
{
public:
	Vaus(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY);

	void Move(int direction, float dt);

	void SetSpeed(float speed);
	float GetSpeed();

private:
	float m_Speed = 600.f;
};