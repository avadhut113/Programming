#pragma once

#include <iostream>
#include <memory.h>

class HotDrink
{
public:
	HotDrink() = default;
	virtual void prepare_drink(int volume) = 0;
};

class Tea : public HotDrink
{
public:
	Tea() = default;
	void prepare_drink(int volume) override{
		std::cout << "Take tea bag, bring hot water, pour it in " << volume <<  " cup, add leamon, enjoy!!" <<std::endl;
	}
};

class Coffee : public HotDrink
{
public:
	Coffee() = default;
	void prepare_drink(int volume) override {
		std::cout << "Crush some coffee beans, bring hot water, pour it in " << volume <<" cup, add some cream, enjoy!!" << std::endl;
	}
};