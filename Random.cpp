// File: Random.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of the function
// prototyped in Random.h

#include <random>
using namespace std;
 
int random(int max)
{
    // Seed with a real random value, if available
    random_device rd;
 
    // Return a random number between 1 and max
    default_random_engine e1(rd());
    uniform_int_distribution<int> uniform_dist(1, max);

    return uniform_dist(e1);
}

