#include <SDL.h>
#include "./Core/Collision.h"


bool Breakout::Collision::AABB(const SDL_FRect A, const SDL_FRect B)
{
    if (A.x + A.w >= B.x &&
        B.x + B.w >= A.x &&
        A.y + A.h >= B.y &&
        B.y + B.h >= A.y)
    {
        return true;
    }
   
    return false;
    
}
