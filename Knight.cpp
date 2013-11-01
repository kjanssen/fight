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
