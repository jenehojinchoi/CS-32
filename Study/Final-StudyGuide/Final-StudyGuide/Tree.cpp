////
////  Tree.cpp
////  Final-StudyGuide
////
////  Created by Jene Hojin Choi on 2021/08/18.
////
//
//#include "Tree.hpp"
//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
////// Represents a node of an n-ary tree
////struct Node;
//  
// // Utility function to create a new tree node
//Node *newNode(int val)
//{
//    Node *temp = new Node;
//    temp->val = val;
//    return temp;
//}
// 
//// Prints the n-ary tree level wise
//void LevelOrderTraversal(Node * root)
//{
//    if (root==NULL)
//        return;
//  
//    // Standard level order traversal code
//    // using queue
//    queue<Node *> q;  // Create a queue
//    q.push(root); // Enqueue root
//    while (!q.empty())
//    {
//        int n = int(q.size());
// 
//        // If this node has children
//        while (n > 0)
//        {
//            // Dequeue an item from queue and print it
//            Node * p = q.front();
//            q.pop();
//            cout << p->val << " ";
//  
//            // Enqueue all children of the dequeued item
//            for (int i=0; i<p->children.size(); i++)
//                q.push(p->children[i]);
//            n--;
//        }
//  
//        cout << endl; // Print new line between two levels
//    }
//}
//
//int countLeaves(Node * root)
//{
//    if (root == nullptr) return 0;
//    if (root->children.size() == 0) {
//        //cout << "key: " << root->val << "\n";
//        return 1;
//    }
//    
//    int count = 0;
//    //cout << "\n";
//    //cout << "key: " << root->val << "\n";
//    for (int i = 0; i < root->children.size(); i++) {
//        count += countLeaves(root->children[i]);
//    }
//    
//    return count;
//}
//
