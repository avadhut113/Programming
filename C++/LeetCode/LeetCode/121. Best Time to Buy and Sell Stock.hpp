#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Solution121 {
public:
    /*static int maxProfit(vector<int>& prices) {
        unsigned int maxProfit = 0u;

        for (int i = 0; i < prices.size(); i++) {
            int end = prices.size() - 1;
            while (i < end) {
                if (prices[i] < prices[end] && maxProfit < (prices[end] - prices[i])) {
                    maxProfit = prices[end] - prices[i];
                }
                end--;
            }
        }
        return maxProfit;
    }*/

    /*static int maxProfit(vector<int>& prices) {

        if (prices.size() == 0) return 0;

        int ans = 0;

        int start = prices[0], end = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < start) {
                //restart as session
                ans = max(ans, end - start);
                start = prices[i];
                end = prices[i];
            }
            else {
                //continue current session
                end = max(end, prices[i]);
            }
        }
        ans = max(ans, end - start);
        return ans;
    }*/

    static int maxProfit(vector<int>& prices) {
        int valley = INT_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < valley) {
                valley = prices[i];
            }
            else if (prices[i] - valley > ans) {
                ans = prices[i] - valley;
            }
        }
        return ans;
    }
};

void test121()
{
    std::vector<int> prices{ 7,1,5,3,6,4 };
    std::cout << Solution121::maxProfit(prices) << "\n";
}