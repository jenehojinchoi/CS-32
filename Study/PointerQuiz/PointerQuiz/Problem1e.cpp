//
//  Problem1e.cpp
//  PointerQuiz
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#include "Problem1e.hpp"
#include <iostream>
using namespace std;

int* computeSquares(int& n)
{
    static int arr[10];
    n = 10;
    for (int k = 0; k < n; k++)
        arr[k] = (k+1) * (k+1);
    return arr;
}

void f()
{
    int junk[100];
    for (int k = 0; k < 100; k++)
        junk[k] = 123400000 + k;
}

int Problem1e()
{
    int m;
    int* ptr = computeSquares(m);
    f();
    for (int i = 0; i < m; i++)
        cout << ptr[i] << ' ';
    cout << "\n";
    return 0;
}
