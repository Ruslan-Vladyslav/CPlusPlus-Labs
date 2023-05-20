#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>


using namespace std;

void pointer();
char* input_File();
void processFile(const char* input_file, const char* output_file);
int numMax(const char* line);
void write_File(char* filename, char* text);
char* read_File(char* filename);
void add_input(char* filename, char* text);
