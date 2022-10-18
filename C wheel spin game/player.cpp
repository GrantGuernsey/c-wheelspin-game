#include <iostream>
#include "player.h"
#include "wheel.h"
using namespace std;

player::player(){
	money = 0;
	wheel playerWheel;
}

player::player(int cash){
	money = cash;
}

void player::changeMoney(int cash){
	money = money + cash;
}

void player::setMoney(int cash){
	money = cash;
}

int player::getWheelValue(int size){
  playerWheel.setLength(size);
  return playerWheel.spin();
}