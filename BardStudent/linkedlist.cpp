// Filename: linkedlist.cpp
// 
// Contains the class LinkedList that represents a linked list. This contains some basic operations, such as insert, delete, find, length
// 
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020

#include "linkedlist.h"
#include <cstdlib>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>
using namespace std;

// Default constructor sets head and tail to null
LinkedList :: LinkedList()
{
	head = NULL;
}

// Insert(int val): Inserts the int val into list, at the head of the list. Note that there may be multiple copies of val in the list.
// Input: Int to insert into the linked list
// Output: Void, just inserts new Node
void LinkedList :: insert(string val)
{
    Node* findn = this->find(val);
    int countfreq; 
    if(findn == NULL)
    {
      Node *to_add = new Node; // creates new Node
      to_add->data = val; // sets the data to hold input val
      to_add->freq = 1; 

      to_add->next = head; // make to_add point to existing head
      head = to_add; // set head to to_add
    }
    else{
        countfreq = findn->freq;
        findn->freq = countfreq+1; 
        //cout << "FREQ(inside) "+to_string(countfreq) << endl;
    }
    /*
    if(findn != NULL)
    {
        countfreq = findn->freq;
        findn->freq = countfreq+1; 
        cout << "FREQ(inside) "+to_string(countfreq) << endl;
    }
    else
    {
      Node *to_add = new Node; // creates new Node
      to_add->data = val; // sets the data to hold input val
      to_add->freq = 1; 

      to_add->next = head; // make to_add point to existing head
      head = to_add; // set head to to_add
    }*/
    
}

// find(int val): Finds a Node with data "val"
// Input: int to be found
// Output: a pointer to a Node containing val, if it exists. Otherwise, it returns NULL
// Technically, it finds the first Node in the list containing val
Node* LinkedList :: find(string val)
{
    Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    // curr will look over list. At every iteration, we will check if curr->data is val. If so, we are done. Otherwise, we proceed through the list.
    string temp;
    while(curr != NULL) //looping over list
    {
        temp = curr->data; 
        if (temp.compare(val) == 0) // found val, so return curr
            return curr;
        curr = curr->next; // otherwise, proceed through list
    }
    // if loop terminates, val not found
    return NULL;
}

// deleteNode(int val): Delete a Node with data val, if it exists. Otherwise, do nothing.
// Input: int to be removed
// Output: pointer to Node that was deleted. If no Node is deleted, return NULL. If there are multiple Nodes with val, only the first Node in the list is deleted.
Node* LinkedList :: deleteNode(string val)
{
    Node* prev = NULL;
    Node* curr = head;
    string temp;
    while(curr != NULL) // loop over list, starting from head
    {
        temp = curr->data; 
        if (temp.compare(val) == 0) // we found Node with val, so break
            break; 
        //otherwise, proceed list
        prev = curr; // move prev by one Node
        curr = curr->next; // move curr by one Node
    }
    // at this point, curr points to Node with val. If curr is null, then val is not in the list.
    if (curr == NULL) // val not found
        return NULL; 
    // val is in list. Note that curr is not NULL. There is a case analysis now. If prev is null, then curr is head. So we delete head directly.
    // Otherwise, we delete the Node after prev.
    if (prev == NULL) // we need to delete head
        head = head->next; // delete head
    else // we delete Node after prev. Note that both curr and prev are not NULL
        prev->next = curr->next; // make prev point to Node after curr. This removes curr from list
    return curr;
}

// Deletes every Node to prevent memory leaks.
// Input: None
// Output: Void, just deletes every Node of the list
void LinkedList :: deleteList()
{
	Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
    Node *temp = NULL;

	// curr will loop over list. At every iteration, we first store a pointer to the next Node, and then delete the current Node.
    while(curr != NULL){ // Looping over list
		temp = curr->next; // store pointer to next Node in the list
		delete(curr); // delete the current Node
		curr = temp; // update curr to proceed through list
	}
	head = NULL;
}

// Prints list in order
// Input: None
// Output: string that has all elements of the list in order
string LinkedList :: print()
{
    string list_str = ""; // string that has list
	Node *curr = head; // curr is the current Node as it progresses through the linked list. Initialized to head to start at the head of the list
	// curr will loop over list. It prints the content of curr, and then moves curr to next Node.
	while(curr != NULL){ // looping over list
        list_str = list_str + curr->data + " " + to_string(curr->freq) + ", "; //append string with current Node's data
		curr = curr->next; // proceed through list
	}
    if (list_str.length() > 0) // string is non-empty
        list_str.pop_back(); // remove the last (extra) space from string
    return list_str;
}

// Computes the length of the linked list
// Input: None
// Output: Int, length of list
int LinkedList :: length()
{
    int length = 0; // initialize length to zero
    Node *curr = head; // curr is ths current Node as it progresses through the linked list. Initialized to head to start at the head of the list
	
    while(curr != NULL){ // looping over list
      length++; // increment length
      curr = curr->next; // proceed to next Node
    }
    return length;
}

void LinkedList :: selectionSort() 
{
    Node* curr = head;
    Node* max = NULL; 
    Node* check = NULL;
    
    while (curr != NULL) //goes through list
    {
        max = curr;
        check = curr->next;
        //cout << "Curr: " + max->data << endl;
        
        while(check != NULL)
        {
            //cout << "----Check: " + check->data << endl;
            //cout << "----Compare: " + curr->data + " " + check->data << endl; 
            //cout << "----Compare: " + to_string(compare(max->data, max->freq, check->data, check->freq)) << endl;
            if(compare(max->data, max->freq, check->data, check->freq) == -1) // || compare(max->data, max->freq, check->data, check->freq) < 0)
            {
                
                max = check;
                //cout << "Max: " + max->data << endl;
            }
              
            check = check->next;
        }
      
        //swap 
        int tf = curr->freq; //tempfreq
        string tw = curr->data; //tempword
        curr->data = max->data;
        curr->freq = max->freq;
        max->data = tw;
        max->freq = tf;
        
        curr = curr->next;
    }
}

//
//input node1 and node2
//output: 1 if node1 is greater
//0 if equal
//-1 if node1 is less
int LinkedList :: compare(string word1, int count1, string word2, int count2)
{
    //cout << "_________Test 1: " + word1 + " " + word2  << endl;
    if(count1 > count2)
    {
      return 1;
    }
    if(count2 > count1)
    {
      return -1;
    }
    else //if they have the same freq, lexigraphical compparsion. 
    {
        //cout << "_________Test END: " + word1 + " " + word2 + " " + to_string(word1.compare(word2) ) << endl;
        //return ( strcmp(word1.c_str(), word2.c_str()) );
        //return (word1.compare(word2));
        if(word1 < word2)
        {
          return 1;
        }
        if(word2 < word1)
          return -1;
        else
          return 0; 
    }
}

string LinkedList :: search(int num)
{
  if(head == NULL)
  {
    return "-";
  }
  Node* curr = head;
  for(int i = 0; i < num; i++ )
  {
    if(curr->next != NULL)
      curr = curr->next;
    else
      return "-";
      //cout << "Count: " + to_string(i) << endl;
  }
  return curr->data; 
}
