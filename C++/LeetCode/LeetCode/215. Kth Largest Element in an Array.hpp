#pragma once
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution215 {
public:
    static int findKthLargest(vector<int>& nums, int k) {
        //the smaller the earlier to be popped
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        //the smallest in top k elements
        return pq.top();
    }
};

void test215()
{
    std::vector<int> v{ 3,2,3,1,2,4,5,5,6 };
    std::cout << Solution215::findKthLargest(v, 4);
}