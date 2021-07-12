//
//  Problem3b.cpp
//  PointerQuiz
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#include "Problem3b.hpp"
#include <iostream>
using namespace std;

// This function searches through str for the character chr.
// If the chr is found, it returns a pointer into str where
// the character was first found, otherwise nullptr (not
// found).

// my solution
const char* findTheChar(const char str[], char chr)
{
    const char * ptr = str;
    while (ptr != nullptr) {
        if (*ptr == chr)
            return ptr;
        ptr++;
    }
    return nullptr;
}

//// Problem 3c
//const char* findTheChar(const char *str, char chr)
//{
//    for (const char* tmp = str; tmp != 0; tmp++)
//        if (*tmp == chr)
//            return tmp;
//    return nullptr;
//}

int Problem3b() {
    const char str[6] = "abcde";
    const char * temp = findTheChar(str, 'c');
    cout << "temp: " << temp << "\n";
    cout << "*temp: " << *temp << "\n";
    return 0;
}
