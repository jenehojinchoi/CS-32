//
//  LinkedList.cpp
//  Week5
//
//  Created by Jene Hojin Choi on 2021/08/01.
//

#include "LinkedList.hpp"
#include <iostream>
using namespace std;

struct Node;

class LinkedList;

// default constructor
LinkedList::LinkedList()
{
    head = nullptr;
}

// copy constructor
LinkedList::LinkedList(const LinkedList& rhs)
{
    head = nullptr;
    Node* p = nullptr;
    Node* other = rhs.head;
    
    while (other != nullptr) {
        Node* newNode = new Node;               // dynamically allocate new Node
        newNode->next = nullptr;
        newNode->data = other->data;          // update new node's value
        if (p != nullptr)
            p->next = newNode;
        if (head == nullptr)
            head = newNode;
        p = newNode;
        other = other->next;
    }
}
 
// destructor
LinkedList::~LinkedList()
{
    Node* curr = head;
    while (curr!= nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;                 // release memory
    }
}

// Exchange the contents of this LinkedList with the other one.
void LinkedList::swap(LinkedList &other)
{
    Node* temp = head;
    head = other.head;
    other.head = temp;
    temp = nullptr;                 // release memory
}

// assignment operator
const LinkedList& LinkedList::operator = (const LinkedList& rhs)
{
    if (this == &rhs)
        return *this;
    LinkedList copy = LinkedList(rhs);
    this -> swap(copy);             //swaps heads of linked lists
    return *this;
}

void LinkedList::insertToFront(const int &val)
{
    Node* temp = new Node;          // create temp to make a new node
    temp->data = val;              // set temp's value as val which is passed on
    temp->next = head;              // set temp's next as head. then temp becomes val->head
    head = temp;                    // then set head as temp to update it
}

void LinkedList::printList() const
{
    Node* curr = head;
    while (curr!=nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;                       // when loop ends
}

Node* insertInOrder(Node* head, int value) {
    if (head->data < value || !head){
        Node *p = new Node;
        p->data = value;
        p->next = head;
        head = p;
    } else
        head->next = insertInOrder(head->next, value);
    return head;
}
