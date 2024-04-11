#include "Managers/BrickManager.h"
#include "Core/Collision.h"
#include "Entities/EngergyBall.h"

#include <iostream>
#include <algorithm>


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


void BrickManager::CheckCollision(EnergyBall* energyBall)
{
	for (auto& brick : m_Bricks)
	{
		//Remove object if Lamda returns true (Object collides with energyball)

		m_Bricks.erase(
			std::remove_if(
				m_Bricks.begin(),
				m_Bricks.end(),
				[&energyBall](auto& p) { if (Breakout::Collision::CircleRect(energyBall->GetTransform(), p.GetTransform())) { energyBall->BrickWallHit(p); return true; } return false; }),
				m_Bricks.end()
		);
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
