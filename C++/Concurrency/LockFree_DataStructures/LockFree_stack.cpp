// LockFree_stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <atomic>
#include <memory>

template<typename T>
class lock_free_stack
{
private:
    struct Node {
        std::shared_ptr<T> data{nullptr};
        Node* next{ nullptr };

        Node(const T& _data):data(std::make_shared(_data)){}
    };

    std::atomic<Node*> head{nullptr};
public:

    void push(T const& data)
    {
        Node* newnode = new Node(data);

        newnode->next = head.load(std::memory_order_acquire);
        while(!head.compare_exchange_weak(newnode->next, newnode));
    }

    std::shared_ptr<T> pop()
    {
        Node* old_head = head.load();
        while (head && !(head.compare_exchange_weak(old_head, old_head->next)));
        return (old_head ? old_head->data : std::make_shared<T>());
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

