//
//  Problem1.cpp
//  Week7
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

#include <iostream>
#include <list>
#include <set>
using namespace std;

int deleteOddSumLists(set<list<int>*>& s)
{
    int numDeleted = 0;
    set<list<int>*>::iterator set_it = s.begin();
    
    while (set_it!=s.end())
    {
        int sum = 0;
        
        list<int>::iterator list_it = (*set_it)->begin();
        list<int>::iterator list_end = (*set_it)->end();
        while (list_it != list_end)
        {
            sum += *list_it;
            list_it++;
        }
        
        // delete list and remove from set if sum is odd
        // otherwise, proceed to check the next list
        if (sum % 2 == 1)
        {
            delete *set_it;
            set_it = s.erase(set_it);
            numDeleted++;
        }
        else
            set_it++;
    }
    return numDeleted;
}
