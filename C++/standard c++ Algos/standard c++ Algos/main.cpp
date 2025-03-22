// standard c++ Algos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Sentinels.h"
#include "Algorithms.h"
#include "SortAlgos.h"
#include "PartitioningAlgos.h"
#include "Divide_and_Conqure.h"
#include "LinearOperations.h"
#include "SetOperations.h"
#include "TrasformationAlgos.h"
#include "LeftFold.h"
#include "GeneralReductions.h"
#include "Generators.h"
#include "Search_and_Compare.hpp"
#include "Min_Max.h"
#include "Ranges.h"
#include "Views.h"
#include "CRTP.h"
#include "GCD.h"
#include "Pow.h"
#include "Series.h"
using namespace std;

//base case function
void Print()
{
}

//template pack
template <typename T, typename... Params>
//parameter pack
void Print(T&& a, Params&&... args)
{
    std::cout << a;
    if (sizeof...(args) != 0)
        std::cout << ",";
    Print(std::forward<Params>(args)...);
}


class test1
{
    int t{ 10 };
public:

    int get_t() const {
        return t;
    }

    void set_t(const int& _t) {
        t = _t;
    }

};

bool IsPercentDiffGreterThan20(unsigned int Old, unsigned int New);

int main()
{
    //Initialize_data();

    //copy_data(); 

    //mental_model_for_itr();

    //standard_algos();

    //lex_compare();

   // Sorting_algorithms();

    //partitioning_algorithms();

    //divide_and_Conqure();

    //linearOperations();

   // Set_Operations();

    //Trasformation_Algos();

    //left_fold();

    //reduction();

    //generators();

    //search_and_compare();

    //min_max();

    notion_on_ranges();

    projections();

    //views();
    

    /*int SignalStregnthPercentage = 74;
    int newSignalStregnthPercentage = 90;

    std::cout << IsPercentDiffGreterThan20(SignalStregnthPercentage, newSignalStregnthPercentage) << std::endl;*/


    //const test1 T;
    //const test1* t_ptr = &T;

    //const_cast<test1*>(t_ptr)->set_t(20);

    //std::cout << t_ptr->get_t();


    //Print(1, 2.5, 3, "4");

    //static_assert(Sum1toN<5>::sum == 15, "failed");

    //static_assert(Pow<3, 3>::val == 27, "failed");

    ////static_assert(euclid_gcd_temp<36, 60>::result == 12, "failed");

    //static_assert(euclid_gcd_rec(36, 60) == 12, "Failed");

    //PrintOneToN<100>::print();
}

bool IsPercentDiffGreterThan20(unsigned int Old, unsigned int New)
{
    unsigned int fPer{};

    if ((0ul != Old) && (0ul != New))
    {
        int diff = New > Old ? New - Old : Old - New;
        fPer = (diff * 100) / Old ;
    }

    return fPer >= 20;
};
