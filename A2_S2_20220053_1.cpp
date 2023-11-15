// File: A2_S2_20220053_1.cpp
// Purpose: to make the sentence capitalized
// Author: Osama Eslam
// Section: S2
// ID: 20220053
// TA: Maya Ahmed
// Date: 23 Oct 2023

#include <bits\stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

int main(){
  string sentence; 
  getline(cin,sentence);
  int size = sentence.size();
  vector<char> newSentence(size);
  for(int i = 0; i < sentence.size(); i++){
    if(i != sentence.size()-1){
      if(sentence[i] == ' ' && sentence[i+1] == ' '){
      continue;
      }
    }
    
    if(i == 0){
      sentence[i] = toupper(sentence[i]);
    }
    else{
      sentence[i] = tolower(sentence[i]);
    }
    newSentence.push_back(sentence[i]);
  }
  for(int i = 0; i < newSentence.size(); i++){
    cout << newSentence[i];
  }
}