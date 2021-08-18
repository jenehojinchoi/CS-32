//
//  Problem1.cpp
//  LA-Worksheet
//
//  Created by Jene Hojin Choi on 2021/07/12.
//

#include "Problem1.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <cassert>
using namespace std;

struct Node;
class LinkedList;

int cmpr(Node* head, int* arr, int arr_size) {
    Node* curr = head;
    int i = 0;
    int index = -1;
    while (curr) {
        if (curr->value == arr[i]) {
            index++;
        }
        curr = curr->next;
        i++;
    }
    return index;
}

int Problem1() {
    LinkedList ll;
    for (int i=6; i>0; i--) {
        if (i!=4) {
            ll.insertToFront(i);
        }
    }
    cout << "head->";
    ll.printList();
    
    int a[6] = {1, 2, 3, 4, 5, 6};
    assert(cmpr(ll.head, a, 6) == 2);
    
    int b[7] = {1, 2, 3, 5, 6, 7, 5};
    assert(cmpr(ll.head, b, 7) == 4); // Should print 4

    int c[3] = {5, 1, 2};
    assert(cmpr(ll.head, c, 3) == -1); // Should print -1

    int d[3] = {1, 2, 3};
    assert(cmpr(ll.head, d, 3) == 2); // Should print 2

    return 0;
}
