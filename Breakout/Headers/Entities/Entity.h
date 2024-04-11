#pragma once
#include <SDL_image.h>

class Entity
{
public:
	
	Entity(const char* filePath, SDL_Renderer* renderer);
	Entity(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY);
	
	void SetPosition(float posX, float posY);
	void SetPosition(SDL_FRect pos);
	const SDL_FRect GetPosition();
	void SetSize(float width, float height);

	void GetCenter(float &posX, float &posY);

	void Draw();

private:
	
	SDL_Texture* m_Sprite = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
	SDL_FRect m_Position;
};