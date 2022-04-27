#include "LoginFunctions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
// #include <conio.h>

using namespace std;

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

void menu()
{
    cout << "Hello user\nWhat do you want to do?" << endl;
    cout << "1-Register\n2-Login\n3-Change Password\n4-Exit" << endl;
    cout << "Please choose: ";
}

void extractFileData()
{
    fstream file;
    char ch[400];
    file.open("data.txt", ios::in);
    file.getline(ch, 400);
    while (!file.eof())
    {
        int id = stoi(ch);
        users[id].userId = id;
        file.getline(ch, 400);
        users[id].userName = ch;
        file.getline(ch, 400);
        users[id].email = ch;
        file.getline(ch, 400);
        users[id].oldPassword = ch;
        file.getline(ch, 400);
        users[id].password = ch;
        file.getline(ch, 400);
        users[id].phoneNumber = ch;
        file.getline(ch, 400);
        file.getline(ch, 400);
    }
    file.close();
}

bool is_valid_name(string str3)
{
    regex valid_name("[a-zA-Z_]+");
    return regex_match(str3, valid_name);
}

bool is_valid_email(string str)
{
    regex valid_email("[^.]([a-zA-Z0-9#!%$‘&+*–/=?^_`{|}~][.]?)+@[a-zA-Z]+\.[a-z]+");
    // regex valid_email("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(str, valid_email);
}
bool is_valid_phoneNumber(string str2)
{
    regex valid_PN("(01)(0|1|2|5)[0-9]+");
    return regex_match(str2, valid_PN);
}

void userId()
{
    cout << "Please enter your id: ";
    cin >> user.userId;

    while (isRegID(user.userId))
    {
        cout << "you entered ID that has been registered, please enter another ID:  ";
        cin >> user.userId;
    }
}

void userName()
{
    cout << "Please enter your name: ";
    cin >> user.userName;
    while (!(is_valid_name(user.userName)))
    {
        cout << "you entered name with incorrect format, please enter correct name: ";
        cin >> user.userName;
    }
}

void email()
{
    cout << "Please enter your email: ";
    cin >> user.email;

    for (auto j = users.begin(); j != users.end(); ++j)
    {
        while ((!(is_valid_email(user.email))) || (user.email == j->second.email))
        {
            cout << "you can't use this entered email, please enter another email: ";
            cin >> user.email;
            j = users.begin();
        }
    }
}

void password()
{
    cout << "Please enter your password: ";
    cin >> user.password;
}

void phoneNumber()
{
    cout << "Please enter your phone number: ";
    cin >> user.phoneNumber;
    while ((!(is_valid_phoneNumber(user.phoneNumber))) || (user.phoneNumber.length() != 11))
    {
        cout << "you entered phone number with incorrect format, please enter correct phone number: ";
        cin >> user.phoneNumber;
    }

}

void assign_to_map()
{
    users[user.userId].userId = user.userId;
    users[user.userId].userName = user.userName;
    users[user.userId].email = user.email;
    users[user.userId].oldPassword = "";
    users[user.userId].password = user.password;
    users[user.userId].phoneNumber = user.phoneNumber;
}

void store_data(){
    fstream file;
    file.open("data.txt", ios::out);
    for (auto i : users)
    {
        file << i.second.userId << endl;
        file << i.second.userName << endl;
        file << i.second.email << endl;
        file << i.second.oldPassword << endl;
        file << i.second.password << endl;
        file << i.second.phoneNumber << endl;
        file << endl;
    }
    file.close();
}

void reg()
{
    userId();
    userName();
    email();
    password();
    phoneNumber();
    assign_to_map();
    store_data();
}

bool isRegID(int id){
    if (users[id].userId == 0)
    {
        return false;
    }
    return true;
}

void login(){
    int id,trials=4;
    string password;
    while (trials !=0)
    {
        cout<< "Enter your ID: ";
        cin>>user.userId;
        cout<< "Enter your password: ";
        cin>> user.password;
        // string str;
        // char chr;
        // cin.ignore();
        // while (chr = _getch()!='\n')
        // {
        //     str+=chr;
        //     cout<<"*";     
        // }
        // user.oldPassword =str;
        //TODO: replace password with *****
        //TODO: decrypt password from data to compare
        if(users[user.userId].password== user.password && isRegID(user.userId)){
            cout<<"Successful login, welcome "<<users[user.userId].userName<<endl;
            break;
        }else
        {
            cout<<"Failed login. Try again."<<endl; 
            trials--; 
            if (trials<4)
            {
                cout<< "You have "<<trials<<" trials\n";
                if (trials == 0)
                {
                    cout<<"You have denied access to the system!!!\n";
                    break;
                }
                
            }
        }   
    }  
}