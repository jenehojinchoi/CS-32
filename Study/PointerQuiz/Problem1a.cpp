//
//  Problem1a.cpp
//  PointerQuiz
//
//  Created by Jene Hojin Choi on 2021/07/11.
//

#include "Problem1a.hpp"
#include <iostream>
using namespace std;

int Problem1a()
 {
    int arr[3] = { 5, 10, 15 };
    int* ptr = arr;
    *ptr = 10; // set arr[0] to 10
    *(ptr + 1) = 20; // set arr[1] to 20
    ptr += 2;
    ptr[0] = 30; // set arr[2] to 30
    while (ptr >= arr) {
        cout << ' ' << *ptr; // print values
        ptr--;
    }
    cout << endl;
    return 0;
}
 
