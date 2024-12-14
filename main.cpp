#include "linkedlist.h"
#include "Menu.h"
#include "Restaurant.h"
#include "Person.h"
#include "Customer.h"
#include "Chef.h"

#include "linkedlist.cpp"
#include "Menu.cpp"
#include "Restaurant.cpp"
#include "Person.cpp"
#include "Customer.cpp"
#include "Chef.cpp"

using namespace std;

int main() {

    Restaurant restaurant(0);
    restaurant.startUpMenuChoice();

    LinkedList menu;
    Menu menuList;

    menuList.loadMenu(menu, "ChineseCuisine.txt");
    menu.print();

    Customer customer("John", 21, "Pot Stickers", 50.0);
    cout << customer.getName() << " would like to order: " << customer.getOrder() << endl;


    return 0;
}
