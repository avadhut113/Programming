#pragma once

class Solution_342 {
public:
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

    bool isPowerOfFour(int n) {
		if (n <= 0) {
			return false;
		}
		if (n == 1) {
			return true;
		}
		if (n % 4 != 0) {
			return false;
		}
		return isPowerOfFour(n / 4);
    }

	bool isPowerOfThree(int n) {
		if (n <= 0) {
			return false;
		}
		if (n == 1) {
			return true;
		}
		if (n % 3 != 0) {
			return false;
		}
		return isPowerOfThree(n / 3);
	}
};
