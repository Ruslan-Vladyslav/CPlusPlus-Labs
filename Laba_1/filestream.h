#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void stream();
void clearFile(string filename);
void inputFile(string filename);
string readFile(string& filename);
void processFile(string inputFilename, string outputFilename);
int numMax(const string& line);

