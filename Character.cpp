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
    maxHP = 100;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 50;
    eva = 1;
    alive = true;
}

Character::Character (string newName)
{
    name = newName;
    maxHP = 100;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 50;
    eva = 1;
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

int Character::getMaxHP ()
{
    return maxHP;
}

int Character::getMaxSP ()
{
    return maxSP;
}

void Character::setHP (int newHP)
{
    HP = newHP;
}

void Character::damage (int damage)
{
    HP -= damage;
}

void Character::heal (int hitPoints)
{
    HP += hitPoints;
}

int Character::getHP ()
{
    return HP;
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
    if (HP <= 0) {
        return "He drops to the floor, dead.";
    } else if (HP < 25)
        return "He coughs up blood. The end is near.";
    else if (HP < 50)
        return "He looks weary. You're not making this easy.";
    else if (HP < 75)
        return "He feels uneasy. He takes a step back.";
    else
        return "He steadily holds his ground.";
}

void attack (Character * enemy)
{
    
}
