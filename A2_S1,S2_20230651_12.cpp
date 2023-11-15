// File: A2_S2_20230651_12.cpp
// Purpose: Phishing Scanner.
// Author: Abdallah Elsayed
// Section: S1,S2
// ID: NA
// TA: Eng/Khaled Ibrahim
// Date: 5 Nov 2023

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std ;
// function to scan a file for phishing keywords

void scanFile(ifstream & file,  unordered_map<string, int> & keywords) {
    string word;
    int totalPoints = 0;

   while (getline(file, word)) {
for (const auto  & pair  : keywords) {
size_t found = word.find(pair.first);
while (found != string::npos) {                        //to stop loop
cout << pair.first<< "  "<<pair.second << endl ;
totalPoints += pair.second;
found = word.find(pair.first, found + 1);              //continue from found+1
}
}
}

    cout << "Total points: " << totalPoints <<endl;       // print total number
}

int main() {
    // define the phishing keywords and their point values
    unordered_map<string, int> keywords = {
        {"bank", 3},
        {"credit card", 2},
        {"password", 3},
        {"social security number", 3},
        {"amazoon",2},
         {"official",1},
         {"security",2},
         {"urgant",1},
         {"information",3},
         {"ebay",2},
         {"confirm",1},
         {"account",3},
         {"address",3},
         {"mail",2},
         {"telephone",2},
         {"personal",3},
         {"atm",1},
         {"warning",2},
    };

    // Open the file to scan
    ifstream file ;
     file.open ("input.txt" ,ifstream :: in);


    // Scan the file for phishing keywords
    scanFile(file, keywords);

    // Close the file
    file.close();

    return 0;
}
