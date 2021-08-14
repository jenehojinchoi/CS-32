//
//  WordTree.cpp
//  Homework4
//
//  Created by Jene Hojin Choi on 2021/08/14.
//

#include "WordTree.h"
using namespace std;

struct WordNode;

// create node helper
void WordTree::createWordNode(WordType v, int count, WordNode*& temp)
{
    temp = new WordNode;
    temp->count = count;
    temp->m_data = v;
    temp->m_left = nullptr;
    temp->m_right = nullptr;
}

// copy constructor helper
// copySource is a soucre, temp is going to copy copySource.
void WordTree::copy(WordNode *temp, WordNode* copySource)
{
    if (copySource == nullptr) return;
    else {
        createWordNode(copySource->m_data, copySource->count, temp);
        copy(temp->m_left, copySource->m_left);
        copy(temp->m_right, copySource->m_right);
    }
}

// copy constructor
WordTree::WordTree(const WordTree& rhs)
{
    //it the reference tree is empty, set root to nullptr and return
    if (rhs.root == nullptr)
    {
        this->root = nullptr;
        return;
    }
    else copy(this->root, rhs.root);
}


void WordTree::addToNonEmptyWordTree(WordType v, WordNode* curr)
{
    if (v == curr->m_data) {
        curr->count++;
    }
    
    else if (v < curr->m_data) {
        if (curr->m_left != nullptr) addToNonEmptyWordTree(v, curr->m_left);
        else createWordNode(v, 1, curr->m_left);
    }
    
    else if (v > curr->m_data) {
        if (curr->m_right != nullptr) addToNonEmptyWordTree(v, curr->m_right);
        else createWordNode(v, 1, curr->m_right);
    }
}


// Inserts v into the WordTree
void WordTree::add(WordType v)
{
    if (root == nullptr) createWordNode(v, 1, root);
    else addToNonEmptyWordTree(v, root);
}

// distinctWords helper
int WordTree::distinctWordsOfWordTree(WordNode *curr) const
{
    if (curr == nullptr) return 0;
    return (1 + distinctWordsOfWordTree(curr->m_left) + distinctWordsOfWordTree(curr->m_right));
}

// Returns the number of distinct words / nodes
int WordTree::distinctWords() const
{
    return distinctWordsOfWordTree(root);
}

// totalWords helper
int WordTree::totalWordsOfWordTree(WordNode* curr) const
{
    if (curr == nullptr) return 0;
    else return (curr->count + totalWordsOfWordTree(curr->m_left) + totalWordsOfWordTree(curr->m_right));
}

// Returns the total number of words inserted, including
// duplicate values
int WordTree::totalWords() const
{
    return totalWordsOfWordTree(root);
}

// helper function for destructor
void WordTree::freeTree(WordNode* node)
{
    if (node == nullptr) return;
    freeTree(node->m_left);
    freeTree(node->m_right);
    delete node;
}

// Destroys all the dynamically allocated memory in the
// tree
WordTree::~WordTree()
{
    freeTree(root);
}


// Swap the contents of this tree with the other one
void WordTree::swapWordTree(WordTree &rhs)
{
    WordNode* temp = root;
    root = rhs.root;
    rhs.root = temp;
    temp = nullptr;
}

// assignment operator
const WordTree& WordTree::operator=(const WordTree& rhs)
{
    if (this != &rhs) {
        WordTree temp(rhs);
        swapWordTree(temp);
    }
    return *this;
}

// streamout helper
void WordTree::streamHelper(ostream& output, WordNode* curr) const
{
    if (curr == nullptr)
        return;
    streamHelper(output, curr->m_left);
    output << curr->m_data << " " << curr->count << endl;
    streamHelper(output, curr->m_right);
    return;
}

// Prints the LinkedList
ostream& operator<<(ostream &out, const WordTree& rhs)
{
    rhs.streamHelper(out, rhs.root);
    return out;
}
