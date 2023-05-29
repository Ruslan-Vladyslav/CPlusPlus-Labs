#pragma once
#include <iostream>
#include <string>

using namespace std;



class Numeral_16 {  
	string hexadecimal;

public:
	Numeral_16() {};
	Numeral_16(string x) : hexadecimal(x) {}
	Numeral_16(int decimal) { hexadecimal = turnHexa(decimal); };

	string Get_num() { return hexadecimal; }

	string turnHexa(long n);
	int turnDecimal();

	Numeral_16 inc();
	Numeral_16 sum(Numeral_16& other);

	Numeral_16 operator++();
	Numeral_16 operator++(int);
	Numeral_16 operator+(Numeral_16& other);
	Numeral_16 operator+=(int other);
};
