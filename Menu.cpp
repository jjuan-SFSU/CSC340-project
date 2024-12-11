#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Menu::loadMenu(LinkedList& menu, const string& menuChoice) {

    ifstream file(menuChoice);
    string food;

    if (!file.is_open()) {
        cout << "Error opening file: " << menuChoice << endl;
        return;
    }

    while (getline(file, food)) {
        menu.push_back(food);
    }

    file.close();
}
