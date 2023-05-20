#include "filestream.h"
#include "menu.h"


// Меню
void stream() {
    char c;
    int i;
    string file, newfile;

    takeName(file, newfile);

    do {
        menu();
        cin >> i;

        switch (i) {
        case 1:
            takeName(file, newfile);
            break;
        case 2:
            clearFile(file);
            clearFile(newfile);
            cout << "\n\nFiles successfully cleared!\n";
            inputFile(file);
            break;
        case 3:
            do {
                inputFile(file);
                cout << "\nDo you want to add another line (y/n)?\n";
                cout << ">> ";
                cin >> c;
                if (c == 'n' || c == 'N') break;
            } while (c == 'y' || c == 'Y');
            break;
        case 4:
            cout << readFile(file) << endl;
            cout << "============================================\n";
            break;
        case 5:
            cout << readFile(file) << endl;
            cout << "============================================\n";
            processFile(file, newfile);
            cout << readFile(newfile) << endl;
            cout << "============================================\n";
            break;
        case 6:
            cout << "\nExiting program\n";
            return;
            break;
        default:
            printf("\nUncorrect input!\n");
            break;
        }
    } while (i != 6);
}

// Очищення файлу
void clearFile(string filename) {
    ofstream file;
    file.open(filename, ofstream::trunc);
    if (!file) {
        cerr << "\n\nCannot open the file!" << endl;
        return;
    }
    file.close();
}

// Введення тексту у файл
void inputFile(string filename) {
    ofstream file;
    file.open(filename, ofstream::app);
    if (!file.is_open()) {
        cerr << "\n\nCannot open the file!" << endl;
        return;
    }

    string text;
    cout << "\n\nEnter your text:\n";
    cout << "============================================\n";
    getline(cin, text);

    do {
        text = "";
        getline(cin, text);
        if (text != "") {
            file << text << endl;
        }
    } while (!text.empty());
    file.close();
    cout << "============================================\n\n";
}


string readFile(string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "\n\nCannot open the file!";
        return " ";
    }
    else {
        string contents, line;
        cout << "\n\nCurrent data in file: " << filename + "\n";
        cout << "============================================\n";
        while (getline(file, line)) {
            contents += line + "\n";
        }

        file.close();
        return contents;
    }
}

// Запис у новий файл результатів (найбільше число, числа через кому, слова)
void processFile(string inputFile, string outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    string line;
    while (getline(inFile, line)) {
        bool hasNumbers = false;

        for (char c : line) {
            if (isdigit(c)) {
                hasNumbers = true;
                break;
            }
        }

        if (hasNumbers) {
            int maxNum = numMax(line);
            outFile << "max number (" << maxNum << ")  |  ";

            bool isFirst = true;
            bool numFound = false;
            string numTake;

            for (char c : line) {
                if (isdigit(c)) {
                    numTake += c;
                    numFound = true;
                }
                else if (numFound) {
                    int number = stoi(numTake);
                    if (number != maxNum) {
                        if (isFirst) {
                            outFile << maxNum;
                            isFirst = false;
                        }
                        outFile << ", " << number;
                    }
                    numTake.clear();
                    numFound = false;
                }
            }

            outFile << "  |  ";

            // Зворотне виведення символів
            for (int i = line.length() - 1; i >= 0; i--) {
                if (!isdigit(line[i])) {
                    outFile << line[i];
                }
            }
            outFile << endl;
        }
    }

    inFile.close();
    outFile.close();
}

// Знаходження найбільшого числа у рядку
int numMax(const string& line) {
    int maxNum = -1;
    string numTake;
    bool numFound = false;

    for (char c : line) {
        if (isdigit(c)) {
            numTake += c;
            numFound = true;
        }
        else if (numFound) {
            int number = stoi(numTake);
            if (number > maxNum) {
                maxNum = number;
            }
            numTake.clear();
            numFound = false;
        }
    }

    if (numFound) {
        int number = stoi(numTake);
        if (number > maxNum) {
            maxNum = number;
        }
    }
    return maxNum;
}
