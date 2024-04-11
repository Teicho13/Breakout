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

void EnergyBall::SetDirection(float dirX, float dirY)
{
	//Normalize direction
	float length = sqrtf(dirX * dirX + dirY * dirY);
	m_Direction.x = m_Speed * (dirX / length);
	m_Direction.y = m_Speed * (dirY / length);
}

float EnergyBall::Reflect(float hitX, float playerW)
{
	//Clamp hitX to start and width of player
	if (hitX < 0) 
	{
		hitX = 0;
	}
	else if (hitX > playerW)
	{
		hitX = playerW;
	}

	//Scale reflection between -2 and 2
	hitX -= playerW / 2.0f;
	return 2.0f * (hitX / (playerW / 2.0f));
}



void EnergyBall::BouncePlayer(Vaus* player)
{
	//Get center of the ball
	Breakout::vec2 center = GetCenter();
	float ballX = center.x;

	//Check which where you hit player and what direction to reflect to
	
	float hitX = Reflect(ballX - player->GetTransform().x, player->GetTransform().w);
	
	//Set Direction to reflection and up
	SetDirection(hitX, -1);

	//Set ball position above player
	SDL_FRect tmpRec = GetTransform();
	tmpRec.y = (player->GetTransform().y - tmpRec.h) - 1;
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
	SDL_FRect tmpRec = GetTransform();
	return Breakout::vec2(tmpRec.x + (tmpRec.w / 2.f), tmpRec.y + (tmpRec.h / 2.f));
}
