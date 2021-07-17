//
//  OnlineDating.h
//  Project2
//
//  Created by Jene Hojin Choi on 2021/07/14.
//

#ifndef OnlineDating_h
#define OnlineDating_h

#include <string>
#include <iostream>

//typedef IntWrapper OnlineType;
typedef std::string OnlineType;
//typedef int OnlineType;

struct Node
{
    std::string firstName;
    std::string lastName;
    OnlineType data;
    Node* next;
    Node* prev;
};

class OnlineDating
{
private:
    Node* head;
    
public:
    OnlineDating();
    
    ~OnlineDating();
    
    OnlineDating(const OnlineDating& rhs);
    
    OnlineDating& operator=(const OnlineDating &rhs);

    bool noMatches() const;

    int howManyMatches() const;

    bool makeMatch(const std::string& firstName, const std::string& lastName, const OnlineType& value);

    bool transformMatch(const std::string& firstName, const
    std::string& lastName, const OnlineType & value);

    bool makeOrTransform(const std::string& firstName, const
    std::string& lastName, const OnlineType& value);

    bool blockPreviousMatch(const std::string& firstName, const
    std::string& lastName);

    bool someoneAmongMatches(const std::string& firstName, const
    std::string& lastName) const;

    bool lookAtMatches(const std::string& firstName, const
    std::string& lastName, OnlineType& value) const;

    bool confirmMatch(int i, std::string& firstName, std::string&
    lastName, OnlineType & value) const;

    void tradeMatches(OnlineDating& other);
};

bool mergeMatches(const OnlineDating & odOne, const OnlineDating & odTwo, OnlineDating & odJoined);
void authenticateMatches (const std::string& fsearch, const std::string& lsearch, const OnlineDating& odOne, OnlineDating& odResult);

#endif /* OnlineDating_h */
