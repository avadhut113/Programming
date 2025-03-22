#include "MathTest.h"
#include <iostream>

namespace Arithmatic {
	int CMath::add(int x, int y)
	{
		std::cout << __FUNCTION__ << std::endl;
		return x + y;
	}
}

int Add(int x, int y)
{
	return x + y;
}