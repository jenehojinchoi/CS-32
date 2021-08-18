////
////  test.cpp
////  Homework2
////
////  Created by Jene Hojin Choi on 2021/07/24.
////
//
//#include "recursion.h"
//#include <iostream>
//#include <string>
//#include <cassert>
//using namespace std;
//
//int main()
//{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// mTimesN Test
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    assert(mTimesN(4, 8)==32);
//    assert(mTimesN(0, 1)==0);
//    assert(mTimesN(0, 0)==0);
//    assert(mTimesN(1, 0)==0);
//    assert(mTimesN(19898, 23)==457654);
//    
//    cout << "mTimesN Test passed" << "\n";
//    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// TallyTheDigits Test
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    assert(tallyTheDigits(18838, 8)==3);
//    assert(tallyTheDigits (55555, 3)==0);
//    assert(tallyTheDigits (0, 0)==0);
//    
//    cout << "TallyTheDigits Test passed" << "\n";
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// foursUp Test
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    assert(foursUp("yyuu")=="y44yu44u");
//    
//    cout << "foursUp Test passed" << "\n";
//    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// parentheticallySpeaking Test
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    assert(parentheticallySpeaking("(x)7")=="(x)");
//    
//    cout << "parentheticallySpeaking Test passed" << "\n";
//    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// totalEclipseOfTheHeart Test
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    int arr1[3] = {2, 4, 8};
//    assert(!totalEclipseOfTheHeart(arr1, 3, 11));
//    assert(totalEclipseOfTheHeart(arr1, 3, 0));
//    
//    cout << "totalEclipseOfTheHeart Test passed" << "\n";
//    
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// seasonFinale Test
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////    string maze[10] = {
////     "XXXXXXXXXX",
////     "X.......@X",
////     "XX@X@@.XXX",
////     "X..X.X...X",
////     "X..X...@.X",
////     "X....XXX.X",
////     "X@X....XXX",
////     "X..XX.XX.X",
////     "X...X....X",
////     "XXXXXXXXXX"
////     };
////
////    assert(seasonFinale(maze, 10, 10, 6, 4, 1, 1));
//    
//    string m1a[5] = { //r = 5, c = 7
//                     "XXXXXXX",
//                     "X...X@X",
//                     "XXX.X.X",
//                     "X@....X",
//                     "XXXXXXX" };
//    string m1b[5] = { //r = 5, c = 7
//                     "XXXXXXX",
//                     "X...X@X",
//                     "XXX.X.X",
//                     "X@....X",
//                     "XXXXXXX" };
//    string m1c[5] = { //r = 5, c = 7
//                     "XXXXXXX",
//                     "X...X@X",
//                     "XXX.X.X",
//                     "X@....X",
//                     "XXXXXXX" };
//    string m1d[5] = { //r = 5, c = 7
//                     "XXXXXXX",
//                     "X...X@X",
//                     "XXX.X.X",
//                     "X@....X",
//                     "XXXXXXX" };
//    string m1e[5] = { //r = 5, c = 7
//                     "XXXXXXX",
//                     "X...X@X",
//                     "XXX.X.X",
//                     "X@....X",
//                     "XXXXXXX" };
//
//    string m2a[10] = { //r = 10, c = 10
//                        "XXXXXXXXXX",
//                        "X.......@X",
//                        "XX@X@@.XXX",
//                        "X..X.X...X",
//                        "X..X...@.X",
//                        "X....XXX.X",
//                        "X@X....XXX",
//                        "X..XX.XX.X",
//                        "X...X....X",
//                        "XXXXXXXXXX" };
//    string m2b[10] = { //r = 10, c = 10
//                        "XXXXXXXXXX",
//                        "X.......@X",
//                        "XX@X@@.XXX",
//                        "X..X.X...X",
//                        "X..X...@.X",
//                        "X....XXX.X",
//                        "X@X....XXX",
//                        "X..XX.XX.X",
//                        "X...X....X",
//                        "XXXXXXXXXX" };
//    string m2c[10] = { //r = 10, c = 10
//                        "XXXXXXXXXX",
//                        "X.......@X",
//                        "XX@X@@.XXX",
//                        "X..X.X...X",
//                        "X..X...@.X",
//                        "X....XXX.X",
//                        "X@X....XXX",
//                        "X..XX.XX.X",
//                        "X...X....X",
//                        "XXXXXXXXXX" };
//    string m2d[10] = { //r = 10, c = 10
//                        "XXXXXXXXXX",
//                        "X.......@X",
//                        "XX@X@@.XXX",
//                        "X..X.X...X",
//                        "X..X...@.X",
//                        "X....XXX.X",
//                        "X@X....XXX",
//                        "X..XX.XX.X",
//                        "X...X....X",
//                        "XXXXXXXXXX" };
//    string m2e[10] = { //r = 10, c = 10
//                        "XXXXXXXXXX",
//                        "X.......@X",
//                        "XX@X@@.XXX",
//                        "X..X.X...X",
//                        "X..X...@.X",
//                        "X....XXX.X",
//                        "X@X....XXX",
//                        "X..XX.XX.X",
//                        "X...X....X",
//                        "XXXXXXXXXX" };
//    string m2f[10] = { //r = 10, c = 10
//                        "XXXXXXXXXX",
//                        "X.......@X",
//                        "XX@X@@.XXX",
//                        "X..X.X...X",
//                        "X..X...@.X",
//                        "X....XXX.X",
//                        "X@X....XXX",
//                        "X..XX.XX.X",
//                        "X...X....X",
//                        "XXXXXXXXXX" };
//
//    string m3a[4] = { //r = 4, c = 4
//                        "XXXX",
//                        "X.@X",
//                        "X@.X",
//                        "XXXX" };
//    string m3b[4] = { //r = 4, c = 4
//                        "XXXX",
//                        "X.@X",
//                        "X@.X",
//                        "XXXX" };
//
//    assert(seasonFinale(m1a, 5, 7, 1, 1, 3, 5));
//    assert(seasonFinale(m1b, 5, 7, 1, 1, 1, 2));
//    assert(seasonFinale(m1c, 5, 7, 1, 1, 2, 3));
//    assert(seasonFinale(m1d, 5, 7, 1, 1, 2, 5));
//    assert(seasonFinale(m1e, 5, 7, 1, 1, 3, 2));
//
//    assert(seasonFinale(m2a, 10, 10, 1, 1, 8, 8));
//    assert(seasonFinale(m2b, 10, 10, 1, 1, 5, 8));
//    assert(!seasonFinale(m2c, 10, 10, 1, 1, 8, 1));
//    assert(seasonFinale(m2d, 10, 10, 1, 1, 7, 8));
//    assert(seasonFinale(m2e, 10, 10, 6, 4, 1, 1));
//    assert(seasonFinale(m2f, 10, 10, 1, 1, 6, 4));
//
//    assert(!seasonFinale(m3a, 4, 4, 1, 1, 2, 2));
//    assert(seasonFinale(m3b, 4, 4, 1, 1, 1, 1));
//
//    cout << "seasonFinale Test passed" << "\n";
//    
//    return 0;
//}
