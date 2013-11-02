// File: Rogue.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of the Rogue class

#include "Rogue.h"

Rogue::Rogue ()
{
    actions[0] = "Attack";
    //actions[1] = "Sidestep";
    //actions[2] = "Debilitate";
    name = "Rogue";
    maxHP = 70;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 30;
    eva = 15;
    alive = true;
    enemyChar = false;
}

Rogue::Rogue (bool isEnemyChar)
{
    actions[0] = "Attack";
    //actions[1] = "Sidestep";
    //actions[2] = "Debilitate";
    name = "Rogue";
    maxHP = 70;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 30;
    eva = 15;
    alive = true;
    enemyChar = isEnemyChar;
}

string Rogue::status ()
{
    if (HP <= 0) {
        return "\tHe drops. Looks like he wont live to fight another day.";
    } else if (HP < maxHP / 4)
        return "\t.He's bloody and wondering why he let this go so far.";
    else if (HP < maxHP / 2)
        return "\tHe now moves frantically rather that gracefully.";
    else if (HP < 3 * maxHP / 4)
        return "\tHis confidence has now turned to determination.";
    else
        return "\tHe looks confident and light on his feet.";
}

string Rogue::attackText (string enemyName)
{
    if (!isEnemy())
        return "\tYou slash at the " + enemyName + " with your dagger.";
    else 
        return "\tThe " + enemyName + " slashes at you with his dagger.";
}

void Rogue::onEvade (Character * target)
{
}
