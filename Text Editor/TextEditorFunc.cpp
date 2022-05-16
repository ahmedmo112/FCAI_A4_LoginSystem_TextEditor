// FCAI - Programming 1 - 2022 - Assignment 4
// Program Name: Text Editor
// Program Description: Edit on text files
// Last Modification Date: 14/5/2022
// Second author - ID : Ahmed Mohamed Hany / 20210038
// First author - ID : Salma Mohammed Mahmoud / 20210161
// Third author - ID : Ahmed Reda Elsayed / 20210018
// Under The Supervision of: Dr. Mohamed El-Ramly


#include "TextEditorFunc.h"

int displayMenu()
{
    int choice;

    while (true)
    {
        cout << "\nHello user\nWhat do you want to do\n"
             << endl;
        cout << "1-Add new text to the end of the file\n2-Display the content of the file\n3-Empty the file\n4-Encrypt the file content\n5-Decrypt the file content" << endl;
        cout << "6-Merge another file\n7-Count the number of words in the file\n8-Count the number of characters in the file\n9-Count the number of lines in the file\n10-Search for a word in the file" << endl;
        cout << "11-Count the number of times a word exists in the file\n12-Turn the file content to upper case\n13-Turn the file content to lower case\n14-Turn file content to 1st caps\n15-Save\n16-Exit" << endl;
        cout << "\nPlease choose: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            addingContent();
        }
        else if (choice == 2)
        {
            displayContent();
        }
        else if (choice == 3)
        {
            eraseContent();
        }
        else if (choice == 4)
        {
            encryptContent();
        }
        else if (choice == 5)
        {
            decryptContent();
        }
        else if (choice == 6)
        {
            merge();
        }
        else if (choice == 7)
        {
            countWords();
        }
        else if (choice == 8)
        {
            countCharacters();
        }
        else if (choice == 9)
        {
            countLines();
        }
        else if (choice == 10)
        {
            findWord();
        }
        else if (choice == 11)
        {
            n_WordExist();
        }
        else if (choice == 12)
        {
            contentToUpper();
        }
        else if (choice == 13)
        {
            contentToLower();
        }
        else if (choice == 14)
        {
            firstCap();
        }
        else if (choice == 15)
        {
            saveFile();
        }
        else if (choice == 16)
        {
            return 0;
        }
        else
        {
            cout << "wrong choice, please choose again" << endl;
        }
    }
}

void loadFile() // Function for load data from file
{
    cout << "Please Enter Your File Name: ";
    cin >> fileName; // take file name from user
    file.open(fileName, ios::in); // opem file at read mode 
    if (file.fail()) // check if file  exist 
    {
        file.open(fileName, ios::out); //open new file at write mode to create it if the file doesn't exist 
        cout << "This is a new file. I created it for you \n";
    }
    else
    {
        //if file exist
        cout << "This File Already Exists\n";
        char ch;
        file.get(ch); // get every char from file till End Of File
        while (!file.eof())
        {
            content += ch; //add charachter to string names content 
            file.get(ch);
        }
    }

    file.close(); //close file
}

void addingContent()
{
    char text[10000];
    cout << "Enter the text you want to append: ";
    cin.ignore();
    cin.getline(text, 10000, char(26)); // take input character by character until faces (CTRl + z) which is (26) by ascii
    if (content != "")
    {
        content += "\n";
    }
    content += text;
}

void displayContent()
{
    cout << content << endl;
}

void eraseContent()
{
    content = "";
}

void encryptContent()
{
    string encrypt = "";
    for (char i : content)
    {
        if (i == '\n')
        {
            encrypt += '\n';
        }
        else
        {
            encrypt += char(int(i) + 1); // encrypt each character by one in ascii
        }
    }
    content = encrypt;
}

void decryptContent()
{
    string decrypt = "";
    for (char i : content)
    {
        if (i == '\n')
        {
            decrypt += '\n';
        }
        else
        {
            decrypt += char(int(i) - 1); // decrypt each character by one in ascii
        }
    }
    content = decrypt;
}

void merge()
{
    fstream file2;
    char name[80];
    char ch;
    cout << "Enter file name: ";
    cin >> name;
    file2.open(name); // open the second file to merge
    if (file2.fail())
    {
        cout << "Invalid File Name" << endl;
    }
    else
    {
        file2.get(ch);
        content += '\n';
        while (!file2.eof())
        {
            content += ch;// add each character from second file to the first file
            file2.get(ch);
        }
        file2.close();
    }
}

void countWords()
{

    unsigned count = 0;
    int state = 0, i = 0, out = 0, in = 1;

    while (content[i] != '\0') // (\0) is the NULL character it has the value zero
    {
        if (content[i] == ' ' || content[i] == '\n' || content[i] == '\t')
            state = out;
        else if (state == out)
        {
            state = in;
            ++count;
        }

        ++i;
    }
    cout << "\nThere are " << count << " word in the given file\n";
}

void countCharacters()
{
    cout << "number of characters is : " << content.length() << endl;
}

void countLines()
{

    int count = 1, i = 0;
    while (content[i] != '\0')// (\0) is the NULL character it has the value zero
    {
        if (content[i] == '\n')
        {
            count++;
        }
        ++i;
    }
    cout << "\nThere are " << count << " line in the given file\n";
}

string stringToLower(string str) // Function to convert string to lower case 
{
    for (int i = 0; i < str.length(); i++) // loop from 0 to the str length 
    {
        str[i] = tolower(str[i]); //convert each char to lowercase
    }
    return str; //return string 
}

void findWord()
{
    int count = 0;
    vector<string> word_by_word;
    string store_word, temp;
    char lowerStr_arr[2000];
    bool check = false;

    cout << "Please Enter a Word: ";
    cin >> temp;
    temp = stringToLower(temp);

    for (int i = 0; i < content.length(); i++)
    {
        lowerStr_arr[i] = tolower(content[i]);
    }

    for (int i = 0; i < content.length(); i++)
    {
        if (lowerStr_arr[i] != ' ' && lowerStr_arr[i] != '\n')
        {
            store_word += lowerStr_arr[i];
        }
        else
        {
            word_by_word.push_back(store_word); // push back words to vector
            store_word = "";
        }
    }
    word_by_word.push_back(store_word);

    for (int i = 0; i < word_by_word.size(); i++)
    {
        if (temp == word_by_word[i]) // check if entered word to find is exist in vector
        {
            check = true;
            break;
        }
    }
    if (check == true)
    {
        cout << "word was found :D" << endl;
    }
    if (check == false)
    {
        cout << "word wasn't found;(" << endl;
    }
}

void n_WordExist() // Function get the number of word repeated in file
{
    int count = 0;
    vector<string> splited_words; //vector to split each word
    string store_str, word;
    string lowerStr;

    cout << "Please Enter a Word: ";
    cin >> word; // take word from user 

    word = stringToLower(word); //convert it to lower case by caling function stringToLower()
    lowerStr = stringToLower(content); //convert content to lower case and assign it to lowerStr string 

    for (int i = 0; i < content.length(); i++) //loop from 0 to length of content for looping  on each char 
    {
        if (lowerStr[i] != ' ' && lowerStr[i] != '\n') //check the char is not equal space or new line
        {
            store_str += lowerStr[i]; //add the char to string names store_str
        }
        else
        {
            splited_words.push_back(store_str); // add the string store_str to vector 
            store_str = ""; //set store_str to Empty string
        }
    }
    splited_words.push_back(store_str); // push back last word

    for (int i = 0; i < splited_words.size(); i++) // loop from 0 to vector size to get each one 
    {
        if (word == splited_words[i]) // compare the ward with each word of vector
        {
            count++; // increament the count by 1
        }
    }
    cout << "The word \"" << word << "\" was found " << count << " times" << endl;
}

void contentToUpper() //function to convert the content of file to uppercase
{
    for (int i = 0; i < content.length(); i++) // loop from 0 to the content length
    {
        content[i] = toupper(content[i]);  //convert each char to uppercase
    }
}

void contentToLower() //function to convert the content of file to lower case
{
    content = stringToLower(content); // set the content with return value of function StringToLower()
}

//function to convert the first char of the word to uppercase
// and the other alphapet of the word to Lowercase
void firstCap() 
{
    for (int i = 0; i < content.length(); i++) // loop from 0 to the content length
    {
        //chack if the previous char is space or newline or is the first index 0
        if (content[i - 1] == ' ' || content[i - 1] == '\n' || i == 0)
        {
            content[i] = toupper(content[i]); //convert char to upper case 
        }
        else
        {
            content[i] = tolower(content[i]); //convert char to lower case
        }
    }
}

void saveFile() // Function for save the file
{
    int choice;
    cout << "For Save The File with The Same File Name Enter 1 \nOr Under a Different Name Enter 2: ";
    cin >> choice; // take the user choice
    if (choice == 1) // if choose 1 mean he want to save with the same name
    {
        file.open(fileName, ios::out); // open file at output mode 
        for (int i = 0; i < content.length(); i++) // loop from 0 to the content length
        {
            file << content[i]; // write each char to the file
        }
        file.close();
    }
    else if (choice == 2) // if choose 2 mean he want to save with the different name 
    {
        char diff_fileName[100];
        cout << "Please Enter The new file name (end with .txt): ";
        cin >> diff_fileName; //take from user the new file name 
        file.open(diff_fileName, ios::out); // open file at output mode 
        for (int i = 0; i < content.length(); i++) // loop from 0 to the content length
        {
            file << content[i]; // write each char to the file
        }
        file.close();
    }
    else
    {
        cout << "Error, Please Try Again and 1 Or 2 only...\n";
    }
}