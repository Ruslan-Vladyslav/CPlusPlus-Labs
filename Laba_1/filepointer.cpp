#define _CRT_SECURE_NO_WARNINGS

#include "filepointer.h"
#include "menu.h"

void pointer() {
    char* cur_file = (char*)malloc(256 * sizeof(char));
    char* new_file = (char*)malloc(256 * sizeof(char));
    char* lines;

    inputName(cur_file, new_file);

    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            inputName(cur_file, new_file);
            break;
        case 2:
            cout << "\n\nFiles successfully cleared!\n";
            lines = input_File();
            cout << "============================================\n\n";
            write_File(cur_file, lines);
            break;
        case 3:
            lines = input_File();
            add_input(cur_file, lines);
            break;
        case 4:
            cout << "\n\nCurrent data in file: " << cur_file << "\n";
            cout << "============================================";
            lines = read_File(cur_file);
            cout << lines;
            cout << "\n============================================\n";
            break;
        case 5:
            cout << "\n\nCurrent data in file: " << cur_file << "\n";
            cout << "============================================";
            lines = read_File(cur_file);
            cout << lines;
            cout << "\n============================================\n";
            processFile(cur_file, new_file);
            cout << "\n\nCurrent data in file: " << new_file << "\n";
            cout << "============================================\n";
            lines = read_File(new_file);
            cout << lines;
            printf("\n============================================\n");
            break;
        case 6:
            printf("\n\nExiting program\n\n");
            return;
        default:
            printf("\nIncorrect input!\n");
            break;
        }
    } while (choice != 6);
    free(cur_file);
    free(new_file);
}

char* read_File(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        cerr << "\n\nCannot open the file!" << endl;
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    char* array = (char*)calloc(size, sizeof(char));
    fread(array, sizeof(char), size, file);

    array[size] = '\0';
    fclose(file);
    return array;
}

void add_input(char* filename, char* text) {
    FILE* file = fopen(filename, "a+");
    if (file == nullptr) {
        cerr << "\n\nCannot open the file!" << endl;
        return;
    }
    fputs(text, file);
    fclose(file);
}

char* input_File() {
    char c;
    bool check = false;
    int size = 0, size_max = 256;
    char* array = (char*)calloc(size_max, sizeof(char));

    cout << "\n\nEnter your text:\n";
    cout << "============================================\n";

    while (cin.get(c)) {
        if (c == '\n') {
            if (check) break;
            check = true;
        }
        else {
            check = false;
        }
        if (size == size_max) {
            size_max *= 2;
            char* temp = (char*)calloc(size_max, sizeof(char));
            for (int i = 0; i < size; i++) {
                temp[i] = array[i];
            }
            free(array);
            array = temp;
        }
        array[size] = c;
        size++;
    }
    array[size] = '\0';
    return array;

}

void write_File(char* filename, char* text) { //запис нового тексту у файл
    FILE* file = fopen(filename, "w");
    if (file == nullptr) {
        cerr << "\n\nCannot open the file!" << endl;
        return;
    }
    fputs(text, file);
    fclose(file);
}

void processFile(const char* input_file, const char* output_file) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    if (input == NULL || output == NULL) {
        printf("\n\nCannot open the file!");
        return;
    }

    char line[256];
    while (fgets(line, 256, input)) {
        int Numbers = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                Numbers = 1;
                break;
            }
        }

        if (Numbers) {
            int maxNum = numMax(line);

            fprintf(output, "max number (%d)  |  %d, ", maxNum, maxNum);

            int First = 1;
            int numF = 0;
            char numTake[256];
            int numIn = 0;

            for (int i = 0; line[i] != '\0'; i++) {
                if (line[i] >= '0' && line[i] <= '9') {
                    numTake[numIn++] = line[i];
                    numF = 1;
                }
                else if (numF) {
                    numTake[numIn] = '\0';
                    int number = atoi(numTake);
                    if (number != maxNum) {
                        if (!First) {
                            fprintf(output, ", ");
                        }
                        fprintf(output, "%d", number);
                        First = 0;
                    }
                    numIn = 0;
                    numF = 0;
                }
            }

            fprintf(output, "  |  ");

            int length = strlen(line);
            int lastIndex = length - 1;
            int firstIndex = 0;

            while (lastIndex >= 0 && (line[lastIndex] == '\n' || line[lastIndex] == '\r')) {
                lastIndex--;
            }
            while (firstIndex < length && (line[firstIndex] == '\n' || line[firstIndex] == '\r')) {
                firstIndex++;
            }

            for (int i = lastIndex; i >= firstIndex; i--) {
                if (!(line[i] >= '0' && line[i] <= '9')) {
                    fputc(line[i], output);
                }
            }

            fputc('\n', output);
        }
    }

    fclose(input);
    fclose(output);
}

int numMax(const char* line) {
    int maxNum = -1;
    char numTake[256];
    int numIndex = 0;
    int numF = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            numTake[numIndex++] = line[i];
            numF = 1;
        }
        else if (numF) {
            numTake[numIndex] = '\0';
            int number = atoi(numTake);
            if (number > maxNum) {
                maxNum = number;
            }
            numIndex = 0;
            numF = 0;
        }
    }

    if (numF) {
        numTake[numIndex] = '\0';
        int number = atoi(numTake);
        if (number > maxNum) {
            maxNum = number;
        }
    }
    return maxNum;
}