// File: A2_S2_20220053_4.cpp
// Purpose: to find the prime numbers using the Greek astronomer Eratosthenes algorithm
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
  ll n; cin >> n;
  deque<ll> numbers;
  numbers.push_back(2);
  for(int i = 3; i <= n; i++){ // we take all the numbers between 2 and n
    numbers.push_back(i);
  }
  for(int i = 0; i < n; i++){
    if(i >= numbers.size()){ // to not loop out the range
      break;
    }
    int m = numbers[i]; // the number that i will add to multiple each time
    int multiple = numbers[i]; // the number i will delete from the numbers set
    while(multiple <= n){
      multiple += m;
      // to remove the element by value
      numbers.erase(remove(numbers.begin(), numbers.end(), multiple), numbers.end());
    }
  }
  for(int i = 0; i < numbers.size(); i++){
    cout << numbers[i] << ' ';
  }
}
