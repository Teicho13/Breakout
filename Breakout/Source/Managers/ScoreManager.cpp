#include <fstream>
#include <iostream>

#include "./Managers/ScoreManager.h"



void ScoreManager::Init()
{
	m_Score = 0;
	LoadHighScore();
}

void ScoreManager::AddScore(int amount)
{
	m_Score += amount;
}

void ScoreManager::ReductScore(int amount)
{
	m_Score -= amount;
	if(m_Score < 0)
	{
		m_Score = 0;
	}
}

void ScoreManager::SaveHighScore()
{
	std::ofstream file("PlayerScore.txt");
	file << m_Score;
	file.close();
}

void ScoreManager::LoadHighScore()
{
	std::ifstream file("PlayerScore.txt");
	if(file.is_open())
	{
		file >> m_HighScore;
	}
	else
	{
		m_HighScore = 0;
	}
	file.close();

	std::cout << m_HighScore << std::endl;
}

void ScoreManager::ClearHighScore()
{
	m_HighScore = 0;
	std::ifstream file("PlayerScore.txt");
	if(file.is_open())
	{
		file.clear();
	}
	file.close();
}

void ScoreManager::ClearScore()
{
	m_Score = 0;
}

int ScoreManager::GetScore()
{
	return m_Score;
}

int ScoreManager::GetHighScore()
{
	return m_HighScore;
}
