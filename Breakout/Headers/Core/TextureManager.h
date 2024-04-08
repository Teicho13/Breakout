#pragma once
#include <vector>

struct SDL_Renderer;
struct SDL_Texture;

class TextureManager
{
public:
	TextureManager(SDL_Renderer* render);
	~TextureManager();
	
	SDL_Texture* CreateTexture(const char* TexturePath);

	void RenderTextures();

private:
	SDL_Renderer* m_Renderer;
	std::vector<SDL_Texture*> m_GameTextures;
};