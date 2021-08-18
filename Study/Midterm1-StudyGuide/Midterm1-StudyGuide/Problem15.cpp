//
//  Problem14.cpp
//  Midterm1-StudyGuide
//
//  Created by Jene Hojin Choi on 2021/07/11.
//

#include "Problem15.hpp"
#include <iostream>
using namespace std;

int Problem15 ()
{
    int v1 = 10;
    int v2 = 25;
    int *p1 = &v1;
    int *p2 = &v2;
    *p1 += *p2;
    cout << "*p1 = " << *p1 << " *p2 = " << *p2
    << " v1 = " << v1 << " v2 = " << v2 << "\n";
    cout << "p1: " << p1 << "\n";
    cout << "p2: " << p2 << "\n\n";
    
    p2 = p1;
    
    cout << "*p1 = " << *p1 << " *p2 = " << *p2
    << " v1 = " << v1 << " v2 = " << v2 << "\n";
    cout << "p1: " << p1 << "\n";
    cout << "p2: " << p2 << "\n\n";
    
    *p2 = *p1 + *p2;
    
    cout << "*p1 = " << *p1 << " *p2 = " << *p2
    << " v1 = " << v1 << " v2 = " << v2 << "\n";
    cout << "p1: " << p1 << "\n";
    cout << "p2: " << p2 << "\n\n";
    return 0;
}
