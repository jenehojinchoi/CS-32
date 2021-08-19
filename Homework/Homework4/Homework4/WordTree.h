//
//  WordTree.h
//  Homework4
//
//  Created by Jene Hojin Choi on 2021/08/14.
//

#ifndef WordTree_h
#define WordTree_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

typedef std::string WordType;

struct WordNode {
    int count = 0; //  added count
    WordType m_data;
    WordNode *m_left;
    WordNode *m_right;
};

class WordTree {
private:
    WordNode *root;
    
    // create a wordNode
    void createWordNode(WordType v, int count, WordNode*& temp);
    
    // copy constructor helper
    void copy(WordNode *& temp, WordNode* copySource);
    
    // stream helper
    void streamHelper(std::ostream& output, WordNode* curr) const;
    
    // free memory of tree node by node
    void freeTree(WordNode* node);
    
    // distinctWords helper
    int distinctWordsOfWordTree(WordNode *curr) const;
    
    // totalWords helper
    int totalWordsOfWordTree(WordNode* curr) const;
    
    // makes words lowercase
    void lower(WordType& v);
    
    // remove special characters at the end
    void removeSpecialCharacters(WordType& v);
    
    // create a vector of parsed words
    //std::vector<std::string> createParsedWordList(WordType &v);
    //std::vector<std::string> findFirstandRest(WordType w);
    bool findFirstandRest(WordType& w);
    
    void addHelper(WordType &v);
    
public:
    // default constructor
    WordTree() : root(nullptr) { };
    
    // copy constructor
    WordTree(const WordTree& rhs);

    // assignment operator
    const WordTree& operator=(const WordTree& rhs);
    
    // Inserts v into the WordTree
    void add(WordType v);
    
    // Returns the number of distinct words / nodes
    int distinctWords() const;
    
    // Returns the total number of words inserted, including
    // duplicate values
    int totalWords() const;
    
    // Swap the contents of this tree with the other one
    void swapWordTree(WordTree &rhs);

    // Prints the LinkedList
    friend std::ostream& operator<<(std::ostream &out, const WordTree& rhs);
    
    // Destroys all the dynamically allocated memory in the tree
    ~WordTree();
};


#endif /* WordTree_h */
