// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct Creature;
struct Game
{
    vector<Creature*> creatures;
};

struct StatQuery
{
    enum Statistic { attack, defense } statistic;
    int result;
};

struct Creature
{
protected:
    Game& game;
    int base_attack, base_defense;

public:
    Creature(Game& game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
        base_defense(base_defense) {}
    virtual int get_attack() = 0;
    virtual int get_defense() = 0;
    virtual void set_attck(int attack) = 0;
    virtual void set_defence(int defence) = 0;

    friend ostream& operator<<(ostream& os, Creature& creature) {
        os << " attack : " << creature.base_attack << " defence :" << creature.base_defense;
        return os;
    }

};

class Goblin : public Creature
{
public:
    Goblin(Game& game, int base_attack, int base_defense) : Creature(game, base_attack, base_defense) {}

    Goblin(Game& game) : Creature(game, 1, 1) {}

    int get_attack() override {
        return base_attack;
    }

    int get_defense() override {
        return base_defense;
    }

    void set_attck(int attack) {
        base_attack = attack;
    }

    void set_defence(int defence) {
        base_defense = defence;
    }

};

class GoblinKing : public Goblin
{
public:
    GoblinKing(Game& game) : Goblin(game, 3, 3) {
        for (auto* creature : game.creatures) {
            Goblin* normal_goblin = dynamic_cast<Goblin*>(creature);
            if (normal_goblin) {
                creature->set_attck(creature->get_attack() + 1);
                creature->set_defence(creature->get_defense() + 1);
            }
        }
    }
};

int main()
{
    Game game;
    Goblin goblin(game);
    GoblinKing goblin_king(game);
    game.creatures.push_back(&goblin);
    game.creatures.push_back(&goblin_king);

    std::cout << goblin << std::endl;
}
