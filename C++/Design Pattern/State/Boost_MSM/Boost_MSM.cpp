// Boost_MSM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
//back-end
#include <boost/msm/back/state_machine.hpp>

//front-end
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/functor_row.hpp>


namespace msm = boost::msm;
namespace mpl = boost::mpl;

using namespace msm::front;

std::vector<std::string> state_name{
    "off_hook",
    "connecting",
    "connected",
    "on_hold",
    "destroyed"
};

struct call_dialed
{
    call_dialed() {
        std::cout << "processing event call_dialed" << std::endl;
    }
};
struct call_connected
{
    call_connected() {
        std::cout << "processing event call_connected" << std::endl;
    }
};
struct hang_up
{
    hang_up() {
        std::cout << "processing event hang_up" << std::endl;
    }
};
struct place_on_hold
{
    place_on_hold() {
        std::cout << "processing event place_on_hold" << std::endl;
    }
};
struct taken_off_hold
{
    taken_off_hold() {
        std::cout << "processing event taken_off_hold" << std::endl;
    }
};
struct left_message
{
    left_message() {
        std::cout << "processing event left_message" << std::endl;
    }
};
struct phone_trown_onto_wall
{
    phone_trown_onto_wall() {
        std::cout << "processing event phone_trown_onto_wall" << std::endl;
    }
};


struct phone_state_machine : state_machine_def<phone_state_machine>
{
    bool angry{ true };
    struct off_hook : state<>
    {
        template<class Event, class FSM>
        void on_entry(const Event& event, FSM& fsm) {
            std::cout << "off hook" << std::endl;
        }
    };
     
    struct connecting : state<>
    {
        template<class Event, class FSM>
        void on_entry(const Event& event, FSM& fsm) {
            std::cout << "we are connecting" << std::endl;
        }
    };
    struct connected : state<> 
    {
        template<class Event, class FSM>
        void on_entry(const Event& event, FSM& fsm) {
            std::cout << "we are connected" << std::endl;
        }
    };
    struct on_hold : state<> 
    {
        template<class Event, class FSM>
        void on_entry(const Event& event, FSM& fsm) {
            std::cout << "we are on hold" << std::endl;
        }
    };
    struct phone_destroyed : state<> 
    {
        template<class Event, class FSM>
        void on_entry(const Event& event, FSM& fsm) {
            std::cout << "phone destroyed" << std::endl;
        }
    };

    struct phone_being_destroyed : state<> {
        template<class EVT, class FSM, class source_state, class target_state>
        void operator()(EVT const&, FSM&, source_state&, target_state&) {
            std::cout << "Phones breaks in to millions pieces" << std::endl;
        }
    };

    struct can_destroy_phone : state<> {
        template<class EVT, class FSM, class source_state, class target_state>
        bool operator()(EVT const&, FSM& fsm, source_state&, target_state&) {
            return fsm.angry;
        }
    };

    struct transition_table : mpl::vector <
        Row<off_hook, call_dialed, connecting>,
        Row<connecting, call_connected, connected>,
        Row<connected, place_on_hold, on_hold>,
        Row<on_hold, phone_trown_onto_wall, phone_destroyed, phone_being_destroyed, can_destroy_phone>
    > {};

    // starting state
    typedef off_hook initial_state;

    // what happens if there's nowhere to go
    template <class FSM, class Event>
    void no_transition(Event const& e, FSM&, int state)
    {
        std::cout << "No transition from state " << state_name[state]
            << " on event " << typeid(e).name() << std::endl;
    }

};

int main()
{
    msm::back::state_machine<phone_state_machine> phone;

    auto info = [&]()
    {
        auto i = phone.current_state()[0];
        std::cout << "The phone is currently " <<
            state_name[i] << "\n";
    };

    info();
    phone.process_event(call_dialed{});
    info();
    phone.process_event(call_connected{});
    info();
    phone.process_event(place_on_hold{});
    info();
    phone.process_event(phone_trown_onto_wall{});
    info();

    // try process_event here :)
    phone.process_event(call_dialed{});

    std::cout << "We are done using the phone" << "\n";

    getchar();
    return 0;
}
