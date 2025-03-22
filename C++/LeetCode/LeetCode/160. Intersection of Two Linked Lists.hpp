#pragma once
#include "ListNode.hpp"
#include <stack>


class Solution160 {
public:
    static ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        std::stack<ListNode*> stackA, stackB;

        ListNode* itr = headA;
        while (itr) {
            stackA.emplace(itr);
            itr = itr->next;
        }

        itr = headB;
        while (itr) {
            stackB.emplace(itr);
            itr = itr->next;
        }

        while (!stackA.empty() && !stackB.empty() && (stackA.top() == stackB.top())) {
            itr = stackA.top();
            stackA.pop();
            stackB.pop();
        }
        return itr;
    }
};

void test160()
{
    ListNode* nodea1 = new ListNode(1);
    ListNode* nodea2 = new ListNode(2);
    nodea1->next = nodea2;

    ListNode* nodeb1 = new ListNode(1);
    ListNode* nodeb2 = new ListNode(2);
    ListNode* nodeb3 = new ListNode(3);
    nodeb1->next = nodeb2; nodeb2->next = nodeb3;

    ListNode* nodec1 = new ListNode(66);
    ListNode* nodec2 = new ListNode(2);
    ListNode* nodec3 = new ListNode(3);
    nodec1->next = nodec2; nodec2->next = nodec3;

    nodea2->next = nodec1;
    nodeb3->next = nodec1;

    ListNode* ll1 = nodea1;
    ListNode* ll2 = nodea1;

    std::cout << Solution160::getIntersectionNode(ll1, ll2)->val;
}