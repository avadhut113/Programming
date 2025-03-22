// 66_PlusOne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int i = digits.size() - 1;
    int c = 1;
    while (i >= 0) {
        digits[i] += c;
        c = digits[i] / 10;
        digits[i] %= 10;
        i--;
    }
    if (c > 0) digits.insert(digits.begin(), c);
    return digits;
}

void printVector(vector<int>& v)
{
    cout << "{ ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "} " << endl;
}

int test()
{
    int a[] = { 9,9,9 };
    vector<int> d(&a[0], &a[0] + sizeof(a) / sizeof(int));
    vector<int> v = plusOne(d);
    printVector(v);
    return 0;
}
