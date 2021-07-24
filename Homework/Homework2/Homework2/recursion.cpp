//
//  recursion.cpp
//  Homework2
//
//  Created by Jene Hojin Choi on 2021/07/24.
//

#include "recursion.h"
#include <iostream>
#include <string>
using namespace std;

// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int mTimesN(unsigned int m, unsigned int n)
{
    if (n==0) return 0;
    return m + mTimesN(m, n - 1);
}

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
// tallyTheDigits(18838, 8) => 3
// tallyTheDigits (55555, 3) => 0
// tallyTheDigits (0, 0) => 0 or 1 (either if fine)
//

int tallyTheDigits(int num, int digit)
{
    if (num == 0) return 0;
    else if (num % 10 == digit) return 1 + tallyTheDigits(num / 10, digit);
    else return tallyTheDigits(num / 10, digit);
}


// Returns a string where the same characters next each other in
// string n are separated by "44" (you can assume the input
// string will not have 4’s)
//
// Pseudocode Example:
// foursUp("goodbye") => "go44odbye"
// foursUp("yyuu") => "y44yu44u"
// foursUp("aaaa") => "a44a44a44a"
//
string foursUp(string n)
{
    if (n.size()==0 || n.size()==1) return n;
    if (n[0] == n[1])
        return n[0] + string("44") + foursUp(n.substr(1, n.size()-1));
    else
        return n[0] + foursUp(n.substr(1, n.size() - 1));
}


// str contains a single pair of parentheses, return a new
// string made of only the parentheses and whatever those
// parentheses contain
//
// Pseudocode Example:
// parentheticallySpeaking("abc(ghj)789") => "(ghj)"
// parentheticallySpeaking ("(x)7") => "(x)"
// parentheticallySpeaking ("4agh(y)") => "(y)"
// parentheticallySpeaking ("4agh()") => "()"
//

string parentheticallySpeaking(string str)
{
    if (str[0] == '(') {
        if (str[str.size()-1] == ')') return str;
        else return parentheticallySpeaking(str.substr(0, str.size()-1));
    }
    else return parentheticallySpeaking(str.substr(1, str.size()-1));
}


// Return true if the total of any combination of elements in
// the array a equals the value of the target.
//
// Pseudocode Example:
// totalEclipseOfTheHeart([2, 4, 8], 3, 10) => true
// totalEclipseOfTheHeart ([2, 4, 8], 3, 6) => true
// totalEclipseOfTheHeart ([2, 4, 8], 3, 11) => false
// totalEclipseOfTheHeart ([2, 4, 8], 3, 0) => true
// totalEclipseOfTheHeart ([], 0, 0) => true
//
bool totalEclipseOfTheHeart(const int a[], int size, int target)
{
    if (target == 0) return true;
    if (size == 0) return false;
    return totalEclipseOfTheHeart(a+1, size-1, target-*a);
}

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise

bool seasonFinale(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if (sr==er && sc==ec)
        return true;
    
    maze[sr][sc] = '@';
    if (maze[sr-1][sc] == '.' && seasonFinale(maze, nRows, nCols, sr-1, sc, er, ec))
        return true;
    if (maze[sr][sc-1] == '.' && seasonFinale(maze, nRows, nCols, sr, sc-1, er, ec))
        return true;
    if (maze[sr+1][sc] == '.' && seasonFinale(maze, nRows, nCols, sr+1, sc, er, ec))
        return true;
    if (maze[sr][sc+1] == '.' && seasonFinale(maze, nRows, nCols, sr, sc+1, er, ec))
        return true;
    return false;
}
