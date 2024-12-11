#include "iostream"
#include "linkedlist.h"
#include "linkedlist.cpp"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    LinkedList list = LinkedList("test");
    list.print();

    return 0;
}
