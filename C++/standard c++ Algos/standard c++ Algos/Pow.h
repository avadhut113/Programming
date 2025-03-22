#pragma once

template<int num, int exp>
struct Pow
{
    enum { val = num * Pow<num, exp - 1>::val };
};

template<int num>
struct Pow<num, 0>
{
    enum { val = 1 };
};
