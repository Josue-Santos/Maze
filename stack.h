#include<string>
#include<iostream>
using namespace std;

/******************************************************************************
Name: Stack.h
Des: This is the header file for the maze.
Author: Josue Santos
******************************************************************************/

//Used to store a coordinate in a maze
struct Coordinate
{
	int Row, Column;
};
//Define a Stacktype
typedef Coordinate Stacktype;
//Prototype a Node in a Linked List
struct Node;
//Define a Pointer Node
typedef Node* Stackptr;
//Define a Node in a Linked List, Each Node will store a coordinate
struct Node
{
	Stacktype Element;
	Stackptr Next;
};

class Stack
{
public:
	//Constructor
	Stack();
	//Destructor
	~Stack();
	//Will see if stack is empty
	bool Empty();
	//Will place elements in stack
	bool Push(Stacktype);
	//will remove elements in stack
	bool Pop(Stacktype&);

private:
	//define a pointer to the top of the stack
	Stackptr Top;
};