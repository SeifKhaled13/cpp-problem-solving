// File: A2_S2_20221077_11.cpp
// Purpose: File Comparison.
// Author: Seif Eldin Khaled Rajab
// Section: S1,S2
// ID: 20221077
// TA: Eng/Khaled Ibrahim
// Date: 5 Nov 2023

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// function to check if a character is whitespace (space, tab, or newline)
bool isWhiteSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// function to compare two files character by character
bool compareCharacterByCharacter(const string& file1, const string& file2) {
    ifstream f1(file1 + ".txt"); // add .txt extension automatically to the file name
    ifstream f2(file2 + ".txt"); // add .txt extension automatically to the file name

    if (!f1.is_open() || !f2.is_open()) {
        cerr << "error opening files!" << endl; // error message if files cannot be opened
        return false;
    }

    int lineNum = 1;
    char c1, c2;

    while (!f1.eof() || !f2.eof()) {
        f1.get(c1); // read a character from the first file
        f2.get(c2); // read a character from the second file

        if (c1 != c2) {
            cout << "files are different at line " << lineNum << ":" << endl;
            cout << "file 1: " << c1 << endl;
            cout << "file 2: " << c2 << endl;
            return false;
        }

        if (c1 == '\n') {
            lineNum++; // increment line number when a newline character is encountered
        }
    }

    cout << "files are identical!" << endl;
    return true;
}

// function to compare two files word by word (ignoring whitespace, tabs, and newlines)
bool compareWordByWord(const string& file1, const string& file2) {
    ifstream f1(file1 + ".txt"); // open the first file for reading (with .txt extension)
    ifstream f2(file2 + ".txt"); // open the second file for reading (with .txt extension)

    if (!f1.is_open() || !f2.is_open()) {
        cerr << "error opening files!" << endl; // error message if files cannot be opened
        return false;
    }

    int lineNum = 1;
    string word1, word2;

    while (!f1.eof() || !f2.eof()) {
        f1 >> word1; // read a word from the first file (ignoring whitespace, tabs, and newlines)
        f2 >> word2; // read a word from the second file (ignoring whitespace, tabs, and newlines)

        // remove whitespace, tabs, and newlines from words
        word1.erase(remove_if(word1.begin(), word1.end(), isWhiteSpace), word1.end());
        word2.erase(remove_if(word2.begin(), word2.end(), isWhiteSpace), word2.end());

        if (word1 != word2) {
            cout << "files are different at line " << lineNum << ":" << endl;
            cout << "file 1: " << word1 << endl;
            cout << "file 2: " << word2 << endl;
            return false;
        }

        if (word1.find('\n') != string::npos) {
            lineNum++; // increment line number when a newline character is encountered within a word
        }
    }

    cout << "files are identical!" << endl;
    return true;
}

int main() {
    string file1, file2;
    char choice;

    cout << "enter the name of the first file (without .txt): ";
    cin >> file1;
    cout << "enter the name of the second file (without .txt): ";
    cin >> file2;

    cout << "choose comparison type (c for character-by-character, w for word-by-word): ";
    cin >> choice;

    if (choice == 'c') {
        compareCharacterByCharacter(file1, file2);
    } else if (choice == 'w') {
        compareWordByWord(file1, file2);
    } else {
        cout << "invalid choice. please select 'c' or 'w'." << endl;
    }

    return 0;
}
