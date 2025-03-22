// RomanToInt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution13 {
public:
    static int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {

            switch (s[i]) {
            case 'I': 
                if (s[i + 1] == 'V') {
                    num += 4; i++;
                }else if (s[i + 1] == 'X') {
                    num += 9; i++;
                }
                else {
                    num += 1;
                }                 
                break;
            case 'L':
                num += 50;
                break;
            case 'V' :
                num += 5;
                break;
            case 'X' :
                if (s[i + 1] == 'L') {
                    num += 40; i++;
                }
                else if (s[i + 1] == 'C') {
                    num += 90; i++;
                }
                else {
                    num += 10;
                }
                break;          
            case 'C':
                if (s[i + 1] == 'D') {
                    num += 400; i++;
                }
                else if (s[i + 1] == 'M') {
                    num += 900; i++;
                }
                else {
                    num += 100;
                }
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
            } 
        }
        return num;
    }
};

int test13()
{
    std::cout << Solution13::romanToInt("MCMXCIV") << std::endl;
}
