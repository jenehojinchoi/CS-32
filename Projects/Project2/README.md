# Project 2
#### <strong>A description of the design of your implementation and why you chose it. (A couple of sentences will probably suffice, perhaps with a picture of a typical List and an empty List. Is your list circular? Does it have a dummy node? What's in your nodes?)</strong>

OnlineDating is a doubly-linked list to fulfill the requirements on the project spec. However, I thought there was no need for each node to contain information about the previous node since the spec did not ask us to do a reversal (like reverseList in homework 1).


My doubly-linked list implementation was not a circular node. The initial and last nodes are pointed by a head pointer. The nodes have a value of type OnlineType, firstName and lastName in string, and pointers to previous node and next node. 



#### <strong>A brief description of notable obstacles you overcame.</strong>

The most difficult part for me was to implement makeMatch(). It seemed easy, but it turned out to be an issue because it had to do with adding in the front and back of a specific node. Also, before testing it out in the main function, I was not able to come up with edge cases, such as when the previous or next node of a current node is a null pointer. 


Even after I thought my code would run, it took a long time for me to actually come up with makeMatch() that would run correctly. It was hard to find logic for a condition when incoming firstName (or lastname) was smaller than current firstName (or lastName). It was important to set a new node as a previous node of the current node to store all previous and next node.


I also had a difficulty implementing mergeMatches(), since it had to deal with a lot of loops. I was worried if calling functions already declared above will result in too long run time. However, I could not come up with any better idea, so I had to do deal with some nested loops and use those functions. I first found if the resulting boolean will be true or false by looping through both lists and finding if they have the same full name and same or different value.



#### <strong>Pseudocode for non-trivial algorithms</strong>

```
bool OnlineDating::blockPreviousMatch(const std::string& firstName, const std::string& lastName)
{
  Loop through the list
    if firstname and lastname are the same;
      if curr->prev == nullptr and curr->next != nullptr
        set head as curr->next
        set curr->next->prev as nullptr (removed)
      
      else if curr->prev == nullptr and curr->next != nullptr
        set curr->prev->next as nullptr (removed)
    
      else if curr->next != nullptr and curr->prev != nullptr
        remove the node

      else ( this case means head had only one node with the fullname)
        set head as nullptr;         
        delete curr; // release memory
        return true

  // out of the loop
  return false 
}
```
<br></br>

```
bool OnlineDating::makeMatch(const std::string& firstName, const std::string & lastName, const OnlineType& value)
{
  1) If head is null
  make head a new node that contains incoming firstName, lastName, and value 

  2) Else Loop through the list 
    1) If last name is the same
      i) If firstname is the same
          return false
      ii) If firstname is larger than current 
          newNode should be previous node of current
                        
          if newNode is not a null pointer        
            set newNode's next node as a current node
            return true
          if newNode is a null pointer 
            set head as previous node of current
            return true
      
      iii) If firstname is smaller than current and next node of current is a null pointer
        newNode's previous = curr
    newNode's next = nullptr        
    return true

    2) If last name is larget than current = similar to (i)
        return true

    3) If last name is smaller than current and next node of current is a null pointer = similar to (iii)
      return true

  return false // the case should not be here, but I added in case there is an edge case
}
```
<br></br>

```
bool mergeMatches(const OnlineDating & odOne, const OnlineDating & odTwo, OnlineDating & odJoined)
{
  check for base case when odOne or odTwo are null
    odJoined = not null linked list among odOne and odTwo
    return true


    if odOne and odTwo are not null
      loop through odOne and odTwo to 
    if there are same fullname with different value
      result = false
    otherwise result = true

  if result = true, odJoined = odOne (deep copy)
    Loop through odTwo and merge the two lists

  if result = false, odJoined = empty OnlineDating
    Loop through odTwo and add everything except same full name 
    Loop through odOne and add everything except same fullname

  return result
}
```
<br></br>

```
void authenticateMatches (const std::string& fsearch, const std::string& lsearch, const OnlineDating& odOne, OnlineDating& odResult) 
{
  odResult = odOne (deep copy)


  Loop through odOne by using int i & take odOne's firstName, lastName, and value
    if fsearch == "*" and lsearch == "*"
      return; // do nothing
    else if fsearch != "*" and lsearch == "*"
      if firstName != fsearch 
        remove it from odResult
      else 
        do nothing

    else if lsearch != "*" and fsearch == "*"
      if lastName != lsearch 
          remove it from odResult
      else 
        do nothing

    else  // search for a specific name
      if  firstName != fsearch and lastName != lsearch
          remove if from odResult
      else
        do nothing
}
```