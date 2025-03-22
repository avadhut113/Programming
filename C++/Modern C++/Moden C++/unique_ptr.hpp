// Type your code here, or load an example.
#include <iostream>
#include <utility>

template <class contained>
class unique_ptr
{
public:
    constexpr unique_ptr() = default;
    constexpr unique_ptr(contained* ptr_) : ptr(std::exchange(ptr_, nullptr)) {}
    constexpr ~unique_ptr() { reset(); }

    constexpr unique_ptr(unique_ptr&& up) : ptr(std::exchange(up.ptr, nullptr)) {}
    constexpr unique_ptr& operator=(unique_ptr&& up) {
        reset();
        ptr = std::exchange(up.ptr, nullptr);
    }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    contained* operator->() { return ptr; }
    contained& operator*() { return *ptr; }
private:
    constexpr void reset() {
        delete ptr;
        ptr = nullptr;
    }

    contained* ptr;
};

constexpr void test_unique_ptr()
{
    unique_ptr<int> ptr(new int(10));
    //std::cout << *ptr << std::endl;
}
#pragma once
