#include <iostream>
#include "linkedlist.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;


int main(int argc, char** argv)
{
    if (argc < 3) // must provide two arguments as input
    {
        throw std::invalid_argument("Usage: ./hello <INPUT FILE> <OUTPUT FILE>"); // throw error
    }

    ifstream word_shake; // stream for input file
    ifstream length_rank; // stream for output file CHANGE BACK

    word_shake.open(argv[1]); // open input file
    length_rank.open(argv[2]); // open output file
  
    //length_rank = fopen(argv[2], "r");
  
    LinkedList aLL[39]; //array of linked list aLL
  
    string command; 
    //char *com, *dummy, *valstr, *op; // for using with strtok, strtol
  
    //cout << "Printing1" << endl;

    // MAKE A GET FUNCTI
    //
    //puts the words in the list by first looking at their length
    //then if it's already in there, update 
    
    int lengths;
    while(getline(word_shake,command)) // get next line of input, store as repeat
    {
        lengths = command.length();
        aLL[lengths].insert(command);  
    }
    //cout << "Printing2" << endl;
          //int counter = 0;  
          //while(counter != 36)
          //{
          //  cout << to_string(counter) + "|| " + aLL[counter].print() << endl;
          //  length_rank << to_string(counter) + "|| " + aLL[counter].print() << endl;
          //  counter++;
          
    
    for(int i = 0; i < 39; i++) //should be 39
    {
        aLL[i].selectionSort(); 
        //cout << to_string(i) + "|| " + aLL[i].print() << endl;
        //cout << "Count: " + to_string(i) << endl;
    }
    
  //cout << "Printing2" << endl;
  
    int len, rank;
    //int val;
    while(length_rank >> len >> rank) // get next line of input, store as repeat
    {
        //cout << "Count: " + to_string(a) + " " + to_string(b) << endl;
        cout << aLL[len].search(rank) << endl;
      
    }
    // run ./shake sam.txt simple-input.txt
    // 
    
    //int a, b;

    //fscanf (length_rank, "%d %d", &a, &b);
  
    //cout << "Count: " + to_string(a) << endl;
  
    
    //cout << "Printing3" << endl;
    word_shake.close();
    length_rank.close();
}