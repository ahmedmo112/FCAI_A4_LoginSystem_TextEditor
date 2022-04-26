#include "LoginFunctions.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map<int, Users> users;

void extractFileData(){
    fstream file;
    char ch[400];
    file.open("data.txt",ios::in);
    file.getline(ch,400);
    while (!file.eof())
    {
        int id = stoi(ch);
        users[id].id = id;
        file.getline(ch,400);
        users[id].name = ch; 
        file.getline(ch,400);
        users[id].email = ch;
        file.getline(ch,400);
        users[id].oldPassword = ch;
        file.getline(ch,400);
        users[id].password = ch;
        file.getline(ch,400);
        users[id].phoneNumber = ch;
        file.getline(ch,400);
        file.getline(ch,400);
    }
    file.close();
}

void test(){ // for test that the data is saved at map 
    int id;
    cout<<"Enter user id: ";
    cin>>id;
    cout<<"name: "<<users[id].name<<endl;
    cout<<"email: "<<users[id].email<<endl;
    cout<<"password: "<<users[id].password<<endl;
    cout<<"phone: "<<users[id].phoneNumber<<endl;
}
