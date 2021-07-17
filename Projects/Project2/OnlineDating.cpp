//
//  OnlineDating.cpp
//  Project2
//
//  Created by Jene Hojin Choi on 2021/07/14.
//

#include "OnlineDating.h"
#include <string>
#include <cassert>
#include <iostream>

// Create an empty OnlineDating list
OnlineDating::OnlineDating()
{
    head = nullptr;
}

// Destructor
OnlineDating::~OnlineDating()
{
    Node *curr = head;
    while (curr) {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
}

// Copy Constructor
OnlineDating::OnlineDating(const OnlineDating &rhs)
{
    this->head = nullptr;
    if (rhs.head){
        Node *curr = rhs.head;
        
        while (curr) {
            this->makeMatch(curr->firstName, curr->lastName, curr->data);
            curr = curr->next;
        }
    }
}

// Assignment operator
OnlineDating& OnlineDating::operator=(const OnlineDating &rhs)
{
    if (this != &rhs){
        OnlineDating temp(rhs);
        tradeMatches(temp);
    }
    return *this;
}


bool OnlineDating::noMatches() const
{
    return (!head);
}

int OnlineDating::howManyMatches() const
{
    Node *curr = head;
    int matches = 0;
    while (curr) {
        matches++;
        curr = curr->next;
    }
    return matches;
}

    
bool OnlineDating::makeMatch(const std::string& firstName, const std::string& lastName, const OnlineType& value)
// If the full name (both the first and last name) is not equal
// to any full name currently in the list then add it and return
// true. Elements should be add according to their last name.
// Elements with the same last name should be added according to
// their first names. Otherwise, make no change to the list and
// return false (indicating that the name is already in the
// list).
{
    // empty head
    if (!head) {
        head = new Node;
        head->data = value;
        head->firstName = firstName;
        head->lastName = lastName;
        head->prev = nullptr;
        head->next = nullptr;
        return true;
    }
    
    // not empty head
    Node *curr = head;

    while (curr) {
        if (curr->lastName == lastName) {
            if (curr->firstName == firstName) {
                return false;
                
            } else if (curr->firstName > firstName) {
                Node *newNode = new Node;
                
                newNode->data = value;
                newNode->firstName = firstName;
                newNode->lastName = lastName;
                
                newNode->next = curr;

                if (curr->prev != nullptr) {
                    newNode->prev = curr->prev;
                    curr->prev->next = newNode;

                } else { // curr->prev == nullptr
                    newNode->prev = nullptr;
                    head = newNode;
                    
                }
                curr->prev = newNode;
                
                return true;
            }
            
            else if (!curr->next && curr->firstName < firstName) {
                // if curr->next == nullptr, we need to insert newNode now
                // next iteration will not going to happen
                Node *newNode = new Node;
                newNode->data = value;
                newNode->firstName = firstName;
                newNode->lastName = lastName;
                
                newNode->prev = curr;
                curr->next = newNode;
                newNode->next = nullptr;
                
                return true;
            }
            
        } else if (curr->lastName > lastName) {
            Node *newNode = new Node;
            
            newNode->data = value;
            newNode->firstName = firstName;
            newNode->lastName = lastName;
            
            newNode->next = curr;

            if (curr->prev != nullptr) {
                newNode->prev = curr->prev;
                curr->prev->next = newNode;

            } else { // curr->prev == nullptr
                newNode->prev = nullptr;
                head = newNode;
                
            }
            curr->prev = newNode;
            
            return true;
        }
            
        else if (!curr->next && curr->lastName < lastName) {
            Node *newNode = new Node;
            newNode->data = value;
            newNode->firstName = firstName;
            newNode->lastName = lastName;
            
            newNode->prev = curr;
            curr->next = newNode;
            newNode->next = nullptr;
            
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool OnlineDating::someoneAmongMatches(const std::string& firstName, const std::string& lastName) const
// Return true if the full name is equal to a full name
// currently in the list, otherwise false.
{
    Node *curr = head;
    while (curr) {
        if (curr->firstName == firstName && curr->lastName == lastName) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}


bool OnlineDating::transformMatch(const std::string& firstName, const std::string& lastName, const OnlineType & value)
// If the full name is equal to a full name currently in the
// list, then make that full name no longer map to the value it
// currently maps to, but instead map to the value of the third
// parameter; return true in this case. Otherwise, make no
// change to the list and return false.
{
    Node *curr = head;
    while (curr) {
        if (curr->firstName == firstName && curr->lastName == lastName) {
            // if the name is the same, set data as value parameter
            curr->data = value;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool OnlineDating::makeOrTransform(const std::string& firstName, const std::string& lastName, const OnlineType& value)
// If full name is equal to a name currently in the list, then
// make that full name no longer map to the value it currently
// maps to, but instead map to the value of the third parameter;
// return true in this case. If the full name is not equal to
// any full name currently in the list then add it and return
// true. In fact, this function always returns true.

{
    if (someoneAmongMatches(firstName, lastName)) // check if there is the full name
        return transformMatch(firstName, lastName, value);  // change the value
    return makeMatch(firstName, lastName, value);           // add extra node
}

bool OnlineDating::blockPreviousMatch(const std::string& firstName, const std::string& lastName)
// If the full name is equal to a full name currently in the
// list, remove the full name and value from the list and return
// true. Otherwise, make no change to the list and return
// false.
{
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->lastName == lastName && curr->firstName == firstName) {
                if (curr->prev == nullptr && curr->next != nullptr ) {
                    head = curr->next;
                    curr->next->prev = nullptr;
                    
                } else if (curr->next == nullptr && curr->prev != nullptr) {
                    curr->prev->next = nullptr;
                    
                } else if (curr->next != nullptr && curr->prev != nullptr ) {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    
                } else { // curr->prev == nullptr && curr->next == nullptr
                    head = nullptr;
                }

                delete curr;
                return true;
            }
        curr = curr->next;
    }
    return false;
}


bool OnlineDating::lookAtMatches(const std::string& firstName, const std::string& lastName, OnlineType& value) const
// If the full name is equal to a full name currently in the
// list, set value to the value in the list that that full name
// maps to, and return true. Otherwise, make no change to the
// value parameter of this function and return false.
{
    Node *curr = head;
    while (curr) {
        if (curr->firstName == firstName && curr->lastName == lastName) {
            value = curr->data;
            return true;
        }
        curr = curr->next;
    }
    return false;
}


bool OnlineDating::confirmMatch(int i, std::string& firstName, std::string& lastName, OnlineType & value) const
// If 0 <= i < size(), copy into firstName, lastName and value
// parameters the corresponding information of the element at
// position i in the list and return true. Otherwise, leave the
// parameters unchanged and return false. (See below for details
// about this function.)
{
    // this function will change parameters!
    Node *curr = head;
    int index = 0;
    if ( 0 <= i && i < howManyMatches()) {
        while (index != i) {
            index++;
            curr = curr->next;
        }
        firstName = curr->firstName;
        lastName = curr->lastName;
        value = curr->data;
        return true;
    }
    return false;
}

void OnlineDating::tradeMatches(OnlineDating& other)
// Exchange the contents of this list with the other one.
{
    Node* curr = head;
    head = other.head;
    other.head = curr;
    curr = nullptr;     // return to null
}


// Non member functions
bool mergeMatches(const OnlineDating & odOne, const OnlineDating & odTwo, OnlineDating & odJoined) {
//If a full name appears in exactly one of odOne and odTwo, then odJoined must
//contain an element consisting of that full name and its corresponding value.
//If a full name appears in both odOne and odTwo, with the same corresponding value in
//both, then odJoined must contain an element with that full name and value.
    
//When this function returns, odJoined must contain no elements other than those
//required by these rules. (You must not assume odJoined is empty when it is passed in
//to this function; it might not be.)
    
//If there exists a full name that appears in both odOne and odTwo, but with different
//corresponding values, then this function returns false; if there is no full name like this,
//the function returns true. Even if the function returns false, result must be constituted as
//defined by the above rules.
    

    // base case
    if (odOne.noMatches() && !odTwo.noMatches()) {
        odJoined = odTwo;
        return true;
    } else if (odTwo.noMatches()) {
        odJoined = odOne;
        return true;
    }

    std::string firstName;
    std::string lastName;
    OnlineType val;
    bool result = true;

    // using i, take fN, lN, and val from existing odTwo nodes
    int i = 0;
    while (odTwo.confirmMatch(i, firstName, lastName, val))
    {
        // if odJoined already has the name
        if (odOne.someoneAmongMatches(firstName, lastName)) {
            OnlineType data;
            odOne.lookAtMatches(firstName, lastName, data);   // take value of odOne value with the same fullname

            // if values are different
            if (data != val) {
                result = false;
            }
        }
        i++;
    }
    
    
    // if result is true
    odJoined = odOne; // make odJoined as odOne
    i = 0;
    
    if (result) {
        while (odTwo.confirmMatch(i, firstName, lastName, val))
        {
            if (!odJoined.makeMatch(firstName, lastName, val)) {
                OnlineType compMe;
                odOne.lookAtMatches(firstName, lastName, compMe);
            }
            i++;
        }
        return result;
    }
    
    // else if result is false
    OnlineDating newodj;
    odJoined = newodj;
    // loop through odOne
    i = 0;
    while (odOne.confirmMatch(i, firstName, lastName, val))
    {
        // if odTwo does not have the name
        // add it to odJoined
        if (!odTwo.someoneAmongMatches(firstName, lastName)) {
            odJoined.makeMatch(firstName, lastName, val);
        }
        i++;
    }
    
    // loop through odTwo
    i = 0;
    while (odTwo.confirmMatch(i, firstName, lastName, val))
    {
        // if odTwo does not have the name
        // add it to odJoined
        if (!odOne.someoneAmongMatches(firstName, lastName)) {
            odJoined.makeMatch(firstName, lastName, val);
        }
        i++;
    }
    return result;
}

void authenticateMatches (const std::string& fsearch, const std::string& lsearch, const OnlineDating& odOne, OnlineDating& odResult)
//When this function returns, odResult must contain a copy of all the elements in odOne
//that match the search terms; it must not contain any other elements. You can wildcard
//the first name, last name or both by supplying "*". (You must not assume result is empty
//when it is passed in to this function; it may not be.)
{
    OnlineType val;
    odResult = odOne;

    std::string firstName;
    std::string lastName;

    int i = 0;
    
    while (odOne.confirmMatch(i, firstName, lastName, val)) {
        if (lsearch == "*" && fsearch == "*" )
            return;
        
        else if (lsearch == "*" && fsearch != "*") {
            if (firstName != fsearch)
                odResult.blockPreviousMatch(firstName, lastName);
        }
        
        else if (fsearch == "*" && lsearch != "*") {
            if (lastName != lsearch)
                odResult.blockPreviousMatch(firstName, lastName);
        }
        else { //lsearch != "*" && fsearch != "*"
            // nothing happens
            if (firstName != fsearch || lastName != lsearch ) {
                odResult.blockPreviousMatch(firstName, lastName);
            }
        }
        i++;
    }
}
