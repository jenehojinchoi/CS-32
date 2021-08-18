//
//  main.cpp
//  Midterm1-StudyGuide
//
//  Created by Jene Hojin Choi on 2021/07/11.
//
//

// 
//#include <iostream>
//using namespace std;
//
//int deleteNum (int *nums, int numItems, int a) {
//    int numItemsNew=0;
//    int *iter = nums;
//    for (int i = 0; i < numItems; i++) {
//        if (*iter != a) {
////            *nums = *iter;
////            nums++;
//            numItemsNew++;
//        }
//        iter++;
//    }
//    return numItemsNew;
//};
//
//int insertNum(int *nums, int numItems, int times) {
////    return numItems + times;??
//}
//
//int main ()
//{
//     const int NUMITEMS = 20;
//     int nums[NUMITEMS] = {3, 2, 3, 3, 9, 6, 7, 5};
//     int numItems=8;
//
//     // deleteNum should delete all of the occurrences
//     // of its 3rd argument from the array and return the
//     // number of meaningful numbers left in the array. For
//     // example nums after the call below start
//     // {2, 9, 6, 7, 5, ...} and numItems 5
//
//     numItems = deleteNum(nums, numItems, 3);
//     cout << "numItems: " <<  numItems << "\n";
//
//     // insertNum should insert its 3rd argument that
//     // number of times into the array and return the
//     // number of meaningful numbers in the array. For
//     // instance nums after the call below should start
//     // {2, 2, 2, 9, 6, 7, 5, ...} and numItems 7
//     // You can assume there is enough space in the array.
//     numItems = insertNum(nums, numItems, 2);
//
//     return 0;
//}

#include <iostream>
#include "Problem13.hpp"
#include "Problem15.hpp"
#include "Problem16.hpp"

using namespace std;

class Point {
   public:
      int x;
      int y;
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
      double distanceFromOrigin();
   // Constructors and other methods may exist
};

int main ()
{
//     Problem13();
//   Problem15();
    Point a;
    a.x = 1;
    a.y = 2;
    a.getX();
    a.getY();
}
