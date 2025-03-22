// PointerChain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct Creature
{
    string name;
    int attack, defence;

    Creature(const string& _n, int a,int d) : name(_n), attack(a),defence(d){}

    friend ostream& operator<<(ostream& os,const Creature& creature)
    {
        os << "name : " << creature.name << " attack : " << creature.attack << " defence : " << creature.defence;
        return os;
    }
};

class CreatureModifire
{
    CreatureModifire* next{ nullptr };
protected:
    Creature& creature;
public:
    CreatureModifire(Creature& creature): creature(creature){}

    void add(CreatureModifire* cm)
    {
        if (next) next->add(cm);
        else next = cm;
    }

    virtual void handle()
    {
        if (next) next->handle();

    }
};

class DoubleAttackModifier : public CreatureModifire
{
public:
    DoubleAttackModifier(Creature& creature) :CreatureModifire(creature) {}

    void handle() override
    {
        creature.attack *= 2;
        CreatureModifire::handle();
    }
};

class IncreaseDefenceModifier : public CreatureModifire
{
public:
    IncreaseDefenceModifier(Creature& creature) :CreatureModifire(creature) {}

    void handle() override
    {
        if (creature.attack <= 2) {
            creature.defence++;
            CreatureModifire::handle();
        }
    }
};

int main()
{
    Creature Goblin{ "Goblin", 1,1 };
    CreatureModifire cm{ Goblin };
    DoubleAttackModifier dam{ Goblin };
    DoubleAttackModifier dam2(Goblin);
    IncreaseDefenceModifier idm{ Goblin };

    cm.add(&dam);
    cm.add(&dam2);
    cm.add(&idm);
    cm.handle();

    cout << Goblin << std::endl;
    return 0;


}
