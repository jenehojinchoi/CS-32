////
////  Worksheet2.cpp
////  Midterm1-StudyGuide
////
////  Created by Jene Hojin Choi on 2021/07/11.
////
//
//#include "Worksheet2.hpp"
//#include <iostream>
//using namespace std;
//
//
//class A {
//public:
//  A(int sz) {
//    b = new B;
//    arr = new int[sz];
//    n = sz;
//  }
//
//  A(const A& other) {
//    b = new B(*other.b);
//    n = other.n;
//    arr = new int[n];
//    for (int i = 0; i < n; i++) {
//      arr[i] = other.arr[i];
//    }
//    str = other.str;
//  }
//
//  A& operator=(const A& other) {
//    if (this != &other) {
//     A temp(other);
//     std::swap(b, temp.b);
//     std::swap(arr, temp.arr);
//     std::swap(n, temp.n);
//     std::swap(str, temp.str);
//    }
//    return *this;
//  }
//
//  ~A() {
//    delete b;
//    delete [] arr;
//  }
//
//private:
//  //one dynamically allocated B object; assume B has a default
//  //constructor, a copy constructor, and an assignment operator
//  B* b;
//  //dynamically allocated array
//  int* arr;
//  //size of arr (determined by a constructor)
//  int n;
//  std::string str;
//};
//
//
//int worksheet2() {
//    A a(5);
//    return 0;
//}
