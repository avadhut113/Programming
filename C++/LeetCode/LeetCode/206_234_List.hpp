#pragma once
#include "ListNode.hpp"
#include <iostream>
/*
 * definition for singly-linked list.
 */


class List {
public:
    ListNode* head{ nullptr };

    bool isPalindromeUtil(ListNode** left, ListNode* right);
    bool isPalindrome(ListNode* head);
    bool isPalindromeIterative(ListNode* head);

    ListNode* reverseList(ListNode* head);

    ListNode* removeElements(ListNode* head, int val);
};
ListNode* List::removeElements(ListNode* head, int val) {

    if (head == nullptr) return nullptr;
    head->next = removeElements(head->next, val);
    if (head->val == val) {
        ListNode* next = head->next;
        delete head;
        head = nullptr;
        return next;
    }
    return head;
}


ListNode* List::reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

bool List::isPalindromeUtil(ListNode** left, ListNode* right)
{
    /* stop recursion when right becomes NULL */
    if (right == nullptr)
        return true;

    /* If sub-list is not palindrome then no need to
    check for current left and right, return false */
    bool isp = isPalindromeUtil(left, right->next);
    if (isp == false)
        return false;

    /* Check values at current left and right */
    bool isp1 = (right->val == (*left)->val);

    /* Move left to next node */
    *left = (*left)->next;

    return isp1;
}

// A wrapper over isPalindromeUtil()
bool List::isPalindrome(ListNode* head)
{
    return isPalindromeUtil(&head, head);
}

bool List::isPalindromeIterative(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast != nullptr)
        slow = slow->next;
    slow = reverseList(slow);

    while (slow) {
        if (slow->val != head->val)
            return false;
        slow = slow->next;
        head = head->next;
    }

    return true;
}

void test_reverseList()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    List L;
    L.head = node1;
    node1->next = node2; node2->next = node3; node3->next = node4; node4->next = node5;

    L.head = L.reverseList(L.head);
}

void test_PalindromeList()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(2);
    ListNode* node5 = new ListNode(1);

    List L;
    L.head = node1;
    node1->next = node2; node2->next = node3; node3->next = node4; node4->next = node5;
    std::cout << L.isPalindrome(L.head) ? "True" : "False";
}

void test_RemoveElementList()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(6);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(4);
    ListNode* node6 = new ListNode(5);
    ListNode* node7 = new ListNode(6);

    List L;
    L.head = node1;
    node1->next = node2; node2->next = node3; node3->next = node4; node4->next = node5; node5->next = node6; node6->next = node7;
    L.removeElements(L.head, 6);
}

int test()
{
    test_RemoveElementList();
}