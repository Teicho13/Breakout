#include "./Entities/Vaus.h"

Vaus::Vaus(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY) : Entity(filePath, renderer, width, height, posX, posY)
{
}

void Vaus::Move(int direction, float dt)
{
	SDL_FRect tmpRec = GetPosition();
	tmpRec.x += m_Speed * direction * dt;
	SetPosition(tmpRec);
}

void Vaus::SetSpeed(float speed)
{
	m_Speed = speed;
}

float Vaus::GetSpeed()
{
	return m_Speed;
}
