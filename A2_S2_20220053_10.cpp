// File: A2_S2_20220053_10.cpp
// Purpose: to censor the words that isn't allowed in the social network platform
// Author: Osama Eslam
// Section: S2
// ID: 20220053
// TA: Maya Ahmed
// Date: 27 Oct 2023

#include <bits\stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

int main(){
  // the words that i will censor
  map<string, string> dataBaseForWords = {
      {u8"فلسطين", u8"ف.ل.س.ط.ي.ن"},
      {u8"اسرائيل", u8"ا.س.ر.ا.ئ.ي.ل"},
      {u8"الموت", u8"ا.ل.م.و.ت"},
      {u8"غزة", u8"غ.ز.ة"},
      {u8"حرب", u8"ح.ر.ب"},
      {u8"قتل", u8"ق.ت.ل"},
      {u8"موت", u8"م.و.ت"},
      {u8"انتحار", u8"ا.ن.ت.ح.ا.ر"},
      {u8"لاسرائيل", u8"ل.ا.س.ر.ا.ئ.ي.ل"}
  };
  // to take the input and output files
  string inputFile = "input.txt";
  string outputFile = "output.txt";
  // to open them
  ifstream input(inputFile);
  ofstream output(outputFile);

  string line;
  string check = ""; // to take each word alone

  while (getline(input, line))
  {
    for(int i = 0; i < line.size(); i++){
      if(line[i] != ' '){
        check += line[i]; // to take the word
      }
      else{
        // to loop on the map and check if the check = any word on it or no
        for (auto it = dataBaseForWords.begin(); it != dataBaseForWords.end(); ++it){
          string key = it->first;
          if(key == check){
            check = it->second;
            break;
          }
        }
        // add the cencored version of the word
        output << check << ' ';
        check = "";
      }
    }
    
  }
  //i did it again for a last time to add the last word in the line
  for (auto it = dataBaseForWords.begin(); it != dataBaseForWords.end(); ++it){
    string key = it->first;
      if(key == check){
        check = it->second;
        break;
      }
  }
  output << check << ' ';
  // to close the files
  input.close();
  output.close();
}