//
//  Problem5.cpp
//  PointerQuiz
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#include "Problem5.hpp"
#include <iostream>
#include <string>
using namespace std;

//Write a function named deleteG that accepts one character pointer as a
//parameter and returns no value. The parameter is a C string. This function must
//remove all of the upper and lower case 'g' letters from the string. The resulting
//string must be a valid C string.
//Your function must declare no more than one local variable in addition to the
//parameter; that additional variable must be of a pointer type. Your function must
//not use any square brackets and must not use the strlen or strcpy library
//functions.

void deleteG (char *msg) {
    char * p = msg;
    while (*msg != 0) {
        cout << "*msg: " << *msg << "\n";
        if (*msg != 'G' and *msg != 'g'){
            cout << "*p: " << *p << "\n";
            *p = *msg;
            cout << "*p = *msg : " << *p << "\n";
            p++;
            cout << "p++: " << *p << "\n";
        }
        msg++;
        cout << "\n";
    }
    *p = 0;
}

int Problem5() {
    char msg[100] = "glass";
    //"I recall the glass gate next to Gus in Lagos, near the gold bridge.";
    deleteG(msg);
    // prints I recall the lass ate next to us in Laos, near
    // the old bride.
    cout << msg << "\n";
    return 0;
}
