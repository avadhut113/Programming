#pragma once

template <typename T>
void print()

template <typename... Args>
void printParameters(Args&... args)
{
	std::cout << ... << args << "\n";
}