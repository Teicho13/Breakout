#pragma once
#include "Entity.h"

class Brick : public Entity
{
public:
	Brick(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY);
};