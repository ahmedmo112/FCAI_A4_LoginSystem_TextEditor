#ifndef TEXTLIB_H
#define TEXTLIB_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

fstream file;
char fileName[100];
string content;

int displayMeny();
void loadFile();
void addingContent();
void displayContent();
void eraseContent();
void encryptContent();
void decryptContent();
void n_WordExist();
string toLower(string str);
void contentToUpper();
void contentToLower();
void firstCap();
void saveFile();

#endif