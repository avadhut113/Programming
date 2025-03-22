#pragma once
#include <iostream>
#include <vector>


class Solution1475 {
public:
    //1stApproach using broute force
    static vector<int> finalPrices(vector<int>& prices) {
        std::vector<int> discountedPrice(prices.size(),-1);

        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] <= prices[i]) {
                    discountedPrice[i] = prices[i] - prices[j];
                    break;
                }
            }
            if (discountedPrice[i] == -1)
                discountedPrice[i] = prices[i];
        }
        discountedPrice[prices.size() - 1] = prices[prices.size()-1];
        return discountedPrice;
    }

    //Second Approach using Stack
    static vector<int> finalPrices2(vector<int>& prices) {
        // Create a stack to keep track of indices of prices
        stack<int> indexStack;

        // Initialize the answer vector with the original prices
        vector<int> discountedPrices = prices;

        // Loop through each price
        for (int i = 0; i < prices.size(); ++i) {
            // While stack is not empty and the current price is less than or equal to
            // the price at the top of the stack (indicates a discount is available)
            while (!indexStack.empty() && prices[indexStack.top()] >= prices[i]) {
                // Apply the discount to the price at the top index
                discountedPrices[indexStack.top()] -= prices[i];
                // Pop the index from the stack as the discount has been applied
                indexStack.pop();
            }
            // Push the current index onto the stack
            indexStack.push(i);
        }

        // Return the vector containing final prices after discounts
        return discountedPrices;
    }
};

void test1475()
{
    std::vector<int> prices{ 8,4,6,2,3 };
    for (const auto& res : Solution1475::finalPrices2(prices)) {
        std::cout << res << " ";
    }
    std::cout << "\n";
}