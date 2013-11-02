#ifndef WIZARD_H
#define WIZARD_H

// File: Wizard.h
// Author: Kyle Janssen
// Contents: This file contains the sescription of a class that represents
// Wizard characters.

#include "Hero.h"

class Wizard : public Hero
{
    public:
        // Default Constructor
        Wizard();

	// This constructor tells the Wizard if it is an enemy or not
	Wizard(bool isEnemyChar);

        // This function returns the status of a Character based on its HP
        string status();

        // This function returns the text for a player attacking an enemy
        string attackText(string enemyName);

	// This function has the Wizard perfor the action corresponding to
	// actionNum
	void doAction (int actionNum, Character * target);

	// The only difference here is that a Wizard attacks with only
	// a third of his base attack
	void attack (Character * target);

	// This function causes the Wizard to hurl a fireball at the target
	void fireball (Character * target);
};

#endif
