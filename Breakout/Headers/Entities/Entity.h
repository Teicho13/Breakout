#pragma once
#include <SDL_image.h>

class Entity
{
public:
	
	Entity(const char* filePath, SDL_Renderer* renderer);
	Entity(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY);
	
	void SetPosition(float posX, float posY);
	void SetPosition(SDL_FRect trans);
	const SDL_FRect GetTransform();
	void SetSize(float width, float height);

	void GetCenter(float &posX, float &posY);

	void Draw();

protected:
	SDL_Texture* m_Sprite = nullptr;
	SDL_Renderer* m_Renderer = nullptr;

private:
	
	SDL_FRect m_Transform;
};