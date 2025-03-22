// Std_Visit with Varient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <variant>

struct AddressPrinter
{
    void operator()(std::string name) {
        std::cout << "House name : " << name << std::endl;
    }

    void operator()(int house_no) {
        std::cout << "House No : " << house_no << std::endl;
    }
};


int main()
{
    std::variant<std::string, int> house;

    house = "Nikhilesh Homes";
    //house = 102;

    //AddressPrinter ap;
    //std::visit(ap, house);

    std::visit([](auto& arg) {
                                using T = std::decay_t<decltype(arg)>;
                                if constexpr (std::is_same_v<T, std::string>) {
                                    std::cout << "House name : " << arg << std::endl;
                                }
                                if constexpr (std::is_same_v<T, int>) {
                                    std::cout << "House No : " << arg << std::endl;
                                }
                             }
    , house);

    return 0;
}