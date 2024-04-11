#include "./Entities/EngergyBall.h"

EnergyBall::EnergyBall(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY)
	: Entity(filePath, renderer, width, height, posX, posY)
{
	m_Direction = { 400.f, -400.f };
	//m_Direction = { 0.f, 0.f };

}

void EnergyBall::Move(float dt)
{
	SDL_FRect tmpRec = GetPosition();
	tmpRec.x += m_Direction.x * dt;
	tmpRec.y += m_Direction.y * dt;
	CheckBounds(tmpRec);
	SetPosition(tmpRec);
}

void EnergyBall::CheckBounds(SDL_FRect& tmpRec)
{
	if (tmpRec.x + tmpRec.w >= 1280.f)
	{
		tmpRec.x = 1280.f - tmpRec.w;
		m_Direction.x *= -1;
	}

	if (tmpRec.x <= 0.f) 
	{
		tmpRec.x = 0.f;
		m_Direction.x *= -1;
	}

	if (tmpRec.y <= 0.0f)
	{
		tmpRec.y = 0.f;
		m_Direction.y *= -1;
	}

	//Temporary for debugging
	if (tmpRec.y + tmpRec.h >= 720.f)
	{
		tmpRec.y = 720.f - tmpRec.h;
		m_Direction.y *= -1;
	}
		
}

Breakout::vec2 EnergyBall::GetCenter()
{
	SDL_FRect tmpRec = GetPosition();
	return Breakout::vec2(tmpRec.x + (tmpRec.w / 2), tmpRec.y + (tmpRec.h / 2));
}
