//
//  Problem2.hpp
//  LA-Worksheet
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#ifndef Problem2_hpp
#define Problem2_hpp

#include <iostream>

class LL {
public:
    LL() { head = nullptr; }
    // copy constructor
    LL(const LL& other);
    int findNthFromLast(int n);
    int getSize();
    
private:
    struct Node {
        public:
            int val;
            Node* next;
        };
    Node* head;
};



#endif /* Problem2_hpp */
