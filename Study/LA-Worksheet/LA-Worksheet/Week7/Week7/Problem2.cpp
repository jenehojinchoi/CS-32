//
//  main.m
//  Week7
//
//  Created by Jene Hojin Choi on 2021/08/02.
//

#include <iostream>
//added
#include <set>
using namespace std;

class Potato {
public:
    Potato(int in_size) : size(in_size) { };
    int getSize() const {
        return size;
    };
    
private:
    int size;
};

// added
bool operator < (const Potato& a, const Potato& b) {
    return a.getSize() < b.getSize();
}
//
//int main() {
//    set<Potato> potatoes;
//    Potato p1(3);
//    Potato p2(4);
//    Potato p3(5);
//    
//    potatoes.insert(p1);
//    potatoes.insert(p2);
//    potatoes.insert(p3);
//    
//    set<Potato>::iterator it = potatoes.begin();
//    while (it != potatoes.end()) {
//        //added
//        it = potatoes.erase(it);
//    }
//    
//    for (it = potatoes.begin(); it != potatoes.end(); it++) {
//        // modified
//        cout << it->getSize() << endl;
//    }
//}
