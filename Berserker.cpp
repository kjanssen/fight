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
