#ifndef LOGINLIB_H
#define LOGINLIB_H

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
#include <iomanip>
#include <conio.h>
#include <sstream>


using namespace std;

struct Users
{
    int userId;
    string userName;
    string email;
    string password;
    string phoneNumber;

} user;

map<int, Users> map_users;

int menu();
void extractFileData();
bool isValidName();
bool isValidEmail();
bool isValidPhoneNumber();
bool isRegID(int id);
void userId();
void userName();
void email();
void repeatPassword();
void coverPassword();
void comparesPasswords();
bool StrongNess(string &input);
void password();
void phoneNumber();
void assignToMap();
void storeData();
void reg();
void login();
string encrypt(string password);
string decrypt(string e_password);
void checkTheOldPass();
void newPass();
void storeAndChangePass();
void changePassword();

#endif