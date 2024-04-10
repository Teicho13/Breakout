#include "Managers/BrickManager.h"

void BrickManager::SetRenderer(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

void BrickManager::CreateBricks(int amount, int rowMax)
{
	//Where Object get placed
	float placementX = 65.f;
	float placementY = 32.f;
	float offsetX = 55.f;
	float offsetY = 10.f;

	int row = 0;
	int column = 0;
	
	//What Texture to use for the bricks
	const char* filePath = "";

	for (int i = 0; i < amount; i++)
	{
		//Every Row Max go down a layer
		if (i % rowMax == 0 && i != 0)
		{
			row++;
			column = 0;
		}

		filePath = GetBrickTexture(filePath, row);

		m_Bricks.emplace_back(Brick(filePath, m_Renderer, 65.f, 32.f, offsetX + (placementX * column), offsetY + (placementY * row)));

		column++;
	}
}

void BrickManager::DrawBricks()
{
	if (m_Renderer != nullptr)
	{
		for (auto& brick : m_Bricks)
		{
			brick.Draw();
		}
	}
}

const char* BrickManager::GetBrickTexture(const char*& filePath, int row)
{
	switch (row)
	{
	case 0:
		filePath = "Assets/Images/Entities/BrickRed.png";
		break;
	case 1:
		filePath = "Assets/Images/Entities/BrickOrange.png";
		break;
	case 2:
		filePath = "Assets/Images/Entities/BrickGreen.png";
		break;
	default:
		filePath = "Assets/Images/Entities/BrickRed.png";
		break;
	}

	return filePath;
}
