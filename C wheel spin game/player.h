#ifndef PLAYER
#define PLAYER

#include "wheel.h"
#include <iostream>
using namespace std;

class player{
private:
	int money;
	wheel playerWheel;
public:
	player();
	player(int cash);
	
	int getMoney(){return money;}
	void changeMoney(int cash);
	void setMoney(int cash);
  int getWheelValue(int size);
};

#endif