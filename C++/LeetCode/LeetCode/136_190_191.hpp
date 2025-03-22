#pragma once
#include <iostream>

using namespace std;

class Solution136_190_191 {
public:
    static uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;
        int d = 0;
        while (n > 0) {
            // cout << d << " " << n << endl;
            x += (n % 2) << (31 - d);
            n >>= 1;
            d++;
        }
        return x;
    }

    static int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n > 0) {
            if (n & 1 == 1) {
                ans++;
                // cout << ans << endl;
            }
            n >>= 1;
        }
        return ans;
    }

    static int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }

};

void test_136_190_191()
{
    vector<int> v{ 1,2,1,2,4,3,4,3,4 };
    //std::cout << Solution190::reverseBits(43261596);
    Solution136_190_191::singleNumber(v);
}