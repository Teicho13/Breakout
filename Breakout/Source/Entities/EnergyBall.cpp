#include "./Entities/EnergyBall.h"
#include "./Entities/Vaus.h"
#include "./Entities/Brick.h"
#include <iostream>
#include <cmath>

EnergyBall::EnergyBall(const char* filePath, SDL_Renderer* renderer, float width, float height, float posX, float posY)
	: Entity(filePath, renderer, width, height, posX, posY)
{
	m_Direction = { m_Speed, -m_Speed };
}

void EnergyBall::Move(float dt)
{
	SDL_FRect tmpRec = GetTransform();
	tmpRec.x += m_Direction.x * dt;
	tmpRec.y += m_Direction.y * dt;
	CheckBounds(tmpRec);
	SetPosition(tmpRec);
}

void EnergyBall::SetDirection(float dirX, float dirY)
{
	//Normalize direction
	float length = sqrtf(dirX * dirX + dirY * dirY);
	m_Direction.x = m_Speed * (dirX / length);
	m_Direction.y = m_Speed * (dirY / length);
}

float EnergyBall::Reflect(float hitX, float playerW)
{
	//Clamp hitX to start and width of player
	if (hitX < 0) 
	{
		hitX = 0;
	}
	else if (hitX > playerW)
	{
		hitX = playerW;
	}

	//Scale reflection between -2 and 2
	hitX -= playerW / 2.0f;
	return 2.0f * (hitX / (playerW / 2.0f));
}



void EnergyBall::BouncePlayer(Vaus* player)
{
	//Get center of the ball
	Breakout::vec2 center = GetCenter();
	float ballX = center.x;

	//Check which where you hit player and what direction to reflect to
	
	float hitX = Reflect(ballX - player->GetTransform().x, player->GetTransform().w);
	
	//Set Direction to reflection and up
	SetDirection(hitX, -1);

	//Set ball position above player
	SDL_FRect tmpRec = GetTransform();
	tmpRec.y = (player->GetTransform().y - tmpRec.h) - 1;
	SetPosition(tmpRec);
}

//side 0: Left, 1: Right, 2: Top, 3: Bottom
void EnergyBall::BounceBrick(int side)
{
	// Direction factors
	float mulx = 1.f;
	float muly = 1.f;

	//Get Current movement Direction

	if (m_Direction.x > 0.f)
	{
		//Ball is moving to the right

		if (m_Direction.y > 0.f)
		{
			//Ball is moving downwards
			if (side == 0 || side == 3)
			{
				mulx = -1.f;
			}
			else
			{
				muly = -1.f;
			}
		}
		else if (m_Direction.y < 0.0f)
		{
			//Ball is moving upwards
			if (side == 0 || side == 1)
			{
				mulx = -1.f;
			}
			else
			{
				muly = 1.f;
			}
		}

	}
	else if (m_Direction.x < 0.f)
	{
		//Ball is moving to the left
		if (m_Direction.y > 0.f)
		{
			//Ball is moving downwards
			if (side == 2 || side == 3)
			{
				mulx = -1.f;
			}
			else
			{
				muly = 1.f;
			}
		}
		else if (m_Direction.y < 0.0f)
		{
			//Ball is moving upwards
			if (side == 1 || side == 2)
			{
				mulx = -1.f;
			}
			else
			{
				muly = -1.f;
			}
		}
	}

	SetDirection(mulx * m_Direction.x, muly * m_Direction.y);
}

void EnergyBall::BrickWallHit(Brick& brick)
{
	////Get ball center
	//Breakout::vec2 ballCenter = GetCenter();
	////Get Brick center
	//float brickX = brick.GetTransform().x;
	//float brickY = brick.GetTransform().y;
	//brick.GetCenter(brickX,brickY);

	////Calculate Distance between centers
 //	float diffX = brickX - ballCenter.x;
	//float diffY = brickY - ballCenter.y;

	//float minXDist = (brick.GetTransform().w / 2) + (GetTransform().w / 2.f);
	//float minYDist = (brick.GetTransform().h / 2) + (GetTransform().h / 2.f);

	//// Calculate the depth of collision for both the X and Y axis
	//float depthX = diffX > 0 ? minXDist - diffX : -minXDist - diffX;
	//float depthY = diffY > 0 ? minYDist - diffY : -minYDist - diffY;

	//// Now that you have the depth, you can pick the smaller depth and move
	//// along that axis.
	//if (depthX != 0 && depthY != 0) {
	//	if (abs(depthX) < abs(depthY)) {
	//		// Collision along the X axis. React accordingly
	//		if (depthX > 0) {
	//			std::cout << "Left Hit \n";
	//			BounceBrick(0);
	//		}
	//		else {
	//			// Right side collision
	//			std::cout << "Right Hit \n";
	//			BounceBrick(1);
	//		}
	//	}
	//	else {
	//		// Collision along the Y axis.
	//		if (depthY > 0) {
	//			// Top side collision
	//			std::cout << "Top Hit \n";
	//			BounceBrick(2);
	//		}
	//		else {
	//			// Bottom side collision
	//			std::cout << "Bottom Hit \n";
	//			BounceBrick(3);
	//		}
	//	}
	//}

	//TODO: Get a propper implementation for hitting bricks

	m_Direction.x *= -1.f;
	m_Direction.y *= -1.f;
}

void EnergyBall::CheckBounds(SDL_FRect& tmpRec)
{
	if (tmpRec.x + tmpRec.w + 17.f >= 1280.f)
	{
		tmpRec.x = 1280.f - tmpRec.w - 17.f;
		m_Direction.x *= -1;
	}

	if (tmpRec.x <= 0.f + 17.f) 
	{
		tmpRec.x = 0.f + 17.f;
		m_Direction.x *= -1;
	}

	if (tmpRec.y <= 0.0f + 16.f)
	{
		tmpRec.y = 0.f + 16.f;
		m_Direction.y *= -1;
	}
}

Breakout::vec2 EnergyBall::GetCenter()
{
	SDL_FRect tmpRec = GetTransform();
	return Breakout::vec2(tmpRec.x + (tmpRec.w / 2.f), tmpRec.y + (tmpRec.h / 2.f));
}
