#include "func.h"


// Головне меню програми
void menu() {
    char c;
    int i;
    string file, newfile;

    inputName(file, newfile);

    cout << "\n\nWhat do you want to do?\n";
    
    do {
        cout << "\n1) Choose other files\n"
            << "2) Clear files / type new data\n"
            << "3) Add a new client to list\n"
            << "4) Watch file input (list of clients)\n"
            << "5) Watch list of clients that booked after 16:30\n"
            << "6) Exit\n";
        cout << ">> ";
        cin >> i;

        switch (i) {
        case 1:
            inputName(file, newfile);
            break;
        case 2:
            clearFile(file);
            cout << "\n\nFile successfuly cleared!\nEnter information about client:\n";
            inputFile(file);
            break;
        case 3:
            do {
                inputFile(file);
                cout << "\nDo you want to add another (y/n)?\n";
                cout << ">> ";
                cin >> c;
                if (c == 'n' || c == 'N') break;
            } while (c == 'y' || c == 'Y');
            break;
        case 4:
            readFile(file);
            break;
        case 5:
            outputFile(file, newfile);
            break;
        case 6:
            cout << "\nExitting program\n";
            return;
            break;
        }
    } while (i != 6);
}

void clearFile(string filename) {
    ofstream file;
    file.open(filename, ios::binary | ios::trunc);
    if (!file) {
        cerr << "Cannot open the file!" << endl;
        return;
    }
    file.close();
}

string inputName(string& filename, string& newfilename) {
    cout << "\nEnter files name which you want to create | open";
    cout << "\n=========================================================\n";
    cin.ignore();
    cout << "Enter input  file: ";
    getline(cin, filename);
    filename += ".bin";
    cout << "Enter output file: ";
    getline(cin, newfilename);
    newfilename += ".bin";
    return filename, newfilename;
}

// Перевірка чи є вільний час для запису
bool isTimeAvailable(string filename, Time time, int duration) {
    Client client;
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "\n\nCannot open the file!\n" << endl;
        return false;
    }

    int targetMinutes = time.hour * 60 + time.min;
    int targetEndMinutes = targetMinutes + duration;

    while (file.read((char*)&client, sizeof(Client))) {
        int appointmentMinutes = client.time.hour * 60 + client.time.min;
        int appointmentEndMinutes = appointmentMinutes + client.duration;

        if (targetMinutes >= appointmentMinutes && targetMinutes < appointmentEndMinutes) {
            return false;
        }

        if (targetEndMinutes > appointmentMinutes && targetEndMinutes <= appointmentEndMinutes) {
            return false;
        }
    }

    return true;
}

// Вввід даних про користувача
void inputFile(string filename) {
    Client client;
    Time time = { 0, 0 };
    ofstream file;
    file.open(filename, ios::binary | ios::app);
    if (!file) {
        cerr << "\n\nCannot open the file!\n" << endl;
        return;
    }

    bool validTime = false;
    bool validDuration = false;

    cout << "\nName: ";
    cin >> client.name;

    cout << "Surname: ";
    cin >> client.surname;

    do {
        cout << "Enter time (hours and minutes in format HH MM): ";
        if (!(cin >> time.hour) || !(cin >> time.min) || cin.get() != '\n') {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter valid hour and minute in the format HH MM\n";
            validTime = false;
        }
        else if (time.hour < 8 || time.hour >= 22 || time.min < 0 || time.min > 59) {
            cout << "The hairdresser works from 8:00 to 22:00" << endl;
            cout << "Enter again" << endl;
            validTime = false;
        }
        else if (!isTimeAvailable(filename, time, client.duration)) {
            cout << "The time is already taken by another client!" << endl;
            cout << "Enter again" << endl;
            validTime = false;
        }
        else {
            validTime = true;
        }
    } while (!validTime);

    do {
        cout << "Duration of procedure: ";
        cin >> client.duration;

        if (client.duration < 10 || client.duration > 60) {
            cout << "The procedure can take 10 - 60 minutes!" << endl;
            validDuration = false;
        }
        else {
            validDuration = true;
        }
    } while (!validDuration);

    client.time = time;
    file.write((char*)&client, sizeof(Client));
    file.close();
    cout << "Client successfully added!" << endl;
}

// Виведення списку клієнтів у поточному файлі
void readFile(string filename) {
    Client client;
    ifstream file;
    file.open(filename, ios::binary);
    if (!file) {
        cerr << "Cannot open the file!\n" << endl;
        return;
    }

    cout << "\n============================================================" << endl;
    cout << left << setw(16) << "Surname" << setw(14) << "Name" << setw(14) << "Time" << setw(10) << "Duration" << endl;
    cout << "------------------------------------------------------------" << endl;
    while (file.read((char*)&client, sizeof(Client))) {
        cout << left << setw(16) << client.surname << setw(14) << client.name << setw(2) << client.time.hour << ":" << setw(2) << client.time.min << setw(10) << " " << client.duration << " min" << endl;
    }
    cout << "\n============================================================" << endl;

    file.close();
}

// Виведення списку клієнті записаних після 16:30 у новий файл
void outputFile(string filename, string newFilename) {
    Client client;
    Time time;
    ifstream file(filename, ios::binary);
    ofstream newFile(newFilename, ios::binary);

    if (!file) {
        cerr << "Cannot open the file!\n" << endl;
        return;
    }
    if (!newFile) {
        cerr << "Cannot create the new file!\n" << endl;
        return;
    }

    cout << "\nClients who booked after 16:30 in file: " << newFilename << endl;
    cout << "============================================================" << endl;
    cout << left << setw(16) << "Surname" << setw(14) << "Name" << setw(14) << "Time" << setw(10) << "Duration" << endl;
    cout << "------------------------------------------------------------" << endl;

    while (file.read((char*)&client, sizeof(Client))) {
        if ((client.time.hour >= 16 && client.time.min >= 30) || (client.time.hour > 16 && client.time.min >= 0)) {
            newFile.write((char*)&client, sizeof(Client));
            cout << left << setw(16) << client.surname << setw(14) << client.name << setw(2) << client.time.hour << ":" << setw(2) << client.time.min << setw(10) << " " << client.duration << " min" << endl;
        }
    }
    cout << "\n============================================================" << endl;

    file.close();
    newFile.close();
}
