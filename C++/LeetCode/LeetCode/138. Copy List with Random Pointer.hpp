#pragma once
#include <unordered_map>
#include <iostream>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> 
    }
};