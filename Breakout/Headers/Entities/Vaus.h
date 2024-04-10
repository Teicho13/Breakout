#pragma once
#include "Entity.h"

class Vaus : public Entity
{
public:
	Vaus(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY);
};