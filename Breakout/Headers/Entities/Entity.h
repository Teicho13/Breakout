#pragma once
#include <SDL_image.h>

class Entity
{
public:
	
	Entity(const char* filePath, SDL_Renderer* renderer);
	Entity(const char* filePath, SDL_Renderer* renderer, int width, int height, int posX, int posY);
	
	void SetPosition(int posX, int posY);
	void SetSize(int width, int height);

	void Draw(SDL_Renderer* renderer);

private:
	
	SDL_Texture* m_Sprite = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
	SDL_Rect m_Position;
};