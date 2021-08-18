//
//  Tree.hpp
//  Final-StudyGuide
//
//  Created by Jene Hojin Choi on 2021/08/17.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>
#include <string>
#include <vector>
#include <queue>

typedef int DataType;
using namespace std;

/////////////////////////////////////////////////////////////////
// Node
/////////////////////////////////////////////////////////////////

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(DataType data): val(data), left(nullptr), right(nullptr) {};
};

/////////////////////////////////////////////////////////////////
// Functions in Final Study Guide, Worksheets
/////////////////////////////////////////////////////////////////

// Final Study Guide

Node* expand_leaf(Node* node, DataType x, DataType y);

// expand_leaf adds two leaves
// addOne adds only one leaf
Node* addOne(Node* T, DataType x, std::string dir);

void printBT(const std::string& prefix, const Node* TreeNode, bool isLeft);

int height(Node* T);

bool same_tree(Node* T1, Node* T2);

Node* bst_insert(DataType item, Node* T);


// Worksheet Week 8

bool treeContains(const Node* head, int n);

void reverse(Node* root);

void levelOrder(Node* root);

void printGivenLevel(Node* t, int level);

void printLevelOrder(Node * root);

void rootToLeaf(Node* root, vector<std::string>& paths, std::string curr);

vector<std::string> rootToLeaf(Node* root);

/////////////////////////////////////////////////////////////////
// Traversal
/////////////////////////////////////////////////////////////////

void inorder(Node* root, std::vector<int>& nodes);

std::vector<int> inorderTraversal(Node* root);

void preorder(Node* root, std::vector<int>& nodes);

std::vector<int> preorderTraversal(Node* root);

void postorder(Node* root, std::vector<int>& nodes);

std::vector<int> postorderTraversal(Node* root);
/////////////////////////////////////////////////////////////////
// Tree
/////////////////////////////////////////////////////////////////

class Tree {
private:
    Node *root;

    // create a wordNode
    void createTreeNode(DataType v, Node*& temp);

    // copy constructor helper
    void copy(Node *temp, Node* copySource);

    // add helper
    void addToNonEmptyWordTree(DataType v, Node* curr);

    // stream helper
    void streamHelper(std::ostream& output, Node* curr) const;

    // free memory of tree node by node
    void freeTree(Node* node);


public:
    // default constructor
    Tree() : root(nullptr) { };

    // copy constructor
    Tree(const Tree& rhs);

    // getRoot
    Node* getRoot();

    // assignment operator
    const Tree& operator=(const Tree& rhs);

    // Inserts v into the WordTree
    void add(DataType v);

    // Swap the contents of this tree with the other one
    void swapTree(Tree &rhs);

    // Prints the LinkedList
    friend std::ostream& operator<<(std::ostream &out, const Tree& rhs);

    // Destroys all the dynamically allocated memory in the tree
    ~Tree();
};

#endif /* Tree_hpp */
