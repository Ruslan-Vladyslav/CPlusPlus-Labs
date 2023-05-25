#include "user.h"
#include "header.h"



void interface() {
	string num1, num2;
	int dec1, dec2;
	int value, option;

	cout << "\n\nEnter the base of the input number:";
	cout << "\n1) Hexadecimal";
	cout << "\n2) Decimal";
	cout << "\n>> ";
	cin >> option;


	if (option == 1) {
		cout << "\n\nEnter hexadecimal number N1: ";
		cin >> num1;
		while (!checkHexa(num1)) {
			cout << "Invalid input! Please enter a valid hexadecimal number: ";
			cin >> num1;
		}

		cout << "Enter hexadecimal number N2: ";
		cin >> num2;
		while (!checkHexa(num2)) {
			cout << "Invalid input! Please enter a valid hexadecimal number: ";
			cin >> num2;
		}

		cout << "Enter the amount to increase number 2: ";
		cin >> value;
	}
	else if (option == 2) {
		cout << "\n\nEnter decimal number N1: ";
		cin >> dec1;
		cout << "Enter decimal number N2: ";
		cin >> dec2;
		cout << "Enter the amount to increase number 2: ";
		cin >> value;
	}

	Numeral_16 N1;
	Numeral_16 N2;
	Numeral_16 N3;

	if (option == 1) {
		N1 = Numeral_16(num1);
		N2 = Numeral_16(num2);
	}
	else if (option == 2) {
		N1 = Numeral_16(dec1);
		N2 = Numeral_16(dec2);
	}


	cout << "\n\n\nYour input\n";
	cout << "-------------------------------------------\n";
	cout << "N1 (hexadecimal): " << N1.Get_num() << ", (decimal - " << N1.turnDecimal() << ")\n";
	cout << "N2 (hexadecimal): " << N2.Get_num() << ", (decimal - " << N2.turnDecimal() << ")\n";
	cout << "-------------------------------------------\n\n";

	N1++;
	N2 += value;
	N3 = N1 + N2;
	int decimalN3 = N3.turnDecimal();

	cout << "\nResult\n";
	cout << "-------------------------------------------\n";
	cout << "N1 incremented: " << N1.Get_num() << ", (decimal - " << N1.turnDecimal() << ")\n";
	cout << "N2 incremented by " << value << ": " << N2.Get_num() << ", (decimal - " << N2.turnDecimal() << ")\n";
	cout << "Decimal value of N3: " << decimalN3;
	cout << "\n-------------------------------------------\n\n";
}

// Перевірка чи є число шістнадцятковим
bool checkHexa(string str) {
    string validChars = "0123456789ABCDEF";
    for (char c : str) {
        if (validChars.find(toupper(c)) == string::npos)
            return false;
    }
    return true;
}
