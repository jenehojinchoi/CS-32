//
//  LinkedList.hpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/01.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>

struct Node {
    int data;
    Node *next;
};

Node* insertInOrder(Node* head, int value);

class LinkedList {
private:
    Node* head;
    void printReverseNode(Node* curr) const;
    
public:
    
     // default constructor
     LinkedList();

     // copy constructor
     LinkedList(const LinkedList& rhs);

     // Destroys all the dynamically allocated memory
     // in the list.
     ~LinkedList();
    
    
     // assignment operator
     const LinkedList& operator=(const LinkedList& rhs);
    
    // Exchange the contents of this LinkedList with the other one.
    void swap(LinkedList &other);
    
    void insertToFront(const int &val);
    
    void printList() const;
};


#endif /* LinkedList_hpp */
