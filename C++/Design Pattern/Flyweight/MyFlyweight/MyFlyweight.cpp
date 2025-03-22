// MyFlyweight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/bimap.hpp>

using key = uint32_t;


class User
{
protected:
    static boost::bimap<key, std::string> name;
    static key seed;
    key first_name, last_name;

public:
    User(const std::string& first_name, const std::string& last_name) : first_name(add(first_name)), last_name(add(last_name)) {

    }

    static key add(const std::string s) {
        auto it = name.right.find(s);
        if (it == name.right.end()) {
            key id = ++seed;
            name.insert({ seed,s });
            return id;
        }
        return it->second;
    }

    const std::string& GetFirstName()const {
        return name.left.find(first_name)->second;
    }

    const std::string& GetLastName()const {
        return name.left.find(last_name)->second;
    }

    friend std::ostream& operator<<(std::ostream& os, User user) {
        os << "First name : " << user.GetFirstName() << "{" << user.first_name << "}" << " Last name : " << user.GetLastName() << "{" << user.last_name << "}";
        return os;
    }

};

key User::seed{ 0 };
boost::bimap<key, std::string> User::name{};

int main()
{
    User user1{ "Megha","Patil" };
    User user2{ "Avadhut","Patil" };

    std::cout << user1 << std::endl << user2;

}

