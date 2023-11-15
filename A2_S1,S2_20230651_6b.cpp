// File: A2_S2_20230651_6b.cpp
// Purpose: Printing Many Numbers.
// Author: Abdallah Elsayed
// Section: S1,S2
// ID: NA
// TA: Eng/Khaled Ibrahim
// Date: 5 Nov 2023

#include <iostream>
#include <string.h>
using namespace std;

string ntobinary(int n){
// recursion function
if(n==0){
    return "0";
}
else if(n==1){
    return "1";
}
else{
    return ntobinary(n/2)+ntobinary(n%2);

}
}
 static void binaryprint(int n){
string ntobinary(int n);
 // make sure n is a non negative number
    if(n<0){
            cout<<"Enter non negative number"<<endl;

    }

//print()

else{

        if(n==0){
                cout <<"the binary number is:"<<n<<endl;
                }

        else {
           cout<<"the binary number is:"<< ntobinary(n)<<endl;
             }

}


}

int main()
{
          cout <<"enter a non negative value:";
          int x;
          cin>> x;
          binaryprint(x);

}
