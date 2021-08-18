//
//  DoublyLinkedList.cpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/01.
//

#include "DoublyLinkedList.hpp"
#include <string>
#include <cassert>
#include <iostream>

// Create an empty OnlineDating list
DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
}

// Destructor
DoublyLinkedList::~DoublyLinkedList()
{
    Node *curr = head;
    while (curr) {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
}

// Copy Constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &rhs)
{
    this->head = nullptr;
    if (rhs.head){
        Node *curr = rhs.head;
        
        while (curr) {
            curr->val = this->head->val;
            curr = curr->next;
        }
    }
}

// Assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList &rhs)
{
    if (this != &rhs){
        DoublyLinkedList temp(rhs);
    }
    return *this;
}


//Node* DoublyLinkedList::reverse(Node* head)
//{
//    Node* newHead = new Node;
//    Node* temp = head;
//    while (temp->next) {
//        temp = temp->next;
//    }
//
//    while (temp->prev) {
//        newHead->val = temp->val;
//        newHead->next = new Node;
//        newHead->next = temp->prev;
//    }
//
//    return newHead;
//}

Node* DoublyLinkedList::reverse(Node* head) {
    if (head == nullptr)
        return head;

    Node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    if (head->prev == nullptr)
        return head;
    return reverse(head->prev);
}
