#pragma once
#include <queue>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};



class Solution117 {
public:
    static Node* connect(Node* root) {
        if (!root) return root;

        std::queue<Node*> q;

        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();

            Node* prev = nullptr;

            while (level_size-- > 0) {
                Node* cur = q.front(); q.pop();

                if (prev) prev->next = cur;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);

                prev = cur;
            }
        }

        return root;
    }
};

void test117()
{
    Node* root = new Node(); root->val = 1;
    Node* root1 = new Node(); root1->val = 2;
    Node* root2 = new Node(); root2->val = 3;
    Node* root11 = new Node(); root11->val = 4;
    Node* root12 = new Node(); root12->val = 5;
    Node* root22 = new Node(); root22->val = 7;
    root->left = root1; root->right = root2;
    root1->left = root11; root1->right = root12;
    root2->right = root22;

    root = Solution117::connect(root);
}
