#pragma once
#include "ListNode.hpp"
#include <set>


//Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class Solution148 {
public:
    static ListNode* sortList(ListNode* head) {
        if (!head) return head;
        std::multiset<int> Set;
        ListNode* cur = head;

        while (cur) {
            Set.emplace(cur->val);
            cur = cur->next;
        }

        cur = head;
        int i = 0;
        auto itr = Set.begin();
        while (cur) {
            cur->val = *itr;
            itr++;
            cur = cur->next;
        }

        return head;
    }
};

void test_148()
{
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);
    ListNode* node4 = new ListNode(3);
    //ListNode* node5 = new ListNode(3);

    ListNode* ll1 = node1; node1->next = node2; node2->next = node3; node3->next = node4; /*node4->next = node5;*/

    ll1 = Solution148::sortList(ll1);
}
