//
//  test2.cpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

#include <iostream>
#include <string>
using namespace std;
 
// Insert itsGoingDownFourReal code here
template <typename T>
void itsGoingDownFourReal (T a) {
    T result = a+a+a+a;
    cout << "With the input "<< a << ", when it goes down four real, I get "<< result << "\n";
}

bool theQuadSquad(int x[], int size, int total, int count){
    if(count == 4 && total == 0) return true;
    if(size == 0 || total < 0 || count > 4) return false;
    return theQuadSquad(x, size-1, total-x[size-2], count+1) || theQuadSquad(x, size-1, total, count);
}
//Given an unsorted array, return true if there is a combination of four elements that add up to a given sum.
//
//theQuadSquad({5, 2, 1, 9, 7, 0, 4, 3}, 8, 20, 0) ==> true
//
//theQuadSquad({5, 2, 1, 9, 7, 0, 4, 3}, 8, 26, 0) ==> false
//
//theQuadSquad({5, 2, 1, 9, 7, 0, 4, 3}, 8, 10, 0) ==> true

int main()
{
    int A[8] = {5, 2, 1, 9, 7, 0, 4, 3};
    assert(theQuadSquad(A, 8, 20, 0));
    int B[8] = {5, 2, 1, 9, 7, 0, 4, 3};
    assert(!theQuadSquad(B, 8, 26, 0));
    int C[8] = {5, 2, 1, 9, 7, 0, 4, 3};
    assert(theQuadSquad(C, 8, 10, 0));
    cout << "passed" << "\n";
    
    return 0;
}
