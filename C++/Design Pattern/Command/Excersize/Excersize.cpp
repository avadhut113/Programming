// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Command
{
    enum Action { deposit, withdraw } action;
    int amount{ 0 };
    bool success{ false };
};

struct Account
{
    int balance{ 0 };

    void process(Command& cmd)
    {
        switch (cmd.action)
        {
        case Command::Action::deposit:
            cmd.success = deposit(cmd.amount);
            break;
        case Command::Action::withdraw:
            cmd.success = withdraw(cmd.amount);
            break;

        }
    }

    bool withdraw(int amount)
    {
        if (amount <= balance) {
            amount -= balance;
            return true;
        }
        return false;
    }

    bool deposit(int amount)
    {
        balance += amount;
        return true;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

