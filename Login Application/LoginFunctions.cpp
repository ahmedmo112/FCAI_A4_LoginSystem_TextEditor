#include "LoginFunctions.h"
#include <iostream>
#include <fstream>
#include <map>
// #include <conio.h>

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
    // int id;
    // cout<<"Enter user id: ";
    // cin>>id;
    // cout<<"name: "<<users[id].name<<endl;
    // cout<<"email: "<<users[id].email<<endl;
    // cout<<"password: "<<users[id].password<<endl;
    // cout<<"phone: "<<users[id].phoneNumber<<endl;
    for(auto e:users){
        cout<<e.second.email<<endl;
    }
}

void login(){
    int id,trials=4;
    string password;
    while (trials !=0)
    {
        cout<< "Enter your ID: ";
        cin>>id;
        cout<< "Enter your password: ";
        cin>> password;
        // string str;
        // char chr;
        // cin.ignore();
        // while (chr = _getch()!='\n')
        // {
        //     str+=chr;
        //     cout<<"*";     
        // }
        //TODO: replace password with *****
        //TODO: decrypt password from data to compare
        if(users[id].password==password){
            cout<<"Successful login, welcome "<<users[id].name<<endl;
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
