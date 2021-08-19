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
void WordTree::copy(WordNode *&temp, WordNode* copySource) 
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
        root = nullptr;
        return;
    }
    else copy(root, rhs.root);
}

void WordTree::lower(WordType &v)
{
    string::iterator it;
    for(it = v.begin(); it < v.end(); it++) {
        if (*it >= 'A' && *it <= 'Z') {
            *it = tolower(*it);
        }
    }
}

void WordTree::removeSpecialCharacters(WordType& v)
{
    int size = int(v.size());
    if ((v[size-1] >= 32 && v[size-1] <= 47) || (v[size-1] >= 58 && v[size-1] <= 64))
        v.erase(v.end()-1);
}

//vector<string> WordTree::createParsedWordList(WordType &v)
//{
//
//    vector<string> list;
//    string::iterator it =  v.begin();
//    int idx = 0;
//    int begin = 0;
//
//    while (it != v.end())
//    {
////        cout << "*it: " << *it << "\n";
////        cout << "begin: " << begin << "\n";
//
//        if (!isalpha(*it)) {
//            string s = v.substr(begin, idx);
//            list.push_back(s);
//            begin = idx + 1;
//        }
//        it++;
//        idx++;
//    }
//
//    // end
//    if (begin != idx) {
//        string s = v.substr(begin, idx);
//        list.push_back(s);
//    }
//
//    return list;
//}


bool WordTree::findFirstandRest(WordType& w){
    vector<string> list;
    string::iterator it =  w.begin();

    int i = 0;
    while(it != w.end()){
        cout << "*it: " << *it << "\n";
        if(!isalpha(*it)){
            if(i != 0){
                string s = w.substr(0, i);
                addHelper(s);
                string rest = w.substr(i+1, w.size());
                return findFirstandRest(rest);// rest of the word
            }
            else{
                string rest = w.substr(i+1, w.size());
                return findFirstandRest(rest);
            }
        }
        
        if (i == w.size()-1) {
            string s = w.substr(0, w.size());
            addHelper(w);
            return true;
        }
        
        i++;
        it++;
    }
    return true;
}

void WordTree::add(WordType v)
{
    lower(v);
    removeSpecialCharacters(v);
    findFirstandRest(v);
}

// Inserts v into the WordTree
void WordTree::addHelper(WordType &v)
{
    if (root == nullptr) {
        createWordNode(v, 1, root);
        return;
        
    }
    //else using a temporary pointer to trace the list until find the right dead end
    WordNode* cur = root;
    for (;;)
    {
        if (v == cur->m_data) {
            cur->count++;
            return;
        }
        
        if (v < cur->m_data)
        {
            if (cur->m_left != nullptr)
                cur = cur->m_left;
            else
            {
                createWordNode(v, 1, cur->m_left);
                return;
            }
        }
        
        if (v > cur->m_data)
        {
            if (cur->m_right != nullptr)
                cur = cur->m_right;
            else
            {
                createWordNode(v, 1, cur->m_right);
                return;
            }
        }
    }
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
    if (root != nullptr) freeTree(root);
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
    
    if (curr == nullptr) return;
    streamHelper(output, curr->m_left);
    output << curr->m_data << " " << curr->count << endl;
    streamHelper(output, curr->m_right);
}

// Prints the LinkedList
ostream& operator<<(ostream &out, const WordTree& rhs)
{
    rhs.streamHelper(out, rhs.root);
    return out;
}
