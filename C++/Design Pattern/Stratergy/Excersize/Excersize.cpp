// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct DiscriminantStrategy
{
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    // todo
    virtual double calculate_discriminant(double a, double b, double c)
    {
        return b * b - 4 * a * c;
    }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
    // todo
    virtual double calculate_discriminant(double a, double b, double c)
    {
        double descriminant = b * b - 4 * a * c;
        if (descriminant < 0) {
            return NAN;
        }
        return descriminant;
    }
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver(DiscriminantStrategy& strategy) : strategy(strategy) {}

    tuple<complex<double>, complex<double>> solve(double a, double b, double c)
    {
        complex<double> real, imaginary;
        double discriminant = strategy.calculate_discriminant(a, b, c);
        if (discriminant > 0) {
            real = (-b + sqrt(discriminant)) / (2 * a);
            imaginary = (-b - sqrt(discriminant)) / (2 * a);
        }
        else if (discriminant == 0) {
            real = imaginary = (-b + sqrt(discriminant)) / (2 * a);
        }
        else {
            real = -b / (2 * a);
            imaginary = sqrt(discriminant) / (2 * a);
        }
        return { real,imaginary };
    }
};

int main()
{
    OrdinaryDiscriminantStrategy ods;
    RealDiscriminantStrategy rds;

    QuadraticEquationSolver qes1(ods);
    QuadraticEquationSolver qes2(rds);

    tuple<complex<double>, complex<double>> eq;
    eq = qes1.solve(1, 10, 16);
    eq = qes1.solve(1, 4, 5);

    tuple<complex<double>, complex<double>> eq2;
    eq2 = qes1.solve(1, 10, 16);
    eq2 = qes2.solve(1, 4, 5);

}

