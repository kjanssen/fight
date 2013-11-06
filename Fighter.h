#ifndef FIGHTER_H
#define FIGHTER_H

// File: Fighter.h
// Author: Kyle Janssen
// Contents: This file contains the sescription of a class that represents
// Fighter characters.

#include "Hero.h"

class Fighter : public Hero
{
    public:
        // Default Constructor
        Fighter();

        // This constructor tells the Fighter if it is an enemy or not
        Fighter(bool isEnemyChar);

        // This function returns the status of a Character based on its HP
        string status();

        // This function returns the text for a player attacking an enemy
        string attackText(string enemyName);

        // This function has the Fighter perform the action correspoinding to
        // actionNum
        void doAction (int actionNum, Character * target);

        // This action executes an attack that cannot be evaded and has a
        // higher minimum damage
        void wellPlacedBlow (Character * target);
};

#endif
