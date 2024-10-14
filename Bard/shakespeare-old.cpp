#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

#define MAX_LEN 800

int main(int argc, char* argv[]){
  
  FILE *shake, *nums;
  
  LinkedList a[26]; // initializing the array of linked list
  
  char line[MAX_LEN];
  
  if (argc < 3) // must provide two arguments as input
  {
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
  }
  
  // open files for reading and writing 
  shake = fopen(argv[1], "r");
  nums = fopen(argv[2], "r");
  if( shake==NULL )
  {
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
  }
  if( nums==NULL )
  {
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
  }
  
  
  
  //while( fgets(line, MAX_LEN, shake) != NULL)  {  
      //printf(fgets(line, MAX_LEN, shake)); //Prints the line, got it
      //for(int i = 0; i < 26; i++)
      //{
      //  printf(fgets(line, MAX_LEN, shake));
      //}
      
      
      
      
   //}
  
  /*for (int i = 0; i < 26; i++)
  {
    printf(fgets(line, MAX_LEN, shake)); //prints the entrire line
    a[i] = fgets(line, MAX_LEN, shake); 
  }
  
  for (int i = 0; i < 26; i++)
  {cd BA
    printf("%i : %s", i, a[i]); 
  }
  */ 
  /*int count=0;
  printf("Testing \n");
  while( fgets(line, MAX_LEN, shake) != NULL)  { 
    printf("%s", line);
    a[1].insert(count); 
    count++;
    if(count == 20)
    {
      break;
    }
  }*/
  a[1].insert(100); 
  
  printf("Testing \n");
  char str[10] = a[1].print();
  printf("%s", str); 
  printf("Testing \n");
  
}