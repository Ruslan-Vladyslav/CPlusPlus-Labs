#include "func.h"
#include "func.cpp"

using namespace std;


int main() {
    int ch;

    do {
        cout << "\n\nChoose a data type:\n"
            << "1) int\n"
            << "2) double\n"
            << "3) float\n"
            << "4) string\n"
            << "5) Exit\n";
        cout << ">> ";
        cin >> ch;

        switch (ch) {
        case 1: {
            List<int> lst;
            input(lst);
            Main(lst);
            break;
        }
        case 2: {
            List<double> lst;
            input(lst);
            Main(lst);
            break;
        }
        case 3: {
            List<float> lst;
            input(lst);
            Main(lst);
            break;
        }
        case 4: {
            List<string> lst;
            input(lst);
            Main(lst);
            break;
        }
        case 5:
            cout << "\n\nExiting program\n";
            break;
        default:
            cout << "\nInvalid choice!\n";
            break;
        }
    } while (ch != 5);
    return 0;
}