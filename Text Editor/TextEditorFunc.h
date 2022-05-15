#ifndef TEXTLIB_H
#define TEXTLIB_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <vector>
#include <string>

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
void merge();
void countWords();
void countCharacters();
void countLines();
string toLower(string str);
void findWord();
void n_WordExist();
void contentToUpper();
void contentToLower();
void firstCap();
void saveFile();

#endif