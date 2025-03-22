// Coroutines_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <coroutine>
#include <cassert>

class resumable
{
public:
    struct promise_type;
    using co_handle = std::coroutine_handle<promise_type>;

    resumable(co_handle handle) : _handle(handle) {
        assert(handle);
    }
    resumable(const resumable&) = delete;
    resumable(resumable&&) = delete;

    bool resume() {
        if (not _handle.done())
            _handle.resume();

        return not _handle.done();
    }

    ~resumable() { _handle.destroy(); }
private:
    co_handle  _handle;
};

struct resumable::promise_type
{
    using co_handle = std::coroutine_handle<promise_type>;

    auto get_return_object() {
        return co_handle::from_promise(*this);
    }

    auto initial_suspend() { return std::suspend_always(); }
    auto final_suspend() noexcept { return std::suspend_always(); }

    void return_void(){}
    void unhandled_exception() {
        std::terminate();
    }
};

resumable foo()
{
    std::cout << "a" << std::endl;
    co_await std::suspend_always();
    std::cout << "b" << std::endl;
    co_await std::suspend_always();
    std::cout << "c" << std::endl;
}

void test_coroutine()
{

    resumable res = foo();
    res.resume();
    res.resume();
    res.resume();

}
