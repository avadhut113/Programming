#pragma once
#include <iostream>
#include "ListNode.hpp"
using namespace std;

class Solution2 {
public:
     static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);
        ListNode* curr = preHead;
        int carry = 0;
        while (l1 || l2) {

            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;

            int sum = num1 + num2 + carry;
            carry = sum/10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry)
            curr->next = new ListNode(carry);

        return preHead->next;
    }
};

void test2()
{
    ListNode* l1 = new ListNode(2); l1->next = new ListNode(4); l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5); l2->next = new ListNode(6); l2->next->next = new ListNode(4);
    Solution2::addTwoNumbers(l1, l2);
}