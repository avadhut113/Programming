#pragma once


template <typename T>
class my_smart_pointer
{
    T* ptr;
public:
    explicit my_smart_pointer(T* p) :ptr(p) {}

    T* operator->() {
        return ptr;
    }

    T& operator*() {
        return *ptr;
    }

    ~my_smart_pointer() {
        delete[] ptr;
        //ptr = nullptr;
    }
};