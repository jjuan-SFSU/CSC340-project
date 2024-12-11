#include "Restaurant.h"
#include <iostream>
#include <string>
using namespace std;

Restaurant::Restaurant(int menuChoice) {
	this->menuChoice = menuChoice;
}

int Restaurant::startUpMenuChoice() {
	int choice;
	cout << "--------------------------------------------" << endl;
	cout << "Options menu:" << endl;
	cout << "  (" << CUISINE << ") Choose which cuisine of food you would like" << endl;

	cin >> choice;

	if (choice < 0 || choice > 1) {
		cout << "Error! Input must be a number between 1 and " << 1 << ", or 0 to exit." << endl;
	}

	return choice;
}

void Restaurant::displayMenu() {
	int choice;

	do {
		choice = startUpMenuChoice();

		switch (choice) {
			case CUISINE:
				cout << "test" << endl;
				break;
			
			case QUIT:
				cout << "Thank you! Bye!" << endl;
				break;
		}
	} while (choice != QUIT);
}

