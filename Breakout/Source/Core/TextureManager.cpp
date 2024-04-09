#include "Core/TextureManager.h"
#include <SDL_image.h>

TextureManager::TextureManager(SDL_Renderer* render)
{
	m_Renderer = render;
}

TextureManager::~TextureManager()
{
	delete m_Renderer;
}

SDL_Texture* TextureManager::CreateTexture(const char* TexturePath)
{
	//Create texture
	SDL_Surface* Surface = IMG_Load(TexturePath);
	SDL_Texture* TempTexture = SDL_CreateTextureFromSurface(m_Renderer, Surface);
	//Free Surface since we dont need it anymore
	SDL_FreeSurface(Surface);

	return TempTexture;
}

void TextureManager::RenderTexture(SDL_Texture* Texture, const SDL_Rect* Position)
{
	SDL_RenderCopy(m_Renderer, Texture, NULL, Position);
}
