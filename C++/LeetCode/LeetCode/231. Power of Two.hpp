// PowerOfTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution231 {
public:
	/*bool isPowerOfTwo(int n) {

		int rem = 0;

		if (n == 0)
			return false;

		while (rem == 0) {
			rem = n % 2;
			n /= 2;
		}
		if (rem == 1 && n==0)
			return true;
		else
			return false;
	}*/

	//faster solution
	bool isPowerOfTwo(int n) {
		if (n <= 0) {
			return false;
		}
		if (n == 1) {
			return true;
		}
		if (n % 2 != 0) {
			return false;
		}
		return isPowerOfTwo(n / 2);
	}
};

int test231()
{
	Solution231 sl;
	std::cout << sl.isPowerOfTwo(16);
}
