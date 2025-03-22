#pragma once
#include <vector>
#include <iostream>
#include <string>



using namespace std;

class Solution_1002 {
public:

    vector<string> commonChars(vector<string>& words) {
        constexpr int MAX = 26;
        int arr_char[MAX] = {0};
        vector<string> res;

        for (auto& word : words) {
            for (auto& latter : word) {
                arr_char[latter - 97]++;
            }
        }

        for (int index = 0; index < MAX; index++) {
            int reaptation = arr_char[index] / words.size();
            for (int i = 0; i < reaptation; i++) {
                /*std::string str; 
                str = char(97 + index);*/

                char ch = 'a'; // Example char       
                res.push_back(std::string(1, char(97 + index)));
            }
                
        }
        return res;
    }
};

void test_1002()
{
    Solution_1002 sl;
    std::vector<std::string> str{ "bella","label","roller" };
    sl.commonChars(str);
}