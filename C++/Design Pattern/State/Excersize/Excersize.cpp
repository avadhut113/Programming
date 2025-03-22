// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class State
{

};

class Locked : public State
{

};

class Unlocked : public State
{

};

class Error : public State
{

};

class CombinationLock
{
    vector<int> combination;
public:
    string status;

    CombinationLock(const vector<int>& combination) : combination(combination),status("LOCKED") {
    
    }

    void enter_digit(int digit)
    {
        if (combination.size() != status.size()) {
            status.append(std::to_string(digit));
            cout << status;
        }
        else
        {
            status = "OPEN";
        }
    }
};



int main()
{
    std::cout << "Hello World!\n";
}