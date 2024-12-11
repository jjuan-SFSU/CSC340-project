#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include <string>

using namespace std;

class Customer : public Person {

    private:
        string order;
        double budget;

    public:
        Customer(const string& name, int age, const string& order, double budget);

        bool isFull() const;
        string review() const;
        bool IDcheck() const;

        void displayInfo() const override;
        string getRole() const override;

        string getOrder() const;
        void setOrder(const string& order);

        double getBudget() const;
        void setBudget(double budget);
};

#endif
