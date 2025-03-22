#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution12 {
public:
    static string intToRoman(int num) {
        // if number in these minus continuously
        // if not try next => in end all 1's will be added to make remaining num
        vector<string> s = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        vector<int> n = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        string ans = "";
        while (num != 0) {
            for (int i = 0; i < n.size(); i++) {
                while (num >= n[i]) {
                    num -= n[i];
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};
void test_12()
{
    std::cout << Solution12::intToRoman(3749) << std::endl;
    std::cout << Solution12::intToRoman(58) << std::endl;
    std::cout << Solution12::intToRoman(1994) << std::endl;
}
