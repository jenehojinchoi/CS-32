//
//  Problem7.cpp
//  Week7
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

#include <iostream>
//using namespace std;

template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << max(3, 7) << std::endl;
    std::cout << max(3.0, 7.0) << std::endl;
    //cout << max(3, 7.0) << endl;
}
