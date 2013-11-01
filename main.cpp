//*******************************************************************
//
// Kyle Janssen - Fight_v2.cpp - 
//
// Revised edition of game made about a year ago. Fight is a simple
// battle game with perfectly even odds in which the player fights
// an unidentified opponent. The player and his opponent punch and
// kick at eachother until one of them is dead.
//
//*******************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Random.h"
#include "Character.h"

using namespace std;

void displayBanner();
void doOneTurn(Character * player, Character * enemy);
void checkInput(char& decision, char dec1, char dec2);
void displayMenu(int playerHealth);
void playerAttack(char decision, Character * enemy);
void decideAttack(char decision, bool& attackHits, int& damage);
void punch(bool& hit, int& damage);
void kick(bool& hit, int& damage);
void enemyAttack(Character * player);
bool replay();

int main()
{
  Character * player;
  Character * enemy;
  bool play = true;
    
  while (play) {
    player = new Character("Player1");
    enemy = new Character("Enemy");


    displayBanner();
    
    while (enemy->isAlive() && player->isAlive())
      doOneTurn(player, enemy);

    play = replay();   
  }
    
  cout << endl << endl;
}





void displayBanner()
{
  cout << "//////////////////////////////////////////////////////////////" << endl;
  cout << "//                                                          //" << endl;
  cout << "//                          FIGHT!                          //" << endl;
  cout << "//                                                          //" << endl;
  cout << "//////////////////////////////////////////////////////////////" << endl << endl;

  cout << "Your opponent stares you straight in the eyes. What ";
  cout << "do you do?" << endl << endl;
}





//*******************************************************************
//
// This function does one turn of the fight.
//
// pre: both players are alive
//
// post: one turn in the battle passes
//
//*******************************************************************

void doOneTurn(Character* player, Character* enemy)
{
  char decision;
    
  displayMenu(player->getHP());
  cin >> decision;
  checkInput(decision, 'a', 'b');
    
  playerAttack(decision, enemy);
    
  if (enemy->isAlive())
    enemyAttack(player);
}





//*******************************************************************
//
// This function checks to make sure the user input is valid.
//
// pre: the player has made a decision
//
// post: if the decision was invalid, it has been made valid
//
//*******************************************************************

void checkInput(char& decision, char dec1, char dec2)
{
  while (decision != dec1 && decision != dec2) {
    cout << "Try again (" << dec1 << " or " << dec2 << "): ";
    cin >> decision;
  }
}



    

//*******************************************************************
//
// This function displays the player's menu.
//
// pre: player has positive health
//
// post: menu has been displayed
//
//*******************************************************************
    
void displayMenu(int playerHealth)
{
  cout << "   ---------------------- " << endl;
  cout << "  |  a. Punch    |   HP  |" << endl;
  cout << "  |  b. Kick     |  " << setw(3) << playerHealth << "  |" << endl;
  cout << "   ---------------------- " << endl << endl;
}
    




//*******************************************************************
//
// This function excecutes the player's portion of the turn.
//
// pre: player has made valid decision
//
// post: player has made an attack
//
//*******************************************************************

void playerAttack(char decision, Character* enemy)
{
  bool attackHits = false;
  int damage;
    
  decideAttack(decision, attackHits, damage);
    
  if (decision == 'a')
    cout << "\nYou punch at your enemy.\n";
  else
    cout << "\nYou kick at your enemy.\n";
        
  if (attackHits) {
    enemy->damage(damage);

    cout << damage << " damage!" << endl;
    attackHits = false;
  } else
    cout << "You miss!" << endl;
    
  cout << enemy->status() << endl << endl;

  if (enemy->getHP() < 1)
      enemy->kill();
}





//*******************************************************************
//
// This function takes the players choice and excecutes a specific
// attack.
//
// pre: decision == a || b
//
// post: either punch() or kick() has been excecuted
//
//*******************************************************************

void decideAttack(char decision, bool& attackHits, int& damage)
{
  switch(decision)
    {
    case 'a' : 
      punch(attackHits, damage);
      break;
    case 'b' : kick(attackHits, damage);
      break;
    default  : cout << "Something is wrong.";
      break;
    }
}





//*******************************************************************
//
// This function caluculates the success of a punch attack the has an
// 80% chance to hit and does 15-40 dmg.
//
// pre: player chooses to punch
//
// post: damage and hitChance are calculated
//
//*******************************************************************

void punch(bool& hit, int& damage)
{
  damage = random(25) + 15;    // Dmg 15-40
    
  if (random(100) <= 80)
    hit = true;
}





//*******************************************************************
//
// This function caluculates the success of a kick attack the has a
// 60% chance to hit and does 30-55 dmg.
//
// pre: player chooses to kick
//
// post: damage and hitChance are calculated
//
//*******************************************************************

void kick(bool& hit, int& damage)
{
  damage = random(25) + 30;
    
  if (random(100) <= 60)
    hit = true;
}






//*******************************************************************
//
// This function excecutes the player's portion of the turn.
//
// pre: player has taken his turn
//
// post: enemy has made an attack
//
//*******************************************************************

void enemyAttack(Character* player)
{
  int actionChance;
  bool attackHits = false;
  int damage;
    
  actionChance = random(2);
  if (actionChance == 0)
    punch(attackHits, damage);
  else if (actionChance == 1)
    kick(attackHits, damage);
        
  if (actionChance == 0) 
    cout << "Your enemy punches at you. ";       
  else if (actionChance == 1)
    cout << "Your enemy kicks at you. ";

  if (attackHits) {
    player->damage(damage);
    cout << damage << " damage!" << endl << endl;
    attackHits = false;
  } else
    cout << "He misses!" << endl;
    
  if (player->getHP() <= 0) {
    player->kill();
    cout << "You are dead." << endl << endl;
  }
}







bool replay()
{
  char decision;
    
  cout << "Would you like to play again? (y or n): ";
  cin >> decision;
    
  checkInput(decision, 'y', 'n');
    
  if (decision == 'y') {
    cout << endl << endl;
    return true;
  } else
    return false;
}
