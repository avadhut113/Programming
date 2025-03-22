#pragma once
#include <iostream>

template <class Derived>
class Employee
{
public:
    Employee() = default;
    Derived& getDerived() { return static_cast<Derived&>(*this); }
    void printSalary() { getDerived().printSalary(); }
    ~Employee() = default;
};

class Engineer :public Employee<Engineer>
{
public:
    void printSalary() { std::cout << "Enginneers salary = 10K$ "; }
};

template <typename T>
void printSalary(Employee<T>& e)
{
    e.printSalary();
}

class test
{
    //static const auto a;
public:
    test* fun1() { return this; }
    test& fun2() { return *this; }
    void fun3() {}
};