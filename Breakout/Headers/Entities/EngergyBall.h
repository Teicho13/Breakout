#pragma once
#include "Entity.h"
#include "Core/Math.h"

struct SDL_FRect;
class Vaus;
class EnergyBall : public Entity
{
public:
	EnergyBall(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY);

	void Move(float dt);
	void SetDirection(float dirX, float dirY);

	float Reflect(float hitX, float playerW);
	void BouncePlayer(Vaus* player);

	void CheckBounds(SDL_FRect& tmpRec);
	Breakout::vec2 GetCenter();

	Breakout::vec2 m_Direction;

private: 
	
	float m_Speed = 400.f;
};