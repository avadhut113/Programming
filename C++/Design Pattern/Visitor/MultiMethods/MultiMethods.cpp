// MultiMethods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <functional>
#include <typeindex>

struct GameObject;

void collide(GameObject& first, GameObject& second);

struct GameObject
{
    virtual std::type_index type() const = 0;
    virtual void collide(GameObject& other) {
        ::collide(*this, other);
    }
};

//CRTP
template<typename T> 
struct GameObjectImpl : GameObject
{
    std::type_index type() const override {
        return typeid(T);
    }
};

struct  Planet : GameObjectImpl<Planet>
{

};

struct  Astroid : GameObjectImpl<Astroid>
{

};

struct  SpaceShip : GameObjectImpl<SpaceShip>
{

};

void spaceship_planet() { std::cout << "spaceship lands on planet \n"; }
void astroid_planet() { std::cout << "astroid burns up in atmostphere\n"; }
void astroid_spaceship() { std::cout << "astroid destroys spaceship\n"; }

std::map<std::pair<std::type_index, std::type_index>, std::function<void(void)>> outcomes{
    {{typeid(SpaceShip),typeid(Planet)}, spaceship_planet},
    {{typeid(Astroid),typeid(Planet)},astroid_planet},
    {{typeid(Astroid),typeid(SpaceShip)},astroid_spaceship}
};

void collide(GameObject& first, GameObject& second)
{
    auto it = outcomes.find({ first.type(),second.type() });

    if (it == outcomes.end()) {
        it = outcomes.find({ second.type(),first.type() });
        if (it == outcomes.end()) {
            std::cout << "object passes each other harmlessly\n";
            return;
        }
    }
    it->second();
}


int main()
{
    SpaceShip spaceship;
    Astroid astroid;
    Planet planet;

    collide(planet, spaceship);
    collide(planet, astroid);
    collide(spaceship, astroid);
    collide(planet, planet);

    return 0;
}
