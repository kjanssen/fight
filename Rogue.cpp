// File: Rogue.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of the Rogue class

#include "Rogue.h"

Rogue::Rogue ()
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Sidestep";
    cost[1] = 30;
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
    enemyChar = false;
}

Rogue::Rogue (bool isEnemyChar)
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Sidestep";
    cost[1] = 30;
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
    enemyChar = isEnemyChar;
}

string Rogue::status ()
{
    if (HP <= 0) {
        return "\tHe drops. Looks like he wont live to fight another day.";
    } else if (HP < maxHP / 4)
        return "\tHe's bloody and wondering why he let this go so far.";
    else if (HP < maxHP / 2)
        return "\tHe now moves frantically rather that gracefully.";
    else if (HP < 3 * maxHP / 4)
        return "\tHis confidence has now turned to determination.";
    else
        return "\tHe looks confident and light on his feet.";
}

string Rogue::attackText (string enemyName)
{
    if (!isEnemy())
        return "\tYou slash at the " + enemyName + " with your dagger.";
    else 
        return "\tThe " + enemyName + " slashes at you with his dagger.";
}

void Rogue::onEvade (Character * target)
{
    cout << "\n\tAttack of Opportunity!\n";
    attack(target);
}

void Rogue::doAction (int actionNum, Character * target)
{
    spendSP(cost[actionNum - 1]);

    if (actionNum == 1) {
        attack(target);
        if (target->isEnemy())
	    cout << target->status() << endl;

    } else if (actionNum == 2)
        sidestep();

    cout << endl;
}

void Rogue::sidestep ()
{
    eva += 5;

    if (!isEnemy())
      cout << "\tYou take a step to the side, away from your enemy's gaze.\n";
    else
      cout << "\tThe rogue takes a step to the side, why is he so hard to hit?\n";
}
