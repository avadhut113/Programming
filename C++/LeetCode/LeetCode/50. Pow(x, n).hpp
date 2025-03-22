#pragma once


class Solution50 {
public:
    static double myPow(double x, int n) {
        // Inner function to calculate power using Quick Power Algorithm (also known as Binary Exponentiation)
         auto quickPow = [](double base, long long exponent) -> double {
            double result = 1.0; // Initialize the result to 1, as anything to the power of 0 is 1
            while (exponent > 0) { // Iterate until the exponent becomes 0
                if (exponent & 1) { // If the exponent is odd, multiply the current result by the base
                    result *= base;
                }
                base *= base; // Square the base
                exponent >>= 1; // Right shift exponent by 1 (divide the exponent by 2)
            }
            return result; // Return the final result of base raised to the exponent
            };

        // Check the sign of the exponent and call quickPow function
        // If 'n' is negative, we take the reciprocal of base raised to the power of absolute value of 'n'
        // We cast 'n' to long long to handle cases when n is INT_MIN, which flips to positive out of range if n is an int
        return n >= 0 ? quickPow(x, n) : 1.0 / quickPow(x, -(long long)n);
    }
};

void test50()
{
    std::cout << Solution50::myPow(2.00, 10) << "\n";
    std::cout << Solution50::myPow(2.10, 3) << "\n";
    std::cout << Solution50::myPow(2.00, -2) << "\n";
    std::cout << Solution50::myPow(3, 3) << "\n";

}