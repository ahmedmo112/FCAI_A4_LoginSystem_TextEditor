#include "TextEditorFunc.h"

void loadFile()
{
    cout << "Please Enter Your File Name: ";
    cin >> fileName;
    fstream file;
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

void saveFile(){
    fstream file;
    file.open(fileName,ios::out);
    for (int i = 0; i < content.length(); i++)
    {
        file << content[i];
    }
    file.close();
}