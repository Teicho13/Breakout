

#include <iostream>
#include <SDL.h>

#include "./States/GameOverState.h"
#include "./States/MenuState.h"

#include "./Entities/Number.h"
#include "Managers/ScoreManager.h"

GameOverState GameOverState::m_GameOverState;

void GameOverState::Init(StateManager* manager)
{
	std::cout << "Init GameOver State \n";

	m_Renderer = manager->GetRenderer();

	m_Score = new Entity("Assets/Images/UI/Score.png", manager->GetRenderer(), 257, 49.f, (static_cast<float>(manager->m_WindowWidth) / 2.f) - (257.f / 2.f), 50.f);
	m_HighScore = new Entity("Assets/Images/UI/HighScore.png", manager->GetRenderer(), 465, 49.f, (static_cast<float>(manager->m_WindowWidth) / 2.f) - (465 / 2.f), 300.f);

	CreateNumberArray(manager->GetScoreManager()->GetScore(),manager->GetScoreManager()->GetHighScore());
	CreateNumbers();
	CreateHighScoreNumbers();
}

void GameOverState::Tick(StateManager* manager, float deltaTime)
{
}

void GameOverState::Shutdown()
{
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
		switch (m_ScoreNumber[i])
		{
		case 0:
			m_ScoreText[i] = new Number("Assets/Images/Numbers/Number0.png", m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
			break;
		case 1:
			m_ScoreText[i] = new Number("Assets/Images/Numbers/Number1.png", m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
			break;
		case 2:
			m_ScoreText[i] = new Number("Assets/Images/Numbers/Number2.png", m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
			break;
		case 3:
			m_ScoreText[i] = new Number("Assets/Images/Numbers/Number3.png", m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
			break;
		case 4:
			m_ScoreText[i] = new Number("Assets/Images/Numbers/Number4.png", m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
			break;
		case 5:
			m_ScoreText[i] = new Number("Assets/Images/Numbers/Number5.png", m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
			break;
		case 6:
			m_ScoreText[i] = new Number("Assets/Images/Numbers/Number6.png", m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
			break;
		case 7:
			m_ScoreText[i] = new Number("Assets/Images/Numbers/Number7.png", m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
			break;
		case 8:
			m_ScoreText[i] = new Number("Assets/Images/Numbers/Number8.png", m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
			break;
		case 9:
			m_ScoreText[i] = new Number("Assets/Images/Numbers/Number9.png", m_Renderer, 49.f, 49.f, offsetX + (49 * i), offsetY);
			break;
		}
	}
}

void GameOverState::CreateHighScoreNumbers()
{
	float offsetX = (1280 / 2.f) - (490 / 2.f);
	float offsetY = 400.f;
	for (int i = 0; i < 9; ++i)
	{
		switch (m_HighScoreNumber[i])
		{
		case 0:
			m_HighScoreText[i] = new Number("Assets/Images/Numbers/Number0.png", m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
			break;
		case 1:
			m_HighScoreText[i] = new Number("Assets/Images/Numbers/Number1.png", m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
			break;
		case 2:
			m_HighScoreText[i] = new Number("Assets/Images/Numbers/Number2.png", m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
			break;
		case 3:
			m_HighScoreText[i] = new Number("Assets/Images/Numbers/Number3.png", m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
			break;
		case 4:
			m_HighScoreText[i] = new Number("Assets/Images/Numbers/Number4.png", m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
			break;
		case 5:
			m_HighScoreText[i] = new Number("Assets/Images/Numbers/Number5.png", m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
			break;
		case 6:
			m_HighScoreText[i] = new Number("Assets/Images/Numbers/Number6.png", m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
			break;
		case 7:
			m_HighScoreText[i] = new Number("Assets/Images/Numbers/Number7.png", m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
			break;
		case 8:
			m_HighScoreText[i] = new Number("Assets/Images/Numbers/Number8.png", m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
			break;
		case 9:
			m_HighScoreText[i] = new Number("Assets/Images/Numbers/Number9.png", m_Renderer, 49.f, 49.f, (49 * i) + offsetX, offsetY);
			break;
		}
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




