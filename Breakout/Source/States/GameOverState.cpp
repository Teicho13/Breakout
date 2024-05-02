

#include <iostream>
#include <SDL.h>

#include "./States/GameOverState.h"

#include <string>

#include "./States/MenuState.h"

#include "./Entities/Number.h"
#include "Managers/ScoreManager.h"

GameOverState GameOverState::m_GameOverState;

void GameOverState::Init(StateManager* manager)
{
	std::cout << "Init GameOver State \n";

	m_Renderer = manager->GetRenderer();

	//Create Text image for score and highscore

	m_Score = new Entity("Assets/Images/UI/Score.png", manager->GetRenderer(), 257, 49.f, (static_cast<float>(manager->m_WindowWidth) / 2.f) - (257.f / 2.f), 50.f);
	m_HighScore = new Entity("Assets/Images/UI/HighScore.png", manager->GetRenderer(), 465, 49.f, (static_cast<float>(manager->m_WindowWidth) / 2.f) - (465 / 2.f), 300.f);

	//TODO: Implement Sprite class, sprite class can take in a texture sheet so you can easily switch between images in a single object.

	//Divide current score and highscore into an array of integers
	CreateNumberArray(manager->GetScoreManager()->GetScore(),manager->GetScoreManager()->GetHighScore());

	//Create Images for each number according to previous scores
	CreateNumbers();
	CreateHighScoreNumbers();
}

void GameOverState::Tick(StateManager* manager, float deltaTime)
{
}

void GameOverState::Shutdown()
{
	DeleteNumbers();

	delete m_Score;
	delete m_HighScore;
}

void GameOverState::Render(StateManager* manager)
{
	RenderNumbers();

	m_Score->Draw();
	m_HighScore->Draw();
}

void GameOverState::HandleEvents(StateManager* manager)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//Window "X" is clicked
		case SDL_QUIT:
			manager->Shutdown();
			break;

			//key is pressed
		case SDL_KEYDOWN:
			//If Escape is clicked exit out
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				manager->Shutdown();
				return;
			}
			if (event.key.keysym.sym == SDLK_RETURN)
			{
				manager->ChangeState(MenuState::Instance());
				return;
			}
			break;
		}
	}
}

void GameOverState::CreateNumberArray(int score, int highScore)
{
	for (int i = 9; i-- > 0;)
	{
		m_ScoreNumber[i] = score % 10;
		score /= 10;
	}

	for (int i = 9; i-- > 0;)
	{
		m_HighScoreNumber[i] = highScore % 10;
		highScore /= 10;
	}
}

void GameOverState::CreateNumbers()
{
	float offsetX = (1280 / 2.f) - (490 / 2.f);
	float offsetY = 150.f;

	for (int i = 0; i < 9; ++i)
	{
		std::string assetPath = "Assets/Images/Numbers/Number" + std::to_string(i) + ".png";
		m_ScoreText[i] = new Number(assetPath.c_str(), m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
	}
}

void GameOverState::CreateHighScoreNumbers()
{
	float offsetX = (1280 / 2.f) - (490 / 2.f);
	float offsetY = 400.f;
	for (int i = 0; i < 9; ++i)
	{
		std::string assetPath = "Assets/Images/Numbers/Number" + std::to_string(i) + ".png";
		m_HighScoreText[i] = new Number(assetPath.c_str(), m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
	}
}

void GameOverState::RenderNumbers()
{
	for (int i = 0; i < 9; ++i)
	{
		m_HighScoreText[i]->Draw();
		m_ScoreText[i]->Draw();
	}
}

void GameOverState::DeleteNumbers()
{
	for (int i = 0; i < 9; ++i)
	{
		delete m_ScoreText[i];
		delete m_HighScoreText[i];
	}
}




