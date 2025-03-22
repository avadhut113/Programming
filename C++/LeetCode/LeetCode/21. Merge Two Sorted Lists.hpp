// MergeTwoSortedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "ListNode.hpp"
#include <iostream>
#include <assert.h>


 //Definition for singly-linked list.
 
class Solution21 {
public:

    //Not worked.
    //ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    //    if (list1 == nullptr)
    //        return list2;

    //    ListNode* curr1 = list1;
    //    ListNode* curr1Prev = curr1;
    //    ListNode* curr2 = list2;

    //    while (curr1 && curr2) {
    //        if (curr1->val >= curr2->val) {
    //            if (list1 == curr1)
    //                list1 = curr2;

    //            list2 = curr2->next;
    //            curr2->next = curr1;

    //            if(curr1 != curr1Prev)
    //                curr1Prev->next = curr2;

    //            curr1Prev = curr2;
    //            curr2 = list2;
    //        }
    //        else {

    //            if (curr2->next == nullptr) {
    //                curr2->next = curr1->next;
    //                curr1->next = curr2;
    //                curr2 = nullptr;
    //            }

    //            curr1Prev = curr1;
    //            curr1 = curr1->next;
    //        }
    //    }
    //    return list1;
    //}

    void MoveNode(ListNode** destRef, ListNode** sourceRef)
    {
        ListNode* newNode = *sourceRef;
        assert(newNode != NULL);

        *sourceRef = newNode->next;

        newNode->next = *destRef;

        *destRef = newNode;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* result = NULL;

        ListNode** lastPtrRef = &result;

        while (1) {
            if (list1 == NULL) {
                *lastPtrRef = list2;
                break;
            }
            else if (list2 == NULL) {
                *lastPtrRef = list1;
                break;
            }
            if (list1->val <= list2->val)
                MoveNode(lastPtrRef, &list1);
            else
                MoveNode(lastPtrRef, &list2);

            lastPtrRef = &((*lastPtrRef)->next);
        }
        return (result);
    }

};

int test()
{
    //ListNode node11(1), node12(9), node13(9), node14(9), node15(9), node16(9), node17(9), node18(9), node19(9), node20(9);
    //ListNode node21(9);

    //ListNode* root1, * root2;

    //root1 = &node11; node11.next = &node12; node12.next = &node13; node13.next = &node14; node14.next = &node15;
    //node15.next = &node16; node16.next = &node17; node17.next = &node18; node18.next = &node19; node19.next = &node20;

    //root2 = &node21;

    //ListNode node11(1), node12(2), node13(4);
    //ListNode node21(1), node22(3), node23(4);

    //ListNode* root1, * root2;

    //root1 = &node11; node11.next = &node12; node12.next = &node13; 

    //root2 = &node21; node21.next = &node22; node22.next = &node23;

    ListNode node11(1);
    ListNode node21(2);

    ListNode* root1, * root2;

    root1 = &node11;

    root2 = &node21;

    Solution21 sl;
    sl.mergeTwoLists(root1, root2);
}
