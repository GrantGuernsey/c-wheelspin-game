#include <cstdlib>
#include "wheel.h"
using namespace std;

wheel::wheel(){
	upper = 10;
}

wheel::wheel(int upperBound){
	upper = upperBound;
}

void wheel::setLength(int upperBound){
	upper = upperBound;
}

int wheel::spin(){
	return rand() % upper + 1;
}