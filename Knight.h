#ifndef KNIGHT_H
#define KNIGHT_H

// File: Knight.h
// Author: Kyle Janssen
// Contents: This file contains the sescription of a class that represents
// Knight characters.

#include "Hero.h"

class Knight : public Hero
{
    public:
        // Default Constructor
        Knight();

        // This function returns the status of a Character based on its HP
        string status();

        // This function returns the text for a player attacking an enemy
        string playerAttackText(string name);

        // This function returns the text for an enemy attacking a player
        string enemyAttackText(string name);
};

#endif
