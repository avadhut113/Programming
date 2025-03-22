// MatriMultiplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix1D.h"
#include"Matrix2D.h"

#include <chrono>
using namespace std::chrono;

void Matrix2D_Mul()
{
    Matrix2D<int> A2(200, 200);
    Matrix2D<int> B2(200, 200);
    Matrix2D<int> res2(200, 200);

    A2.set_all_rand();

    B2.set_all_rand();

    //A2.print();
    std::cout << std::endl;
    //B2.print();
    std::cout << std::endl;

    auto start = high_resolution_clock::now();
    Matrix2D<int>::sequential_multiply(&A2, &B2, &res2);        //Sequential Multiply
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count() << std::endl;
    //res2.print();

    std::cout << std::endl;
    std::cout << std::endl;

    start = high_resolution_clock::now();
    Matrix2D<int>::parallel_multiply(&A2, &B2, &res2);          //Parallel Multiply
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count() << std::endl;
    //res2.print();
}

void Matrix1D_Mul()
{
    //Matrix1D<int> A(3,3);
    //Matrix1D<int> B(3, 3);
    //Matrix1D<int> res(3, 3);

    //A.set_all_rand();

    //B.set_all_rand();

    //A.print();
    //std::cout << std::endl;
    //B.print();
    //std::cout << std::endl;
    //Matrix1D<int>::sequential_multiply(&A, &B, &res);
    //res.print();
}

void Martix1D_Transpose()
{
    Matrix1D<int> A(4, 3);
    Matrix1D<int> res(3, 4);

    A.set_all_rand();
    A.print();

    auto start = high_resolution_clock::now();
    Matrix1D<int>::Sequential_transpose(&A, &res);        //Sequential Multiply
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Sequential Multiply : " << duration.count() << std::endl;
    res.print();

    std::cout << std::endl;
    std::cout << std::endl;

    //start = high_resolution_clock::now();
    //Matrix1D<int>::Parallel_transpose(&A, &res);          //Parallel Multiply
    //stop = high_resolution_clock::now();
    //duration = duration_cast<microseconds>(stop - start);
    //std::cout << duration.count() << std::endl;
    //res2.print();
}

void Martix2D_Transpose()
{
    Matrix2D<int> A(2000, 2000);
    Matrix2D<int> res(2000, 2000);

    A.set_all_rand();
    //A.print();

    auto start = high_resolution_clock::now();
    Matrix2D<int>::Sequential_transpose(&A, &res);        //Sequential Multiply
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Sequential Multiply : " << duration.count() << std::endl;
    //res.print();

    std::cout << std::endl;
    std::cout << std::endl;

    start = high_resolution_clock::now();
    Matrix2D<int>::Parallel_transpose(&A, &res);          //Parallel Multiply
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Parallel Multiply : " << duration.count() << std::endl;
    //res.print();
}

int main()
{

    //Matrix2D_Mul();

    Martix1D_Transpose();
}