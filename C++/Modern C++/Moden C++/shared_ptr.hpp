#pragma once
#include <iostream>
#include <utility>
#include <format>

class ref_count
{
public:
	explicit ref_count() : m_counter(0){}
	void reset() { m_counter = 0; }
	~ref_count() {
		m_counter = 0;
	}

	ref_count& operator++() {
		m_counter++;
		return *this;
	}

	ref_count& operator++(int) {
		m_counter++;
		return *this;
	}

	inline unsigned int get() { return m_counter; }

	ref_count& operator--() {
		m_counter--;
		return *this;
	}

	ref_count& operator--(int) {
		m_counter--;
		return *this;
	}

	bool operator==(const ref_count& right) const {
		return this->m_counter == right.m_counter;
	}


private:
	unsigned int m_counter{};
};

template<class contained>
class shared_ptr
{
public:
	shared_ptr() : ptr(nullptr){}
	shared_ptr(contained* ptr_) : ptr(std::exchange(ptr_, nullptr)), count(new ref_count) {
		(*count)++;
	}
	~shared_ptr() {
		reset();
	}

	//copy semantics
	shared_ptr(const shared_ptr& right) {
		ptr = right.ptr;
		count = right.count;
		(*count)++;
	}
	shared_ptr& operator=(const shared_ptr& right) {
		if (&right != this) {
			reset();
			ptr = right.ptr;
			count = right.count;
			(*count)++;
		}
		return *this;
	}

	//move semantics
	shared_ptr(shared_ptr&& right) {
		ptr = right.ptr;
		count = right.count;
		right.ptr = nullptr;
		right.count = nullptr;
	}
	shared_ptr& operator=(shared_ptr&& right) {
		if (&right != this) {
			reset();

			ptr = right.ptr;
			count = right.count;
			right.ptr = nullptr;
			right.count = nullptr;
		}
		return *this;
	}

	contained* operator->() const { return ptr; }
	contained& operator*() const { return *ptr; }

	unsigned int get_count() { return ptr != nullptr ? count->get() : 0 ; }

private:
	void reset() {
		if (ptr && count) {
			(*count)--;
			if (count->get() == 0) {
				delete ptr;
				delete count;
				ptr = nullptr;
				count = nullptr;
			}
		}
	}

	contained* ptr;
	ref_count* count;
};

void test_shared_ptr()
{
	shared_ptr<int> sp1(new int(10));
	std::cout << std::format("sp1 : {} , ref : {} \n", *sp1, sp1.get_count());

	shared_ptr<int> sp2(sp1);
	std::cout << std::format("sp2 : {} , ref : {} \n", *sp2, sp2.get_count());
	*sp2 = 20;
	sp2 = sp1;
	std::cout << std::format("sp1 : {} , ref : {} \n", *sp1, sp1.get_count());

	shared_ptr<int> sp3(std::move(sp1));
	//std::cout << std::format("sp1 : {} , ref : {} \n", *sp1, sp1.get_count());
	*sp3 = 30;
	std::cout << std::format("sp3 : {} , ref : {} \n", *sp3, sp3.get_count());
	std::cout << std::format("sp2 : {} , ref : {} \n", *sp2, sp2.get_count());

	shared_ptr<int> sp4;
	//std::cout << std::format("sp1 : {} , ref : {} \n", *sp1, sp1.get_count());
	sp4 = std::move(sp2);
	*sp4 = 40;
	std::cout << std::format("sp4 : {} , ref : {} \n", *sp4, sp4.get_count());
	std::cout << std::format("sp3 : {} , ref : {} \n", *sp3, sp3.get_count());

}