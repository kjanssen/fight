// File: Character.cpp
// Author: Kyle Janssen
// Contains: This file contains the implementation of a class called Character

#include <iostream>
#include "Character.h"
#include "Random.h"
using namespace std;

Character::Character ()
{
    name = "DefaultName";
    maxHealth = 100;
    health = maxHealth;
    alive = true;
}

Character::Character (string newName)
{
    name = newName;
    maxHealth = 100;
    health = maxHealth;
    alive = true;
}

void Character::setName (string newName)
{
    name = newName;
}

string Character::getName ()
{
    return name;
}

int Character::getMaxHealth ()
{
    return maxHealth;
}

void Character::setHealth (int newHealth)
{
    health = newHealth;
}

void Character::damage (int damage)
{
    health -= damage;
}

void Character::heal (int hitpoints)
{
    health += hitpoints;
}

int Character::getHealth ()
{
    return health;
}

void Character::kill ()
{
    alive = false;
}

void Character::revive ()
{
    alive = true;
}

bool Character::isAlive ()
{
    return alive;
}

string Character::status ()
{
    if (health <= 0) {
        return "He drops to the floor, dead.";
    } else if (health < 25)
        return "He coughs up blood. The end is near.";
    else if (health < 50)
        return "He looks weary. You're not making this easy.";
    else if (health < 75)
        return "He feels uneasy. He takes a step back.";
    else
        return "He steadily holds his ground.";
}

void attack (Character * enemy)
{
    
}
