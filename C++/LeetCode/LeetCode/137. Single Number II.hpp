#pragma once
#include <vector>
#include <iostream>

class Solution137 {
public:
    static int singleNumber(std::vector<int>& nums) {
        int onlyOnce = 0; // Variable for the element that appears only once
        int twiceState = 0; // Variable for the element that appears twice

        // Iterate over each element in the input vector
        for (int num : nums) {
            // Update `onlyOnce` only if `twiceState` is not set. This is part of tracking
            // the element that appears once. If `twiceState` is set, reset `onlyOnce`.
            int newOnlyOnce = (~onlyOnce & twiceState & num) | (onlyOnce & ~twiceState & ~num);

            // Update `twiceState`: it should be set if `onlyOnce` is not set and `num` is unique (XOR operation).
            // If `num` is already in `onlyOnce`, then it should be cleared.
            int newTwiceState = ~onlyOnce & (twiceState ^ num);

            // Update the states with the newly calculated values
            onlyOnce = newOnlyOnce;
            twiceState = newTwiceState;
        }
        // Since the problem guarantees one number appears exactly once and the others appear exactly three times,
        // the `onlyOnce` variable will end up with the single appearing number. 
        return twiceState; // The element that appears once is found in `twiceState` at the end of the loop

    }
};

void test137()
{
    //std::vector<int> v = { 0,1,0,1,0,1,99 };
    std::vector<int> v = { 2, 2, 3, 2 };

    std::cout << Solution137::singleNumber(v);
}