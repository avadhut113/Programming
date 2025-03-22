// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "ListNode.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    //    //ListNode* resultList = nullptr;
    //    ////ListNode* currNode = nullptr;

    //    //long long rev1 = returnRevNum(l1, 0);
    //    //long long rev2 = returnRevNum(l2, 0);

    //    //long long int result = rev1 + rev2;

    //    //resultList = NumToList(result);

    //    ///*ListNode* currNode = nullptr;

    //    //while (result > 0) {
    //    //    int reminder = result % 10;
    //    //    listnode node(reminder);

    //    //    if (currnode != nullptr)
    //    //        currnode->next = &node;

    //    //    currnode = &node;
    //    //    result /= 10;
    //    //}*/

    //    //return resultList;


    //    ListNode* res = new ListNode(-1); //res=result to represent another list for result.
    //    ListNode* curr = res; //curr=current to loop over the result list.
    //    int carry = 0;
    //    while (l1 || l2)
    //    {
    //        int n1 = l1 ? l1->val : 0; //n1=pointing to l1 to check null or not.
    //        int n2 = l2 ? l2->val : 0; //n2=pointing to l2 to check null or not.
    //        int sum = n1 + n2 + carry;
    //        carry = sum / 10;
    //        curr->next = new ListNode(sum % 10);
    //        curr = curr->next;

    //        if (l1)
    //            l1 = l1->next;

    //        if (l2)
    //            l2 = l2->next;
    //    }
    //    if (carry)
    //        curr->next = new ListNode(1);   //if carry>0 then put carry at new created last node.

    //    return res->next;
    //

    //}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


        ListNode* res = new ListNode(-1);
        ListNode* curr = res;
        int carry = 0;
        while (l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1)
                l1 = l1->next;

            if (l2)
                l2 = l2->next;
        }
        if (carry)
            curr->next = new ListNode(1);

        return res->next;


    }

    ListNode* NumToList(long long int number)
    {
        ListNode* mainHead = new ListNode();
        int remainder = number % 10;
        mainHead->val = remainder;
        number = number / 10;
        ListNode* head;
        head = mainHead;
        while (number != 0) {
            ListNode* nextNode = new ListNode();
            int remainder = number % 10;
            nextNode->val = remainder;
            head->next = nextNode;
            head = nextNode;
            number = number / 10;
        }
        return mainHead;
    }

    long long returnRevNum(ListNode* list, long long int res)
    {

        if (list != nullptr) {
            res = returnRevNum(list->next, res);
            res = res * 10 + list->val;
        }
        return res;
    }
};

int test()
{
    //ListNode node11(9), node12(9), node13(9), node14(9), node15(9), node16(9), node17(9);
    //ListNode node21(9), node22(9), node23(9), node24(9);

    ListNode node11(1), node12(9), node13(9), node14(9), node15(9), node16(9), node17(9), node18(9), node19(9), node20(9);
    ListNode node21(9);

    ListNode* root1, *root2, *root3;

    root1 = &node11; node11.next = &node12; node12.next = &node13; node13.next = &node14; node14.next = &node15;
    node15.next = &node16; node16.next = &node17; node17.next = &node18; node18.next = &node19; node19.next = &node20;
    
    
    
    root2 = &node21;

    Solution sl;

    //int res1 = sl.returnRevNum(root1, 0);

    //int res2 = sl.returnRevNum(root2, 0);

    root3 = sl.addTwoNumbers(root1, root2);
}
