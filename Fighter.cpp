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
