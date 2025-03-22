#pragma once
#include <vector>
#include <string>

using namespace std;

//Backtracking approach

/*
class Solution17 {
public:
    std::vector<string> digit2letters{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    std::vector<string> ans;

    void backtrack(string& comb, string next_digits) {
        if (next_digits.empty()) {
            ans.push_back(comb);
        }
        else {
            for (const char& c : digit2letters[next_digits[0] - '0']) {
                comb += c;
                backtrack(comb, next_digits.substr(1));
                comb.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();

        string comb = "";
        backtrack(comb, digits);

        return ans;
    }
};
*/

class Solution17 {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();

        std::vector<string> digit2letters{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

        vector<string> ans = { "" };

        for (const char& c : digits) {
            int d = c - '0';
            vector<string> olds = ans;
            ans.clear();
            for (const string& old : olds) {
                for (const char& c : digit2letters[d]) {
                    ans.push_back(old + c);
                }
            }
        }

        return ans;
    }
};


void test17()
{
    Solution17 sl;
    std::string digit("234");
    std::vector<string> ans = sl.letterCombinations(digit);
}