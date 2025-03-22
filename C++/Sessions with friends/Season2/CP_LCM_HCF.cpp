#include <iostream>
#include <vector>

std::vector<unsigned int> 
GetMyFactors(
	unsigned int no
)
{
	std::vector<unsigned int> factors{};

	int loop_count = 0;

	for(int i = 2; i <= no/2; ++i)
	{
		loop_count++;

		if (no % i == 0)
		{
			factors.emplace_back(i);
			no = no / i;
			i = 1;
		}
	}

	if (no > 1)
	{
		factors.emplace_back(no);
	}

	std::cout << "loop count for: " << loop_count << std::endl;

	return factors;
}

unsigned int GetLCM(
	unsigned int no1,
	unsigned int no2
)
{
	unsigned lcm = 1;

	auto print_me = [](const std::vector<unsigned int>& v) {

		for (/*const*/ auto& i : v)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	};

	auto /*std::vector*/ v1 = GetMyFactors(no1);

	std::cout << no1 << "'s factors: ";
	print_me(v1);

	auto /*std::vector*/ v2 = GetMyFactors(no2);

	std::cout << no2 << "'s factors: ";
	print_me(v2);

	// compare two vectors and calc lcm

	int i = 0, j = 0;
	while (i < v1.size() && j < v2.size())
	{
		if (v1[i] == v2[j])
		{
			lcm = lcm * v1[i];
			i++;
			j++;
		}
		else
		{
			lcm *= v1[i] < v2[j] ? v1[i++] : v2[j++];
		}
	}

	while (i < v1.size())
	{
		lcm *= v1[i++];
	}

	while (j < v2.size())
	{
		lcm *= v2[j++];
	}

	return lcm;
}


unsigned int GetHCF(
	unsigned int no1,
	unsigned int no2
)
{
	unsigned hcf = 1;

	auto print_me = [](const std::vector<unsigned int>& v) {

		for (/*const*/ auto& i : v)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	};

	auto /*std::vector*/ v1 = GetMyFactors(no1);

	std::cout << no1 << "'s factors: ";
	print_me(v1);


	auto /*std::vector*/ v2 = GetMyFactors(no2);

	std::cout << no2 << "'s factors: ";
	print_me(v2);


	// compare two vectors and hfc
	
	int i = 0, j = 0;
	while (i < v1.size() && j < v2.size())
	{
		if (v1[i] == v2[j])
		{
			hcf = hcf * v1[i];
			i++;
			j++;
		}
		else
		{
			v1[i] < v2[j] ? i++ : j++;
		}
	}

	return hcf;
}


int main(/*void*/)
{
	std::cout << "Enter two numbers for calculating the LCM: ";

	int no1, no2;

	std::cin >> no1;
	std::cin >> no2;

	std::cout << "LCM of " << no1 << " and " << no2 << " is : " << GetLCM(no1, no2) << std::endl;

	std::cout << "HCF of " << no1 << " and " << no2 << " is : " << GetHCF(no1, no2) << std::endl;

	return 0;
}
