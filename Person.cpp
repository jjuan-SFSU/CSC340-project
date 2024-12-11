#ifndef PERSON_CPP
#define PERSON_CPP

#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(const string name, int age) : name(name), age(age) {}
Person::~Person() {}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

#endif PERSON_CPP