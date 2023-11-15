// File: A2_S2_20221077_8.cpp
// Purpose: Generate Fractal Patterns.
// Author: Seif Eldin Khaled Rajab
// Section: S1,S2
// ID: 20221077
// TA: Eng/Khaled Ibrahim
// Date: 5 Nov 2023

#include <iostream>
using namespace std;

void printAsterisks(int n, int i) {
    if (n == 1) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "*\n";
    } else {
        printAsterisks(n / 2, i);
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < n; j++) {
            cout << "*";
        }
        cout << "\n";
        printAsterisks(n / 2, i + n / 2);
    }
}

void pattern(int n, int i) {
    if (n > 0 && n % 2 == 0) {
        printAsterisks(n, i);
    }
}

int main() {
    pattern(16, 0); // you can change the values of n and i as needed.
    return 0;
}
