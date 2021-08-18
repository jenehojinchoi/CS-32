//
//  LinkedList.cpp
//  LA-Worksheet/Week3
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#include <iostream>
#include "LinkedList.hpp"
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
        newNode->value = other->value;          // update new node's value
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

// assignment operator
const LinkedList& LinkedList::operator = (const LinkedList& rhs)
{
    if (this == &rhs)
        return *this;
    LinkedList copy = LinkedList(rhs);
    this -> swap(copy);             //swaps heads of linked lists
    return *this;
}

// Inserts val at the front of the list
void LinkedList::insertToFront(const ItemType &val)
{
    Node* temp = new Node;          // create temp to make a new node
    temp->value = val;              // set temp's value as val which is passed on
    temp->next = head;              // set temp's next as head. then temp becomes val->head
    head = temp;                    // then set head as temp to update it
}

void LinkedList::insertNItems(int num, const ItemType &val, std::string str)
{
    Node * curr = head;
    int i=num;
    if (str == "front") {
        while(i!=0){
            Node* temp = new Node;
            temp->value = val;
            temp->next = head;
            head = temp;
            i--;
        }
    }
}


// Prints the LinkedList
void LinkedList::printList() const
{
    Node* curr = head;
    while (curr!=nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;                       // when loop ends
}

//return true, returns false if
// there is no element i
bool LinkedList::get(int i, ItemType& item) const
{
    int count = 0;
    Node* curr = head;
    while (curr!=nullptr) {
        if (count==i) {             // if count == index
            item = curr->value;     // set item as value of current
            return true;
        }
        count++;                    // increment count
        curr = curr->next;          // move curr to next
    }
    return false;
}

// Reverses the LinkedList
void LinkedList::reverseList()
{
    Node* curr = head;
    Node* prev = nullptr;           // save previous
    Node* next = nullptr;           // save next
    
    while (curr!=nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    };
    head = prev;
}

// use this for recursively calling
void LinkedList::printReverseNode(Node* curr) const
{
    // base case
    if (curr==nullptr)
        return;

    // recursively call
    printReverseNode(curr->next);
    if (curr->next == nullptr)
        cout << curr->value;
    else
        cout << " " << curr->value;
}

// Prints the LinkedList in reverse order
void LinkedList::printReverse() const
{
    printReverseNode(head);
    cout << endl;
}

// Appends the values of other onto the end of this LinkedList.
void LinkedList::append(const LinkedList &other)
{
    
    if (head == nullptr) {
        head = other.head;
    } else {
        Node* curr = head;                      // curr points to where head points to
        while (curr->next != nullptr) {
            curr = curr->next;              // move curr to next node
        }

        LinkedList temp(other);                 // LinkedList we want to append to
        curr->next = temp.head;                 // when curr is at last Node, curr points to temp's head instead of nullptr
        temp.head = nullptr;
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

// Returns the number of items in the Linked List.
int LinkedList::size() const
{
    Node* curr = head;
    int size = 0;
    while (curr != nullptr)
    {
        size++;                     // increment size
        curr = curr->next;          // move curr to next node
    }
    return size;
}
