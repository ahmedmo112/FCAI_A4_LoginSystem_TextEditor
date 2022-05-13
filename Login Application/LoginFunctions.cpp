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
            reg();
        }
        else if (choice == 2)
        {
            login();
        }
        else if (choice == 3)
        {
            changePassword();
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
        users[id].userId = id; //add the id to the map of struct with id as key 
        file.getline(ch, 400); 
        users[id].userName = ch; //add the name to the map of struct with id as key 
        file.getline(ch, 400);
        users[id].email = ch; //add the email to the map of struct with id as key 
        file.getline(ch, 400);
        users[id].password = ch;//add the password to the map of struct with id as key 
        file.getline(ch, 400);
        users[id].phoneNumber = ch; //add the phone number to the map of struct with id as key 
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
    regex valid_email("[^.]([a-zA-Z0-9#!%$‘&+*–/=?^_`{|}~][.]?)+@[a-zA-Z]+(.com)");
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

string passwd2;
void repeat_password()
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

string passwd;
void coverpassword()
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

void compares_passwords()
{
    int pass = 3;
    while (pass > 0)
    {
        if (passwd != passwd2)
        {
            passwd2 = "";
            cout << endl;
            cout << "passwords are not the same \n please enter it again : ";
            repeat_password();
            pass -= 1;
        }
        else
        {
            break;
        }
    }
}

bool StrongNess(string &input)
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
        coverpassword();
        // StrongNess(passwd);
    } while (!(StrongNess(passwd)));
    cout << endl;
    cout << "repeat password : ";
    repeat_password();
    cout << endl;
    compares_passwords();
    user.password = passwd;
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

//Function to assign the user input data to map of struct with id as key
void assign_to_map()
{
    users[user.userId].userId = user.userId; //add the id to the map of struct with id as key 
    users[user.userId].userName = user.userName; //add the user name to the map of struct with id as key 
    users[user.userId].email = user.email; //add the email to the map of struct with id as key 
    users[user.userId].password = encrypt(user.password); //add the encrypted password to the map of struct with id as key 
    users[user.userId].phoneNumber = user.phoneNumber; //add the phonenumber to the map of struct with id as key 
}

void store_data() // function to store each elament at the map to file
{
    fstream file;
    file.open("data.txt", ios::out); // open file at input mode
    for (auto i : users) //loops on each elament at map
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
    assign_to_map();
    store_data();
}

bool isRegID(int id) // function chackes if the id is Registered before
{
    if (users[id].userId == 0) //chack the id of the input id is 0 or some thing else
    {
        return false; // return false if dosen't exist 
    }
    return true; // return true if exist
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
        coverpassword(); // get from user password 
        cout << endl;
        user.password = encrypt(passwd); // assign encrypted passwd to the user password from struct 
        // compare the encrypted stored password with the input password  and chack the id is exist
        if (users[user.userId].password == user.password && isRegID(user.userId))
        {
            cout << "Successful login, welcome " << users[user.userId].userName << endl; 
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
        coverpassword(); // take from user the old password coverd with stras
        if (decrypt(users[user.userId].password) == passwd) // compare the stored password with the input password
        {
            break; // if ture break
        }
        cout << "Error, Please Re-Enter The Old Password: ";
    }
}

void newPass() // Function take the new password
{
    do
    {
        //display the rules
        cout << "\nmake sure that : \n 1- including letters, numbers, and upper and lower case \n 2- never use less than 8 characters\n ";
        cout << "Please Enter The New Password: ";
        coverpassword(); // take from user the old password coverd with stras
    } while (!(StrongNess(passwd))); //loop till the password become strong 
    cout << "Please Enter The New Password Again: ";
    repeat_password(); // take from user the old password coverd with stras again
    if (passwd2 != passwd) //compare two passwords
    {
        cout << "The Passwords doesn't match Please enter it again...\n";
        newPass(); // is doesn't equal call the function newPass again
    }
}

void storeAndChangePass() // Function for Storing the new password  
{
    users[user.userId].password = encrypt(passwd); //assing to the passord value of id key the encrypted password
}

void changePassword() // The main function to change password
{
    cout << "Please Login First...\n";
    login(); // Login first
    checkTheOldPass(); // take the old password and chack is true 
    newPass(); // take the new password
    storeAndChangePass(); // saving the new password
    cout << "Password Changed Successfully\n\n";
    store_data(); //save data to file 
}