#pragma once

#include <memory>

template<typename T> class CPimpl
{
	std::unique_ptr<T> impl;
public:
	template<typename...Args>CPimpl(Args &&... args);
	CPimpl();
	~CPimpl();

	T* operator->();
	T& operator*();
};

