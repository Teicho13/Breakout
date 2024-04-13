#include <iostream>
#include <algorithm>
#include <random>

#include "Managers/BrickManager.h"
#include "Core/Collision.h"
#include "Entities/EnergyBall.h"


typedef std::mt19937 rng_type;
std::uniform_int_distribution<rng_type::result_type> udist(0, 9);

void BrickManager::SetRenderer(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
}

int BrickManager::GetRandomNumber(int min, int max)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(min, max);

	return distr(gen);
}

void BrickManager::CreateBricks(int amount, int rowMax)
{
	//Where Object get placed
	float placementX = 65.f;
	float placementY = 32.f;
	float offsetX = 55.f;
	float offsetY = 20.f;

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

		
		//Get Random number to determine weather it is a destructible brick or not
		int randVal = GetRandomNumber(0, 9);
		bool isSolid = false;

		if (randVal == 3)
		{
			isSolid = true;
		}

		//Get Brick texture based on the row
		filePath = GetBrickTexture(filePath, row, isSolid);
		
		m_Bricks.emplace_back(Brick(filePath, m_Renderer, 65.f, 32.f, offsetX + (placementX * column), offsetY + (placementY * row),isSolid));

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


bool BrickManager::CheckCollision(EnergyBall* energyBall)
{
	for (size_t i = 0; i < m_Bricks.size(); i++)
	{
		if (Breakout::Collision::CircleRect(energyBall->GetTransform(), m_Bricks[i].GetTransform()))
		{
			if (!m_Bricks[i].GetIsSolid())
			{
				m_Bricks.erase(m_Bricks.begin() + i);
				energyBall->m_Direction.x *= -1.f;
				energyBall->m_Direction.y *= -1.f;
				return true;
			}
			energyBall->m_Direction.x *= -1.f;
			energyBall->m_Direction.y *= -1.f;
			return false;
		}
	}
	return false;
}

void BrickManager::ClearBricks()
{
	m_Bricks.clear();
	m_Renderer = nullptr;
}

const char* BrickManager::GetBrickTexture(const char*& filePath, int row, bool solid)
{
	if (solid)
	{
		return filePath = "Assets/Images/Entities/BrickGrey.png";
	}

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
