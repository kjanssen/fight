//*******************************************************************
//
// Kyle Janssen - main.cpp -
//
// Fight - A turn-based fighting game
//
// Fight is a simple fighting game inwhich the player fights
// an opponent of various classes.
//
//*******************************************************************

#include <iostream>
#include <iomanip>
#include "Random.h"
#include "Character.h"
#include "Berserker.h"
#include "Fighter.h"
#include "Knight.h"
#include "Rogue.h"
#include "Wizard.h"

using namespace std;

void displayBanner();
Character * pickCharacter(bool isEnemy);
void doOneTurn(Character * player, Character * enemy);
void displayMenu(Character * player, Character * enemy);
bool replay();

int main()
{
  Character * player;
  Character * enemy;
  bool play = true;
    
  while (play) {
    displayBanner();

    player = pickCharacter(false);
    enemy = pickCharacter(true);

    cout << "The " << enemy->getName() << " stares you straight in the eyes. What ";
    cout << "do you do?" << endl << endl;
    
    while (player->isAlive() && enemy->isAlive())
      doOneTurn(player, enemy);

    displayMenu(player, enemy);

    play = replay();   
  }
    
  cout << endl << endl;
}





void displayBanner()
{
  cout << endl;
  cout << "//////////////////////////////////////////////////////////////" << endl;
  cout << "//                                                          //" << endl;
  cout << "//                          FIGHT!                          //" << endl;
  cout << "//                                                          //" << endl;
  cout << "//////////////////////////////////////////////////////////////" << endl << endl;
}


Character * pickCharacter(bool isEnemy)
{
  string who = (isEnemy) ? "enemy" : "your";

  cout << "\tChoose " << who << " class:\n\n";
  cout << "\t\t1. Berserker\n";
  cout << "\t\t2. Fighter\n";
  cout << "\t\t3. Knight\n";
  cout << "\t\t4. Rogue\n";
  cout << "\t\t5. Wizard\n";
  cout << "\t\t6. Random\n\n\t> ";

  char choice;
  cin >> choice;
  cout << endl;

  while (!(choice - '0' > 0 && choice - '0' <= 6) && choice != 'q') {
    cout << "Choice invalid.\n\n\t> ";
    cin >> choice;
    cout << endl;
  }

  if (choice == 'q') {
    Character * character = new Character;
    character->kill();
    return character;
  }

  int choiceNum = (choice == '6') ? random(5) : choice - '0';
  
  switch (choiceNum) {
    case 1:
      return  new Berserker(isEnemy);

    case 2:
      return new Fighter(isEnemy);

    case 3:
      return new Knight(isEnemy);

    case 4:
      return new Rogue(isEnemy);

    case 5:
      return new Wizard(isEnemy);

    default:
      return new Character(isEnemy);
  }
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
  char choice;
  displayMenu(player, enemy);
  cin >> choice;
  cout << endl;
  
  while (!(choice - '0' > 0 && choice - '0' <= player->numActions()) && choice != 'q') {
    cout << "Choice invalid.\n\n\t> ";
    cin >> choice;
    cout << endl;
  }

  while (player->getCost(choice - '0') > player->getSP()) {
    cout << "Not enough SP.\n\n\t> ";
    cin >> choice;
    cout << endl;
  }

  if (choice == 'q') {
    player->kill();
    return;
  }
    
  player->doAction(choice - '0', enemy);

  cout << enemy->status() << endl << endl;
  if (enemy->isAlive()) {
    enemy->attack(player);
    cout << endl;
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
    
void displayMenu(Character * player, Character * enemy)
{
  string enemyName = (enemy->isAlive()) ? enemy->getName() : enemy->getName() + " x_x";
  string playerName = (player->isAlive()) ? player->getName() : player->getName() + " x_x";
  
  cout << "\t+----------------------------------------+\n";
  cout << "\t| " << setw(39) << left << enemyName << "|\n";
  cout << "\t|                                        |\n";
  cout << "\t| HP " << setw(3) << right << enemy->getHP() << "/" 
       << setw(3) << left << enemy->getMaxHP() << " [";

  for (int i = 0; i < 25; i++) {
    if (enemy->getHP() > i * enemy->getMaxHP() / 25)
      cout << "|";
    else cout << " ";
  }

  cout << "] |\n\t+----------------------------------------+\n\n";


  cout << "\t+----------------------------------------+\n";
  cout << "\t| " << setw(39) << left << playerName << "|\n";
  cout << "\t|                                        |\n";
  cout << "\t| HP " << setw(3) << right <<  player->getHP() << "/"
       << setw(3) << left << player->getMaxHP() << " [";

  for (int i = 0; i < 25; i++) {
    if (player->getHP() > i * player->getMaxHP() / 25)
      cout << "|";
    else cout << " ";
  }

  cout << "] |\n";
  cout << "\t| SP " << setw(3) << right <<  player->getSP() << "/"
       << setw(3) << left << player->getMaxSP() << " [";

  for (int i = 0; i < 25; i++) {
    if (player->getSP() > i * player->getMaxSP() / 25)
      cout << "|";
    else cout << " ";
  }

  cout << "] |\n";
  cout << "\t|                                        |\n";

  for (int i = 0; i < 4; i++)
    cout << "\t|     " << i + 1 << ". " << setw(32) << left << player->action(i) << "|\n";

  cout << "\t+----------------------------------------+\n\n\t> ";
}
    



bool replay()
{
  char decision;
    
  cout << "Would you like to play again? (y or n): ";
  cin >> decision;
    
  if (decision == 'y') {
    cout << endl << endl;
    return true;
  } else
    return false;
}
