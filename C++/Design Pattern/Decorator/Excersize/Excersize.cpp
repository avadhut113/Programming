// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Flower
{
    virtual string str() = 0;
};

struct Rose : Flower
{
    string str() override {
        std::ostringstream oss{};
        oss << "A rose";
        return oss.str();
    }
};

struct RedFlower : Flower
{
    Flower& flower;
    RedFlower(Flower& _flower):flower(_flower){}
    string str() override;
};

struct BlueFlower : Flower
{
    Flower& flower;
    BlueFlower(Flower& _flower) :flower(_flower) {}
    string str() override;
};

string RedFlower::str()
{
    std::ostringstream oss{};
    if (dynamic_cast<BlueFlower*>(&flower)) {
        oss << flower.str() << " and red";
    }
    else {
        oss << flower.str() << " that is red";
    }
    return oss.str();
}

string BlueFlower :: str() {
    std::ostringstream oss{};
    if (dynamic_cast<RedFlower*>(&flower)) {
        oss << flower.str() << " and blue";
    }
    else {
        oss << flower.str() << " that is blue";
    }
    return oss.str();
}





int main()
{
    Rose rose;
    RedFlower red_rose{ rose };
    RedFlower red_red_rose{ red_rose };
    BlueFlower blue_red_rose{ red_rose };
    BlueFlower blue{ rose };
    //RedFlower red{ blue{red_rose{rose{}}} }
    cout << rose.str();          // "A rose"
    cout << red_rose.str();      // "A rose that is red"
    cout << red_red_rose.str();  // "A rose that is red"
    cout << blue_red_rose.str(); // "A rose that is red and blue"
}
