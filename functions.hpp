#include <iostream>
#include <vector>
#include <fstream>
#include <string>

//checks if the given string is nubmer or not
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

//checks if the given char is number or not
bool is_number(char num) {
    return (num > '9' || num < '1');
}

//convert's string to int
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

//compressing the given string
std::string compress(std::string& text) {
    int size = text.size();
    std::string compressed {};
    for (int i = 0; i < size;  ++i) {
        char current_symbol = text[i];
        int count = 1;
        while (text[i + 1] == current_symbol) {
            ++count;
            ++i;
        }
        compressed += current_symbol;
        if (count >= 2) {
            compressed += std::to_string(count);
        }
    }
    text = {};
    text += compressed;
    return text;
}

//decompressing the given string
std::string decompress(std::string& text) {
    std::string str = "";
    int size = text.size();
    for (int i = 0; i < size; ++i) {
        char currentsymbol = text[i];
        std::string tmp = "";
        tmp.push_back(text[i + 1]);
        if (is_number(tmp))
        {
            int count  = my_stoi(tmp);
            while(count > 0)
            {
                str.push_back(currentsymbol);
                --count;
            }
        }
        else if (is_number(currentsymbol))
        {
            str.push_back(currentsymbol);
        }
    }
    return str;
}



//copressing what is in the file
void file_compresed() {
    std::ifstream fin;
    std::ofstream fout;
    std::string text;
    fin.open("input.txt");
    fout.open("output.txt");
    if (fin.is_open() && fout.is_open()) {
        text = {};
        while (!fin.eof()) {
            getline(fin, text);
            fout << compress(text);
        }
    }
}

//decopressing what is in the file
void file_decompresed() {
    std::ifstream fin;
    std::ofstream fout;
    std::string text;
    fin.open("input.txt");
    fout.open("output.txt");
    if (fin.is_open() && fout.is_open()) {
        text = {};
        while (!fin.eof()) {
            fin >> text;
            //getline(fin, text);
            fout << decompress(text) << std::endl;
        }
    }
}

// comprasse or decomprasse file
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
