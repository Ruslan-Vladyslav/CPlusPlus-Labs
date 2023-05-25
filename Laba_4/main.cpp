#include "header.h"
#include "user.h"


using namespace std;


int main() {
	char choice;
	do {
		interface();

		cout << "\n\nDo you want to continue (y/n)?:";
		cout << "\n>> ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	cout << "\n\nExitting program\n";
	return 0;
}