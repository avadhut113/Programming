#pragma once
#include <iostream>
#include <string>

using namespace std;

class Solution392 {
public:
    /*static bool isSubsequence(string s, string t) {

        unsigned int i = 0;
        while (i < t.size())
        {
            if (s.empty()) {
                return true;
            }

            if (s[0] == t[i]) {
                s.erase(s.begin());
            }
            i++;
        }
        if (s.empty())
            return true;
        return false;
    }*/

    static bool isSubsequence(string s, string t) {

        if (s.empty())
            return true;

        unsigned int i = 0;
        unsigned int j = 0;
        while (i < t.size())
        {
            if (s[j] == t[i]) {
                j++;
                if (j == s.size() - 1)
                    return true;
            }
            i++;
        }
        return false;
    }
};

void test392()
{
    std::cout << std::boolalpha << Solution392::isSubsequence("acb", "ahbgdc") <<"\n";
}