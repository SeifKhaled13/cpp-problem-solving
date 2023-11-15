// File: A2_S2_20221077_2.cpp
// Purpose: Converts male speech to inclusive speech that includes both male and female.
// Author: Seif Eldin Khaled Rajab
// Section: S1,S2
// ID: 20221077
// TA: Eng/Khaled Ibrahim
// Date: 5 Nov 2023

#include <iostream>
#include <string>
#include <regex> // i used regex (Regular Expression) to match he / his / him patterns as a word and not part of another word

using namespace std;

// function to convert male speech to inclusive speech using regular expressions
void convertToInclusiveSpeech(string& sentence) {
    // define regular expressions to match complete words with 'he,' 'him,' or 'his'
    regex heRegex("\\bhe\\b", regex_constants::icase); // \b ensures whole word match, (regex_constants::icase makes it case-insensitive)
    regex himRegex("\\bhim\\b", regex_constants::icase);
    regex hisRegex("\\bhis\\b", regex_constants::icase);

    // replace the matched words with 'he or she,' 'him or her,' or 'his or her'
    sentence = regex_replace(sentence, heRegex, "he or she");
    sentence = regex_replace(sentence, himRegex, "him or her");
    sentence = regex_replace(sentence, hisRegex, "his or her");
}

int main() {
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    convertToInclusiveSpeech(sentence);

    cout << "Inclusive speech: " << sentence << endl;

    return 0;
}
