// Boost_Flyweight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/flyweight.hpp>


class User
{
    
public:
    boost::flyweight<std::string> first_name, last_name;

    User(const std::string& first, const std::string& last) : first_name{ first }, last_name{ last } {

    }

    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        os << "First Name : " << user.first_name << " Last Name : " << user.last_name;
        return os;
    }

};

int main()
{
    User user1{ "Megha","Patil" };
    User user2{ "Avadhut","Patil" };

    std::cout << user1 << std::endl << user2 << std::endl;

    std::cout << std::boolalpha;

    std::cout << (&user1.first_name.get() == &user2.first_name.get()) << std::endl;
    std::cout << (&user1.last_name.get() == &user2.last_name.get()) << std::endl;

}

