////
////  main.m
////  Project3
////
////  Created by Jene Hojin Choi on 2021/07/27.
////
//
//#include <iostream>
//#include <fstream>
//#include <istream>
//#include <string>
//
//using namespace std;
//
//const int MAXRESULTS = 20;    // Max matches that can be found
//const int MAXDICTWORDS = 30000; // Max words that can be read in
//
////Puts each string in dictfile into the array dict. Returns the number of words
////read into dict. This number should not be larger than MAXDICTWORDS since that is
////the size of the array.
//int makeDictionary(istream &dictfile, string dict[])
//{
//    if (MAXDICTWORDS <= 0) return 0;
//
//    string str;
//    if (getline(dictfile, str)) // getline is better than >>
//        // string hypens- malfunctions
//    {
//        // can i make it without declaring count...?
//        int count = makeDictionary(dictfile, dict) + 1;
//        if (count <= MAXDICTWORDS) // count is smaller than maxdictwords
//        {
//            dict[count-1] = str;    // make str in dict with index
//            return count;
//        }
//        else return MAXDICTWORDS; // count is larger than maxdictwords
//    }
//    else return 0;
//}
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//// returns index if word contains a char
//int indexOfChar(string &dictWord, char c, int i)
//{
//    if (i > dictWord.length() || dictWord.length() == 0) return -1;
//    if (c == dictWord[i]) return i;
//    else return indexOfChar(dictWord, c, ++i);
//}
//
//
//// isAnagram function
//bool isAnagram(string &word, string &dictWord)
//{
//    if (word.length() == 0 && dictWord.length() == 0) return true;
//    if (word.length() != dictWord.length()) return false;
//    else {
//        int index = indexOfChar(dictWord, word[0], 0);
//        if (index != -1) {
//            string newWord = word.substr(1, word.length());
//            string newDictWord = dictWord.substr(0, index) + dictWord.substr(index+1, dictWord.length());
//            return isAnagram(newWord, newDictWord);
//        } else return false;
//    }
//}
//
//// find empty index in results array
//// returns MAXRESULT when there is no empty string
//// shuffleChars calls findEmpty when there is only spot
//int findEmpty(string results[])
//{
//    if (results[0] == "")
//        return 0;
//    return findEmpty(results+1) + 1;
//}
//
//
//// find if a word is already in results array
//bool containsWord(string &dictWord, string results[])
//{
//    if (!results || results[0] == "")
//        return false;
//    if (results[0] == dictWord)
//        return true;
//    else return containsWord(dictWord, results+1);
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
////Puts all the possibilities of word which are found in dict into results. Returns
////the number of matched words found. This number should not be larger than
////MAXRESULTS since that is the size of the array. The size is the number of words
//
//int shuffleChars2(string &word, const string dict[], int size, string results[])
//{
//    if (size == 0 || word.length()==0)
//        return findEmpty(results);
//    else {
//        string dictWord = dict[0];
//        if (isAnagram(word, dictWord)) {
//            int emptyIndex = findEmpty(results);
//            if (emptyIndex < MAXRESULTS && !containsWord(dictWord, results)) {
//                results[emptyIndex] = dictWord;
//            }
//        }
//        return shuffleChars2(word, dict+1, size-1, results);
//    }
//}
//
//int shuffleChars(string word, const string dict[], int size, string results[])
//{
//    return shuffleChars2(word, dict, size, results);
//}
//
//
//void revealOutcomes(const string results[], int size)
//{
//    if (size <= 0)
//        return;
//    else
//    {
//        cout << results[0] << endl;
//        revealOutcomes(results+1, size-1);
//    }
//}
//
////
//////int main()
//////{
//////    string results[MAXRESULTS];
//////    string dict[MAXDICTWORDS];
//////    ifstream dictfile;
//////    int nwords;
//////    string word;
//////
//////    dictfile.open("words.txt");
//////    if (!dictfile) {
//////        cout << "File not found!" << endl;
//////        return (1);
//////    }
//////
//////    nwords = makeDictionary(dictfile, dict);
//////
//////    cout << "Please enter a string for an anagram: ";
//////    cin >> word;
//////
//////    int numMatches = shuffleChars(word, dict, nwords, results);
//////    if (!numMatches)
//////        cout << "No matches found" << endl;
//////    else
//////        revealOutcomes(results, numMatches);
//////
//////    return 0;
//////}
//
//////
//////  main.cpp
//////  AnagramRecursion
//////
//////  Created by Edwin Ambrosio on 7/27/20.
//////  Copyright (c) 2020 Edwin Ambrosio. All rights reserved.
//////
////
////#include <iostream>
////#include <fstream>
////#include <string>
////using namespace std;
////
////const int MAXRESULTS   = 20;    // Max matches that can be found
////const int MAXDICTWORDS = 30000; // Max words that can be read in
////
////
////// Functions for reading in dictionary
////int makeDictionary(istream &dictfile, string dict[]);
////
////int makeDictionary_aux(istream &dictfile, string dict[], int i);
////
////
////// Functions for finding permutations
////int shuffleChars(string word, const string dict[], int a, string results[]);
////
////void RecFor(const string dict[], const int dictSize, string pre, string post,  int i, int size, string results[], int& nwords);
////
////void shuffleChars_aux(const string dict[], const int dictSize, string pre, string post,  string results[], int& numResults);
////
////// Functions for printing results
////void revealOutcomes(const string results[], int);
////
////void revealOutcomes_aux(const string results[], int, int);
////
////
//////int main()
//////{
//////    string results[MAXRESULTS];
//////    string dict[MAXDICTWORDS];
//////    ifstream dictfile;         // file containing the list of words
//////    int nwords;                // number of words read from dictionary
//////    string word;
//////
//////    dictfile.open("words.txt");
//////    if (!dictfile) {
//////        cout << "File not found!" << endl;
//////        return (1);
//////    }
//////
//////    nwords = makeDictionary(dictfile, dict);
//////
//////    cout << "Please enter a string for an anagram: ";
//////    cin >> word;
//////
//////    int numMatches = shuffleChars(word, dict, nwords, results);
//////    if (!numMatches)
//////        cout << "No matches found" << endl;
//////    else
//////        revealOutcomes(results, numMatches);
//////
//////    return 0;
//////}
////
////int makeDictionary(istream &dictfile, string dict[]) {
////
////    return makeDictionary_aux(dictfile, dict, 0);
////}
////
////int makeDictionary_aux(istream &dictfile, string dict[], int i) {
////
////    if (i >= MAXDICTWORDS)
////        return i;
////    if (dictfile >> dict[i])
////        return makeDictionary_aux(dictfile, dict, i+1);
////    return i;
////}
////
////void revealOutcomes(const string results[], int numMatches) {
////    revealOutcomes_aux(results, numMatches, 0);
////}
////
////void revealOutcomes_aux(const string results[], int numMatches, int i) {
////
////    if (i >= MAXRESULTS || i >= numMatches)
////        return;
////    cout << results[i] << endl;
////    revealOutcomes_aux(results, numMatches, i+1);
////}
////
////
////int shuffleChars(string word, const string dict[], int dictSize,
////                     string results[]) {
////
////    int nwords=0;  // not necessary but makes counting found permutations easier
////    shuffleChars_aux(dict, dictSize, string(""), word, results, nwords);
////    return nwords;
////}
////
////// Places the string s into results, returns the newly placed string's position
////// Returns -1 if it's already in the array or if array is full
////int insertloop (string results[], string s, int i) {
////
////    if (i == MAXRESULTS)
////        return -1;
////    if (results[i] == "") {
////        results[i] = s;
////        return i;
////    }
////    if (results[i] == s)
////        return -1;
////    return insertloop(results, s, i+1);
////}
////
////// returns true if word is in dict
////bool isInDictionary(const string dict[], int size, string word, int i) {
////
////    if (i >= size)
////        return false;
////    if (dict[i] == word)
////        return true;
////    return isInDictionary(dict, size, word, i+1);
////}
////
////void shuffleChars_aux(const string dict[], const int dictSize, string pre, string post,  string results[], int& nwords)
////{
////    if (post == "") {       // if post is empty pre is a permutation
////        string permutation = pre;
////        if (!isInDictionary(dict, dictSize, permutation, 0))
////            return;
////        int lastInsertPos = insertloop(results, permutation, 0); // insert permutation in dictionary
////        if (lastInsertPos == -1) {
////            return;
////        }
////        nwords = lastInsertPos+1;
////        return;
////    }
////    // loop through characters in post, in otherwords, iterates post.size() number of times
////    RecFor(dict, dictSize, pre, post, 0, (int) post.size(), results, nwords);
////}
////
////void RecFor(const string dict[], const int dictSize, string pre, string post, int i, int size, string results[], int& nwords) {
////    if (i == size) {
////        return;
////    }
////    // Example:
////    //    if i = 3, pre is "" and post is "example" before call to shuffleChars_aux
////    //    below, then the following would be made to generate all the permutations that
////    //    start with the letter m.
////    //
////    //    shuffleChars_aux (dict, dictSize, "m", "exaple", results, nwords);
////
////    shuffleChars_aux(dict, dictSize, pre + post[i], post.substr(0,i) + post.substr(i+1),  results, nwords);
////    RecFor(dict, dictSize, pre, post, i+1, size, results, nwords);
////}
//
//  main.cpp
//  AnagramRecursion
//
//  Created by Edwin Ambrosio on 7/27/20.
//  Copyright (c) 2020 Edwin Ambrosio. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 10; // Max words that can be read in


// Functions for reading in dictionary
int makeDictionary(istream &dictfile, string dict[]);

int makeDictionary_aux(istream &dictfile, string dict[], int i);


// Functions for finding permutations
int shuffleChars(string word, const string dict[], int a, string results[]);

void RecFor(const string dict[], const int dictSize, string pre, string post,  int i, int size, string results[], int& nwords);

void shuffleChars_aux(const string dict[], const int dictSize, string pre, string post,  string results[], int& numResults);

// Functions for printing results
void revealOutcomes(const string results[], int);

void revealOutcomes_aux(const string results[], int, int);

//
//int main()
//{
//    string results[MAXRESULTS];
//    string dict[MAXDICTWORDS];
//    ifstream dictfile;         // file containing the list of words
//    int nwords;                // number of words read from dictionary
//    string word;
//
//    dictfile.open("words.txt");
//    if (!dictfile) {
//        cout << "File not found!" << endl;
//        return (1);
//    }
//
//    nwords = makeDictionary(dictfile, dict);
//
//    cout << "Please enter a string for an anagram: ";
//    cin >> word;
//
//    int numMatches = shuffleChars(word, dict, nwords, results);
//    if (!numMatches)
//        cout << "No matches found" << endl;
//    else
//        revealOutcomes(results, numMatches);
//
//    return 0;
//}

int makeDictionary(istream &dictfile, string dict[]) {

    return makeDictionary_aux(dictfile, dict, 0);
}

int makeDictionary_aux(istream &dictfile, string dict[], int i) {

    if (i >= MAXDICTWORDS)
        return i;
    if (dictfile >> dict[i])
        return makeDictionary_aux(dictfile, dict, i+1);
    return i;
}

void revealOutcomes(const string results[], int numMatches) {
    revealOutcomes_aux(results, numMatches, 0);
}

void revealOutcomes_aux(const string results[], int numMatches, int i) {

    if (i >= MAXRESULTS || i >= numMatches)
        return;
    cout << results[i] << endl;
    revealOutcomes_aux(results, numMatches, i+1);
}


int shuffleChars(string word, const string dict[], int dictSize,
                     string results[]) {

    int nwords=0;  // not necessary but makes counting found permutations easier
    shuffleChars_aux(dict, dictSize, string(""), word, results, nwords);
    return nwords;
}

// Places the string s into results, returns the newly placed string's position
// Returns -1 if it's already in the array or if array is full
int insertloop (string results[], string s, int i) {

    if (i == MAXRESULTS)
        return -1;
    if (results[i] == "") {
        results[i] = s;
        return i;
    }
    if (results[i] == s)
        return -1;
    return insertloop(results, s, i+1);
}

// returns true if word is in dict
bool isInDictionary(const string dict[], int size, string word, int i) {

    if (i >= size)
        return false;
    if (dict[i] == word)
        return true;
    return isInDictionary(dict, size, word, i+1);
}

void shuffleChars_aux(const string dict[], const int dictSize, string pre, string post,  string results[], int& nwords)
{
    if (post == "") {       // if post is empty pre is a permutation
        string permutation = pre;
        if (!isInDictionary(dict, dictSize, permutation, 0))
            return;
        int lastInsertPos = insertloop(results, permutation, 0); // insert permutation in dictionary
        if (lastInsertPos == -1) {
            return;
        }
        nwords = lastInsertPos+1;
        return;
    }
    // loop through characters in post, in otherwords, iterates post.size() number of times
    RecFor(dict, dictSize, pre, post, 0, (int) post.size(), results, nwords);
}

void RecFor(const string dict[], const int dictSize, string pre, string post, int i, int size, string results[], int& nwords) {
    if (i == size) {
        return;
    }
    // Example:
    //    if i = 3, pre is "" and post is "example" before call to shuffleChars_aux
    //    below, then the following would be made to generate all the permutations that
    //    start with the letter m.
    //
    //    shuffleChars_aux (dict, dictSize, "m", "exaple", results, nwords);

    shuffleChars_aux(dict, dictSize, pre + post[i], post.substr(0,i) + post.substr(i+1),  results, nwords);
    RecFor(dict, dictSize, pre, post, i+1, size, results, nwords);
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

void testone(int n)
{
    string dictionary[MAXDICTWORDS];
    string results[MAXRESULTS];

    switch (n)
    {
        default: {
            cout << "Bad argument" << endl;
        } break; case 1: {
            istringstream iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod");
            int numResults = makeDictionary(iss, dictionary);
            sort(dictionary, dictionary + numResults);
            assert(numResults == 9 && dictionary[0] == "act" && dictionary[1] == "art");
        } break; case 2: {
            // File is empty, checks that file is empty and makeDictionary returns 0.
            istringstream iss("");
            int numResults = makeDictionary(iss, dictionary);
            assert(numResults == 0 && dictionary[0] == "");
        } break; case 3: {
            // Dictionary has been read properly
            istringstream iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod");
            int numResults = makeDictionary(iss, dictionary);
            sort(dictionary, dictionary + numResults);
            assert(numResults == 9 && dictionary[0] == "act" && dictionary[numResults-1] == "tar");
        } break; case 4: {
            // Input file is larger than the dictionary size
            istringstream iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod\ntoo\nmany\nwords");
            int numResults = makeDictionary(iss, dictionary);
            sort(dictionary, dictionary + numResults);
            assert(numResults == 10 && dictionary[MAXDICTWORDS-1] == "too");
        } break; case 5: {
            // If a certain word with repeated letter is shown in results more than once - still accept.
            string dictionary[] = { "one", "oone", "ne", "e", "too" };
            int numResults = shuffleChars("oto", dictionary, 5, results);
            assert((numResults == 1 || numResults == 2) && results[0] == "too");
        } break; case 6: {
            // Doesn't check numResults nor duplicates.
            string dictionary[] = { "one", "oone", "ne", "e", "too" };
            shuffleChars("oto", dictionary, 5, results);
            assert(results[0] == "too");
        } break; case 7: {
            // If word wasn't found, numResults = 0 and results array is empty.
            string dictionary[] = { "one", "oone", "ne", "e" };
            int numResults = shuffleChars("look", dictionary, 4, results);
            assert(numResults == 0 && results[0] == "" && results[1] == "");
        } break; case 8: {
            // No fraction of a permutation is being searched in dictionary
            string dictionary[] = { "one", "oone", "non", "oon" };
            int numResults = shuffleChars("on", dictionary, 4, results);
            assert(numResults == 0 && results[0] == "" && results[1] == "");
        } break; case 9: {
            // No fraction of a permutation is being searched in dictionary
            string dictionary[] = { "one", "oone", "ne", "e", "neoo", "oneo" };
            int numResults = shuffleChars("neo", dictionary, 6, results);
            assert(numResults == 1 && results[0] == "one" && results[1] == "");
        } break; case 10: {
            // Checking that no error occurs if more than MAXRESULTS are found.
            string dictionary[] = { "true",  "treu", "teru", "teur", "ture",
        "tuer", "rtue", "rteu", "retu","reut", "ruet", "rute", "utre",
        "uter", "uetr", "uert", "urte", "uret", "etru", "etur", "ertu",
        "erut", "eurt", "eutr" };
            // All 24 permutations
            int numResults = shuffleChars("true", dictionary, 24, results);
            assert(numResults == MAXRESULTS);
        } break; case 11: {
            // Checking one word was found, no duplicates.
            string dictionary[] = { "ppp" };
            int numResults = shuffleChars("ppp", dictionary, 1, results);
            assert(numResults == 1 && results[0] == "ppp" && results[1] == "");
        } break; case 12: {
            string dictionary[] = { "run", "dodge", "break", "urn", "defeat" };
            int numResults = shuffleChars("nru", dictionary, 5, results);
            sort(results, results + numResults);
            assert(numResults == 2 && results[0] == "run" && results[1] == "urn");
        } break; case 13: {
            streambuf* oldCoutStreamBuf = cout.rdbuf();
            ostringstream strCout;
            cout.rdbuf(strCout.rdbuf());
            string results[] = { "cat", "act"};
            revealOutcomes(results, 2);
            cout.rdbuf(oldCoutStreamBuf);
            string temp = strCout.str();
            bool match1 = temp.find("act") != string::npos;
            bool match2 = temp.find("cat") != string::npos;
            assert(match1 && match2);
        } break; case 14: {
            istringstream iss ("tier\nrite\nbate\ntire\nttir");
            int numWords = makeDictionary(iss, dictionary);
            sort(dictionary, dictionary + numWords);
            assert(numWords == 5 && dictionary[0] == "bate");
            int numResults = shuffleChars("tier", dictionary, numWords, results);
            assert(numResults == 3 && (results[2] == "tire" || results[2] == "tier" || results[2] == "rite"));
        } break; case 15: {
            string example[] = { "kool", "moe", "dee" };
            int numResults = shuffleChars("look", example, 3, results);
            assert(numResults == 1 && results[0] == "kool");
        } break;
    }
}

int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed" << endl;
}
