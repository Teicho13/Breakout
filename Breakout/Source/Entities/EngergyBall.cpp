#include "./Entities/EngergyBall.h"
#include "./Entities/Vaus.h"

EnergyBall::EnergyBall(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY)
	: Entity(filePath, renderer, width, height, posX, posY)
{
	m_Direction = { m_Speed, -m_Speed };
}

void EnergyBall::Move(float dt)
{
	SDL_FRect tmpRec = GetTransform();
	tmpRec.x += m_Direction.x * dt;
	tmpRec.y += m_Direction.y * dt;
	CheckBounds(tmpRec);
	SetPosition(tmpRec);
}

void EnergyBall::BouncePlayer(Vaus* player)
{
	Breakout::vec2 center = GetCenter();
	float ballX = center.x;
	float ballY = center.y;
	
	//Check where we hit.
	//TODO: Get Hit normal and reflect using the correct angle

	if (ballX >= player->GetTransform().x + (player->GetTransform().w / 2))
	{
		m_Direction.x *= 1;
	}
	else
	{
		m_Direction.x *= -1;

	}

	SDL_FRect tmpRec = GetTransform();
	tmpRec.y = (player->GetTransform().y - tmpRec.h) - 1;
	SetPosition(tmpRec);

	m_Direction.y *= -1;
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
	SDL_FRect tmpRec = GetTransform();
	return Breakout::vec2(tmpRec.x + (tmpRec.w / 2), tmpRec.y + (tmpRec.h / 2));
}
