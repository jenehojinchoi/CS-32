//
//  Problem5.cpp
//  Week7
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

#include <iostream>
using namespace std;


template <class T>
void foo(T input) {
    cout << "Inside the main template foo(): " << input <<
    endl;
}

template<>
void foo(int input) {
    cout << "Specialized template for int: " << input << endl;
}

//int main() {
//    foo<char>('A');
//    foo<int>(19);
//    foo<double>(19.97);
//}
