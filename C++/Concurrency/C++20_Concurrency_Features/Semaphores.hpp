#pragma once
#include <semaphore>
#include <iostream>
#include <string>
#include <thread>
#include <array>

using namespace std::literals::chrono_literals;

std::binary_semaphore start_speaking{ 0 }, p1_done{ 0 }, p2_done{ 0 };

void person_speak(std::string_view text, std::binary_semaphore& w, std::binary_semaphore& r, std::stop_token s)
{
	w.acquire();
	while (not s.stop_requested()) {
		std::cout << text << "\n";
		std::this_thread::sleep_for(1s);
	}
	r.release();
}

void stop_speaking(std::array<std::stop_source, 2> st_source)
{
	for (auto i = 0u; i < st_source.size(); i++) {
		std::this_thread::sleep_for(4s);
		st_source[i].request_stop();
	}
}

void test_semaphore()
{
	std::array st_source{ std::stop_source{}, std::stop_source{} };

	std::jthread p1(person_speak, "Hello person2 I'm Person1\n", std::ref(start_speaking), std::ref(p1_done), st_source[0].get_token());
	std::jthread p2(person_speak, "Hello person1 I'm Person2\n", std::ref(p1_done), std::ref(p2_done), st_source[1].get_token());

	start_speaking.release();

	std::jthread schedule(stop_speaking, st_source);

	p2_done.acquire();

	std::cout << "Goood bye!!!\n";
}