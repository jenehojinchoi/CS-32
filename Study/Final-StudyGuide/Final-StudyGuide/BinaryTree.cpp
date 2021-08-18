//
//  Tree.cpp
//  Final-StudyGuide
//
//  Created by Jene Hojin Choi on 2021/08/17.
//

#include "BinaryTree.hpp"
#include <iostream>
using namespace std;

struct Node;

/////////////////////////////////////////////////////////////////
// Functions in Final Study Guide, Worksheets
/////////////////////////////////////////////////////////////////


void printBT(const std::string& prefix, const Node* TreeNode, bool isLeft)
{
    if( TreeNode != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << TreeNode->val << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), TreeNode->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), TreeNode->right, false);
    }
}

Node* addOne(Node* T, DataType x, std::string dir)
{
    if (T == nullptr) return T;
    
    else if (dir == "left"){
        if (T->left == nullptr && T->right == nullptr){
            //cout << "m_left, m_right nullptr" << "\n";
            T->left = new Node(x);
            
            if (T->left->left==nullptr && T->left->right==nullptr)
                return T;
        }
        
        if (T->left != nullptr)
            //cout << "m_left is not nullptr" << "\n";
            T->left = addOne(T->left, x, "left");
        
        return T; // return the (unchanged) pointer T
    }
    
    else if (dir == "right"){
        if (T->left == nullptr && T->right == nullptr){
            //cout << "m_left, m_right nullptr" << "\n";
            T->right = new Node(x);
            
            if (T->right->left==nullptr && T->right->right==nullptr)
                return T;
        }
        
        if (T->right != nullptr)
            //cout << "m_left is not nullptr" << "\n";
            T->right = addOne(T->right, x, "right");
        
        return T;
    }
    return T;
}

Node* expand_leaf(Node* T, DataType x, DataType y)
{
    if (T == nullptr) return T;
    
    else {
        if (T->left == nullptr && T->right == nullptr){
            //cout << "m_left, m_right nullptr" << "\n";
            T->left = new Node(x);
            T->right = new Node(y);
            
            if (T->left->left==nullptr && T->left->right==nullptr && T->right->left==nullptr && T->right->right==nullptr)
                return T;
        }
        
        if (T->left != nullptr)
            //cout << "m_left is not nullptr" << "\n";
            T->left = expand_leaf(T->left, x, y);
        
        if (T->right != nullptr)
            T->right = expand_leaf(T->right, x, y);
        
        return T; // return the (unchanged) pointer T
    }
}

int height(Node* T) {
    if (T == nullptr) return 0;
    else {
        int lHeight = height(T->left);
        int rHeight = height(T->right);
        
        if (T->left == nullptr && T->right == nullptr) {
            if (lHeight > rHeight) return lHeight;
            else return rHeight;
        }
        else {
            if (lHeight > rHeight) return lHeight + 1;
            else return rHeight+1;
        }
    }
}

bool same_tree(Node* T1, Node* T2)
{
    if (T1 == nullptr && T2 == nullptr) return true;
    if (T1 == nullptr || T2 == nullptr) return false;
    return (same_tree(T1->left, T2->left) && same_tree(T1->right, T2->right));
}

Node* bst_insert(DataType item, Node* T) {
     if (T == nullptr) {
         T = new Node(item);
         return T;
     }
     else {
         if (item <= T->val) T->left = bst_insert(item, T->left);
         else T->right = bst_insert(item, T->right);
         return T; // return the (unchanged) pointer T
     }
}

bool treeContains(const Node* head, int n)
{
    if (head == nullptr) return false;
    else {
        if (head->val == n) return true;
        else return (treeContains(head->left, n) || treeContains(head->right, n));
    }
}

void reverse(Node* root)
{
    if (root != nullptr) {
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        reverse(root->left);
        reverse(root->right);
    }
}

void levelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (int i=1 ; i<=h; i++)
        printGivenLevel(root, i);
}

void printGivenLevel(Node* t, int level)
{
    if (t == nullptr)
        return;
    if (level == 1)
        cout << t->val << " ";
    else if (level > 1) {
        printGivenLevel(t->left, level-1);
        printGivenLevel(t->right, level-1);
    }
}


void printLevelOrder(Node * root)
{
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int nodeCount = int(q.size());
        while (nodeCount > 0) {
            Node* node = q.front();
            cout << node->val << " ";
            q.pop();
            
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}

void rootToLeaf(Node* root, vector<std::string>& paths, std::string curr) {
    if (root->left == nullptr && root->right == nullptr) {
        paths.push_back(curr);
        return;
    }
    
    if (root->left != nullptr) {
        rootToLeaf(root->left, paths, curr + "->" +
        std::to_string(root->left->val));
    }
    
    if (root->right != nullptr) {
        rootToLeaf(root->right, paths, curr + "->" +
        std::to_string(root->right->val));
    }
}

vector<std::string> rootToLeaf(Node* root) {
    vector<std::string> paths;
    if (root != nullptr)
        rootToLeaf(root, paths, std::to_string(root->val));
    return paths;
}

/////////////////////////////////////////////////////////////////
// Traversal
/////////////////////////////////////////////////////////////////

// Helper void function with reference to vector
void inorder(Node* root, vector<int>& nodes) {
    if (root == nullptr) return;
    inorder(root->left, nodes);
    nodes.push_back(root->val);
    inorder(root->right, nodes);
}

// Use helper
vector<int> inorderTraversal(Node* root) {
    vector<int> nodes;
    inorder(root, nodes);
    return nodes;
}

// Helper void function with reference to vector
void preorder(Node* root, vector<int>& nodes) {
    if(root == nullptr) return;
    nodes.push_back(root->val);
    preorder(root->left, nodes);
    preorder(root->right, nodes);
}

// Use helper
vector<int> preorderTraversal(Node* root) {
    vector<int> nodes;
    preorder(root, nodes);
    return nodes;
}

// Helper void function with reference to vector
void postorder(Node* root, vector<int>& nodes) {
    if(root == nullptr) return;
    preorder(root->left, nodes);
    preorder(root->right, nodes);
    nodes.push_back(root->val);
}

// Use helper
vector<int> postorderTraversal(Node* root) {
    vector<int> nodes;
    postorder(root, nodes);
    return nodes;
}

/////////////////////////////////////////////////////////////////
// Tree
/////////////////////////////////////////////////////////////////

Node* Tree::getRoot()
{
    return this->root;
}

// create node helper
void Tree::createTreeNode(DataType v, Node*& temp)
{
    temp = new Node(v);
//    temp->m_data = v;
//    temp->m_left = nullptr;
//    temp->m_right = nullptr;
}

// copy constructor helper
// copySource is a soucre, temp is going to copy copySource.
void Tree::copy(Node *temp, Node* copySource)
{
    if (copySource == nullptr) return;
    else {
        createTreeNode(copySource->val, temp);
        copy(temp->left, copySource->left);
        copy(temp->right, copySource->right);
    }
}

// copy constructor
Tree::Tree(const Tree& rhs)
{
    //it the reference tree is empty, set root to nullptr and return
    if (rhs.root == nullptr)
    {
        this->root = nullptr;
        return;
    }
    else copy(this->root, rhs.root);
}


void Tree::addToNonEmptyWordTree(DataType v, Node* curr)
{
    if (v < curr->val) {
        if (curr->left != nullptr) addToNonEmptyWordTree(v, curr->left);
        else createTreeNode(v, curr->left);
    }
    
    else if (v > curr->val) {
        if (curr->right != nullptr) addToNonEmptyWordTree(v, curr->right);
        else createTreeNode(v, curr->right);
    }
}


// Inserts v into the WordTree
void Tree::add(DataType v)
{
    if (root == nullptr) createTreeNode(v, root);
    else addToNonEmptyWordTree(v, root);
}

// helper function for destructor
void Tree::freeTree(Node* node)
{
    if (node == nullptr) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

// Destroys all the dynamically allocated memory in the
// tree
Tree::~Tree()
{
    freeTree(root);
}


// Swap the contents of this tree with the other one
void Tree::swapTree(Tree &rhs)
{
    Node* temp = root;
    root = rhs.root;
    rhs.root = temp;
    temp = nullptr;
}

// assignment operator
const Tree& Tree::operator=(const Tree& rhs)
{
    if (this != &rhs) {
        Tree temp(rhs);
        swapTree(temp);
    }
    return *this;
}

// streamout helper
void Tree::streamHelper(ostream& output, Node* curr) const
{
    if (curr == nullptr)
        return;
    streamHelper(output, curr->left);
    output << curr->val << endl;
    streamHelper(output, curr->right);
    return;
}

// Prints the LinkedList
ostream& operator<<(ostream &out, const Tree& rhs)
{
    rhs.streamHelper(out, rhs.root);
    return out;
}
