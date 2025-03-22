// Functional_Decorator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <string>

class logger
{
    std::function<void()> func;
    std::string func_name;
public:
    logger(const std::function<void()> &func, std::string name) : func(func), func_name(name){}

    void operator()()
    {
        std::cout << "Entering " << func_name << std::endl;
        func();
        std::cout << "Exiting " << func_name << std::endl;
    }

};

template<typename Func>
class logger2
{
    Func func;
    std::string func_name;
public:
    logger2(Func& func, std::string name) : func(func), func_name(name) {}

    void operator()()
    {
        std::cout << "Entering " << func_name << std::endl;
        func();
        std::cout << "Exiting " << func_name << std::endl;
    }

};

template<typename Func>
auto make_logger(Func func, const std::string& name)
{
    return logger2<Func>(func, name);
}

template <typename> struct logger3;

template<typename R, typename...Args>
class logger3<R(Args...)>
{
    std::function<R(Args...)> func;
    std::string name;
public:
    logger3(const std::function<R(Args...)>& func, const std::string& name) : func(func), name(name){}

    R operator()(Args ...args) {
        std::cout << "Entering " << name << std::endl;
        R result = func(args...);
        std::cout << "Exiting " << name << std::endl;
        return result;
    }
};

template <typename R , typename... Args>
auto make_logger3(R (*func)(Args...), std::string name) {
    return logger3<R(Args...)>(std::function<R(Args...)>(func), name);
}

double add(double a, double b)
{
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    return a + b;
}

int main()
{
    //logger2([]() { std::cout << "Hello world" << std::endl; }, "Hello function")();
    auto log = make_logger([]() {std::cout << "Hello world" << std::endl; }, "Hello function");
    log();

    auto logged_add = make_logger3(add, "Addition");
    auto result = logged_add(2, 3);
    std::cout << result << std::endl;

}
