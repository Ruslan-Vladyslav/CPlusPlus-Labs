#include "filestream.h"
#include "filepointer.h"
#include "menu.h"


using namespace std;


int main(int num, char* arr[]) {
    int choice = check(num, arr);

    switch (choice) {
    case 1:
        pointer();
        break;
    case 2:
        stream();
        break;
    default:
        return 0;
    }
}