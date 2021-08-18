//
//  recursion.cpp
//  Homework2
//
//  Created by Jene Hojin Choi on 2021/07/24.
//


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
    
    maze[sr][sc] = '#';
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

#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include <algorithm>
#include <csignal>
#include <regex>
#include <type_traits>
#include <set>
#include <iostream>
using namespace std;

class streambuf_switcher
{
public:
    streambuf_switcher(ios& dest, ios& src)
        : dest_stream(dest), saved_streambuf(dest.rdbuf(src.rdbuf()))
    {}
    ~streambuf_switcher()
    {
        dest_stream.rdbuf(saved_streambuf);
    }
private:
    ios & dest_stream;
    streambuf* saved_streambuf;
};

set<void*> addrs;
bool recordaddrs = false;

void* operator new(size_t n)
{
    void* p = malloc(n);
    if (recordaddrs)
    {
        recordaddrs = false;
        addrs.insert(p);
        recordaddrs = true;
    }
    return p;
}

void operator delete(void* p) noexcept
{
    if (recordaddrs)
    {
        recordaddrs = false;
        set<void*>::iterator it = addrs.find(p);
        if (it != addrs.end())
            addrs.erase(it);
        recordaddrs = true;
    }
    free(p);
}

void operator delete(void* p, std::size_t s) noexcept
{
    s = addrs.size();   // these two lines do nothing other than
    s += s;               // getting rid of unused var warning on g++
    if (recordaddrs)
    {
        recordaddrs = false;
        set<void*>::iterator it = addrs.find(p);
        if (it != addrs.end())
            addrs.erase(it);
        recordaddrs = true;
    }
    free(p);
}

void testone(int n)
{
    static string maze1[10] = {
        { "XXXXXXXXXX" },
        { "X.X..X...X" },
        { "X.XX.X.XXX" },
        { "X....X.X.X" },
        { "XX.X.X...X" },
        { "XXX..X.X.X" },
        { "X...X...XX" },
        { "X.XX..X.XX" },
        { "X....X...X" },
        { "XXXXXXXXXX" },
    };

    static string maze2[10] = {
        { "XXXXXXXXXX" },
        { "X.X..X...X" },
        { "X.XX.X.XXX" },
        { "X....X.X.X" },
        { "XX.X.X...X" },
        { "XXX.XX.X.X" },
        { "X...X...XX" },
        { "X.XX..X.XX" },
        { "X....X...X" },
        { "XXXXXXXXXX" },
    };

    static string maze3[10] = {
        { "XXXXXXXXXX" },
        { "XX.....XXX" },
        { "X..XX....X" },
        { "X...X...XX" },
        { "X.X.XXX..X" },
        { "XXXX..X..X" },
        { "XX....X..X" },
        { "X.......XX" },
        { "X..XXXXXXX" },
        { "XXXXXXXXXX" },
    };

    static string maze4[10] = {
        { "XXXXXXXXXX" },
        { "XX.....XXX" },
        { "X..XX....X" },
        { "X...X...XX" },
        { "X.X.XXX..X" },
        { "XXXX..X..X" },
        { "XX....X..X" },
        { "X.....X.XX" },
        { "X..XXXXXXX" },
        { "XXXXXXXXXX" },
    };

    int a[4] = { 2,  25, -1, 3 };
    int b[3] = { 2,  4,  8 };
    int c[3] = { 1,  2,  3 };

    switch (n)
    {
    default: {
        assert(false);
    } break; case  1: {
        assert(mTimesN(3, 5) == 15);
    } break; case  2: {
        assert(mTimesN(4, 3) == 12);
    } break; case  3: {
        assert(mTimesN(0, 8) == 0);
    } break; case  4: {
        assert(mTimesN(1, 2));
    } break; case  5: {
        assert(tallyTheDigits(18838, 8) == 3);
    } break; case  6: {
        assert(tallyTheDigits(10300, 0) == 3);
    } break; case  7: {
        assert(tallyTheDigits(1234, 5) == 0);
    } break; case  8: {
        assert(tallyTheDigits(4245, 4) == 2);
    } break; case  9: {
        assert(tallyTheDigits(1111111, 1) == 7);
    } break; case 10: {
        assert(parentheticallySpeaking("abcd(ghj)789") == "(ghj)");
    } break; case 11: {
        assert(parentheticallySpeaking("(xxx)789") == "(xxx)");
    } break; case 12: {
        assert(parentheticallySpeaking("789(xxx)") == "(xxx)");
    } break; case 13: {
        assert(parentheticallySpeaking("(asdf)") == "(asdf)");
    } break; case 14: {
        assert(parentheticallySpeaking("a()a") == "()");
    } break; case 15: {
        assert(totalEclipseOfTheHeart(a, 0, 0));
        assert(!totalEclipseOfTheHeart(a, 0, 1));
    } break; case 16: {
        assert(totalEclipseOfTheHeart(a, 4, 24));
        assert(!totalEclipseOfTheHeart(a, 4, 31));
    } break; case 17: {
        assert(totalEclipseOfTheHeart(b, 3, 12));
        assert(!totalEclipseOfTheHeart(b, 3, 11));
    } break; case 18: {
        assert(totalEclipseOfTheHeart(b, 3, 10));
        assert(totalEclipseOfTheHeart(b, 3, 0));
        assert(!totalEclipseOfTheHeart(b, 3, 1));
    } break; case 19: {
        assert(totalEclipseOfTheHeart(c, 3, 6));
        assert(!totalEclipseOfTheHeart(c, 3, 7));
    } break; case 20: {
        assert(totalEclipseOfTheHeart(c, 3, 1));
        assert(!totalEclipseOfTheHeart(c, 3, 10));
    } break; case 21: {
        assert(foursUp("goodbye") == "go44odbye");
    } break; case 22: {
        assert(foursUp("nothinghere") == "nothinghere");
    } break; case 23: {
        assert(foursUp("yyasdf") == "y44yasdf");
    } break; case 24: {
        assert(foursUp("axxyya") == "ax44xy44ya");
    } break; case 25: {
        assert(foursUp("aaa") == "a44a44a");
    } break; case 26: {
        assert(seasonFinale(maze1, 10, 10, 8, 6, 1, 1));
    } break; case 27: {
        assert(!seasonFinale(maze2, 10, 10, 8, 6, 1, 1));
    } break; case 28: {
        assert(seasonFinale(maze2, 10, 10, 8, 6, 1, 8));
    } break; case 29: {
        assert(seasonFinale(maze3, 10, 10, 4, 3, 7, 1));
    } break; case 30: {
        assert(!seasonFinale(maze4, 10, 10, 4, 3, 7, 1));
    }
    }
}

int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed" << endl;
}
