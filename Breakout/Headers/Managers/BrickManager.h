#pragma once
#include <vector>
#include "Entities/Brick.h"

struct SDL_Renderer;
class EnergyBall;
class Brick;

class BrickManager
{
public:

	void SetRenderer(SDL_Renderer* renderer);
	int GetRandomNumber(int min, int max);

	void CreateBricks(int amount, int rowMax);
	void DrawBricks();

	bool CheckCollision(EnergyBall* energyBall);

	void ClearBricks();

	const char* GetBrickTexture(const char* &filePath, int row, bool solid);

	int count = 0;

private:
	SDL_Renderer* m_Renderer = nullptr;
	std::vector<Brick> m_Bricks;
};
