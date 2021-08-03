//
//  main.m
//  Project3
//
//  Created by Jene Hojin Choi on 2021/07/27.
//

#include <iostream>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

const int MAXRESULTS = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in

//Puts each string in dictfile into the array dict. Returns the number of words
//read into dict. This number should not be larger than MAXDICTWORDS since that is
//the size of the array.
int makeDictionary(istream &dictfile, string dict[])
{
    if (MAXDICTWORDS <= 0) return 0;
    
    string str;
    if (getline(dictfile, str)) // getline is better than >>
        // string hypens- malfunctions
    {
        // can i make it without declaring count...?
        int count = makeDictionary(dictfile, dict) + 1;
        if (count <= MAXDICTWORDS) // count is smaller than maxdictwords
        {
            dict[count-1] = str;    // make str in dict with index
            return count;
        }
        else return MAXDICTWORDS; // count is larger than maxdictwords
    }
    else return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// returns index if word contains a char
int indexOfChar(string &dictWord, char c, int i)
{
    if (i > dictWord.length() || dictWord.length() == 0) return -1;
    if (c == dictWord[i]) return i;
    else return indexOfChar(dictWord, c, ++i);
}


// isAnagram function
bool isAnagram(string &word, string &dictWord)
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


// find if a word is already in results array
bool containsWord(string &dictWord, string results[])
{
    if (!results || results[0] == "")
        return false;
    if (results[0] == dictWord)
        return true;
    else return containsWord(dictWord, results+1);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Puts all the possibilities of word which are found in dict into results. Returns
//the number of matched words found. This number should not be larger than
//MAXRESULTS since that is the size of the array. The size is the number of words

int shuffleChars2(string &word, const string dict[], int size, string results[])
{
    if (size == 0 || word.length()==0)
        return findEmpty(results);
    else {
        string dictWord = dict[0];
        if (isAnagram(word, dictWord)) {
            int emptyIndex = findEmpty(results);
            if (emptyIndex < MAXRESULTS && !containsWord(dictWord, results)) {
                results[emptyIndex] = dictWord;
            }
        }
        return shuffleChars2(word, dict+1, size-1, results);
    }
}

int shuffleChars(string word, const string dict[], int size, string results[])
{
    return shuffleChars2(word, dict, size, results);
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

//
//int main()
//{
//    string results[MAXRESULTS];
//    string dict[MAXDICTWORDS];
//    ifstream dictfile;
//    int nwords;
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
