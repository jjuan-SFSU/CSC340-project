#include "linkedlist.h"
#include "linkedlist.cpp"
#include "Menu.h"
#include "Menu.cpp"
#include "ChineseCuisine.txt"

using namespace std;

int main() {

    LinkedList menu;
    Menu menuList;

    menuList.loadMenu(menu, "ChineseCuisine.txt");
    menu.print();

    return 0;
}
