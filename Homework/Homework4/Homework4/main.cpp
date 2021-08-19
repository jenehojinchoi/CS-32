//////
//////  main.m
//////  Homework4
//////
//////  Created by Jene Hojin Choi on 2021/08/14.
//////

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

//#include <iostream>
//#include "WordTree.h"
//#include <cassert>
//#include <fstream>
//#include <istream>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//int main() {
//    WordTree w;
//
//    string s;
//    ifstream myfile("doi.txt");
//    while(getline(myfile, s))
//    {
//        replace(s.begin(), s.end(), '-', ' ');
//        istringstream iss(s);
//        string sub;
//            locale loc;
//
//        while(iss >> sub)
//        {
//            for(auto& c : sub)
//            {
//               c = tolower(c);
//            }
//            sub.erase(remove_if(sub.begin(), sub.end(), [](char c) { return (!isalpha(c) && c != '\''); } ), sub.end());
//            if (sub == "") {
//                continue;
//            }
//            w.add(sub);
//        }
//    }
//    cout << w << endl;
//    cout << "Total number of words in text: " << w.totalWords() << ".\n";
//    cout << "Number of distinct words appearing in text: " << w.distinctWords() << ".\n";
//}


#include "WordTree.h"
#include <cassert>
#include <iostream>
using namespace std;

void test1()
{
    cerr << "TEST 1 ---------------------------------" << endl;
    WordTree k;

    k.add("Kim");
    k.add("Kanye");
    k.add("Kanye");
    k.add("Kanye");
    cerr << k << endl;
    assert(k.distinctWords() == 2);
    assert(k.totalWords() == 4);
}

void test2()
{
    cerr << "TEST 2 ---------------------------------" << endl;
    WordTree w;

    w.add("Harry");
    w.add("Niall");
    w.add("Niall");
    w.add("Liam");
    w.add("Louis");
    w.add("Harry");
    w.add("Niall");
    w.add("Zayn");
    cerr << w << endl;

    cerr << "This should be the same as:" << endl;

    WordTree copy = w;
    cerr << copy << endl;
}

void test3()
{
    cerr << "TEST 3 ---------------------------------" << endl;
    WordTree me;

    me.add("Justin");
    me.add("Tim");
    me.add("Tim");
    me.add("Zack");
    me.add("Chengye");
    me.add("Tim");
    assert(me.distinctWords() == 4);
    assert(me.totalWords() == 6);

    cerr << me << endl;

    WordTree copy;
    cerr << copy << endl;
    cerr << "^^^ this should be an empty line because our copy is empty right now" << endl;

    copy = me;

    cerr << "This should be the same as:" << endl;
    cerr << copy << endl;
}

void test4()
{
    cerr << "TEST 4 ---------------------------------" << endl;
    WordTree empty;

    WordTree empty2 = empty;

    cerr << empty << endl;
    cerr << empty2 << endl;
    cerr << "^^^ There should be 2 empty lines here because we created 2 empty trees" << endl;
}

void test5()
{
    cerr << "TEST 5 ---------------------------------" << endl;
    WordTree w;
    //w.add("Abc");
    w.add("");
    w.add("abc-def");
    w.add("Abc-Def--Ghi-");
    w.add("abc'");
    w.add("abc.");
    w.add("&abc");
    cout << w;
}


int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    cerr << endl << "ALL TESTS PASSED!" << endl;
}

//
//#include <iostream>
//#include <cassert>
//#include "WordTree.h"
//using namespace std;
//
//int main() {
//    WordTree k;
//    k.add("Kim");
//    k.add("Kanye");
//    k.add("Kanye");
//    k.add("Kanye");
//    assert(k.distinctWords() == 2);
//    assert(k.totalWords() == 4);
//    WordTree w;
//    w.add("Harry");
//    w.add("Niall");
//    w.add("Niall");
//    w.add("Liam");
//    w.add("Louis");
//    w.add("Harry");
//    w.add("Niall");
//    w.add("Zayn");
//    WordTree s(w);
//    cout << s <<endl;
//    WordTree v;
//    v.add("iapapa");
//    v.add("hohoho");
//    v.add("hehehe");
//    v.add("fufufu");
//    v.add("dododo");
//    v.add("hohoho");
//    v.add("dododo");
//    v.add("hohoho");
//    v.add("shiushiu");
//    v.add("hohoho");
//    v.add("pupupu");
//    v.add("dadada");
//    v.add("hahaha");
//    v.add("mememe");
//    v.add("asd");
//    v.add("qweqwe");
//    cout << v <<endl;
//    cout<<v.distinctWords()<<endl;
//    cout<<v.totalWords()<<endl;
//    WordTree p(v);
//    cout<<p;
//    v = w;
//    cout << v << endl;
//    WordTree c;
//    WordTree b(c);
//    cout<<c<<"hoho"<<b<<"hoho";
//    b = v;
//    cout<<b<<"yes";
//}
