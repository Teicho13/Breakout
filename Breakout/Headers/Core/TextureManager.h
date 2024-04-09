#pragma once
#include <SDL_image.h>

class TextureManager
{

public:	
	
	static SDL_Texture* CreateTexture(const char* TexturePath, SDL_Renderer* renderer);

	static void RenderTexture(SDL_Texture* Texture, SDL_Renderer* renderer, const SDL_Rect* Position);
};