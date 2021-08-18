//
//  Problem16.cpp
//  Midterm1-StudyGuide
//
//  Created by Jene Hojin Choi on 2021/07/11.
//

#include "Problem16.hpp"
#include <iostream>
using namespace std;

class M {
public:
    int x;
    int *m = &x;
};


int Problem16() {
    M * A[4];
    M **ptr = A;
    A[1] = new M;

    cout << "A: " << A << "\n";

    cout << "&A: " << &A << "\n";
    cout << "&A[1]: " << &A[1] << "\n\n";

    cout << "ptr: " << ptr << "\n";

    *((*ptr[1]).m) = 3;

    cout << "*(ptr[1]->m): " << *(ptr[1]->m) << "\n";
    cout << "*((*ptr[1]).m): " << *((*ptr[1]).m) << "\n";
    cout << "*((*(ptr + 1))-> m): " << *((*(ptr + 1))->m) << "\n";


    return 0;
}
