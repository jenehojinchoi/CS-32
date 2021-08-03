# Project 3 

### <strong> A brief description of notable obstacles you overcame. </strong>

#### <strong> Algorithms of shuffleChars</strong>
It was difficult to think of algorithms of shuffleChars(). I decided that it was hard to solve the algorithm at once, so I divided the problem into several sub-problems. I first made a helper function called isAnagram, where a word and another word in a dictionary are given and compared. Also, I made indexOfChar, which takes in a word and an alphabet to see if the word has it, and returns the index of the alphabet in the word. I made findEmpty, which finds empty string in a string array results and returns the index of it. This is used to store an anagram found in dictionary. In addition, I made containsWord(), which checks if results[] has duplicate words. 
<br></br>

#### <strong> Edge Cases</strong>
When making makeDictionary(), I could not come up with edge cases such as when MAXDICTWORDS is smaller than the number of words in words.txt file. Also, I first used `dictfile<<str`, however, the professor recommended me to use getline instead since `<<`can cause some issues with special characters such as hypens. 

Also, I did not consider a dictionary which contains duplicate words. I later added bool containsWord() to figure out if results have duplicate dictWord.  
<br></br>

#### <strong> Memory Management</strong>

When I ran my code in XCode, nothing seemed to be wrong. However, when I ran my code in linux enviroment again, it showed an error: stackoverflow. 
I figured out this is happening because I was passing literally every parameters by value; the memory is used up. I changed helper functions and makeDictionary() to take in parameters by reference. Also, I made wrapper function, shuffleChars2(), for shuffleChars() so that it does not create new word everytime it is called recursively. 
I was able to solve the error with the above method:
