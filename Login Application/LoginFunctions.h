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


map<int, Users> users;

void menu();
void extractFileData();
bool is_valid_name();
bool is_valid_email();
bool is_valid_phoneNumber();
void userId();
void userName();
void email();
void password();
void phoneNumber();
void assign_to_map();
void store_data();
void reg();
bool isRegID(int id);
void login();
void newPass();

string encrypt(string password);
string decrypt(string e_password);

#endif