#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
Name: stack.cpp
Des: Stack.Cpp is the implementation file that contains the code to implement
the function definitions of the header file( stack.h).
Author: Josue Santos
******************************************************************************/

//Constructor
Stack::Stack()
{
	//Setting the StackType Pointer Top to Null To initialize
	//a stack
	Top = NULL;
}

//Destructor
Stack::~Stack()
{
	while(Top!=NULL){

		Node * my_node = Top;
		Top = Top->Next;
		delete my_node;
	}
	
}

/******************************************************************************
Name: Empty
Des: This function is in charge of checking if the stack is empty
or not.
******************************************************************************/
bool Stack::Empty()
{
	//If top==NULL return true 
	//else return false shortened
	return(Top == NULL);
}

/******************************************************************************
Name: PUSH
Des: This is the function that is in charge of placing a location into the stack
Stack once the user requests it.
******************************************************************************/
bool Stack::Push(Stacktype info)
{
	//New node to be able to store the data
	Node * my_node = new Node;
	if (my_node == nullptr) {
		delete my_node;
		return false;
	}
	// This is to store the data in the node
	my_node->Element = info;
	// We point the new node to the old one in the stack
	my_node->Next = Top;
	//We now make Top point to my_node which is working as the new top
	Top = my_node;

	return true;
}
/******************************************************************************
Name: POP
Des: This is the function that is in charge of retrieving a Location from the 
Stack once the user requests it.
******************************************************************************/

bool Stack::Pop(Stacktype&Location)
{
	if (!(Empty())) {

		Node * my_node = Top;
		Top = Top->Next;
		Location = my_node->Element;
		delete my_node;

		return true;
	}
	else {
		return false;
	}
}