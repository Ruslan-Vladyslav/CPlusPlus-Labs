#include "func.h"



void menu() {
    char c;
    int i;
    string filename = "bin.txt", newfilename = "newbin.txt";

    cout << "What do you want to do?\n";
    
    do {
        cout << "\n1) Create a new file\n"
            << "2) Add a new client to list\n"
            << "3) Watch file input (list of clients)\n"
            << "4) Watch list of clients that booked after 16:30\n"
            << "5) Exit\n";
        cout << ">> ";
        cin >> i;

        switch (i) {
        case 1:
            clearFile(filename);
            cout << "\nFile successfuly cleared!\nEnter information about client:\n";
            inputFile(filename);
            break;
        case 2:
            do {
                inputFile(filename);
                cout << "The client successfuly added!\n\nDo you want to add another (y/n)?\n";
                cout << ">> ";
                cin >> c;
                if (c == 'n' || c == 'N') break;
            } while (c == 'y' || c == 'Y');
            break;
        case 3:
            readFile(filename);
            break;
        case 4:
            outputFile(filename, newfilename);
            break;
        case 5:
            cout << "\nExitting program\n";
            return;
            break;
        }
    } while (i != 5);
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

bool isTimeAvailable(string filename, Time time) {
    Client client;
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Cannot open the file!\n" << endl;
        return false;
    }

    while (file.read((char*)&client, sizeof(Client))) {
        if (client.time.hour == time.hour) {
            if (time.min >= client.time.min && time.min < client.time.min + client.duration) {
                return false;
            }
            else if (time.min + 10 > client.time.min && time.min < client.time.min) {
                return false;
            }
        }
        else if (time.hour > client.time.hour && time.hour < client.time.hour + (client.duration / 60)) {
            return false;
        }
    }
    return true;
}

void inputFile(string filename) {
    Client client;
    Time time = { 0, 0 };
    ofstream file;
    file.open(filename, ios::binary | ios::app);
    if (!file) {
        cerr << "Cannot open the file!\n" << endl;
        return;
    }

    bool f = true;
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
            f = false;
        }
        else if (time.hour < 8 && time.min < 30 || time.hour == 22 && time.min > 0 || time.min < 0 || time.min > 59) {
            std::cout << "The hairdresser works from 8:00 to 22:00" << endl;
            std::cout << "Enter again" << endl;
            f = false;
        }
        else if (!isTimeAvailable(filename, time)) {
            std::cout << "The time is already taken by another client!" << endl;
            std::cout << "Enter again" << endl;
            f = false;
        }
        else {
            f = true;
        }
    } while (!f);

    do {
        cout << "Duration of procedure: ";
        cin >> client.duration;

        if (client.duration < 10 || client.duration > 60) {
            cout << "The procedure can take 10 - 90 minutes!" << endl;
            f = false;
        }
        else {
            f = true;
        }
    } while (!f);

    client.time = time;
    file.write((char*)&client, sizeof(Client));
    file.close();
    cout << "Client successfully added!" << endl;
}

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