#pragma once
struct SDL_Renderer;
class MenuStar
{
public:
	MenuStar(SDL_Renderer* renderer);
	void Update(float deltaTime);
	void Draw();

	float GetX() { return m_PosX; }
	float GetY() { return m_PosY; }

	float m_Speed = 300.f;

private:
	float m_PosX = 0.f;
	float m_PosY = 0.f;

	SDL_Renderer* m_Renderer = nullptr;
};
