#pragma once
class ScoreManager
{
public:

	void Init();
	void AddScore(int amount);
	void ReductScore(int amount);

	void SaveHighScore();
	void LoadHighScore();
	void ClearHighScore();
	void ClearScore();

	int GetScore();
	int GetHighScore();

private:
	int m_Score = 0;
	int m_HighScore = 0;
};
