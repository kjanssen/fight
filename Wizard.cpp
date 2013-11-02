// File: Wizard.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of the Wizard class

#include "Wizard.h"

Wizard::Wizard ()
{
    actions[0] = "Attack";
    //actions[1] = "Fireball";
    //actions[2] = "Freeze";
    //actions[3] = "Daze";
    name = "Wizard";
    maxHP = 70;
    maxSP = 130;
    HP = maxHP;
    SP = maxSP;
    att = 70;
    def = 30;
    eva = 5;
    alive = true;
    enemyChar = false;
}

Wizard::Wizard (bool isEnemyChar)
{
    actions[0] = "Attack";
    //actions[1] = "Fireball";
    //actions[2] = "Freeze";
    //actions[3] = "Daze";
    name = "Wizard";
    maxHP = 70;
    maxSP = 130;
    HP = maxHP;
    SP = maxSP;
    att = 70;
    def = 30;
    eva = 5;
    alive = true;
    enemyChar = isEnemyChar;
}

string Wizard::status ()
{
    if (HP <= 0) {
        return "\tAll that's left is a bloody wizard hat.";
    } else if (HP < maxHP / 4)
        return "\tIt's beginning to look like magic might not save him this time.";
    else if (HP < maxHP / 2)
        return "\tHe is not used to this kind of punishment, and it's taking its toll.";
    else if (HP < 3 * maxHP / 4)
        return "\tHis body is soft, but he has life in him yet.";
    else
        return "\tHis fingertips glow with magical energy.";
}

string Wizard::attackText (string enemyName)
{
    if (!isEnemy())
        return "\tYou try to club the " + enemyName + " with your staff.";
    else 
        return "\tThe " + enemyName + " tries to club you with his staff.";
}
