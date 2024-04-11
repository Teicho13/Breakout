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

bool Breakout::Collision::CircleRect(const SDL_FRect circle, const SDL_FRect rect)
{
    //Take position from top left and make circle variables
    float radius = (circle.w / 2.f);
    float circleX = circle.x + (circle.w / 2);
    float circleY = circle.y + (circle.h / 2);

    //What Edge we are testing for collision
    float testX = circleX;
    float testY = circleY;

    //Test which edge is closest to circle
    if (circleX < rect.x) testX = rect.x;
    else if (circleX > (rect.x + rect.w)) testX = (rect.x + rect.w);
    if (circleY < rect.y) testY = rect.y;
    else if (circleY > (rect.y + rect.h)) testY = (rect.y + rect.h);

    //Get distance from circle to edge
    float distX = circleX - testX;
    float distY = circleY - testY;
    float distance = sqrtf((distX * distX) + (distY * distY));

    //If Distance is less or equal to radius we have hit.
    if (distance <= radius)
    {
        return true;
    }

    return false;
}
