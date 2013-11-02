#ifndef BERSERKER_H
#define BERSERKER_H

// File: Berserker.h
// Author: Kyle Janssen
// Contents: This file contains the sescription of a class that represents
// Berserker characters.

#include "Hero.h"

class Berserker : public Hero
{
    public:
        // Default Constructor
        Berserker();

        // This function returns the status of a Character based on its HP
        string status();

        // This function returns the text for a player attacking an enemy
        string playerAttackText(string name);

        // This function returns the text for an enemy attacking a player
        string enemyAttackText(string name);
};

#endif
