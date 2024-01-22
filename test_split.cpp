/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
//using namespace std;

int main(int argc, char* argv[])
{

Node* even = nullptr;
Node* odd= nullptr;

Node* head = new Node(1,nullptr);
Node* list = head;
for(int i=2;i<10;i++){
  Node* temp = new Node(i,nullptr);
  list->next = temp;
  list = list->next;
}

/*
even = new Node(2,nullptr);
odd = new Node(1,nullptr);
*/

split(head, odd, even);

std::cout << (head==nullptr) << std::endl;

while(even != nullptr){
  std::cout << even->value << " ";
  Node* cleanup = even;
  even = even->next;
  delete cleanup;

}
std::cout << std::endl;
while(odd != nullptr){
  std::cout << odd->value << " ";
  Node* ocleanup = odd;
  odd = odd->next;
  delete ocleanup;
}
std::cout << std::endl;



return 0;

}
