// File: A2_S2_20220053_7.cpp
// Purpose: to check if the dominos make a chain or no
// Author: Osama Eslam
// Section: S2
// ID: 20220053
// TA: Maya Ahmed
// Date: 27 Oct 2023

#include <bits\stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

struct dominoT {
  int leftDots;
  int rightDots;
};

dominoT domino;
vector<dominoT> dominos;
int number;
int arrLeft[7];
int arrRight[7];
int checkForSoloNumber = 0;
vector<dominoT> numbers;

bool checkForTwoChain(const dominoT n1, const dominoT n2){
  return n1.rightDots == n2.leftDots;
}

bool FormsDominoChain(vector<dominoT> &dominos){
  for(int i = 0; i < number; i++){
    arrLeft[dominos[i].leftDots]++;
    arrRight[dominos[i].rightDots]++;
  }
  for(int i = 1; i < 7; i++){
    if(arrLeft[i] == arrRight[i]){
      continue;
    }
    else{
      checkForSoloNumber++;
    }
  }
  if(checkForSoloNumber == 2 || checkForSoloNumber == 0){
    return true;
  }
  return false;
}

bool numberSolution(vector<dominoT> &dominos, vector<dominoT> &numbers){
  if(dominos.size() == numbers.size()){ // to check when to stop
    return true;
  }
  for(int i = 0; i < dominos.size(); ++i){
    if(dominos[i].leftDots != -1){
      if(numbers.empty() || checkForTwoChain(numbers.back(),dominos[i])){
        numbers.push_back(dominos[i]);
        int leftDots = dominos[i].leftDots;
        dominos[i].leftDots = -1;
        if (numberSolution(dominos, numbers)){
          return true;
        }
        dominos[i].leftDots = leftDots;
        numbers.pop_back();
      }
    }
  }

  return false;
}

int main(){
  cin >> number;
  for(int i = 0; i < number; i++){
    cin >> domino.leftDots >> domino.rightDots;
    dominos.push_back(domino);
  }
  cout << (FormsDominoChain(dominos) ? "Yes" : "No") << endl;
  numberSolution(dominos, numbers);
  for(int i = 0; i < numbers.size(); i++){
    cout << numbers[i].leftDots << '|' << numbers[i].rightDots << ' ';
  }
}