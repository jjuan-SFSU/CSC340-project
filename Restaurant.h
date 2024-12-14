#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>

using namespace std;

enum Actions {QUIT, CUISINE};

struct Restaurant {

	public:
		Restaurant(int menuChoice);
		int startUpMenuChoice();
		void displayMenu();

	private:
		int menuChoice;
};

#endif
