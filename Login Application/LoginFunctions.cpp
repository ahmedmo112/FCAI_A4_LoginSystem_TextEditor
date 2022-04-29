#include "LoginFunctions.h"

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
    regex valid_email("[^.]([a-zA-Z0-9#!%$‘&+*–/=?^_`{|}~][.]?)+@[a-zA-Z]+(.)[a-z]+");
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

void assign_to_map()
{
    users[user.userId].userId = user.userId;
    users[user.userId].userName = user.userName;
    users[user.userId].email = user.email;
    users[user.userId].oldPassword = "";
    users[user.userId].password = encrypt(user.password);
    users[user.userId].phoneNumber = user.phoneNumber;
}

void store_data()
{
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

bool isRegID(int id)
{
    if (users[id].userId == 0)
    {
        return false;
    }
    return true;
}

string pass;

void login()
{
    int id, trials = 4;
    // string password;
    while (trials != 0)
    {
        cout << "Enter your ID: ";
        cin >> user.userId;
        cout << "Enter your password : ";
        coverpassword();
        cout << endl;
        user.password = passwd;
        pass = passwd;
        cout << "var: " << passwd << endl;
        // user.oldPassword =str;
        user.password = encrypt(passwd);
        // TODO: replace password with *****
        // TODO: decrypt password from data to compare
        if (users[user.userId].password == user.password && isRegID(user.userId))
        {
            cout << "Successful login, welcome " << users[user.userId].userName << endl;
            cout << "TEST: Password *after decryption* " << decrypt(user.password) << endl; // Testing decryption##############
            break;
        }
        else
        {
            cout << "Failed login. Try again." << endl;
            trials--;
            if (trials < 4)
            {
                cout << "You have " << trials << " trials\n";
                if (trials == 0)
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

void checkTheOldPass()
{
    cout << user.userId << endl;
    cout << "Please Enter The Old Password: ";
    while (true)
    {
        coverpassword();
        if (decrypt(users[user.userId].password) == passwd)
        {
            break;
        }
        cout << "Error, Please Re-Enter The Old Password: ";
    }
}

void checkIsNotOldpass()
{
    int findIndex = users[user.userId].oldPassword.find(encrypt(passwd));
    if (findIndex < 100)
    {
        cout << "This Password Used Before, Please Enter New One...\n";
        newPass();
    }
}
void newPass()
{
    // passwd = "";
    // cin.ignore();
    do
    {
        cout << "\nmake sure that : \n 1- including letters, numbers, and upper and lower case \n 2- never use less than 8 characters\n ";
        cout << "Please Enter The New Password: ";
        coverpassword();
        // StrongNess(passwd);
    } while (!(StrongNess(passwd)));
    checkIsNotOldpass();
    // string passwd2;
    cout << "Please Enter The New Password Again: ";
    repeat_password();
    if (passwd2 != passwd)
    {
        cout << "The Passwords doesn't match Please enter it again...\n";
        newPass();
    }
}

void storeAndChangePass()
{
    users[user.userId].oldPassword += " ";
    users[user.userId].oldPassword += user.password;
    users[user.userId].password = encrypt(passwd);
}

void changePassword()
{
    cout << "Please Login First...\n";
    login();
    checkTheOldPass();
    newPass();
    storeAndChangePass();
    cout << "Password Changed Successfully\n\n";
    store_data();
}