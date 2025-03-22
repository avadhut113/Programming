#pragma once
#include "ListNode.hpp"
#include <set>
#include <vector>
#include <string_view>

class Solution23 {
public:
    /*static ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::multiset<int> Set;
        for (auto node : lists) {
            while (node) {
                Set.emplace(node->val);
                node = node->next;
            }
        }
        auto itr = Set.begin();
        ListNode* head = new ListNode(*itr);
        itr++;
        ListNode* curr = head;
        while (itr != Set.end()) {
            curr->next = new ListNode(*itr);
            curr = curr->next;
            itr++;
        }
        return head;
    }*/

    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    };

    static ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;

        for (int i = 0; i < lists.size(); ++i) {
            head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }
};


void test23()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(5);
    ListNode* ll1 = node1; node1->next = node2; node2->next = node3;

    ListNode* node11 = new ListNode(1);
    ListNode* node12 = new ListNode(3);
    ListNode* node13 = new ListNode(4);
    ListNode* ll2 = node11; node11->next = node12; node12->next = node13;

    ListNode* node21 = new ListNode(2);
    ListNode* node22 = new ListNode(6);
    ListNode* ll3 = node21; node21->next = node22;

    std::vector<ListNode*> vect{ ll1,ll2,ll3 };

    ListNode* head = Solution23::mergeKLists(vect);
}