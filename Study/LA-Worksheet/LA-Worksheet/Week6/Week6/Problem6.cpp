//
//  Problem6.cpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/01.
//

//
//This function takes as input an array of int that represents the stairs (the robot
//starts at position 0), as well as the length of the array. It shoul return true if a
//path exists for the robot to reach the end of the stairs, and fals otherwise.
//(Hard)
// Ex: isClimbable({2, 0, 3, 0, 0}, 5) == true
// stairs[0]->stairs[2]->End
// Ex: isClimbable({1, 2, 4, 1, 0, 0}, 6) == true
// stairs[0]->stairs[1]->stairs[3]->stairs[2]->End
// Ex: isClimbable({4, 0, 0, 1, 2, 1, 1, 0}, 8) == false

#include <iostream>
#include <cassert>
using namespace std;

bool isClimbable2(int stairs[], int length, int size) {
    cout << "stairs[0]: " << stairs[0] << "\n";
    if (size == 0) {
        if (length == 0) return true;
        else return false;
    } else {
        return isClimbable2(stairs+1, length-stairs[0], size-1) || isClimbable2(stairs+1, length+stairs[0], size-1);
    }
}
//
//bool isClimbable(int stairs[], int length, int size)
//{
//    return isClimbable2(stairs, length, size);
//}

//int main()
//{
//    int A[5] = {2, 0, 3, 0, 0};
//    int size = sizeof(A)/sizeof(A[0]);
//    assert(isClimbable2(A, 5, size));
//    
//    
//    cout << "Passed!" << "\n";
//}
