#pragma once
#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution205 {
public:
    static bool isIsomorphic(string s, string t) {
        vector<int> ms(128, 0), mt(128, 0);

        for (int i = 0; i < s.size(); i++) {
            if (ms[s[i]] != mt[t[i]]) {
                return false;
            }
            ms[s[i]] = i + 1;
            mt[t[i]] = i + 1;
        }

        return true;
    }
};

void test205()
{
    std::cout << std::boolalpha << Solution205::isIsomorphic("egg", "add") << "\n";
    std::cout << std::boolalpha << Solution205::isIsomorphic("foo", "bar") << "\n";
    std::cout << std::boolalpha << Solution205::isIsomorphic("badc", "baba") << "\n";


}