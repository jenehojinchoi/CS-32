//
//  Problem16.cpp
//  Midterm1-StudyGuide
//
//  Created by Jene Hojin Choi on 2021/07/11.
//

#include "Problem17.hpp"
#include <iostream>
using namespace std;

void mystery (int* ptr, int& a, int& b) {
    a++;
    b--;
    if (a > b)
        ptr = &a;
    else
        ptr = &b;
        *ptr += 10;
    return;
}

int Problem17() {
    int num1 = 0, num2 = 14, num3 = 17;
    int *p = &num1;
    mystery(p, num2, num3);
    cout << "num1: " << num1 << " num2: " << num2
        << " num3: " << num3 << endl;
    if (p == &num1) cout << " num1";
    else if (p == &num2) cout << " num2";
    else if (p == &num3) cout << " num3";
    return 0;
}
