#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include "Customer.h"
#include <iostream>
#include <string>

using namespace std;

Customer::Customer(const string& name, int age, const string& order, double budget):
      Person(name, age),
      order(order),
      budget(budget) {}

bool Customer::isFull() const {
      return true;
}

string Customer::review() const {
      return "The food was excellent!";
}

bool Customer::IDcheck() const {
      return getAge() >= 18;
}

void Customer::displayInfo() const {
      cout << "Customer Name: " << getName() << "\n";
      cout << "Age: " << getAge() << "\n";
      cout << "Order: " << order << "\n";
      cout << "Budget: " << budget << "\n";
}

string Customer::getRole() const { return "Customer"; }

string Customer::getOrder() const { return order; }
void Customer::setOrder(const string& newOrder) { order = newOrder; }

double Customer::getBudget() const { return budget; }
void Customer::setBudget(double newBudget) { budget = newBudget; }

#endif
