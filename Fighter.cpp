// File: Fighter.cpp
// Author: Kyle Janssen
// Contents: This file contains the implementation of the Fighter class

#include "Fighter.h"
#include "Random.h"

Fighter::Fighter ()
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Well-Placed Blow";
    cost[1] = 30;
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
    enemyChar = false;
}

Fighter::Fighter (bool isEnemyChar)
{
    actions[0] = "Attack";
    cost[0] = 0;
    actions[1] = "Well-Placed Blow";
    cost[1] = 30;
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
    enemyChar = isEnemyChar;
}

string Fighter::status ()
{
    if (HP <= 0) {
        return "\tHe collapses in a heap as the life drians from his eyes.";
    } else if (HP < maxHP / 4)
        return "\tHe can barely stand, but bloody fingers still grip his weapon.";
    else if (HP < maxHP / 2)
        return "\tHe's hurting now, but it's nothing he hasn't been through before.";
    else if (HP < 3 * maxHP / 4)
        return "\tHe's a little shaken, but holds his ground.";
    else
        return "\tHe stands tall, ready for anything.";
}

string Fighter::attackText (string enemyName)
{
    if (!isEnemy())
        return "\tYou swing your sword at the " + enemyName + ".";
    else 
        return "\tThe " + enemyName + " swings his sword at you.";
}

void Fighter::doAction (int actionNum, Character * target)
{
    spendSP(cost[actionNum -1]);

    if (actionNum == 1) {
        attack(target);
        if (target->isEnemy())
            cout << target->status() << endl;

    } else if (actionNum == 2) {
        wellPlacedBlow(target);
        if (target->isEnemy())
            cout << target->status() << endl;
    }

    cout << endl;
}

void Fighter::wellPlacedBlow (Character * target)
{
    string enemyName = isEnemy() ? name : target->getName();
    int hitChance = random(100);

    if (!isEnemy())
        cout << "\tYou time the strike just right, and slash at the " << enemyName << ".\n";
    else
        cout << "\tThe " << enemyName << " waits for just the right moment, then strikes.\n";

    if (hitChance <= 80) {
        // the strike hits
        // base damage is 25-40 * attacker's attack / target's defense

        int dam = (random(15) + 25) * att / target->getDef();
        target->damage(dam);
        cout << "\t" << dam << " damage!\n";

        if (isEnemy() && !target->isAlive()) cout << "\tYou are dead.\n";

    } else {
        // atack misses

        cout << "\tThe attack misses!\n";

    }
}

