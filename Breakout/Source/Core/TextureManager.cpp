#include "Core/TextureManager.h"


SDL_Texture* TextureManager::CreateTexture(const char* TexturePath, SDL_Renderer* renderer)
{
	//Create texture
	SDL_Surface* Surface = IMG_Load(TexturePath);
	SDL_Texture* TempTexture = SDL_CreateTextureFromSurface(renderer, Surface);
	//Free Surface since we dont need it anymore
	SDL_FreeSurface(Surface);
	return TempTexture;
}

void TextureManager::RenderTexture(SDL_Texture* Texture, SDL_Renderer* renderer, const SDL_Rect* Position)
{
	SDL_RenderCopy(renderer, Texture, NULL, Position);
}

void TextureManager::RenderRect(SDL_Renderer* renderer, const SDL_Rect* rectangle)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderDrawRect(renderer, rectangle);
}

void TextureManager::RenderSolidRect(SDL_Renderer* renderer, const SDL_Rect* rectangle)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	SDL_RenderFillRect(renderer, rectangle);
}

void TextureManager::RenderDot(SDL_Renderer* renderer, int x, int y)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(renderer, x, y);
}
