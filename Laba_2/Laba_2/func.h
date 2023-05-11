#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

struct Time {
	int hour;
	int min;
};

struct Client {
	char name[50];
	char surname[50];
	Time time;
	int duration;
};

void menu();
bool isTimeAvailable(string filename, Time time);
void clearFile(string filename);
void inputFile(string filename);
void readFile(string filename);
void outputFile(string filename, string newFilename);