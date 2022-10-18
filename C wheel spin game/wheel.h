#ifndef WHEEL
#define WHEEL

#include <cstdlib>

class wheel{
private:
	int upper;
	
public:
	wheel();
	wheel(int upperBound);
	void setLength(int upperBound);
	int spin();
};

#endif