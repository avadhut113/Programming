#pragma once
#include <math.h>
#include <limits>

int reversenum(int x) {
	int sum = 0;
	while (x > 0) {
		sum = sum * 10 + x % 10;

		if (sum < INT_MIN || sum > INT_MAX) return 0;

		x /= 10;
	}
	return sum;
}

int reverse(int x) {
	int sum = 0;
	if (0 == x)
		return 0;
	else if (0 < x) {
		return reversenum(x);
	}
	else {
		x *= -1;
		return -1 * reversenum(x);
	}
}