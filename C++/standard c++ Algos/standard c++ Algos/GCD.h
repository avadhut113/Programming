#pragma once

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}


consteval int euclid_gcd_rec(int a, int b)
{
    if (b == 0)
        return a;
    else
        return euclid_gcd_rec(b, a % b);
}





template<size_t M, size_t N>
struct euclid_gcd_meta_temp
{
    static constexpr size_t R = (N == 0) ? 0 : (M % N);
    static constexpr size_t result = (R == 0) ? N : euclid_gcd_meta_temp<N, R>::result;
};

template<size_t M>
struct euclid_gcd_meta_temp<M, 0>
{
    static constexpr size_t result = M;
};

template<size_t N>
struct euclid_gcd_meta_temp<0, N>
{
    static constexpr size_t result = 0;
};

template<>
struct euclid_gcd_meta_temp<0, 0>
{
    static constexpr size_t result = 0;
};

template<size_t M, size_t N>
struct euclid_gcd_temp
{
    static constexpr size_t value1 = (M > N) ? M : N;
    static constexpr size_t value2 = (M == value1) ? N : M;
    static constexpr size_t result = euclid_gcd_meta_temp<value1, value2>::result;
};