//
//  test.cpp
//  Project3
//
//  Created by Jene Hojin Choi on 2021/07/28.
//

#include "anagram.h"
#include <iostream>
#include <cassert>

//const int MAXRESULTS = 20;    // Max matches that can be found
//const int MAXDICTWORDS = 30000; // Max words that can be read in

void testMakeDictionary()
{
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;

    dictfile.open("words.txt");
    nwords = makeDictionary(dictfile, dict);
    
    assert(nwords==25144);
    assert(dict[0]=="zygote");
}

void testShuffleChars()
{
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;

    dictfile.open("words.txt");
    nwords = makeDictionary(dictfile, dict);

    assert(shuffleChars("apt", dict, nwords, results)==3);
    
    string results2[MAXRESULTS];
    assert(shuffleChars("cat", dict, nwords, results2)==2);
    
    string results3[MAXRESULTS];
    assert(shuffleChars("AAA", dict, nwords, results3)==1);
    
    string results4[MAXRESULTS];
    assert(shuffleChars("abovementioned", dict, nwords, results4)==1);
    
    // empty string
    string results5[MAXRESULTS];
    assert(shuffleChars("", dict, nwords, results5)==0);
    
    // no results
    string results6[MAXRESULTS];
    assert(shuffleChars("abcdefghijklmnop", dict, nwords, results6)==0);
}

void testIsAnagram()
{
    assert(isAnagram("cat", "tac"));
    assert(isAnagram("abet", "bate"));
    
    // word.length different
    assert(!isAnagram("abcde", "abcd"));
    
    // case sensitive
    assert(!isAnagram("ABC", "ABc"));
    
    // empty string
    assert(isAnagram("", ""));
    assert(!isAnagram("", "dog"));
    assert(!isAnagram("dog", ""));
}

void testFindEmpty()
{
    string results[MAXRESULTS];
    assert(findEmpty(results)==0);
    
    results[0] = "cat";
    assert(findEmpty(results)==1);
    
    for (int i=0; i<MAXRESULTS; i++) {
        results[i] = "dog";
    }
    assert(findEmpty(results)==20);
}

void testIndexOfChar()
{
    assert(indexOfChar("hello", 'h', 0)==0);
    assert(indexOfChar("hello", 'l', 0)==2);
    assert(indexOfChar("hello", 'o', 0)==4);
   
    // empty string
    assert(indexOfChar("", 'h', 0) == -1);
    
    // not existing char
    assert(indexOfChar("hello", 'w', 0)==-1);
}

int main()
{
    cout << "====================================" << "\n";
    cout << "testMakeDictionary" << "\n";
    testMakeDictionary();
    cout << "testMakeDictionary passed" << "\n";
    cout << "====================================" << "\n";
    cout << "testShuffleChars" << "\n";
    testShuffleChars();
    cout << "testShuffleChars passed" << "\n";
    cout << "====================================" << "\n";
    cout << "testShuffleChars" << "\n";
    testShuffleChars();
    cout << "testShuffleChars passed" << "\n";
    cout << "====================================" << "\n";
    cout << "testIsAnagram" << "\n";
    testIsAnagram();
    cout << "testIsAnagram passed" << "\n";
    cout << "====================================" << "\n";
    cout << "testFindEmpty" << "\n";
    testFindEmpty();
    cout << "testFindEmpty passed" << "\n";
    cout << "====================================" << "\n";
    cout << "testIndexOfChar" << "\n";
    testIndexOfChar();
    cout << "testIndexOfChar passed" << "\n";
    cout << "====================================" << "\n";
}
