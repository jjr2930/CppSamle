#include "Random.h"

Random::Random()
{
    generator = std::mt19937(randomDevice());    
}

int Random::GetRandom(const int& min, const int& max)
{
    dist = std::uniform_int_distribution<int>(min, max);
    return dist(generator);    
}