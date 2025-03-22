#pragma once
#include <iostream>

template <typename T>
struct default_delete
{
    default_delete() = default;
    default_delete(const default_delete&) = default;
    
    template<typename U>
    default_delete(const default_delete<U>& other) {}

    void operator()(T* contained) {
        delete contained;
        contained = nullptr;
    }
};

template <typename T, typename deleter = default_delete<T>>
class my_unique_pointer
{
    T* ptr{nullptr};
    deleter custom_deleter = deleter();

public:
    explicit my_unique_pointer(T* p) :ptr(p) {
    }

    my_unique_pointer(const my_unique_pointer& up) = delete;
    my_unique_pointer& operator=(const my_unique_pointer& up) = delete;

    my_unique_pointer(const my_unique_pointer&& right) noexcept {
        std::cout << "my_unique_pointer(const my_unique_pointer&& right)" << std::endl;
        ptr = right.ptr;
        custom_deleter = right.custom_deleter;
        right.ptr = nullptr;
    }

    // generalized move ctor
    template <typename U, typename E>
    my_unique_pointer(my_unique_pointer<U, E>&& other) noexcept
        : ptr(other.release()), custom_deleter(std::forward<E>(other.get_deleter())) {}

    my_unique_pointer& operator=(my_unique_pointer&& right) noexcept {
        std::cout << "my_unique_pointer& operator=(const my_unique_pointer&& right)" << std::endl;
        if (&right != this) {
            //unique_ptr(std::move(other)).swap(*this);
            delete ptr;
            ptr = right.ptr;
            custom_deleter = right.custom_deleter;
            right.ptr = nullptr;    
        }
        return *this;
    }

    void reset(T* p) noexcept {
        custom_deleter(ptr);
        ptr = p;
    }

    T* release() noexcept {
        auto old_ptr = ptr;
        ptr = nullptr;
        return old_ptr;
    }

    void swap(my_unique_pointer& other) noexcept {
        using std::swap;
        swap(ptr, other.ptr);
    }

    T* operator->() { return ptr; }
    T& operator*() { return *ptr; }
    T* get() const noexcept { return ptr; }
    deleter get_deleter() const noexcept { return custom_deleter; }
    explicit operator bool() { return ptr != nullptr; }

    ~my_unique_pointer() {
        delete ptr;
        //ptr = nullptr;
    }
};

template <class _Ty, class _Dx /* = default_delete<_Ty> */>
class my_unique_ptr2
{
};