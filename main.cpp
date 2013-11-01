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

void displayBanner(Character * enemy);
void doOneTurn(Character * player, Character * enemy);
void displayMenu(Character * player, Character * enemy);
bool replay();

int main()
{
  Character * player;
  Character * enemy;
  bool play = true;
    
  while (play) {
    player = new Character("Player1");
    enemy = new Character("Enemy");


    displayBanner(enemy);
    
    while (enemy->isAlive() && player->isAlive())
      doOneTurn(player, enemy);

    displayMenu(player, enemy);

    play = replay();   
  }
    
  cout << endl << endl;
}





void displayBanner(Character * enemy)
{
  cout << endl;
  cout << "//////////////////////////////////////////////////////////////" << endl;
  cout << "//                                                          //" << endl;
  cout << "//                          FIGHT!                          //" << endl;
  cout << "//                                                          //" << endl;
  cout << "//////////////////////////////////////////////////////////////" << endl << endl;

  cout << "The " << enemy->getName() << " stares you straight in the eyes. What ";
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
  char choice;
  displayMenu(player, enemy);
  cin >> choice;
  cout << endl;
  
  while (!(choice - '0' > 0 && choice - '0' <= player->numActions()) && choice != 'q') {
    cout << "Choice invalid.\n\n\t> ";
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
    enemy->attackPlayer(player);
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
  cout << "\t+----------------------------------------+\n";
  cout << "\t| " << setw(39) << left << enemy->getName() << "|\n";
  cout << "\t|                                        |\n";
  cout << "\t| HP " << setw(3) << right << enemy->getHP() << "/" << left << enemy->getMaxHP() << " [";
  for (int i = 0; i < 25; i++) { if (enemy->getHP() > i * 4) cout << "|"; else cout << " "; }
  cout << "] |\n\t+----------------------------------------+\n\n";


  cout << "\t+----------------------------------------+\n";
  cout << "\t| " << setw(39) << left << player->getName() << "|\n";
  cout << "\t|                                        |\n";
  cout << "\t| HP " << setw(3) << right <<  player->getHP() << "/" << left << player->getMaxHP() << " [";
  for (int i = 0; i < 25; i++) { if (player->getHP() > i * 4) cout << "|"; else cout << " "; }
  cout << "] |\n";
  cout << "\t| SP " << setw(3) << right <<  player->getSP() << "/" << left << player->getMaxSP() << " [";
  for (int i = 0; i < 25; i++) { if (player->getSP() > i * 4) cout << "|"; else cout << " "; }
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
