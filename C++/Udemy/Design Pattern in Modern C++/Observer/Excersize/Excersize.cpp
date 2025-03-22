// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
using namespace std;

struct IRat {};

struct Game
{
    list<IRat*> rats;
};

struct Rat : IRat
{
    Game& game;
    int attack{ 1 };

    Rat(Game& game) : game(game)
    {
        game.rats.push_back(this);
        for (auto r : game.rats) {
            Rat* rat = dynamic_cast<Rat*>(r);
        }
    }

    ~Rat()
    {
        game.rats.remove(this);
        attack = game.rats.size();
    }
};


int main()
{
    Game game;
    Rat r1{ game }, r2{ game };
    cout << r1.attack << " " << r2.attack << std::endl;
    {
        Rat r3{ game };
        cout << r1.attack << " " << r2.attack << " " << r3.attack << std::endl;

    }

    cout << r1.attack << " " << r2.attack << std::endl;

}
