// LongestSubStr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        int longSubStrlen = 0;
        
        for (int j = 0; j < s.length(); j++) {
            string subStr;
            int currLen = 0;
            for (int i = j; i < s.length(); i++) {
                
                if (subStr.find(s[i]) == std::string::npos) {
                    subStr.push_back(s[i]);
                    currLen++;
                }
                else 
                    break;
            }

            if (longSubStrlen < currLen)
                longSubStrlen = currLen;
        }
        return longSubStrlen;
    }
};

int test3()
{
    Solution3 sl;

    cout << sl.lengthOfLongestSubstring(" ") << endl;

    cout << sl.lengthOfLongestSubstring("abcabcbb") << endl;

    cout << sl.lengthOfLongestSubstring("bbbbb") << endl;

    cout << sl.lengthOfLongestSubstring("pwwkew") << endl;

}
