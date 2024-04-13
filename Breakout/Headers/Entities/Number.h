#pragma once
#include "Entity.h"

class Number : public Entity
{
public:
	Number(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY);

private:
	int m_Number = 0;
};