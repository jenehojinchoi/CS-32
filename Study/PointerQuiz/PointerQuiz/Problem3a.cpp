//
//  Problem3a.cpp
//  PointerQuiz
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#include "Problem3a.hpp"
#include <iostream>
using namespace std;

double computeAverage(const double* scores, int nScores)
{
    const double* ptr = scores;
    double tot = 0;
    while (ptr != scores + nScores)
    {
        tot += *ptr;
        ptr++;
    }
//    for(int i = 0; i < nScores; i++)
//    {
//        tot += *(scores + i); // OR tot += *(ptr + i);
//    }
    return tot/nScores;
}

int Problem3a()
{
    // initialization of double array
//    double *a = new double[5]{100.0, 90.0, 80.0, 70.0, 60.0};
    double a[5] = {100.0, 90.0, 80.0, 70.0, 60.0};
    int n = 5;
    double avg = computeAverage(a, n);
    cout << "avg: " << avg << "\n";
    return 0;
}
