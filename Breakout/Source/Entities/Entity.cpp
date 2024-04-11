#include "Entities/Entity.h"
#include "Core/TextureManager.h"

Entity::Entity(const char* filePath, SDL_Renderer* renderer)
{
	m_Sprite = TextureManager::CreateTexture(filePath, renderer);
	m_Renderer = renderer;
	m_Transform.w = 32.f;
	m_Transform.h = 32.f;
	m_Transform.x = 0.f;
	m_Transform.y = 0.f;
}

Entity::Entity(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY)
{
	m_Sprite = TextureManager::CreateTexture(filePath, renderer);
	m_Renderer = renderer;

	m_Transform.w = width;
	m_Transform.h = height;
	m_Transform.x = posX;
	m_Transform.y = posY;
}

void Entity::SetPosition(float posX, float posY)
{
	m_Transform.x = posX;
	m_Transform.y = posY;
}

void Entity::SetPosition(SDL_FRect trans)
{
	m_Transform = trans;
}

const SDL_FRect Entity::GetTransform()
{
	return m_Transform;
}

void Entity::SetSize(float width, float height)
{
	m_Transform.w = width;
	m_Transform.h = height;
}

void Entity::GetCenter(float& posX, float& posY)
{
	SDL_FRect tmpRect = GetTransform();
	posX = tmpRect.x + (tmpRect.w / 2);
	posY = tmpRect.y + (tmpRect.y / 2);
}

void Entity::Draw()
{
	SDL_Rect tmpRect;
	tmpRect.x = m_Transform.x;
	tmpRect.y = m_Transform.y;
	tmpRect.w = m_Transform.w;
	tmpRect.h = m_Transform.h;

	TextureManager::RenderTexture(m_Sprite, m_Renderer, &tmpRect);
}
