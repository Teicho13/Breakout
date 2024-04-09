#include "Entities/Entity.h"
#include "Core/TextureManager.h"

Entity::Entity(const char* filePath, SDL_Renderer* renderer)
{
	m_Sprite = TextureManager::CreateTexture(filePath, renderer);
	m_Renderer = renderer;
	m_Position.w = 32;
	m_Position.h = 32;
	m_Position.x = 0;
	m_Position.y = 0;
}

Entity::Entity(const char* filePath, SDL_Renderer* renderer, int width, int height, int posX, int posY)
{
	m_Sprite = TextureManager::CreateTexture(filePath, renderer);
	m_Renderer = renderer;

	m_Position.w = width;
	m_Position.h = height;
	m_Position.x = posX;
	m_Position.y = posY;
}

void Entity::SetPosition(int posX, int posY)
{
	m_Position.x = posX;
	m_Position.y = posY;
}

void Entity::SetSize(int width, int height)
{
	m_Position.w = width;
	m_Position.h = height;
}

void Entity::Draw(SDL_Renderer* renderer)
{
	TextureManager::RenderTexture(m_Sprite, renderer, &m_Position);
}
