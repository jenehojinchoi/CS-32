//
//  Problem2.cpp
//  PointerQuiz
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#include "Problem2.hpp"
#include <string>
#include <iostream>
using namespace std;

int Problem2() {
    string * fp;
    string fish[5];
    fp = fish;
    fp += 4;
    *fp = "tilapia";
    cout << "*fp: " << *fp << "\n";
    *(fish+3) = "salmon";
    cout << "*fish: " << *fish << "\n";
    cout << "*(fish+3): " << *(fish+3) << "\n";
    fp -= 3;
    fish[2] = "tuna";
    cout << "fish[2]: " << fish[2] << "\n";
    fp[0] = "ono";
    cout << "*fp: " << *fp << "\n";
    
    bool d = (*fp == fish[0]);
    cout << "d: " << d << "\n";
    
    bool b = (*fp == *(fp+1));
    cout << "b: " << b << "\n";
    
    
    return 0;
}
