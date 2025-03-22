#include "ListNode.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution82 {
public:
    static ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = head, *fast = head;
        std::deque<ListNode*> deleter;

        while (fast) {
            while (fast && fast->next && fast->val == fast->next->val) {
                deleter.push_back(fast);
                fast = fast->next;
            }

            if (slow->next == fast) {
                slow = slow->next;
            } else {
                if(slow != fast)
                    deleter.push_back(fast);
                slow->next = fast->next;
                fast = fast->next;
            }
        }
        if (!deleter.empty()) {
            for (auto delNode : deleter) {
                delete delNode;
            }
        }
        return dummy->next;
    }
};

void test82()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next = new ListNode(5);

    head = Solution82::deleteDuplicates(head);
    printList(head);
}