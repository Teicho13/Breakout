#include "./Entities/Brick.h"

Brick::Brick(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY) 
	: Entity(filePath, renderer, width, height, posX, posY)
{
}

Brick::Brick(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY, bool isSolid)
	: Entity(filePath, renderer, width, height, posX, posY)
{
	m_IsSolid = isSolid;
}

bool Brick::GetIsSolid()
{
	return m_IsSolid;
}
