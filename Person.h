#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

struct Person {

  private:
    string name;
    int age;

  public:
    Person(const string name, int age);
    virtual ~Person();

    virtual void displayInfo() const = 0;
    virtual string getRole() const = 0;

    [[nodiscard]] string getName() const;
    int getAge() const;

 };

#endif
