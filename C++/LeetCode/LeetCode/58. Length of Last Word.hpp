// LengthOfLastWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    string::const_iterator itr = s.end() - 1;

    int length = 0;

    if (s.length() == 1 && *itr != ' ')
        return 1;

    while (*itr == ' ') {
        itr--;
    }

    while (*itr != ' ')
    {
        itr--;
        length++;
    }
    return length;
}

int test()
{
   cout << lengthOfLastWord("l");
}
