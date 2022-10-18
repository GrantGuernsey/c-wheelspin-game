

#include "player.h"
#include "wheel.h"
#include <iostream>
#include <random>
using namespace std;

int main() {
  int potTotal, upperWheel = 0;
  wheel houseWheel;
  player myPlayer;

  cout << "Hello welcome to our game! How much money would you like in your pot?: ";
  cin >> potTotal;
  myPlayer.setMoney(potTotal);

  cout << "What would you like your upper value on the wheel to be? (6 - 20, recommended value is 10): ";
  cin >> upperWheel;
  while (upperWheel < 6 || upperWheel > 20) {
    cout << "ERROR, upper value must be from 6 to 20." << endl;
    cout << "What would you like your upper value on the wheel to be? (6 - 20, recommended value is 10): ";
    cin >> upperWheel;
  }

  houseWheel.setLength(upperWheel);

  // cout << "Would you like to play on easy mode or hard mode?: ";

  bool gameplay = true;
  char end;
  
  while (gameplay) {
    int bet, selection = 0;
    cout << "Enter your bet: ";
    cin >> bet;

    if (bet <= myPlayer.getMoney()) {
      cout << "Your bet has been placed." << endl;
      int playerValue = myPlayer.getWheelValue(upperWheel);
      cout << "Your value landed on " << playerValue << endl;
      cout << "Would you like to... \n 1. Double your bet \n 2. Halve your bet \n 3. Leave your bet the same";
      cin >> selection;

      while (selection > 3 or selection <= 0) {
        cout << "Error: Invalid selection, please enter another value." << endl;
        cout << "Would you like to... \n 1. Double your bet \n 2. Halve your bet \n 3. Leave your bet the same";
        cin >> selection;

      }

      if (selection == 1) {
        cout << "You have selected to double your bet, the highest possible pay out is" << (2 * bet) << endl;
        int first = houseWheel.spin();
        int second = houseWheel.spin();
        cout << "The house rolled " << first << " and " << second << endl;
        
        if (first < playerValue && second < playerValue) {
          // double win
          cout << "Player total +" << 2 * bet;
          myPlayer.changeMoney(2 * bet);
        } else if (first < playerValue || second < playerValue) {
          // no loss
          cout << "Player total unchanged";
        } else {
          // double loss
          myPlayer.changeMoney(-2 * bet);
          cout << "Player total -" << 2 * bet;
        }

      }

      else if (selection == 2) {
        cout << "You have selected to halve your bet, the highest possible pay out is" << bet << endl;
        int first = houseWheel.spin();
        int second = houseWheel.spin();
        cout << "The house rolled " << first << " and " << second << endl;

        if (first < playerValue && second < playerValue) {
          cout << "You won! Total payout is" << bet << endl;
          myPlayer.changeMoney(bet);
        }
        else if (( first > playerValue && second < playerValue ) || ( first < playerValue && second > playerValue)){
          cout << "Player total unchanged." << endl;
        }
        else{
          cout << "You lost! Total loss is: " << bet << endl;
          myPlayer.changeMoney(-bet);
        }
      }
			else{
				int first = houseWheel.spin();
				if(playerValue < first){
					cout << "Player total +" << bet << endl;
					player.changeMoney(bet);
				}
				else{
					cout << "Player total -" << bet << endl;
					player.changeMoney(-bet);
				}
			}
    }

    else {
      cout << "Your bet was more than you have in your account. Your current "
              "balance is "
           << myPlayer.getMoney() << endl;
    }

    if (myPlayer.getMoney() <= 0) {
      cout << "You have been kicked from the game, your debt is now: "
           << myPlayer.getMoney() << endl;
      gameplay = false;
    } else {
      cout << "Would you like to continue? y/n ";
      cin >> end;
      //
    }
  }
}