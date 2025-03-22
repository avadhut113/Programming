// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//struct ContainsIntegers
//{
//    virtual int Get_value() = 0;
//};
//
//struct ManyValues : public ContainsIntegers
//{
//    std::vector<int> values;
//    void add(int value) {
//        values.emplace_back(value);
//    }
//    int Get_value() {
//        int sum{ 0 };
//        for(auto i:values) {
//            sum += i;
//        }
//        return sum;
//    }
//
//};
//
//struct SingleValue : public ContainsIntegers
//{
//    int val;
//    SingleValue(int _val):val{_val}{}
//    int Get_value() { return val; }
//};
//
//int sum(const std::vector<ContainsIntegers*> items)
//{
//    int sumation{ 0 };
//    for (auto item : items) {
//        sumation += item->Get_value();
//    }
//    return sumation;
//}

struct Value
{
    virtual int Get_value() = 0;
};


struct SingleValue : Value
{
    int value{ 0 };

    SingleValue() = default;

    explicit SingleValue(const int value)
        : value{ value }
    {
    }

    int Get_value() { return value; }
};

struct ManyValues : vector<int> , Value
{
    void add(const int value)
    {
        push_back(value);
    }

    int Get_value() {
        int sum{ 0 };
        for (auto i : *this) {
            sum += i;
        }
        return sum;
    }
};

struct ContainsIntegers : Value
{
    vector<Value*> values;
    ContainsIntegers(vector<Value*> _values) : values(_values) {}
};


int sum(const vector<ContainsIntegers*> items)
{
    
}

int main()
{
    SingleValue single_value{ 1 };
    ManyValues other_values;
    other_values.add(2);
    other_values.add(3);
   
    std::cout << sum({ &single_value, &other_values });;
}