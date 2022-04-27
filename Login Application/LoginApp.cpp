#include "LoginFunctions.cpp"
#include <iostream>

int main(){
    int choice;
    extractFileData();
<<<<<<< HEAD
    // test();
    login();
=======

    while (true)
    {
        menu();
        cin >> choice;
        if (choice == 1)
        {
            reg();
        }
        else if (choice == 2)
        {
            return 0;
        }
        else if (choice == 3)
        {
            return 0;
        }
        else if (choice == 4)
        {
            return 0;
        }
        else
        {
            cout << "wrong choice, please choose again" << endl;
        }
    }
>>>>>>> 492aa8cc456c335c9fb87adcbb878beac779f024
}
