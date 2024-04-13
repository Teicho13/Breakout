#include <SDL.h>
#include "./Entities/MenuStar.h"

#include "Core/TextureManager.h"
#include "Managers/StateManager.h"

MenuStar::MenuStar(SDL_Renderer* renderer)
{
	m_Renderer = renderer;

	m_PosX = rand() % 1280;
	m_PosY = rand() % 720;
}

void MenuStar::Update(float deltaTime)
{
	m_PosY += m_Speed * deltaTime;
	if (m_PosY >= 720.f) {
		m_PosY = 0.f;
	}
}

void MenuStar::Draw()
{
	TextureManager::RenderDot(m_Renderer, static_cast<int>(GetX()),static_cast<int>(GetY()));
}
