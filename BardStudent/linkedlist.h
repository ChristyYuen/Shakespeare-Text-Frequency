// Filename: linkedlist.h
// 
// Header file for the class LinkedList that represents a linked list
// 
// Japheth Frolick, August 2019
// C. Seshadhri, Jan 2020

#ifndef LIST_H
#define LIST_H

#include <string>
#include <string.h> 

using namespace std;

// node struct to hold data
struct Node
{
	string data; //named data cuz i'm too lazy to change everything
  int freq; //frequency 
	Node *next;
};

class LinkedList
{
	private:
		Node *head; // Stores head of linked list
	public:
		LinkedList(); // Default constructor sets head to null
    void insert(string); // insert int into list 
    Node* find(string); // find int in list, and return pointer to node with that int. If there are multiple copies, this only finds one copy
    Node* deleteNode(string); // remove a node with int (if it exists), and return pointer to deleted node. This does not delete all nodes with the value.
		void deleteList(); // deletes every node to prevent memory leaks, and frees memory
		string print(); // Construct string with data of list in order 
		int length(); // Returns the length of the linked list
    void selectionSort(); //sorts the list
    int compare(string, int, string, int); //compare 2 nodes and returns an int
    string search(int);
};

#endif
