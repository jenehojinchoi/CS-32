//
//  main.m
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/01.
//

#include <iostream>
#include <cassert>
using namespace std;

bool isSolvable(int x, int y, int c)
{
    if (c<x || c<y) return false;
    
    if (c%x == 0) return true;
    else if (c%y == 0) return true;
    else {
        isSolvable(x, y, c-y);
    }
    return false;
}

//int main()
//{
//    assert(isSolvable(7, 5, 45));
//    assert(!isSolvable(9, 23, 112));
//    cout << "Passed!" << "\n";
//}
