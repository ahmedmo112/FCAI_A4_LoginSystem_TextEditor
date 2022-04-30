#include "TextEditorFunc.h"

int displayMenu()
{    
    int choice;
    
    cout << "\nHello user\nWhat do you want to do\n" << endl;
    cout << "1-Add new text to the end of the file\n2-Display the content of the file\n3-Empty the file\n4-Encrypt the file content\n5-Decrypt the file content" << endl;
    cout << "6-Merge another file\n7-Count the number of words in the file\n8-Count the number of characters in the file\n9-Count the number of lines in the file\n10-Search for a word in the file" << endl;
    cout << "11-Count the number of times a word exists in the file\n12-Turn the file content to upper case\n13-Turn the file content to lower case\n14-Turn file content to 1st caps\n15-Save\n16-Exit" << endl;
    cout << "\nPlease choose: ";
    cin >> choice;
    cout << endl;
    while (true)
    {
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

        }
        else if (choice == 7)
        {
        }
        else if (choice == 8)
        {
        }
        else if (choice == 9)
        {
        }
        else if (choice == 10)
        {
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
    cin.getline(text, 10000, char(26));
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
    for(char i:content)
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
    for(char i:content)
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

void n_WordExist(){
    int count=0;
    vector<string> splited_words;
    string store_str, word ;
    char lowerStr[2000];

    cout<<"Please Enter a Word: ";
    cin>>word;
    word = toLower(word);
    
    for (int i = 0; i < content.length(); i++)
    {
        lowerStr[i] = tolower(content[i]);
    }

    for (int i = 0; i < content.length(); i++)
    {
        if (lowerStr[i]!=' ' && lowerStr[i]!='\n')
        {
            store_str+=lowerStr[i];
        }else{
            splited_words.push_back(store_str);
            store_str="";
        } 
    }
    splited_words.push_back(store_str);
    
    for (int i = 0; i < content.length(); i++)
    {
        if (word == splited_words[i])
        {
            count++;
        }
        
    }
    cout<<"The word \"" << word << "\" was found "<< count <<" times"<<endl;
}

string toLower(string str){
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
        content[i]= toupper(content[i]);
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
        if (content[i - 1] == ' ' || content[i - 1] == '\n' )
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
    file.open(fileName,ios::out);
    for (int i = 0; i < content.length(); i++)
    {
        file << content[i];
    }
    file.close();
}