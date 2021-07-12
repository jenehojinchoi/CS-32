//
//  13.cpp
//  Midterm1-StudyGuide
//
//  Created by Jene Hojin Choi on 2021/07/11.
//

#include "Problem13.hpp"
#include <iostream>
using namespace std;

//  {3, 2, 3, 3, 9, 6, 7, 5};

void printNums(int numItems, int (&nums)[20]){
    for (int i=0; i<numItems; i++) {
        if (nums[i]) {
            cout << nums[i] << " ";
        }
    }
    cout << endl;
}

int deleteNum (int *nums, int numItems, int a) {
    int numItemsNew=0;
    int *iter = nums;
    
    for (int i = 0; i < numItems; i++) {
        cout << "\n" << "i: " << i << "\n";
        if (*iter != a) {
            *nums = *iter;
            nums++;
            numItemsNew++;
        }
        iter++;
        
        // print NUMS
        cout << "NUMS: ";
        for (int i=0; i<numItems; i++) {
            if (nums[i]) {
                cout << nums[i] << " ";
            }
        }
        cout << "\n";
        
        // print ITER
        cout << "ITER: ";
        for (int i=0; i<numItems; i++) {
            if (iter[i]) {
                cout << iter[i] << " ";
            }
        }
        cout << "\n\n";
    }
    return numItemsNew;
};

int insertNum(int *nums, int numItems, int times) {
    for (int i = numItems + times - 1; i >= times; i--) {
        *(nums + i) = *(nums + i - times);
    }
    for (int i = 0; i < times; i++) {
        *(nums + i) = times;
    }
    return numItems + times;
}

int Problem13 ()
{
    const int NUMITEMS = 20;
    int nums[NUMITEMS] = {3, 2, 3, 3, 9, 6, 7, 5};
    int numItems=8;

    numItems = deleteNum(nums, numItems, 3);
    cout << "numItems: " <<  numItems << "\n";
    
    numItems = insertNum(nums, numItems, 2);
    cout << "numItems: " <<  numItems << "\n";
    
    return 0;
}
