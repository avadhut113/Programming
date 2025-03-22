#pragma once
#include"ListNode.hpp"
#include <vector>

//Definition for singly-linked list.


class Solution1290 {
public:
    static int getDecimalValue(ListNode* head) {
        if (nullptr == head || (head->val == 0 && head->next == nullptr))
            return 0;

        int result = 0;
        while (head) {
            result = (result << 1) | head->val;
            head = head->next;
        }
        return result;
    }
};

void test1290()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(1);
    node1->next = node2; node2->next = node3;
    std::cout << Solution1290::getDecimalValue(node1);
}