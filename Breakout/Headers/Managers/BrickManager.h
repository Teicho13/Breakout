#pragma once
#include <vector>
#include "Entities/Brick.h"

struct SDL_Renderer;
class Brick;

class BrickManager
{
public:

	void SetRenderer(SDL_Renderer* renderer);

	void CreateBricks(int amount, int rowMax);
	void DrawBricks();

	const char* GetBrickTexture(const char* &filePath, int row);

private:
	SDL_Renderer* m_Renderer = nullptr;
	std::vector<Brick> m_Bricks;
};
