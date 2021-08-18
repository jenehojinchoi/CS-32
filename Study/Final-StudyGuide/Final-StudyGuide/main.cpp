//
//  main.m
//  Final-StudyGuide
//
//  Created by Jene Hojin Choi on 2021/08/17.
//

#include "BinaryTree.hpp"
//#include "Tree.hpp"
#include <iostream>
#include <cassert>

using namespace std;


// Binary tree
//int main()
//{
//    Tree h;
//    h.add(1);
//    expand_leaf(h.getRoot(), 2, 3);
//    expand_leaf(h.getRoot()->left, 4, 5);
//    expand_leaf(h.getRoot()->left->left, 7, 8);
//    addOne(h.getRoot()->right, 6, "right");
//    addOne(h.getRoot()->left->right, 9, "left");
//
//    printBT("", h.getRoot(), false);
//
//    printLevelOrder(h.getRoot());
//}

//int main()
//{
//    Tree a;
//    a.add(1);
//    expand_leaf(a.getRoot(), 2, 3);
//    expand_leaf(a.getRoot()->left, 4, 5);
//
//    printBT("", a.getRoot(), false);
//
//    vector<int>inorder = inorderTraversal(a.getRoot());
//    vector<int>::iterator inorder_iter = inorder.begin();
//    while (inorder_iter != inorder.end()) {
//        cout << *inorder_iter << " ";
//        ++inorder_iter;
//    }
//    cout << "\n";
//
//    vector<int>preorder = preorderTraversal(a.getRoot());
//    vector<int>::iterator preorder_iter = preorder.begin();
//    while (preorder_iter != preorder.end()) {
//        cout << *preorder_iter << " ";
//        ++preorder_iter;
//    }
//    cout << "\n";
//
//    vector<int>postorder = postorderTraversal(a.getRoot());
//    vector<int>::iterator postorder_iter = postorder.begin();
//    while (postorder_iter != postorder.end()) {
//        cout << *postorder_iter << " ";
//        ++postorder_iter;
//    }
//    cout << "\n";
//}

int main()
{
    Tree a;
    a.add(1);
    expand_leaf(a.getRoot(), 2, 3);
    addOne(a.getRoot()->left, 5, "right");
    
    printBT("", a.getRoot(), false);
    
    vector<string> paths = rootToLeaf(a.getRoot());
    vector<string>::iterator i = paths.begin();
    while (i != paths.end()) {
        cout << *i << " ";
        ++i;
    }
}


// non Binary Tree
//int main()
//{
//    /*   Let us create below tree
//    *              10
//    *        /   /    \   \
//    *        2  34    56   100
//    *       / \         |   /  | \
//    *      77  88       1   7  8  9
//    */
//    Node *root = newNode(3);
//    (root->children).push_back(newNode(1));
//    (root->children).push_back(newNode(2));
//    (root->children[0]->children).push_back(newNode(2));
//    (root->children[0]->children).push_back(newNode(7));
//    (root->children[0]->children).push_back(newNode(4));
//    (root->children[0]->children).push_back(newNode(8));
//    (root->children[1]->children).push_back(newNode(9));
//    (root->children[1]->children).push_back(newNode(12));
//    (root->children[1]->children).push_back(newNode(0));
//    (root->children[0]->children[0]->children).push_back(newNode(5));
//    (root->children[0]->children[0]->children).push_back(newNode(6));
//
//    cout << "Level order traversal Before Mirroring\n";
//    LevelOrderTraversal(root);
//
//    cout << "\n" << "Leaves: " << countLeaves(root) << "\n";
//
//    return 0;
//}
