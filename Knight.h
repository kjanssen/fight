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

	// This constructor tell the Knight if it is an enemy or not
	Knight(bool isEnemyChar);

        // This function returns the status of a Character based on its HP
        string status();

        // This function returns the text for a player attacking an enemy
        string attackText(string enemyName);
};

#endif
