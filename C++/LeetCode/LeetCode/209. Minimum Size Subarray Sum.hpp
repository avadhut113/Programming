#include <iostream>
#include <vector>

using namespace std;

class Solution209 {
public:
    static int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();             
        long long sum = 0;               
        int ans = n + 1;                 

        for (int i = 0, j = 0; i < n; ++i) {
            sum += nums[i];               

            while (j < n && sum >= target) {
                ans = min(ans, i - j + 1); 
                sum -= nums[j++];          
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};

void test209()
{
    vector<int> v = { 2,3,1,2,4,3 };
    Solution209::minSubArrayLen(7,v);
}