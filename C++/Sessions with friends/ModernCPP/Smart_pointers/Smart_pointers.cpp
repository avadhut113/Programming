// Smart_pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.

//Works on RAII
//We dont need to take care of de-allocation
//Smart pointer instance will create on stack and actual mem-alloc is on heap.
//Basically it is wrapper over raw pointer

//----valid - usecase----
//1.You must have to intialize smart pointers using provided constructor or may be using make_shared/make_unique like methods
//2.When you start maintaining raw pointer using smart pointer then your raw pointer should not be available for use independently. other wise
//  it will cause undefined behaviour. In other words, in such situation your smart pointer will not treat as "smart".
//3.Although your using smart pointer, it will support only a single instance of core/user defined data types. 
//  i.e. using smart pointer with array is constly(It will occupying extra mem to maintain extra smart pointer).

//https://stackoverflow.com/questions/22834812/clarification-on-smart-pointers-operator-and-operator-overloading


#include <iostream>
#include "my_smart_pointer.h"
#include "my_unique_pointer.h"
#include "my_shared_ptr.h"


class test
{

public:
    int x = 10;
    test() {
        std::cout << "Test::test" << std::endl;
    }

    void  print() {
        std::cout << "Test::print  x=" << x << std::endl;
    }
    ~test() {
        std::cout << "Test::~test" << std::endl;
    }
};

#include <memory>


void usecase_copy_ctor()
{
    std::shared_ptr<int> sp1(new int);
    std::shared_ptr<int> sp2(new int);

    std::shared_ptr<int> sp3(sp1);
    std::shared_ptr<int> sp4(sp3);
}

void our_usecase_copy_ctor()
{
    my_shared_pointer<test> sp1(new test);
    my_shared_pointer<test> sp2(new test);

    my_shared_pointer<test> sp3(sp1);
    my_shared_pointer<test> sp4(sp3);

    my_shared_pointer<test> sp5(std::move(sp1));
    //my_shared_pointer<test> sp3(sp1);

}

void our_usecase_copy_assignment()
{
    my_shared_pointer<test> sp1(new test);
    my_shared_pointer<test> sp2(new test);

    my_shared_pointer<test> sp3(sp1);
    my_shared_pointer<test> sp4(sp3);

    sp2 = sp1;
    sp3 = sp1;
    sp4 = sp3;
}

void usecase_move_ctor()
{
    std::shared_ptr<int> sp1(new int);
    std::shared_ptr<int> sp11(sp1);
    std::shared_ptr<int> sp2(std::move(sp1));

    std::shared_ptr<int> sp3(sp1);
}

void our_usecase_move_ctor()
{
    my_shared_pointer<test> sp1(new test);
    my_shared_pointer<test> sp2(std::move(sp1));

    //my_shared_pointer<test> sp4(new test);
}

void usecase_move_assign()
{
    std::shared_ptr<test> sp1(new test);
    //std::shared_ptr<test> sp2(sp1);
    std::shared_ptr<test> sp3(sp1);
    std::shared_ptr<test> sp4(new test);
    std::shared_ptr<test> sp5(new test);
    std::shared_ptr<test> sp6(sp5);


    //sp5 = std::move(sp4);
    //sp4 = std::move(sp1);
    //sp2 = std::move(sp4);   //
    //sp1 = std::move(sp1);
    sp3 = std::move(sp1);   //move empty  
}

void our_usecase_move_assign()
{
    my_shared_pointer<test> sp1(new test);
    my_shared_pointer<test> sp2(sp1);
    my_shared_pointer<test> sp3(sp1);
    my_shared_pointer<test> sp4(new test);
    my_shared_pointer<test> sp5(new test);
    my_shared_pointer<test> sp6(sp5);


    sp5 = std::move(sp4);
    sp4 = std::move(sp1);
    //sp2 = std::move(sp4);   //
    //sp1 = std::move(sp1);
    //sp3 = std::move(sp1);   //move empty  
}

void func(std::unique_ptr<test[]> sp)
{

}

template<typename X, typename Y>
void func2(X x, Y y)
{

}

//int main()
//{
//    //our_usecase_copy_ctor();
//    //our_usecase_copy_assignment();
//    //usecase_move_ctor();
//    //our_usecase_move_ctor();
//    //our_usecase_move_assign();
//
//    /*{
//        my_smart_pointer<test> my_sp2(new test[5]);
//        (*my_sp2).x = 1;
//
//        ((my_sp2.operator->()) + 1)->x = 3;
//    }*/
//
//
//    //my_unique_pointer<test> up(new test());
//
//   // my_unique_pointer<test> up1(my_unique_pointer<test>());
//
//    /*(*my_sp2).x = 20;
//    my_sp2->print();*/
//
//    //(*up).x = 30;
//    //up->print();
//
//    //my_unique_ptr2<int> sp11;
//
//    std::unique_ptr<test[]> sp(new test[5]/*, [](test* p) {delete[] p; }*/);
//    func(std::move(sp));
//
//    std::unique_ptr<test> sp1(new test/*, [](test* p) {delete[] p; }*/);
//
//    func2<int, int>(1,3);
//
//    std::shared_ptr<int> sp11(new int(5));
//    std::shared_ptr<char> sp12(new char('c'));
//
//    //sp12 = std::shared_ptr<char>(new char('c'));
//
//    my_unique_pointer<test> up11(new test);
//    my_unique_pointer<test> up12(new test);
//
//    up11 = std::move(up12);
//}



int main()
{

}