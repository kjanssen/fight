// File: Fighter.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of the Fighter class

#include "Fighter.h"

Fighter::Fighter ()
{
    actions[0] = "Attack";
    //actions[1] = "Well-Placed Blow";
    //actions[2] = "Block";
    name = "Fighter";
    maxHP = 100;
    maxSP = 100;
    HP = maxHP;
    SP = maxSP;
    att = 50;
    def = 50;
    eva = 5;
    alive = true;
}

string Fighter::status ()
{
    if (HP <= 0) {
        return "\tHe collapsed in a heap as the life drians from his eyes.";
    } else if (HP < maxHP / 4)
        return "\tHe can barely stand, but bloody fingers still grip his weapon.";
    else if (HP < maxHP / 2)
        return "\tHe's hurting now, but it's nothing he hasn't been through before.";
    else if (HP < 3 * maxHP / 4)
        return "\tHe's a little shaken, but holds his ground.";
    else
        return "\tHe stands tall, ready for anything.";
}

string Fighter::playerAttackText (string enemyName)
{
    return "\tYou swing your sword at the " + enemyName + ".";
}

string Fighter::enemyAttackText (string enemyName)
{
    return "\tThe " + enemyName + " swings his sword at you.";
}
