#ifndef CHEF_CPP
#define CHEF_CPP

#include "Chef.h"
#include "linkedlist.h"
#include <iostream>
#include <string>

using namespace std;

Chef::Chef(const string& name, int age, const LinkedList& recipes):
    Person(name, age),
    recipes(recipes) {}

void Chef::cookOrder(const string& order) {
    if (dishAvailable(order)) {
        cout << "Cooking " << order << "...\n";
    } else {
        cout << "Sorry, " << order << " is not available.\n";
    }
}

string Chef::getOrder() const {
    return recipes.size() > 0  ? recipes.getHead() -> getData() : "No orders available";
}

bool Chef::dishAvailable(const string& dish) const {
    for (const auto& recipe : recipes) {
        if (recipe == dish) {
            return true;
        }
    }
    return false;
}

bool Chef::checkIngredients(const string& dish) const {
    return dishAvailable(dish);
}


void Chef::displayInfo() const {
    cout << "Chef Name: " << getName() << "\n";
    cout << "Age: " << getAge() << "\n";
    cout << "Recipes: ";

    for (const auto& recipe : recipes) {
        cout << recipe.getData() << ", ";
    }
    cout << "\n";
}

string Chef::getRole() const {
    return "Chef";
}

#endif