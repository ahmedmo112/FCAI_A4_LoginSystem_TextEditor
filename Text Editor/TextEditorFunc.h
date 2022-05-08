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
void count_words();
void count_characters();
void count_lines();
void find_word();
void n_WordExist();
string toLower(string str);
void contentToUpper();
void contentToLower();
void firstCap();
void saveFile();

#endif