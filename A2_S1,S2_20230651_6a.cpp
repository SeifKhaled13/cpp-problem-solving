// File: A2_S2_20230651_6a.cpp
// Purpose: One Binary Number.
// Author: Abdallah Elsayed
// Section: S1,S2
// ID: NA
// TA: Eng/Khaled Ibrahim
// Date: 5 Nov 2023

#include <iostream>
#include <string.h>

using namespace std;


//recursion function to do prifex
static void numbers(string prifex,int k){

if (k==0){
    cout << prifex <<endl;

     }
        else
     {
         numbers(prifex +"0",k-1);
         numbers(prifex +"1",k-1);

     }

}





int main()
{
    string prifex;
    cout << "enter a number to prifex:";
    getline(cin,prifex);
     int k;
cout<< "enter the number of more binary digit: ";
    cin >> k;

    numbers(prifex,k);

}
