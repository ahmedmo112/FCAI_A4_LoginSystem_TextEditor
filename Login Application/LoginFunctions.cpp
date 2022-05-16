// FCAI - Programming 1 - 2022 - Assignment 4
// Program Name: Login Application
// Program Description: Login System allow user to (Register - Login - Change Password)
// Last Modification Date: 11/5/2022
// Second author - ID : Ahmed Mohamed Hany / 20210038
// First author - ID : Salma Mohammed Mahmoud / 20210161
// Third author - ID : Ahmed Reda Elsayed / 20210018
// Under The Supervision of: Dr. Mohamed El-Ramly


#include "LoginFunctions.h"

int menu()
{
    int choice;
    
    while (true)
    {
        cout << "\nHello user\nWhat do you want to do?" << endl;
        cout << "1-Register\n2-Login\n3-Change Password\n4-Exit" << endl;
        cout << "Please choose: ";
        cin >> choice;
        cout << endl;
        
        if (choice == 1)
        {
            cout << "--------------------You are now in Register page--------------------" << endl;
            reg();
        }
        else if (choice == 2)
        {
            cout << "--------------------You are now in Login page--------------------" << endl;
            login();
        }
        else if (choice == 3)
        {
            cout << "--------------------You are now in Change Password page--------------------" << endl;
            changePassword();
        }
        else if (choice == 4)
        {
            cout << "Good Bye, Hope Satisfy you" << endl;
            return 0;
        }
        else
        {
            cout << "wrong choice, please choose again" << endl;
        }
    }
}

void extractFileData() // Function to extract the data from file
{
    fstream file;
    char ch[400];
    file.open("data.txt", ios::in); //open file at input mode
    file.getline(ch, 400); // get each line and add it to  array of char
    while (!file.eof()) // get lines till reach the End Of File
    {
        //we read depends on file format
        int id = stoi(ch); //convert id to int
        map_users[id].userId = id; //add the id to the map of struct with id as key 
        file.getline(ch, 400); 
        map_users[id].userName = ch; //add the name to the map of struct with id as key 
        file.getline(ch, 400);
        map_users[id].email = ch; //add the email to the map of struct with id as key 
        file.getline(ch, 400);
        map_users[id].password = ch;//add the password to the map of struct with id as key 
        file.getline(ch, 400);
        map_users[id].phoneNumber = ch; //add the phone number to the map of struct with id as key 
        file.getline(ch, 400);
        file.getline(ch, 400);
    }
    file.close();
}

bool isValidName(string str3)
{
    regex valid_name("[a-zA-Z_]+"); // User Name format by regex expression
    return regex_match(str3, valid_name); // check if the entered user name match user name format that formed by regex
}

bool isValidEmail(string str)
{
    regex valid_email("[^.]([a-zA-Z0-9#!%$‘&+*–/=?^_`{|}~][.]?)+@[a-zA-Z]+(.com)"); // Email format by regex expression
    return regex_match(str, valid_email); // check if the entered email match email format that formed by regex
}
bool isValidPhoneNumber(string str2)
{
    regex valid_PN("(01)(0|1|2|5)[0-9]+");
    return regex_match(str2, valid_PN); // check if the entered phone number match phoner number format that formed by regex
}

bool isRegID(int id) // function chackes if the id is Registered before
{
    if (map_users[id].userId == 0) //chack the id of the input id is 0 or some thing else
    {
        return false; // return false if dosen't exist 
    }
    return true; // return true if exist
}

void userId()
{
    cout << "Please enter your id: ";
    cin >> user.userId;

    while (isRegID(user.userId)) // check that entered id not used before by another registered user
    {
        cout << "you entered ID that has been registered, please enter another ID:  ";
        cin >> user.userId;
    }
}

void userName()
{
    cout << "Please enter your name: ";
    cin >> user.userName;
    while (!(isValidName(user.userName))) // check that entered user name match user name format that formed by regex 
    {
        cout << "you entered name with incorrect format, please enter correct name: ";
        cin >> user.userName;
    }
}

void email()
{
    cout << "Please enter your email: ";
    cin >> user.email;

    for (auto j = map_users.begin(); j != map_users.end(); ++j)
    {
        while ((!(isValidEmail(user.email))) || (user.email == j->second.email)) // check that entered email not used before by another registered user and check that entered email match email format that formed by regex 
        {
            cout << "you can't use this entered email, please enter another email: ";
            cin >> user.email;
            j = map_users.begin();
        }
    }
}


string passwd;
void coverPassword() // take password from user with (*) format
{
    int ch = 0;
    passwd = "";
    while (ch = getch())
    {
        if (ch == 13)
        {
            break;
        }
        else if (ch == 8)
        {
            if (passwd.length() > 0)
            {
                cout << "\b \b";
                passwd.erase(passwd.length() - 1);
            }
        }
        else
        {
            cout << "*";
            passwd += ch;
        }
    }
}

string passwd2;
void repeatPassword() // take password from user with (*) format
{
    int chh;
    while (chh = getch())
    {
        if (chh == 13)
        {
            break;
        }
        else if (chh == 8)
        {
            if (passwd2.length() > 0)
            {
                cout << "\b \b";
                passwd2.erase(passwd2.length() - 1);
            }
        }
        else
        {
            cout << "*";
            passwd2 += chh;
        }
    }
}

void comparesPasswords()
{
    int pass = 3;
    while (pass > 0)
    {
        if (passwd != passwd2)
        {
            passwd2 = "";
            cout << endl;
            cout << "passwords are not the same \n please enter it again : ";
            repeatPassword();
            pass -= 1;
        }
        else
        {
            break;
        }
    }
}

bool strongNess(string &input) // check that password is strong
{
    int n = input.length();

    // Checking lower alphabet in string
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;
    string normalChars = "abcdefghijklmnopqrstu"
                         "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

    for (int i = 0; i < n; i++)
    {
        if (islower(input[i]))
            hasLower = true;
        if (isupper(input[i]))
            hasUpper = true;
        if (isdigit(input[i]))
            hasDigit = true;

        size_t special = input.find_first_not_of(normalChars);
        if (special != string::npos)
            specialChar = true;
    }
    int pass = 3;

    cout << endl;
    cout << "Strength of password : ";
    if (hasLower && hasUpper && hasDigit &&
        specialChar && (n >= 8))
    {
        cout << "Strong" << endl;
        return true;
    }
    else if ((hasLower || hasUpper) &&
             specialChar && (n >= 6))
    {
        cout << "Moderate" << endl;
        return false;
    }
    else
    {
        cout << "Weak" << endl;
        return false;
    }
}

void password()
{
    cin.ignore();
    do
    {
        cout << "\nmake sure that : \n 1- including letters, numbers, and upper and lower case \n 2- never use less than 8 characters\n ";
        cout << "Please enter your password: ";
        coverPassword();
    } while (!(strongNess(passwd))); 
    cout << endl;
    cout << "repeat password : ";
    repeatPassword();
    cout << endl;
    comparesPasswords();
    user.password = passwd;
}
void phoneNumber()
{
    cout << "Please enter your phone number: ";
    cin >> user.phoneNumber;
    while ((!(isValidPhoneNumber(user.phoneNumber))) || (user.phoneNumber.length() != 11)) // check that phone number length is 11 and check that entered phone number match phone number format that formed by regex 
    {
        cout << "you entered phone number with incorrect format, please enter correct phone number: ";
        cin >> user.phoneNumber;
    }
}

//Function to assign the user input data to map of struct with id as key
void assignToMap()
{
    map_users[user.userId].userId = user.userId; //add the id to the map of struct with id as key 
    map_users[user.userId].userName = user.userName; //add the user name to the map of struct with id as key 
    map_users[user.userId].email = user.email; //add the email to the map of struct with id as key 
    map_users[user.userId].password = encrypt(user.password); //add the encrypted password to the map of struct with id as key 
    map_users[user.userId].phoneNumber = user.phoneNumber; //add the phonenumber to the map of struct with id as key 
}

void storeData() // function to store each elament at the map to file
{
    fstream file;
    file.open("data.txt", ios::out); // open file at input mode
    for (auto i : map_users) //loops on each elament at map
    {
        file << i.second.userId << endl; // write at first line the user id from map by key value
        file << i.second.userName << endl; // write at first line the user name from map by key value
        file << i.second.email << endl; // write at first line the user email from map by key value
        file << i.second.password << endl; // write at first line the user password from map by key value
        file << i.second.phoneNumber << endl; // write at first line the user phonenumber from map by key value
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
    assignToMap();
    storeData();
}

void login() //Function to Login 
{
    int id, trials = 4;
    // string password;
    while (trials != 0) // loop while the trials equal to 0
    {
        cout << "Enter your ID: ";
        cin >> user.userId; // get from user id 
        cout << "Enter your password : ";
        coverPassword(); // get from user password 
        cout << endl;
        user.password = encrypt(passwd); // assign encrypted passwd to the user password from struct 
        // compare the encrypted stored password with the input password  and chack the id is exist
        if (map_users[user.userId].password == user.password && isRegID(user.userId))
        {
            cout << "Successful login, welcome " << map_users[user.userId].userName << endl; 
            break;
        }
        else 
        {
            cout << "Failed login. Try again." << endl;
            trials--;  // decreasing the trials by one 
            if (trials < 4) // if trials less than 4
            {
                cout << "You have " << trials << " trials\n"; // desplay the trials left
                if (trials == 0) // if trials reach 0 denied access to the system
                {
                    cout << "You have denied access to the system!!!\n";
                    break;
                }
            }
        }
    }
}

string encrypt(string password)
{
    string hex_text = "";
    for (int i = 0; i < password.length(); i++) // for loop for each charachter
    {
        ostringstream s;                                         // string stream type
        password[i] = (password[i] ^ 'z');                       // XOR between key and the char
        s << setfill('0') << setw(2) << hex << int(password[i]); // if the XOR return hex one digit
                                                                 // number then fill the right digit with 0
        hex_text += s.str();                                     // convert the stream variable to string and add it to hex text
    }

    return hex_text; // print the hex text
}

string decrypt(string e_password)
{
    char chr;
    string originalPassword;
    int len = e_password.length(); // get the length of hex text
    for (int i = 0; i < len; i += 2)
    {
        string two_digit = e_password.substr(i, 2);           // get the two digit for every hex from hex text
        chr = (char)(int)strtol(two_digit.c_str(), NULL, 16); // convert two digit to long intger at 16 system (hex)
        originalPassword += (char)(chr ^ 'z');                // print the char of the original message
    }
    return originalPassword;
}

void checkTheOldPass() // function to chacking the old pass is true 
{
    cout << "Please Enter The Old Password: ";
    while (true)
    {
        coverPassword(); // take from user the old password coverd with stras
        if (decrypt(map_users[user.userId].password) == passwd) // compare the stored password with the input password
        {
            break; // if ture break
        }
        cout << "Error, Please Re-Enter The Old Password: ";
    }
}

void newPass() // Function take the new password
{
    passwd = "";
    passwd2 = "";

    do
    {
        //display the rules
        cout << "\nmake sure that : \n 1- including letters, numbers, and upper and lower case \n 2- never use less than 8 characters\n ";
        cout << "Please Enter The New Password: ";
        coverPassword(); // take from user the old password coverd with stras
    } while (!(strongNess(passwd))); //loop till the password become strong 
    cout << "Please Enter The New Password Again: ";
    repeatPassword(); // take from user the old password coverd with stras again
    if (passwd2 != passwd) //compare two passwords
    {
        cout << "The Passwords doesn't match Please enter it again...\n";
        newPass(); // is doesn't equal call the function newPass again
    }
}

void storeAndChangePass() // Function for Storing the new password  
{
    map_users[user.userId].password = encrypt(passwd); //assing to the passord value of id key the encrypted password
}

void changePassword() // The main function to change password
{
    cout << "Please Login First...\n";
    login(); // Login first
    checkTheOldPass(); // take the old password and chack is true 
    newPass(); // take the new password
    storeAndChangePass(); // saving the new password
    cout << "\nPassword Changed Successfully\n\n";
    storeData(); //save data to file 
}