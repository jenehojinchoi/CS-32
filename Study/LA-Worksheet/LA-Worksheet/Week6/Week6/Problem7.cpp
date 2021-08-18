//
//  Problem7.cpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/01.
//

#include <iostream>
#include <cassert>

int sumOfDigits(int num)
{
    if (num<10) return num;
    else return num%10 + sumOfDigits(num/10);
}
//
//int main()
//{
//    assert(sumOfDigits(176)); // should return 14
//    assert(sumOfDigits(111111)); // should return 6
//}
