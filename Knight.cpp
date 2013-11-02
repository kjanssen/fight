// File: Knight.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of the Knight class

#include "Knight.h"

Knight::Knight ()
{
    actions[0] = "Attack";
    //actions[1] = "Dig In";
    name = "Knight";
    maxHP = 130;
    maxSP = 70;
    HP = maxHP;
    SP = maxSP;
    att = 30;
    def = 70;
    eva = 5;
    alive = true;
}

string Knight::status ()
{
    if (HP <= 0) {
        return "\tHe finally collapses in a pile of crumpled steel.";
    } else if (HP < maxHP / 4)
        return "\tDark blood seeps out of the gaps in his armor.";
    else if (HP < maxHP / 2)
        return "\tHis once shiny armor is now visibly battered.";
    else if (HP < 3 * maxHP / 4)
        return "\tHe raises his sheild a little more readily now.";
    else
        return "\tHe stands tall in shining armor.";
}

string Knight::playerAttackText (string enemyName)
{
    return "\tYou swing your gleaming sword at the " + enemyName + ".";
}

string Knight::enemyAttackText (string enemyName)
{
    return "\tThe " + enemyName + " swings his gleaming sword at you.";
}
