#include "./Entities/Vaus.h"

Vaus::Vaus(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY) 
	: Entity(filePath, renderer, width, height, posX, posY)
{
}

void Vaus::Move(int direction, float dt)
{
	SDL_FRect tmpRec = GetTransform();

	//TODO: make this not a magic number / get window width
	if (tmpRec.x + tmpRec.w >= 1280.f && direction == 1)
		direction = 0;

	if (tmpRec.x <= 0.f && direction == -1)
		direction = 0;

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
