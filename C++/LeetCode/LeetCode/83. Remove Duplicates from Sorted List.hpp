// 83. Remove Duplicates from Sorted List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* delNode = head;

        while (temp) {

            while (temp->next && (temp->val == temp->next->val)) {
                temp->next = temp->next->next;
            }

            if(temp)
                temp = temp->next;
        }
        return head;
    }
};

int test()
{
    ListNode* root1;
    ListNode node11(1), node12(9), node13(9), node14(9), node15(9), node16(9), node17(9), node18(9), node19(9), node20(9);
    root1 = &node11; node11.next = &node12; node12.next = &node13; node13.next = &node14; node14.next = &node15;
    node15.next = &node16; node16.next = &node17; node17.next = &node18; node18.next = &node19; node19.next = &node20;

    ListNode* root2;
    ListNode node21(1), node22(1), node23(2), node24(3), node25(3);
    root2 = &node21; node21.next = &node22; node22.next = &node23; node23.next = &node24; node24.next = &node25;

    Solution sl;
    root1 = sl.deleteDuplicates(root1);

    root2 = sl.deleteDuplicates(root2);
}
