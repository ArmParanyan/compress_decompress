#include <iostream>
#include <vector>
#include <fstream>
#include <string>

//checks if the string is number or not
bool is_number(std::string num) {
    for (int i = 0; i < num.length(); ++i)
    {
        if( num[i] > '9' || num[i] < '0') 
        {
            return false;
        }
    }
    return true;
}

//checks if the symbol is not number;
bool is_symbol(char num)
{
    if (num > '9' || num < '0') {
        return true;
    }
    return false;
}

//checks if the symbol is number or not
bool is_number(char num) {
    return (num > '9' || num < '1');
}

//converts string to integer
int my_stoi (std::string num)
{
   int result = -1;
    
    if (is_number(num)) 
    {
        result = 0;
        for (int i = 0; i < num.length(); ++i)
        {
            result += (int)num[i] - '0';
            result *= 10;
        }
    }
    return result/10;
}

//compresses the given string
std::string compress(std::string& text) {
    std::unordered_map<char, int> map;
    int size = text.size();
    std::string str = "";
    for (int i = 0; i < size; ++i) {
        ++map[text[i]];
    }
    for (int i = 0; i < size; ++i) {
        char currsymb = text[i];
        if  (map[text[i]]) { 
            str += currsymb;
            str += std::to_string(map[text[i]]);
            map[text[i]] = 0;
        }
    }
    return str;
}

//decompresses the given string
std::string decompress(std::string& text) {
    std::string str = "";
    int size = text.size();
    for (int i = 0; i < size; ++i) {
        char currentsymbol = text[i];
        std::string tmp = "";
        if (is_symbol(text[i + 1])) {
            tmp.push_back(text[i + 1]);
        }
        while (!is_symbol(text[i + 1])) {
            tmp.push_back(text[i + 1]);
            ++i;
        }
        if (is_number(tmp)) {
            int count = my_stoi(tmp);
            
            while(count) {
                str.push_back(currentsymbol);
                --count;
            }
        }
        else if (is_symbol(currentsymbol)) {
            
            str.push_back(currentsymbol);
        }
    }
    
    return str;
}

//file copression
void file_compresed() {
    std::ifstream fin;
    std::ofstream fout;
    std::string text;
    fin.open("input.txt");
    fout.open("output.txt");
    if (fin.is_open()) {
        text = {};
        while (!fin.eof()) {
            getline(fin, text);
            fout << compress(text);
        }
    }
}

//file decompressetion
void file_decompresed() {
    std::ifstream fin;
    std::ofstream fout;
    std::string text;
    fin.open("input.txt");
    fout.open("output.txt");
    if (fin.is_open()) {
        text = {};
        while (!fin.eof()) {
            getline(fin, text);
            fout << decompress(text) << " ";
        }
    }
}

// user choices what to do with file
void what_to_do_whith_file() {
  
    char choice = '0';
    do {
        std::cout << "What you want to do with your txt file:\n";
        std::cout << "Do you want to compress or decompress.\n";
        std::cout << "For compressing pres 1:\n";
        std::cout << "For decompressing pres 2:\n";
        std::cout << "Enter your choise: " <<std::endl;
        std::cin >> choice;
        std::cout << std::endl;
    } while ((choice != '1' && choice != '2'));  

    switch (choice)
    {
    case '1':
        file_compresed();
        break;
    case '2':
        file_decompresed();
        break;
    }
}
