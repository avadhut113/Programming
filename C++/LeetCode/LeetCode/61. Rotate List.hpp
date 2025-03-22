#include "ListNode.hpp"

class Solution61 {
public:
    static ListNode* rotateRight(ListNode* head, int k) {
        int len{ 0 };
        for (ListNode* curr = head; curr; curr = curr->next) ++len;
        k %= len;
        if (len <= 1 || k == 0)
            return head;

        ListNode* slow = head, * fast = head;
        for (int i = 0; i < k; ++i) 
            fast = fast->next;

        while (slow->next && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* newHead = slow->next;
        fast->next = head;
        slow->next = nullptr;

        return newHead;
    }
};

void test61()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    printList(Solution61::rotateRight(head, 2));
}