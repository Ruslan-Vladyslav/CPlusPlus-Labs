#include "func.h"


int main() {
    char choice;

    cout << "\nThe program, according to the coordinates of the height,\ncenter and radius of the base, can calculate the generating cone\n\n";

    do {
        int number;
        bool f = true;

        do {
            cout << "\nEnter number of cones:\n";
            cout << ">> ";
            cin >> number;
            if (number < 2) {
                cout << "The amount of cones should be more than 1!\n";
                f = false;
            }
            else {
                f = true;
            }
        } while (!f);

        Cone* cones = new Cone[number]; // Масив обєктів

        for (int i = 0; i < number; i++) {
            cones[i] = add_Cone(i);
        }

        int Tvirna = tvirna(cones, number);
        result(cones, number, Tvirna);
        delete[] cones;

        cout << "\n\nDo you want to continue working with the program (y/n)?\n";
        cout << ">> ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\n\nExitting program!" << endl;
    return 0;
}

