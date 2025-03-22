#pragma once
#include "Chat.hpp"

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