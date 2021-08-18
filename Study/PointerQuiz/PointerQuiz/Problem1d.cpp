//
//  Problem1d.cpp
//  PointerQuiz
//
//  Created by Jene Hojin Choi on 2021/07/11.
//

#include "Problem1d.hpp"
#include <iostream>
using namespace std;

// return true if two C strings are equal
bool match(const char str1[], const char str2[]) {
//    cout << "str1[]: " << str1 << "\n"; // can't print str1[]...?
//    cout << "str2[]: " << str2 << "\n";
//    cout << "*str1[]: " << *str1 << "\n";
//    cout << "*str2[]: " << *str2 << "\n";
    
    while (*str1 != 0 && *str2 != 0) { // zero bytes at ends
        if (*str1 != *str2) // compare corresponding chars
            return false;
            str1++; // advance to the next character
            str2++;
    }
    return *str1 == *str2; // both ended at same time?
}

int Problem1d()
{
    char a[10] = "pointy";
    char b[10] = "pointless";
    if (match(a,b))
        cout << "They're the same!\n";
    else
        cout << "They're different!\n";
    return 0;
}
