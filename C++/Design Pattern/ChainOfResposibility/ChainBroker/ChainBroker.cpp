// ChainBroker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include <boost/signals2.hpp>
using namespace std;

struct Query
{
    string creature_name;
    enum Argument {attack , defence} argument;
    int result;
};
struct Game //mediator
{
    boost::signals2::signal<void(Query&)> queries;
};

struct Creature
{
    Game& game;
    int attack, defence;
    string name;
public:
    Creature(Game& game,int _a,int _d, string name): game(game),attack(_a),defence(_d),name(name){}

    int get_attack() const {
        Query q{ name,Query::Argument::attack, attack };
        game.queries(q);
        return q.attack();
    }

    friend ostream& operator<<(ostream& os, Creature& creature) {
        os << "name : " << creature.name << " attack : " << creature.attack << " defence :" << creature.defence;
        return os;
    }
};

class CreatureModifier
{
    Game& game;
    Creature& creature;
public:
    CreatureModifier(Game& game,Creature& creature) :game(game),creature(creature){}
    virtual ~CreatureModifier() = default;
};

class DoubleAttackModifier :public CreatureModifier
{
    boost::signals2::connection conn;
public:
    DoubleAttackModifier(Game& game, Creature& creature) : CreatureModifier(game, creature) {

            conn = game.queries.connect([&](Query& q) {
                        if (q.creature_name == creature.name &&
                            q.argument == Query::Argument::attack) {
                                q.result *= 2;
                        }
                    });

    }
    ~DoubleAttackModifier() { conn.disconnect(); }
};

int main()
{
    Game game;
    Creature Goblin{ game,2,2,"Goblin" };
    cout << Goblin << std::endl;
    {
        DoubleAttackModifier dam{ game,Goblin };
        cout << Goblin << endl;
    }

    cout << Goblin << std::endl;

    return 0;
}
