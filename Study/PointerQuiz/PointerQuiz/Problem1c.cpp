//
//  Problem1c.cpp
//  PointerQuiz
//
//  Created by Jene Hojin Choi on 2021/07/11.
//

#include "Problem1c.hpp"
#include <iostream>

#include <iostream>
#include <cmath>
using namespace std;

void hypotenuse(double leg1, double leg2, double* resultPtr)
{
    *resultPtr = sqrt(leg1*leg1 + leg2*leg2);
}

int Problem1c() {
    double x;
    double* p = &x;
    hypotenuse(1.5, 2.0, p);
    cout << "The hypotenuse is " << p << endl;
    return 0;
}
