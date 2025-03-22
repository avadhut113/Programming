// MyStateMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <map>
#include <vector>

enum class State
{
    off_hook,
    connecting,
    connected,
    on_hold,
    on_hook
};


inline std::ostream& operator<<(std::ostream& os, const State& state)
{
    switch (state)
    {
    case State::off_hook:
        os << "off the hook" << std::endl;
        break;
    case State::connecting:
        os << "connecting" << std::endl;
        break;
    case State::connected:
        os << "connected" << std::endl;
        break;
    case State::on_hold:
        os << "on hold" << std::endl;
        break;
    case State::on_hook:
        os << "on the hook" << std::endl;
        break;
    }
    return os;
}

enum class Trigger
{
    call_dialed,
    hang_up,
    call_connected,
    place_on_hold,
    take_off_hold,
    left_message,
    stop_using_phone
};

inline std::ostream& operator<<(std::ostream& os, const Trigger& trigger)
{
    switch (trigger)
    {
    case Trigger::call_connected:
        os << "call connected" << std::endl;
        break;
    case Trigger::call_dialed:
        os << "call dialed" << std::endl;
        break;
    case Trigger::hang_up:
        os << "call hang up" << std::endl;
        break;
    case Trigger::left_message:
        os << "Please left message" << std::endl;
        break;
    case Trigger::place_on_hold:
        os << "Place on hold" << std::endl;
        break;
    case Trigger::stop_using_phone:
        os << "Stop using phone" << std::endl;
        break;
    case Trigger::take_off_hold:
        os << "take off the phone" << std::endl;
        break;
    }
    return os;
}

int main()
{
    std::map<State, std::vector<std::pair<Trigger, State>>> rules;

    rules[State::off_hook] = { {Trigger::call_dialed, State::connecting}, {Trigger::stop_using_phone, State::on_hook} };

    rules[State::connecting] = { {Trigger::hang_up, State::off_hook}, {Trigger::call_connected, State::connected} };

    rules[State::connected] = { {Trigger::left_message, State::off_hook}, {Trigger::hang_up, State::off_hook}, {Trigger::place_on_hold, State::on_hold} };

    rules[State::on_hold] = { {Trigger::take_off_hold, State::connected}, {Trigger::hang_up, State::off_hook} };

    State currentState{ State::off_hook }, exitState{ State::on_hook };

    while (true) {
        std::cout << "The phone is currently " << currentState << "\n";

    select_trigger:
        std::cout << "Select a trgger: \n";

        int i = 0;
        for (auto item : rules[currentState]) {
            std::cout << i++ << ". " << item.first << "\n";
        }

        int input;
        std::cin >> input;

        if (input<0 || (input + 1) > rules[currentState].size()) {
            std::cout << "Incorrect option. Please try again" << std::endl;
            goto select_trigger;
        }

        currentState = rules[currentState][input].second;

        if (currentState == exitState)
            break;
    }

    std::cout << "we are done using phone" << std::endl;

    return 0;
}
