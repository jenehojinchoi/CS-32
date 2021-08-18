//
//  Problem3.cpp
//  Week7
//
//  Created by Jene Hojin Choi on 2021/08/03.
//

#include <iostream>
#include <vector>
using namespace std;

void removeAllZeroes(vector<int>& x) {
    vector<int>::iterator it = x.begin();
    
    while (it != x.end()) {
        if (*it == 0)
            it = x.erase(it);
        else
            it++;
    }
}

//int main()
//{
//    vector<int> vec;
//    vec.push_back(1);
//    vec.push_back(2);
//    vec.push_back(3);
//    vec.push_back(0);
//    vec.push_back(4);
//    vec.push_back(5);
//    vec.push_back(0);
//    
//    vector<int>::iterator it = vec.begin();
//    while (it != vec.end())
//    {
//        cout << (*it) << "\n";
//        it++;
//    }
//    
//    cout << "\n\n";
//    
//    removeAllZeroes(vec);
//    
//    vector<int>::iterator it2 = vec.begin();
//    while (it2 != vec.end())
//    {
//        cout << (*it2) << "\n";
//        it2++;
//    }
//    
//}
