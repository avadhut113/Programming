// 67 Add Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    string res = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry != 0) {
        if (i >= 0) {
            carry += a[i] == '0' ? 0 : 1;
            i--;
        }
        if (j >= 0) {
            carry += b[j] == '0' ? 0 : 1;
            j--;
        }

        res = ((carry % 2) == 0 ? "0" : "1") + res;
        carry /= 2;
    }

    return res;
}

/*string addBinary(string a, string b) {
    int N = max(a.size(), b.size()) + 1;

    //padding
    a.insert(a.begin(), N - a.size(), '0');
    b.insert(b.begin(), N - b.size(), '0');
    // cout << a << endl;
    // cout << b << endl;
    //now we can iterate from i = 0
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // cout << a << endl;
    // cout << b << endl;

    int i = 0, carry = 0;
    //add b to a
    for (int i = 0; i < N; i++) {
        int ai = a[i] - '0', bi = b[i] - '0';
        int sumi = ai + bi + carry;
        switch (sumi) {
        case 3:
            a[i] = '1';
            carry = 1;
            break;
        case 2:
            a[i] = '0';
            carry = 1;
            break;
        case 1:
            a[i] = '1';
            carry = 0;
            break;
        }
    }
    // cout << a << endl;
    // cout << b << endl;

    if (a[N - 1] == '0') a.resize(N - 1);
    reverse(a.begin(), a.end());
    return a;
}*/

int test()
{
    addBinary("11","1");
}
