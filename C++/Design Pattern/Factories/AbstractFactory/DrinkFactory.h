#pragma once
#include "HotDrinkFactory.h"
#include <map>
#include <string.h>

class DrinkFactory
{
	std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_drinks;
public:
	DrinkFactory() {
		hot_drinks["Tea"] = std::make_unique<TeaFactory>();
		hot_drinks["Coffee"] = std::make_unique<CoffeeFactory>();
	}

	std::unique_ptr<HotDrink> make_drink(std::string drink_name, int volume) {

		if (hot_drinks.find(drink_name) != hot_drinks.end()) {
			auto drink = hot_drinks[drink_name]->make();
			drink->prepare_drink(volume);
			return drink;
		}
		else {
			std::cout << "Drink is not available now, Sorry of inconvinience" << std::endl;
		}
	}
};