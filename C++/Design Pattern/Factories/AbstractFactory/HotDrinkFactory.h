#pragma once
#include "HotDrinks.h"

class HotDrinkFactory
{
public:
	HotDrinkFactory() = default;
	virtual std::unique_ptr<HotDrink> make() = 0;
};

class TeaFactory : public HotDrinkFactory
{
public:
	TeaFactory() = default;
	virtual std::unique_ptr<HotDrink> make() override {
		return std::make_unique<Tea>();
	}
};

class CoffeeFactory : public HotDrinkFactory
{
public:
	CoffeeFactory() = default;
	virtual std::unique_ptr<HotDrink> make() override {
		return std::make_unique<Coffee>();
	}
};