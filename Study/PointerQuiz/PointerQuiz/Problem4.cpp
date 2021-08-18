//
//  Problem4.cpp
//  PointerQuiz
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#include "Problem4.hpp"
#include <iostream>
using namespace std;

int* minimart(int* a, int* b)
{
    if (*a < *b)
        return a;
    else
        return b;
}

void swap1(int* a, int *b)
{
    cout << "INSIDE SWAP1" << "\n";
    cout << "*a: " << *a << "\n";
    cout << "*b: " << *b << "\n\n";
    int* temp = a;
    a = b;
    b = temp;
    cout << "*a: " << *a << "\n";
    cout << "*b: " << *b << "\n";
}

void swap2(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Problem4()
{
    int array[6] = { 5, 3, 4, 17, 22, 19 };
    int* ptr = minimart(array, &array[2]);
    // 5>3 so, ptr points to 4
    // {5, 3, 4, 17, 22, 19}
    cout << "*ptr: " << *ptr << "\n";
    cout << "array: " << array << "\n";
    cout << "*array: " << *array << "\n\n";
    
    ptr[1] = 9;
    // ptr points to 4
    // {5, 3, 4, 9, 22, 19}
    cout << "*ptr: " << *ptr << "\n";
    cout << "array: " << array << "\n";
    cout << "*array: " << *array << "\n\n";
    
    ptr += 2;
    // ptr points to 22
    cout << "*ptr: " << *ptr << "\n";
    cout << "array: " << array << "\n";
    cout << "*array: " << *array << "\n\n";

    *ptr = -1;
    // ptr points to -1
    // {5, 3, 4, 9, -1, 19}
    cout << "*ptr: " << *ptr << "\n";
    cout << "array: " << array << "\n";
    cout << "*array: " << *array << "\n\n";
    
    *(array+1) = 79;
    // array points to 5
    // {5, 79, 4, 9, -1, 19}
    cout << "*ptr: " << *ptr << "\n";
    cout << "array: " << array << "\n";
    cout << "*array: " << *array << "\n\n";
    
    cout << "diff=" << &array[5] - ptr << endl;
    // index of array[5]: 5, index of ptr: -1 -> diff = 1
    
    // important!!!
    swap1(&array[0], &array[1]);
    // &array[0] is address of 5
    // &array[1] is address of 79
    // array[0]을 가리키는 포인터와 array[1]을 가리키는 포인터만 바뀌었을뿐
    // array 자체에는 변화가 없다.
    // {5, 79, 4, 9, -1, 19}
    cout << "*ptr: " << *ptr << "\n";
    cout << "array: " << array << "\n";
    cout << "*array: " << *array << "\n\n";
    
    swap2(array, &array[2]);
    // array is address of 5
    // &array[2] is address of 4
    // {4, 79, 5, 9, -1, 19}
    cout << "*ptr: " << *ptr << "\n";
    cout << "array: " << array << "\n";
    cout << "*array: " << *array << "\n\n";
    
    for (int i = 0; i < 6; i++)
        cout << array[i] << endl;
    
    return 0;
}
