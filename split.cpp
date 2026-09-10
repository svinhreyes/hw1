/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked

list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.*/

#include "split.h"



//void split(Node*& in, Node*& odds, Node*& evens){
  //Base case: the input list is empty.
    //if (in == nullptr){
      //return;
    //}

    //Save the rest of the input list before changing in.
    //Node* next = in->next;

    //Put the current node into the appropriate list.
    //if (in->value % 2 == 0){
      //in->next = evens;
      //evens = in;
    //}else{
      //in->next = odds;
      //odds = in;
    //}

    //Remove the current node from the input list.
    //in = next;

    //Recursively process the rest of the input list.
    //split(in, odds, evens);
//}

/* If you needed a helper function, write it here */

void splitHelper(Node* current, Node*& odds, Node*& evens, Node*& oddsTail, Node*& evensTail){
    //Base case: there are no more nodes to process.
    if (current == nullptr){
      return;
    }

    //Save the next node before changing the current node's next pointer.
    Node* next = current->next;

    //separate the current node from the input list.
    current->next = nullptr;

    //add the current node to the appropriate list.
    if (current->value % 2 == 0){
      if (evens == nullptr){
        //this is the first even node
        evens = current;
        evensTail = current;
      }else{
        //add the node to the end of the even list
        evensTail->next = current;
        evensTail = current;
      }
    }else{
      if (odds == nullptr){
        //this is the first odd node
        odds = current;
        oddsTail = current;
      }else{
        //add the node to the end of the odd list
        oddsTail->next = current;
        oddsTail = current;
      }
    }

    //Recursively process the rest of the original list.
    splitHelper(next, odds, evens, oddsTail, evensTail);
}

void split(Node*& in, Node*& odds, Node*& evens){
    Node* oddsTail = nullptr;
    Node* evensTail = nullptr;

    //recursively split the original list
    splitHelper(in, odds, evens, oddsTail, evensTail);

    //The original list has been completely consumed.
    in = nullptr;
}
