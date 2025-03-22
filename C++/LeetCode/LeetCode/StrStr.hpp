// StrStr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle == "")
            return 0;

        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                for (int j = 0; j < needle.size(); j++) {
                    if (haystack[i+j] != needle[j])
                        break;
                    
                    if (j == needle.length() - 1)
                        return i;
                }
            }   
        }
        return -1;
    }
};

int test()
{
    Solution sl;
    cout << sl.strStr("abssabc", "abc");
}
