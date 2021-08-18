//
//  test.cpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

#include <iostream>
#include <vector>
#include <list>
#include <cassert>
using namespace std;

int factorial (int n) {
    if (n == 0) return 1;
    return n * factorial (n);
}

int whatIsIt(int x, int y) {
    if (x > y)
        return x * y;
    else
        return whatIsIt(x-1, y);
}


void printList(list<double>);

//int main()
//{
//    vector<int> vec;
//    list<double> li;
//
//    for (int i = 0; i < 5; i++) {
//        vec.push_back(i);
//        li.push_back(i + 0.5);
//    }
//
//    // Erase each element one by one, beginning with the
//    // last
//    vector<int>::iterator it = vec.end();
//    while (it >= vec.begin()) {
//        it--;
//        cout << *it << endl;
//        vec.erase(it);
//    }
//
//    printList(li);
//
//    return 0;
//}

void printList(list<double> l)
{
    // Print out the list
    for (list<double>::iterator it2 = l.begin(); it2 !=l.end(); ++it2)
    {
       cout << *it2 << endl;
    }

    return;
}


bool mirrorMirrorOnTheWall(string n){
    if(n.length()==1 || n.length() ==0) return true;
    if(n[0]== n[n.length()-1]){
        return mirrorMirrorOnTheWall(n.substr(1,n.length()-2));
    }
    else return false;
}

//int main()
//{
//    assert(mirrorMirrorOnTheWall(""));  // returns true
//    assert(mirrorMirrorOnTheWall("a"));  // returns true
//    assert(!mirrorMirrorOnTheWall("mirror"));  // returns false
//    assert(mirrorMirrorOnTheWall("racecar")); // returns true
//    cout << "passed!" << "\n";
//}


