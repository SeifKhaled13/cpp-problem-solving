// File: A2_S2_20230651_3.cpp
// Purpose: Split so that it returns a vector of the strings
// Author: Abdallah Elsayed
// Section: S1,S2
// ID: NA
// TA: Eng/Khaled Ibrahim
// Date: 5 Nov 2023

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> split (vector <string> target,string delmiter){
                                                                      // delimter
 string del1,del2;
del1 =delmiter.substr(0,1);
del2 =delmiter.substr(delmiter.size()-1,delmiter.size());
                                                                       //print the out put
for(int i=0;i<target.size();i++){

                                                                       // print . in the end
        if (i == (target.size()-1) ){
     cout<<del1<<target[i]<< del2 <<".";
}

  else   cout<<del1<<target[i]<< del2 <<",";

}
}


int main() {
                                                                       //vector string target
vector <string> vec;
string s;

cout<< "enter the string target and enter \"end\" to end program :  ";
while(cin >> s){
                                                                        //to stop while loop
    if(s == "end"){
        break;
    }
                                                                      //the first string in the vector
    vec.push_back(s);
    }
                                                                    //call function
split(vec,"\" \"");

}
