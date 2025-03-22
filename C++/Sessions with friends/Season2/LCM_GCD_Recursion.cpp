
//Find LCM and GCD/HCF using recursion
#include <iostream>

int gcd(int num1, int num2, int res = 1, int div = 2)
{
	if (div > num1 || div > num2)
		return res;

	if (num1 % div != 0 || num2 % div != 0)
	{	
		return gcd(num1, num2, res, div + 1);
	}

	if (num1 % div == 0 && num2 % div == 0)
	{
		return gcd(num1/div, num2/div, res * div, 2);
	}
		
}

int lcm(int num1, int num2, int res = 1, int div = 2)
{
	if (div > num1 && div > num2)
		return res;

	if (num1 % div == 0 && num2 % div == 0)
	{
		return lcm(num1 / div, num2 / div, res * div, 2);
	}

	if(num1 % div == 0)
		return lcm(num1/div, num2, res * div, 2);
	else if (num2 % div == 0)
		return lcm(num1, num2/div, res * div, 2);
	else
		return lcm(num1, num2, res , div + 1);

}



int main()
{
	std::cout << lcm(50, 99) << std::endl;
	std::cout << gcd(30, 45) << std::endl;
}

