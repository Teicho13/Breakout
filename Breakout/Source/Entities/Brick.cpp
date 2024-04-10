#include "./Entities/Brick.h"

Brick::Brick(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY) 
	: Entity(filePath, renderer, width, height, posX, posY)
{
}