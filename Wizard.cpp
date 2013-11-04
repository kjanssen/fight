// File: Wizard.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of the Wizard class

#include "Wizard.h"
#include "Random.h"

Wizard::Wizard ()
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Fireball";
    cost[1] = 40;
    //actions[2] = "Freeze";
    //actions[3] = "Daze";
    name = "Wizard";
    maxHP = 70;
    maxSP = 130;
    HP = maxHP;
    SP = maxSP;
    att = 70;
    def = 30;
    eva = 5;
    alive = true;
    enemyChar = false;
}

Wizard::Wizard (bool isEnemyChar)
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Fireball";
    cost[1] = 40;
    //actions[2] = "Freeze";
    //actions[3] = "Daze";
    name = "Wizard";
    maxHP = 70;
    maxSP = 130;
    HP = maxHP;
    SP = maxSP;
    att = 70;
    def = 30;
    eva = 5;
    alive = true;
    enemyChar = isEnemyChar;
}

string Wizard::status ()
{
    if (HP <= 0) {
        return "\tAll that's left is a bloody wizard hat.";
    } else if (HP < maxHP / 4)
        return "\tIt's beginning to look like magic might not save him this time.";
    else if (HP < maxHP / 2)
        return "\tHe is not used to this kind of punishment, and it's taking its toll.";
    else if (HP < 3 * maxHP / 4)
        return "\tHis body is soft, but he has life in him yet.";
    else
        return "\tHis fingertips glow with magical energy.";
}

string Wizard::attackText (string enemyName)
{
    if (!isEnemy())
        return "\tYou try to club the " + enemyName + " with your staff.";
    else 
        return "\tThe " + enemyName + " tries to club you with his staff.";
}

void Wizard::doAction (int actionNum, Character * target)
{
    spendSP(cost[actionNum - 1]);

    if (actionNum == 1) {
        attack(target);
        if (target->isEnemy())
	    cout << target->status() << endl;

    } else if (actionNum == 2) {
        fireball(target);
        if (target->isEnemy())
            cout << target->status() << endl;
    }

    cout << endl;
}

void Wizard::attack (Character * target)
{
    string enemyName = isEnemy() ? name : target->getName();

    cout << attackText(enemyName) << endl;
    int hitChance = random(100);

    if (hitChance <= 80 - target->getEva()) {
        // attack hits
        // base damage is 15-40 * attacker's attack / target's defense
      
        int dam = (random(25) + 15) * att / 3 / target->getDef();
	target->damage(dam);
	cout << "\t" << dam << " damage!\n";
      
	if (isEnemy() && !target->isAlive()) cout << "\tYou are dead.\n";

    } else if (hitChance <= 80) {
        // enemy evades
      
        cout << (isEnemy() ? "\tYou evade the attack!\n" : "\tHe evades the attack!\n");
	target->onEvade(this);

    } else {
        // atack misses

        cout << (isEnemy() ? "\tHe misses!\n" : "\tYou miss!\n");

  }
}

void Wizard::fireball (Character * target)
{
    string enemyName = isEnemy() ? name : target->getName();
    int hitChance = random(100);

    if (!isEnemy())
        cout << "\tYou hurl a ball of fire at the " << enemyName << ".\n";
    else
        cout << "\tThe " << enemyName << " hurls a ball of fire at you.\n";

    if (hitChance <= 80 - target->getEva()) {
      // fireball hits
      // base damage is 15-40 * attacker's attack / target's defense

      int dam = (random(25) + 15) * att / target->getDef();
      target->damage(dam);
      cout << "\tIt burns for " << dam << " damage!\n";

      if (isEnemy() && !target->isAlive()) cout << "\tYou are dead.\n";

    } else if (hitChance <= 80) {
      // enemy evades

      cout << (isEnemy() ? "\tYou evade the fireball!\n" : "\tHe evades the firebal!\n");

    } else {
      // atack misses

      cout << "\tThe fireball misses!\n";

    }
}
