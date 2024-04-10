#pragma once
#include "Entity.h"
#include "Core/Math.h"

struct SDL_FRect;
class EnergyBall : public Entity
{
public:
	EnergyBall(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY);

	void Move(float dt);
	void CheckBounds(SDL_FRect& tmpRec);

	Breakout::vec2 m_Direction;

private: 
	
};