#ifndef TEXTLIB_H
#define TEXTLIB_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

char fileName[100];
string content;

void loadFile();
string toLower(string str);
void contentToUpper();
void contentToLower();
void firstCap();
void n_WordExist();
void saveFile();

#endif