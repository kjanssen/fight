// File: Berserker.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of the Berserker class

#include "Berserker.h"

Berserker::Berserker ()
{
    actions[0] = "Attack";
    //actions[1] = "Get Mad";
    //actions[2] = "Charge";
    name = "Berserker";
    maxHP = 100;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 70;
    def = 30;
    eva = 5;
    alive = true;
}

string Berserker::status ()
{
    if (HP <= 0) {
        return "\tHe's on the ground, out of blood, but he still has that crazy look in his eyes.";
    } else if (HP < maxHP / 4)
        return "\tHe's missing significant portions of his body, but still fights like a madman.";
    else if (HP < maxHP / 2)
        return "\tHis eyes no longer point the same direction, but he just keeps coming.";
    else if (HP < 3 * maxHP / 4)
        return "\tHe has a few cuts, but nothing is slowing him down.";
    else
        return "\tMuscles flexing, he lets out a battle cry.";
}

string Berserker::playerAttackText (string enemyName)
{
    return "\tYou swing your axe at the " + enemyName + ".";
}

string Berserker::enemyAttackText (string enemyName)
{
    return "\tThe " + enemyName + " swings his axe at you.";
}
