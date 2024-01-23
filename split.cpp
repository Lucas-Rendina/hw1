/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

//base case
  if(in==nullptr){
    return;
  }

//If the value is even, use a temporary node to reset the next
//pointer, pushing the node to the front of the evens list.
//Then, set in to its next node and recursively call the function
//again on the next node of in.
  if(in->value%2==0){
    Node* temp = in;
    in = in->next;
    temp-> next = evens;
    evens = temp;
    //delete temp;
    split(in,odds,evens);
    
  }
  //If the value is odd, do the same but with odds
  else{
    Node* temp = in;
    in = in->next;
    temp-> next = odds;
    odds = temp;
    //delete temp;
    split(in,odds,evens);
  }
  
}

/* If you needed a helper function, write it here */
