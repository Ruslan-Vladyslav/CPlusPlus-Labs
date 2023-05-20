#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

// Головне меню
void menu() {
    cout << "\n\n1) Choose other files\n"
        << "2) Clear file and add new data\n"
        << "3) Add an array to file\n"
        << "4) Watch file input in current file\n"
        << "5) Watch file input in new file\n"
        << "6) Exit\n";
    cout << ">> ";
}

// Функції для введення назви файлів
string takeName(string& filename, string& newfilename) {
    cin.ignore();
    cout << "\nEnter files name which you want to read|open";
    cout << "\n============================================\n";
    cout << "Enter input  file: ";
    getline(cin, filename);
    filename += ".txt";
    cout << "Enter output file: ";
    getline(cin, newfilename);
    newfilename += ".txt";
    return filename, newfilename;
}

void inputName(char* name, char* newname) {
    int size = 0, newsize = 0;
    char c1, c2;

    cin.ignore();
    cout << "\nEnter files name which you want to read|open";
    cout << "\n============================================\n";
    cout << "Enter input  file: ";

    while (cin.get(c1)) {
        if (c1 == '\n') break;
        name[size] = c1;
        size++;
    }

    cout << "Ebter output file: ";

    while (cin.get(c2)) {
        if (c2 == '\n') break;
        newname[newsize] = c2;
        newsize++;
    }

    name[size] = '\0';
    strcat(name, ".txt");
    newname[newsize] = '\0';
    strcat(newname, ".txt");
}

int check(int num, char* arr[]) {
    if (num != 3) {
        cout << "\nInvalid input!\nThe input should be: -mode (FileStream | FilePointer)" << endl;
        return -1;
    }
    else if (!strcmp(arr[1], "-mode")) {
        if (!strcmp(arr[2], "FilePointer")) {
            cout << "\n\nUsing Filepointer" << endl;
            return 1;
        }
        else if (!strcmp(arr[2], "FileStream")) {
            cout << "\n\nUsing Filestream" << endl;
            return 2;
        }
    }
    else {
        cout << "\nInvalid input!\nThe input should be: -mode (FileStream | FilePointer)" << endl;
        return -1;
    }
}
