#include "Entities/Entity.h"
#include "Core/TextureManager.h"

Entity::Entity(const char* filePath, SDL_Renderer* renderer)
{
	m_Sprite = TextureManager::CreateTexture(filePath, renderer);
	m_Renderer = renderer;
	m_Position.w = 32.f;
	m_Position.h = 32.f;
	m_Position.x = 0.f;
	m_Position.y = 0.f;
}

Entity::Entity(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY)
{
	m_Sprite = TextureManager::CreateTexture(filePath, renderer);
	m_Renderer = renderer;

	m_Position.w = width;
	m_Position.h = height;
	m_Position.x = posX;
	m_Position.y = posY;
}

void Entity::SetPosition(float posX, float posY)
{
	m_Position.x = posX;
	m_Position.y = posY;
}

void Entity::SetPosition(SDL_FRect pos)
{
	m_Position = pos;
}

const SDL_FRect Entity::GetPosition()
{
	return m_Position;
}

void Entity::SetSize(float width, float height)
{
	m_Position.w = width;
	m_Position.h = height;
}

void Entity::Draw()
{
	SDL_Rect tmpRect;
	tmpRect.x = m_Position.x;
	tmpRect.y = m_Position.y;
	tmpRect.w = m_Position.w;
	tmpRect.h = m_Position.h;

	TextureManager::RenderTexture(m_Sprite, m_Renderer, &tmpRect);
}
