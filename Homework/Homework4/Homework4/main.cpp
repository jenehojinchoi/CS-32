////
////  main.m
////  Homework4
////
////  Created by Jene Hojin Choi on 2021/08/14.
////
//
//#include "WordTree.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//int main() {
//    WordTree w;
//    w.add("Harry");
//    w.add("Niall");
//    w.add("Niall");
//    w.add("Liam");
//    w.add("Louis");
//    w.add("Harry");
//    w.add("Niall");
//    w.add("Zayn");
//
//    cout << w;
//
//    WordTree k;
//
//    k.add("Kim");
//    k.add("Kanye");
//    k.add("Kanye");
//    k.add("Kanye");
//    assert(k.distinctWords() == 2);
//    assert(k.totalWords() == 4);
//    cout << "passed" << "\n";
//
//    return 0;
//}

#include <iostream>
#include "WordTree.h"
#include <cassert>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    WordTree w;

    string s;
    ifstream myfile("odyssey1.txt");
    while(getline(myfile, s))
    {
        replace(s.begin(), s.end(), '-', ' ');
        istringstream iss(s);
        string sub;
            locale loc;

        while(iss >> sub)
        {
            for(auto& c : sub)
            {
               c = tolower(c);
            }
            sub.erase(remove_if(sub.begin(), sub.end(), [](char c) { return !isalpha(c); } ), sub.end());
            if (sub == "") {
                continue;
            }
            w.add(sub);

        }
    }
    cout << w << endl;
    cout << "Total number of words in text: " << w.totalWords() << ".\n";
    cout << "Number of distinct words appearing in text: " << w.distinctWords() << ".\n";
}
