#pragma once
#include "ListNode.hpp"
#include <memory>

class Solution203 {
public:
    static ListNode* removeElements(ListNode* head, int val) {


        std::unique_ptr<ListNode> dummyNode(new ListNode());
        dummyNode->next = head;

        // Initialize a pointer that will traverse the list, starting from the dummy node.
        ListNode* current = dummyNode.get();

        // Iterate through the list until the end is reached.
        while (current->next) {
            // Check if the next node's value matches the value to be removed.
            if (current->next->val == val) {
                // If a match is found, skip over the node with the matching value.
                ListNode* del = current->next;
                current->next = current->next->next;
                delete del;
            }
            else {
                // Otherwise, move to the next node.
                current = current->next;
            }
        }

        // Return the next node of dummy as it is the new head of the modified list.
        head = dummyNode->next;
        return head;
    }
};

void test203()
{
    /*ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node61 = new ListNode(6);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node62 = new ListNode(6);
    node1->next = node2; node2->next = node3; node3->next = node61; node61->next = node4; node4->next = node5; 
    node5->next = node62;
    std::cout << Solution203::removeElements(node1, 6);*/

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(1);
    node1->next = node2;
    std::cout << Solution203::removeElements(node1, 1);
}