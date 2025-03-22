// BSTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Tree.h"

using namespace std;

class Test
{
    string name;
public:
    Test() {}
    Test(string name_) : name(name_) {}

    friend ostream& operator<<(ostream& os, Test& t)
    {
        os << t.name;

        return os;
    }

    bool operator<(Test t);
    bool operator<=(Test t);
    bool operator>(Test t);
};

bool Test::operator<(Test t)
{
    return (name < t.name);
}

bool Test::operator<=(Test t)
{
    return (name <= t.name);
}

bool Test::operator>(Test t)
{
    return (name > t.name);
}

void TestBST()
{
    Tree<int> tr;

    /*
                           4
                        /      \
                       1        6
                     /  \      /  \
                    0    2     5   9
                                     \
                                     89
                                    /  \
                                   12   222
                                     \
                                     32
                                    /
                                   22
    */

    tr.add(4);
    tr.add(6);
    tr.add(1);
    tr.add(9);
    tr.add(2);
    tr.add(0);
    tr.add(89);
    tr.add(12);
    tr.add(32);
    tr.add(5);
    tr.add(22);
    tr.add(222);


    //  tr.test();

    tr.showFirst();
    cout << endl;
    tr.showLast();
    cout << endl;

    Tree<string> bst;

    bst.add("Zanildo");
    bst.add("Helder");
    bst.add("Wilson");
    bst.add("Ady");
    bst.add("Adilson");
    bst.add("Patrick");


    bst.showFirst();
    cout << endl;
    bst.showLast();
    cout << endl;

    Tree<Test> test;

    test.add({ "Jhonny" });
    test.add({ "Bruno" });
    test.add({ "Garry" });
    test.add({ "Henry" });
    test.add({ "Amber" });
    test.add({ "Brandy" });
    test.add({ "Danny" });
    test.add({ "Cameron" });
    test.add({ "Edla" });
    test.add({ "Zenalda" });

    test.showFirst();
    cout << endl;
    test.showLast();
    cout << endl;

    //test.print();
}