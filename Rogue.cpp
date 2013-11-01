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
}
