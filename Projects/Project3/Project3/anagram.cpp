//
//  main.m
//  Project3
//
//  Created by Jene Hojin Choi on 2021/07/27.
//

#include "anagram.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

//Puts each string in dictfile into the array dict. Returns the number of words
//read into dict. This number should not be larger than MAXDICTWORDS since that is
//the size of the array.
int makeDictionary(istream &dictfile, string dict[])
{
    if (MAXDICTWORDS <= 0) return 0;
    
    string str;
    if (dictfile >> str)
    {
        // count 안 쓰고 못 만드나?
        int count = 1+makeDictionary(dictfile, dict);
        if (count <= MAXDICTWORDS) // count가 maxdictwords 보다 작으면
        {
            dict[count-1] = str;    // dict에 str 등록
            return count;
        }
        else return MAXDICTWORDS; // count가 maxdictwords 보다 크면
    }
    else return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// returns index if word contains a char
int indexOfChar(string dictWord, char c, int i)
{
    if (i > dictWord.length() || dictWord.length() == 0) return -1;
    if (c == dictWord[i]) return i;
    else return indexOfChar(dictWord, c, ++i);
}


// isAnagram function
bool isAnagram(string word, string dictWord)
{
    if (word.length() == 0 && dictWord.length() == 0) return true;
    if (word.length() != dictWord.length()) return false;
    else {
        int index = indexOfChar(dictWord, word[0], 0);
        if (index != -1) {
            string newWord = word.substr(1, word.length());
            string newDictWord = dictWord.substr(0, index) + dictWord.substr(index+1, dictWord.length());
            return isAnagram(newWord, newDictWord);
        } else return false;
    }
}

// find empty index in results array
// returns MAXRESULT when there is no empty string
// shuffleChars calls findEmpty when there is only spot
int findEmpty(string results[])
{
    if (results[0] == "")
        return 0;
    return findEmpty(results+1) + 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Puts all the possibilities of word which are found in dict into results. Returns
//the number of matched words found. This number should not be larger than
//MAXRESULTS since that is the size of the array. The size is the number of words
int shuffleChars(string word, const string dict[], int size, string results[])
{
    if (size == 0 || word.length()==0)
        return findEmpty(results);
    else {
        if (isAnagram(word, dict[0])) {
            int emptyIndex = findEmpty(results);
            if (emptyIndex < MAXRESULTS) { 
                results[emptyIndex] = dict[0];
            }
        }
        return shuffleChars(word, dict+1, size-1, results);
    }
}


void revealOutcomes(const string results[], int size)
{
    if (size <= 0)
        return;
    else
    {
        cout << results[0] << endl;
        revealOutcomes(results+1, size-1);
    }
}


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
//    cout << "NWORDS: " << nwords << "\n\n";
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
