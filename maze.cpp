#include <fstream>
#include "stack.h"
#include <iostream>
#include <cstdlib> 
#include <string>
//#include <vld.h>

using namespace std;

/******************************************************************************
Name: maze.cpp
Des: This program is designed to read a maze from a text file, and give back another
text file to the user with the maze already solved. The textfile will be a series
of *'snd 0's on a two dimensional array. Where 0's are the paths and the *s are
the walls. If there is a solution to the maze given in the first textfile the program
will output There IS a way out! Otherwise it will output There IS NOT a way out!
This program is using stacks to store the Locations where the user can move in more than 
one direction. Once the program chooses a path, and there is not an exit, it pops a 
Location from the stack and repeats the process. In order for the program to know 
where its been, we have to leave a mark on the positions we've passed. In this Case
I am using a period '.'.This program will also test for memory 
leaks by using the header vld.h. If memory leaks exist, a report will be generated
at the end of execution. If there werent any memory leaks, nothing will show.

Author: Josue Santos
******************************************************************************/
/******************************************************************************
Name: Solve
Des: Solve function will receive a two dimensional arrays which holds the maze
that we got from the input file, then it will output the solved maze
on a different textfile. In order for it to work we need to pass this function 
a Location Coordinate for it to start at the beggining of the maze. The logic 
To solve this maze in this case is as follows: The computer will Move: North, South
West, and East.Once the computer is on a Location it will evaluate
the 4 directions that surround it, if there are 4 available moves the computer
will drop a breadcrumb, push that Location to the stackand then move 
to any direction available following the previously stated order.Then the computer 
starts the process again. If one of the Locations that surround the Location is an E 
we change the Value of our bool variable which holds true if there is an exit and false otherwise
. I separated each possible position where there can be more than one movement 
on the Maze, Starting at 4 possible movements, then 3, then 2, and finally when
there is just one possible movement.If the computer moves out of movements it 
will Pop a Location from the Stack, and repeat the process until the stack 
is empty or there is an Exit.

******************************************************************************/

bool Solve(char Maze[80][80], ofstream &fout,Stacktype Location) 
{
	//Defining a Stack inside the function
	Stack MyStack;
	//Defining two variables, the first one is for our while loop
	//And the second one is to return if there is or there is not a way out.
	bool test = true;
	bool wayout = true;
	if (Maze[Location.Row][Location.Column] == 'E')
	{
		test = false;
	}
	//Defining the coordinates for moving in different Directions
	while (test) {
		Stacktype North = { Location.Row - 1 , Location.Column },
			South = { Location.Row + 1 , Location.Column },
			West = { Location.Row , Location.Column - 1 },
			East = { Location.Row, Location.Column + 1 };
		Stacktype Popped;
		//Lets try to solve this
		Maze[Location.Row][Location.Column] = '.';
		
		/*IF The computer can make 4 moves*********************************************************************************/
		if (Maze[North.Row][North.Column] == '0'&& Maze[South.Row][South.Column]=='0'&& Maze[West.Row][West.Column]=='0'
			&& Maze[East.Row][East.Column]=='0') {
			//Add Location To Stack
			MyStack.Push(Location);
	
			Location.Row = North.Row;
			Location.Column = North.Column;
		}
		/*IF The computer can make 3 moves*********************************************************************************/
		//If the Computer can make Three moves Case 1
		else if (Maze[North.Row][North.Column] == '0'&& Maze[West.Row][West.Column] == '0'&& Maze[East.Row][East.Column] == '0') {
			//Add Location To Stack
			MyStack.Push(Location);
			Location.Row = North.Row;
			Location.Column = North.Column;
		}
		//If the Computer can make Three moves Case 2
		else if (Maze[South.Row][South.Column] == '0'&& Maze[West.Row][West.Column] == '0'&& Maze[East.Row][East.Column] == '0') {
			//Add Location To Stack
			MyStack.Push(Location);
			Location.Row = South.Row;
			Location.Column = South.Column;
		}
		//If the Computer can make Three moves Case 3
		else if (Maze[North.Row][North.Column] == '0'&& Maze[South.Row][South.Column] == '0'&& Maze[West.Row][West.Column] == '0') {
			//Add Location To Stack
			MyStack.Push(Location);
			Location.Row = South.Row;
			Location.Column = South.Column;
		}
		//If the Computer can make Three moves Case 4
		else if (Maze[North.Row][North.Column] == '0'&& Maze[South.Row][South.Column] == '0'&& Maze[East.Row][East.Column] == '0') {
			//Add Location To Stack
			MyStack.Push(Location);
			Location.Row = East.Row;
			Location.Column = East.Column;
		}
		/*IF The computer can make 2 moves*********************************************************************************/
		//If the Computer can make Two moves Case 1
		else if (Maze[North.Row][North.Column] == '0'&& Maze[West.Row][West.Column] == '0') {
			//Add Location To Stack
			MyStack.Push(Location);
			Location.Row = North.Row;
			Location.Column = North.Column;
		}
		//If the Computer can make Two moves Case 2
		else if (Maze[North.Row][North.Column] == '0'&& Maze[East.Row][East.Column] == '0') {
			//Add Location To Stack
			MyStack.Push(Location);
			Location.Row = North.Row;
			Location.Column = North.Column;
		}
		//If the Computer can make Two moves Case 3
		else if (Maze[South.Row][South.Column] == '0'&& Maze[East.Row][East.Column] == '0') {
			//Add Location To Stack
			MyStack.Push(Location);
			Location.Row = South.Row;
			Location.Column = South.Column;
		}
		//If the Computer can make Two moves Case 4
		else if (Maze[South.Row][South.Column] == '0'&& Maze[West.Row][West.Column] == '0') {
			//Add Location To Stack
			MyStack.Push(Location);
			Location.Row = South.Row;
			Location.Column = South.Column;
		}
		//If the Computer can make Two moves Case 5
		else if (Maze[North.Row][North.Column] == '0'&& Maze[South.Row][South.Column] == '0') {
			//Add Location To Stack
			MyStack.Push(Location);
			Location.Row = North.Row;
			Location.Column = North.Column;
		}
		//If the Computer can make Two moves Case 6
		else if (Maze[West.Row][West.Column] == '0'&& Maze[East.Row][East.Column] == '0') {
			//Add Location To Stack
			MyStack.Push(Location);
			Location.Row = West.Row;
			Location.Column = West.Column;
		}
		//To check if there is an exit
		else if (Maze[North.Row][North.Column] == 'E') {
			wayout = true;
			test = false;

		}
		else if (Maze[South.Row][South.Column] == 'E') {
			wayout = true;
			test = false;
		}
		else if (Maze[West.Row][West.Column] == 'E') {
			wayout = true;
			test = false;
		}
		else if (Maze[East.Row][East.Column] == 'E') {
			wayout = true;
			test = false;
		}
		else if (Maze[Location.Row][Location.Column] == 'E')
		{
			wayout = true;
			test = false;
		}
		/*IF The computer can make 1 moves*********************************************************************************/
		//If the computer can move North
		else if (Maze[North.Row][North.Column] == '0') {
			Location.Row = North.Row;
			Location.Column = North.Column;
		}
		//If the computer can Move South
		else if (Maze[South.Row][South.Column] == '0') {
			Location.Row = South.Row;
			Location.Column = South.Column;
		}
		//If the computer can move West
		else if (Maze[West.Row][West.Column] == '0') {
			Location.Row = West.Row;
			Location.Column = West.Column;
		}
		//If the computer can move West
		else if (Maze[East.Row][East.Column] == '0') {
			Location.Row = East.Row;
			Location.Column = East.Column;
		}
		else if(Maze[North.Row][North.Column] != '0'&& Maze[South.Row][South.Column] != '0'&& Maze[West.Row][West.Column] != '0'
			&& Maze[East.Row][East.Column] != '0' && !(MyStack.Empty())){
			MyStack.Pop(Popped);
			Location.Row = Popped.Row;
			Location.Column = Popped.Column;
		
		}
		
		else {
		wayout = false;
		test = false;
		}
	
	}
	
	return wayout;
}
/******************************************************************************
Name: getMazes
Des: This Function is to get the Maze from the input file into the program.
Once the program has gather the maze from the input file it calls 
the function Solve for it to process the maze
******************************************************************************/

void getMazes(ifstream &fin, ofstream &fout) {
	int mazeNumber = 1;
	//Declaring variables to hold the maze values
	string maze, size, rows, cols;
	//To get the size of the maze line by line
	getline(fin, size);
	rows = size.substr(0, 2);
	cols = size.substr(2, 4);

	while (stoi(rows)!= -1 && stoi(cols)!= -1) {
		string entrance, entranceR, entranceC;
		const int mazeRows = 80, mazeCols = 80;
		/* We get the size of the maze by getting the first line of the text file
		which contains two numbers;the number of rows,and the number of columns
		*/
		/*We create a two dimensional array to hold the maze we initialize it to
		an 80 by 80 two dimensional array*/
		char Maze[mazeRows][mazeCols];
		int r = 0, c = 0;
		int count = 0;
		//Now we populate our two dimensional Array 
		while (count != stoi(rows))
		{
			getline(fin, maze);
			if (maze != size) {
				for (c = 0; c < stoi(cols); c++) {
					Maze[r][c] = maze[c];
				}
				r++;
			}
			count++;
		}
		fout << "MAZE NUMBER " << mazeNumber << endl;
		fout << endl;
		mazeNumber++;
	
		//This is to get the coordinates of the Maze entrance
		//Divide the numbers and separate them into two different variables! the first one should be for the rows, and the second one for the columns
		getline(fin, entrance);
		entranceR = entrance.substr(0, 2);
		entranceC = entrance.substr(2, 2);
		//
		
		Stacktype Location = {stoi(entranceR),stoi(entranceC)};
		//Call to funcion Solve which will find a path through the maze or will return false if it cant
		if (Location.Row != '-1'&&Location.Column != '-1') {
			bool X =Solve(Maze, fout, Location);

			/*****************************************************************************************/
			//This for loop is to Print the Solved Maze
			for (int r = 0; r < stoi(rows); r++) {
				for (int c = 0; c < stoi(cols); c++) {
					fout << Maze[r][c];
				}
				fout << endl;
			}
			fout << endl;
			if (X == true) {
				fout << "There IS a way out!" << endl;
			}
			else {
				fout << "There IS NOT a way out!" << endl;
			}
			fout << endl;
		}

		getline(fin, size);
		rows = size.substr(0, 2);
		cols = size.substr(2, 4);
		
	}
	
}

/******************************************************************************
Name: Main
Des: Main will open the textfile and output our labels on the new Textfile
that the other functions are going to create.
******************************************************************************/
void main()
{
	ifstream fin;
	ofstream fout;
	fin.open("Maze.txt");
	fout.open("mazeSolutions.txt");
	fout << "Solutions to A - MAZE - ING Stacks Assignment" << endl;
	fout << "Josue Santos" << endl;
	fout << endl;
	getMazes(fin, fout);

}
