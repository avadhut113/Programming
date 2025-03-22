// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct  IParticipant
{
    virtual void say(int value) = 0;
};

struct Mediator
{
    vector<IParticipant*> participants;
};

struct Participant : public IParticipant
{
    int value{ 0 };
    Mediator& mediator;

    Participant(Mediator& mediator) : mediator(mediator)
    {
        mediator.participants.push_back(this);
    }

    void say(int value)
    {
        for (auto currparticipant : mediator.participants) {
            Participant* participant = dynamic_cast<Participant*>(currparticipant);
            if (participant && participant != this)
                participant->value = value;
        }
    }

    friend ostream& operator<<(ostream& os, const Participant& participant) {
        os << participant.value << std::endl;
        return os;
    }
};

int main()
{
    Mediator m;
    Participant p1{ m }, p2{ m };

    p1.say(3);
    p2.say(2);

    cout << "P1 : " << p1 << "P2 : " << p2;
}

