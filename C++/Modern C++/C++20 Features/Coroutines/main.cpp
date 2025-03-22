// Coroutines.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <exception>
#include <coroutine>
#include <list>
#include <new>
#include <utility>
#include <cstdio>

struct Chat
{
	struct promise_type
	{
		std::string _msgOut{}, _msgIn{};

		void unhandled_exception() noexcept {};
		Chat get_return_object() { return Chat{ this }; }
		std::suspend_always initial_suspend() noexcept { return {}; }
		std::suspend_always yield_value(std::string msg)noexcept {
			_msgOut = std::move(msg);
			return {};
		}

		auto await_transform(std::string) noexcept {
			struct awaiter
			{
				promise_type& pt;
				constexpr bool await_ready() const noexcept { return true; }
				std::string    await_resume() const noexcept { return std::move(pt._msgIn); }
				void           await_suspend(std::coroutine_handle<>) const noexcept {}
			};

			return awaiter{ *this };
		}

		void return_value(std::string msg) noexcept { _msgOut = std::move(msg); }
		std::suspend_always final_suspend() noexcept { return {}; }
	};

	using Handle = std::coroutine_handle<promise_type>;
	Handle mCoroHandle{};

	explicit Chat(promise_type* p) : mCoroHandle{ Handle::from_promise(*p) } {}
	Chat(Chat&& rhs) : mCoroHandle{ std::exchange(rhs.mCoroHandle, nullptr) } {}

	~Chat() {
		if (mCoroHandle) mCoroHandle.destroy();
	}

	std::string listen() {
		if (not mCoroHandle.done()) { mCoroHandle.resume(); }
		return std::move(mCoroHandle.promise()._msgOut);
	}

	void answere(std::string msg) {
		mCoroHandle.promise()._msgIn = msg;
		if (not mCoroHandle.done()) mCoroHandle.resume();
	}
};

Chat Fun()
{
	co_yield "Hello!!\n";

	std::cout << co_await std::string{};

	co_return "Here!\n";
}

void Use()
{
	Chat chat = Fun();
	std::cout << chat.listen();
	chat.answere("Where are you?\n");
	std::cout << chat.listen();
}

int main()
{
	Use();

	return 0;
}