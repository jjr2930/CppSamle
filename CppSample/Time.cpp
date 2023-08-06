#include "Time.h"

SINGLETON_IMPLIMETATION(Time){}

float Time::GetTime()
{
    return currentTime / (float)CLOCKS_PER_SEC;
}

float Time::GetDeltaTime()
{
    return deltaTime / (float)CLOCKS_PER_SEC;
}

void Time::Update()
{
    auto now = clock();
    deltaTime = now - currentTime;
    currentTime = now;
}
