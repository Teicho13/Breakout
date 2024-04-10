#pragma once

class SDL_FRect;

namespace Breakout
{
	class Collision
	{
	public:
		static bool AABB(const SDL_FRect A, const SDL_FRect B);
	};

}