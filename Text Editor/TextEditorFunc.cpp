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
            count_words();
        }
        else if (choice == 8)
        {
            count_characters();
        }
        else if (choice == 9)
        {
            count_lines();
        }
        else if (choice == 10)
        {
            find_word();
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

void loadFile()
{
    cout << "Please Enter Your File Name: ";
    cin >> fileName;
    file.open(fileName, ios::in);
    if (file.fail())
    {
        file.open(fileName, ios::out);
        cout << "This is a new file. I created it for you \n";
    }
    else
    {
        cout << "This File Already Exists\n";
        char ch;
        file.get(ch);
        while (!file.eof())
        {
            content += ch;
            file.get(ch);
        }
    }

    file.close();
}

void addingContent()
{
    char text[10000];
    cout << "Enter the text you want to append: ";
    cin.ignore();
    cin.getline(text, 10000, char(26));
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
            encrypt += char(int(i) + 1);
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
            decrypt += char(int(i) - 1);
        }
    }
    content = decrypt;
}

void merge()
{
    fstream file2;
    char name[80];
    char ch;
    cout << "Enter file name\n";
    cin >> name;
    file2.open(name);
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
            content += ch;
            file2.get(ch);
        }
        file2.close();
    }
}

void count_words()
{

    unsigned count = 0;
    int state = 0, i = 0, out = 0, in = 1;

    while (content[i] != '\0')
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
    cout << "\nThere are " << count << " word in the given file";
}

void count_characters()
{
    cout << "number of characters is : " << content.length() << endl;
}

void count_lines()
{

    int count = 1, i = 0;
    while (content[i] != '\0')
    {
        if (content[i] == '\n')
        {
            count++;
        }
        ++i;
    }
    cout << "\nThere are " << count << " line in the given file";
}

void find_word()
{
    int count = 0;
    vector<string> splited_words;
    string store_str, word;
    char lowerStr[2000];
    bool check = false;

    cout << "Please Enter a Word: ";
    cin >> word;
    word = toLower(word);

    for (int i = 0; i < content.length(); i++)
    {
        lowerStr[i] = tolower(content[i]);
    }

    for (int i = 0; i < content.length(); i++)
    {
        if (lowerStr[i] != ' ' && lowerStr[i] != '\n')
        {
            store_str += lowerStr[i];
        }
        else
        {
            splited_words.push_back(store_str);
            store_str = "";
        }
    }
    splited_words.push_back(store_str);

    for (int i = 0; i < splited_words.size(); i++)
    {
        if (word == splited_words[i])
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

void n_WordExist()
{
    int count = 0;
    vector<string> splited_words;
    string store_str, word;
    char lowerStr[2000];

    cout << "Please Enter a Word: ";
    cin >> word;
    word = toLower(word);

    for (int i = 0; i < content.length(); i++)
    {
        lowerStr[i] = tolower(content[i]);
    }

    for (int i = 0; i < content.length(); i++)
    {
        if (lowerStr[i] != ' ' && lowerStr[i] != '\n')
        {
            store_str += lowerStr[i];
        }
        else
        {
            splited_words.push_back(store_str);
            store_str = "";
        }
    }
    splited_words.push_back(store_str);

    for (int i = 0; i < splited_words.size(); i++)
    {
        if (word == splited_words[i])
        {
            count++;
        }
    }
    cout << "The word \"" << word << "\" was found " << count << " times" << endl;
}
string toLower(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

void contentToUpper()
{
    for (int i = 0; i < content.length(); i++)
    {
        content[i] = toupper(content[i]);
    }
}

void contentToLower()
{
    content = toLower(content);
}

void firstCap()
{
    for (int i = 0; i < content.length(); i++)
    {
        if (content[i - 1] == ' ' || content[i - 1] == '\n' || i == 0)
        {
            content[i] = toupper(content[i]);
        }
        else
        {
            content[i] = tolower(content[i]);
        }
    }
}

void saveFile()
{
    int choice;
    cout << "For Save The File with The Same File Name Enter 1 \nOr Under a Different Name Enter 2: ";
    cin >> choice;
    if (choice == 1)
    {
        file.open(fileName, ios::out);
        for (int i = 0; i < content.length(); i++)
        {
            file << content[i];
        }
        file.close();
    }
    else if (choice == 2)
    {
        char diff_fileName[100];
        cout << "Please Enter The new file name (end with .txt): ";
        cin >> diff_fileName;
        file.open(diff_fileName, ios::out);
        for (int i = 0; i < content.length(); i++)
        {
            file << content[i];
        }
        file.close();
    }
    else
    {
        cout << "Error, Please Try Again and 1 Or 2 only...\n";
    }
}