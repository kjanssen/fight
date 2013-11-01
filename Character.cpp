// File: Character.cpp
// Author: Kyle Janssen
// Contains: This file contains the implementation of a class called Character

#include <iostream>
#include "Character.h"
#include "Random.h"
using namespace std;

Character::Character ()
{
    actions[0] = "Attack";
    name = "DefaultName";
    maxHP = 100;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 50;
    eva = 5;
    alive = true;
}

Character::Character (string newName)
{
    actions[0] = "Attack";
    name = newName;
    maxHP = 100;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 50;
    eva = 5;
    alive = true;
}

int Character::numActions ()
{
    for (int i = 0; i < 4; i++)
        if (actions[i] == "")
            return i;

    return 4;
}

string Character::action (int actionNum)
{
    return actions[actionNum];
}

void Character::doAction (int actionNum, Character * target)
{
    if (actionNum == 1) attackEnemy(target);
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

    if (HP < 1) {
      HP = 0;
      kill();
    }
}

void Character::heal (int hitPoints)
{
    HP += hitPoints;
    HP = (HP > maxHP) ? maxHP : HP;
}

int Character::getHP ()
{
    return HP;
}

void Character::spendSP (int cost)
{
    SP -= cost;
}

void Character::gainSP (int skillPoints)
{
    SP += skillPoints;
    SP = (SP > maxSP) ? maxSP : SP;
}

int Character::getSP ()
{
    return SP;
}

int Character::getAtt ()
{
    return att;
}

int Character::getDef ()
{
    return def;
}

int Character::getEva ()
{
    return eva;
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
        return "\tHe drops to the floor, dead.";
    } else if (HP < 25)
        return "\tHe coughs up blood. The end is near.";
    else if (HP < 50)
        return "\tHe looks weary. You're not making this easy.";
    else if (HP < 75)
        return "\tHe feels uneasy. He takes a step back.";
    else
        return "\tHe steadily holds his ground.";
}

void Character::attackEnemy (Character * enemy)
{
    cout << "\tYou swing at the " << enemy->name << ".\n" ;
    int hitChance = random(100);
    
    if (hitChance <= 80 - enemy->eva) {
        // attack hits
        // base damage is 15-40 * player's attack / enemy's defense

        int dam = (random(25) + 15) * att / enemy->def; 
        enemy->damage(dam);
	cout << "\t" << dam << " damage!\n";

    } else if (hitChance <= 80) {
        // enemy evades

        cout << "\tHe evades the attack!\n";

    } else {
        // atack misses

        cout << "\tYou miss!\n";

    }
}

void Character::attackPlayer (Character * player)
{
    cout << "\tThe " << name << " swings at you.\n";
    int hitChance = random(100);

    if (hitChance <= 80 - player->eva) {
        // attack hits
        // base damage is 15-40 * enemys's attack / player's defense

        int dam = (random(25) + 15) * att / player->def;
	player->damage(dam);
	cout << "\t" << dam << " damage!\n";

	if (!player->isAlive()) cout << "\tYou are dead.\n";

    } else if (hitChance <= 80) {
        // enemy evades

        cout << "\tYou evade the attack!\n";

    } else {
        // atack misses

        cout << "\tHe misses!\n";
    }
}
