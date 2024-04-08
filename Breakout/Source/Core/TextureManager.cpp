#include "Core/TextureManager.h"
#include <SDL_image.h>

TextureManager::TextureManager(SDL_Renderer* render)
{
	m_Renderer = render;
}

TextureManager::~TextureManager()
{
	delete m_Renderer;

	//Remove all pointers
	for (auto& gt : m_GameTextures)
	{
		delete gt;
	}
	m_GameTextures.clear();
}

SDL_Texture* TextureManager::CreateTexture(const char* TexturePath)
{
	//Create texture
	SDL_Surface* Surface = IMG_Load(TexturePath);
	SDL_Texture* TempTexture = SDL_CreateTextureFromSurface(m_Renderer, Surface);
	//Free Surface since we dont need it anymore
	SDL_FreeSurface(Surface);

	m_GameTextures.push_back(TempTexture);
	return TempTexture;
}

void TextureManager::RenderTextures()
{
	if (!m_GameTextures.empty())
	{
		for (size_t i = 0; i < m_GameTextures.size(); i++)
		{
			SDL_RenderCopy(m_Renderer, m_GameTextures[i], NULL, NULL);
		}
	}
}
