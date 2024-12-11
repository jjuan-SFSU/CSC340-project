#ifndef CHEF_H
#define CHEF_H

#include "Person.h"
#include "linkedlist.h"
#include <string>

using namespace std;

class Chef : public Person {
    private:
        LinkedList recipes;

    public:
        Chef(const string& name, int age, const LinkedList& recipes);

        void cookOrder(const string& order);
        string getOrder() const;
        bool dishAvailable(const string& dish) const;
        bool checkIngredients(const string& dish) const;

        void displayInfo() const override;
        string getRole() const override;
};

#endif
