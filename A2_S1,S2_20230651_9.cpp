// File: A2_S2_20230651_9.cpp
// Purpose: Teddy Bear Picnic.
// Author: Abdallah Elsayed
// Section: S1,S2
// ID: NA
// TA: Eng/Khaled Ibrahim
// Date: 5 Nov 2023

#include <iostream>

using namespace std;


bool bears(int n) {

    if (n == 42) {
        return true;
    }

    if (n % 2 == 0) {
        if (bears(n / 2)){return true;}              //recursion step if n=42 or no
    }

    if (n % 5 == 0) {
        if (bears(n - 42)) {return true;}            //recursion step if n=42 or no
            }

    // last 2 digit
    int lastdigit1 = n % 10;
    int lastdigit2 = (n % 100) / 10;

    // lastdigit1 * lastdigit2 != 0 to avoid if last digit is not exist
    if ((n % 3 == 0 || n % 4 == 0) && lastdigit1 * lastdigit2 != 0) {
        if (bears(n - lastdigit1 * lastdigit2)) {return true;}        //recursion step if n=42 or no
    }

     else  return false;
    }

int main() {
cout << "enter number of teedy bears to start: ";
int x;
cin>>x;
    cout <<"is " <<bears(x) << endl;
           }
