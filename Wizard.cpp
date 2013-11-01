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
}
