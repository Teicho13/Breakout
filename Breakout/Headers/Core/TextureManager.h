#pragma once
#include <vector>

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;

class TextureManager
{
public:
	TextureManager(SDL_Renderer* render);
	~TextureManager();
	
	SDL_Texture* CreateTexture(const char* TexturePath);

	void RenderTexture(SDL_Texture* Texture, const SDL_Rect* Position);

private:
	SDL_Renderer* m_Renderer;
};