#include "./Entities/Vaus.h"

#include "Core/TextureManager.h"

Vaus::Vaus(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY) 
	: Entity(filePath, renderer, width, height, posX, posY)
{
	m_Lives = 3;
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

void Vaus::ReduceLives(int amount)
{
	m_Lives -= amount;

	switch(m_Lives)
	{
	case 2:
		SDL_DestroyTexture(m_Sprite);
		m_Sprite = TextureManager::CreateTexture("Assets/Images/Entities/VausPartialDamage.png", m_Renderer);
		break;
	case 1:
		SDL_DestroyTexture(m_Sprite);
		m_Sprite = TextureManager::CreateTexture("Assets/Images/Entities/VausCriticalDamage.png", m_Renderer);
		break;
	case 0:
		SDL_DestroyTexture(m_Sprite);
		m_Sprite = TextureManager::CreateTexture("Assets/Images/Entities/VausDead.png", m_Renderer);
		break;
	}
}

int Vaus::GetLives()
{
	return m_Lives;
}

Breakout::vec2 Vaus::GetNormal()
{
	SDL_FRect tempR = GetTransform();
	float dx = (tempR.x + tempR.w) - tempR.x;
	float dy = (tempR.y + tempR.h) - tempR.y;
	return Breakout::vec2(dy, -dx);
}
