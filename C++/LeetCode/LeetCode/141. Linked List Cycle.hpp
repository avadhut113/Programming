#pragma once
#include "ListNode.hpp"

class Solution141 {
public:
    static bool hasCycle(ListNode* head) {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};

void test141()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node61 = new ListNode(6);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node62 = new ListNode(6);
    node1->next = node2; node2->next = node3; node3->next = node61; node61->next = node4; node4->next = node5;
    node5->next = node62; node62->next = node1;
    std::cout << std::boolalpha << Solution141::hasCycle(node1);
}