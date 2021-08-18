//
//  DoublyLinkedList.hpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/01.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <iostream>

struct Node
{
    int val;
    Node* next;
    Node* prev;
};

class DoublyLinkedList
{
private:
    Node* head;
    
public:
    DoublyLinkedList();
    
    ~DoublyLinkedList();
    
    DoublyLinkedList(const DoublyLinkedList& rhs);
    
    DoublyLinkedList& operator=(const DoublyLinkedList &rhs);
    
    Node* reverse(Node* head);
};

#endif /* DoublyLinkedList_hpp */
