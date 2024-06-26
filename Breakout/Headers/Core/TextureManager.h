#pragma once
#include <SDL_image.h>

class TextureManager
{

public:	
	
	static SDL_Texture* CreateTexture(const char* TexturePath, SDL_Renderer* renderer);

	static void RenderTexture(SDL_Texture* Texture, SDL_Renderer* renderer, const SDL_Rect* Position);

	static void RenderRect(SDL_Renderer* renderer, const SDL_Rect* rectangle);
	static void RenderSolidRect(SDL_Renderer* renderer, const SDL_Rect* rectangle);
	static void RenderDot(SDL_Renderer* renderer, int x, int y);
};