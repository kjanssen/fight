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
    cost[0] = 0;
    name = "Character";
    maxHP = 100;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 50;
    eva = 5;
    alive = true;
    enemyChar = false;
}

Character::Character (bool isEnemyChar)
{
    actions[0] = "Attack";
    cost[0] = 0;
    name = "Character";
    maxHP = 100;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 50;
    eva = 5;
    alive = true;
    enemyChar = isEnemyChar;
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

int Character::getCost (int actionNum)
{
    return cost[actionNum + 1];
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

bool Character::isEnemy ()
{
    return enemyChar;
}

string Character::status ()
{
    if (HP <= 0) {
        return "\tHe drops to the floor, dead.";
    } else if (HP < maxHP / 4)
        return "\tHe coughs up blood. The end is near.";
    else if (HP < maxHP / 2)
        return "\tHe looks weary. You're not making this easy.";
    else if (HP < 3 * maxHP / 4)
        return "\tHe feels uneasy. He takes a step back.";
    else
        return "\tHe steadily holds his ground.";
}

string Character::attackText (string enemyName)
{
    if (!isEnemy())
        return "\tYou swing at the " + enemyName + ".";
    else
        return "\tThe " + enemyName + " swings at you.";
}

void Character::onEvade (Character * target)
{
}

void Character::doAction (int actionNum, Character * target)
{
    if (actionNum == 1) attack(target);
}

void Character::attack (Character * target)
{
    string enemyName = isEnemy() ? name : target->getName();
  
    cout << attackText(enemyName) << endl;
    int hitChance = random(100);
    
    if (hitChance <= 80 - target->getEva()) {
        // attack hits
        // base damage is 15-40 * attacker's attack / target's defense

        int dam = (random(25) + 15) * att / target->getDef(); 
        target->damage(dam);
	cout << "\t" << dam << " damage!\n";

	if (isEnemy() && !target->isAlive()) cout << "\tYou are dead.\n";

    } else if (hitChance <= 80) {
        // enemy evades
      
        cout << (isEnemy() ? "\tYou evade the attack!\n" : "\tHe evades the attack!\n");
	target->onEvade(this);

    } else {
        // atack misses

        cout << (isEnemy() ? "\tHe misses!\n" : "\tYou miss!\n");

    }
}
