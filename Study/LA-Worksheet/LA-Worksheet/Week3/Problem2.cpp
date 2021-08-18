//
//  Problem2.cpp
//  LA-Worksheet
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#include "Problem2.hpp"
#include <iostream>

class LL;
// copy constructor
//LL::LL(const LL& other)
//{
//    if (other.head == nullptr) {
//        head = nullptr;
//    } else {
//        head = new Node;
//        head->val = other.head->val;
//        head->next = nullptr;
//
//        Node* curr = head;
//        Node* otherCurr = other.head;
//
//        while (otherCurr->next) {
//            curr->next = new Node;
//            curr->next->val = otherCurr->next->val;
//            curr->next->next = nullptr;
//
//            curr = curr->next;
//            otherCurr = otherCurr->next;
//        }
//    }
//}


LL::LL (const LL& rhs) {
    head = new Node;
    head->val = rhs.head->val;
    head->next = nullptr;
    
    Node* curr = head;
    Node* other = rhs.head;
    
    while (other) {
        curr->next = new Node;
        curr->val = other->val;
        curr->next = nullptr;
        
        curr = curr->next;
        other = other->next;
    }
    
}

int LL::getSize() {
    int size = 0;
    
    if (head==nullptr)
        return size;
    
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}

int LL::findNthFromLast(int n){
    Node* curr = head;
    int size = getSize();
    
    if (!curr)
        return -1;
    
    for (int i=0; i<size; i++){
        if (i == size-n+1) {
            return curr->val;
        }
        curr = curr->next;
    }
    return -1;
}



