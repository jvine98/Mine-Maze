//=================================================================================================================================
//Group Name: Mine Maze
//Desc: A player will have to get one from side of the room to the other with a limited amount of moves per turn and amount of
//		lives per level
//=================================================================================================================================

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


void displayStartup() {
	cout << "======================================================================================================================" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                                   Mine Maze                                                          " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "======================================================================================================================" << endl;
}
void MediumMapCode();

int main()
{


	// ======================================
	// Map variables
	// ======================================
	string easyLevel = ""; // Placeholders for later.
	// 10 x 10 Grid
	string hardLevel = "";
	// 25 x 25 Grid

	// ======================================
	// Player variables
	// ======================================
	int lives; // Placeholder for later, will depend on the level.
	int moves; // Placeholder for later, limited amount of moves depending on the level.

	// Start up menu;
	displayStartup();

	// selection variable
	int selection;
	//Intro to the game
	cout << "Hello welcome to The Mine Maze\n";
	cout << "Select the Level you want to Play\n";
	cout << "1. Easy\n";
	cout << "2. Medium\n";
	cout << "3. Hard\n";
	cout << "==================================================================================================\n";
	cout << "Enter your selection: ";
	// CIN THE SELECTION
	cin >> selection;
	cout << endl;
	if (selection == 2)
	{
		MediumMapCode();
	}

		system("pause");
		return 0;

}

void MediumMapCode()
{

	// Map for the medium level
	const int medrow = 17, medcolm = 17;
	string medmap[medrow][medrow] = {
		{ " ","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p" },
		{ "a", " ", " ", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " "," "," " },
		{ "b", " ", " ", "-", "-", "-", " ", " ", "|", " ", " ", " ", " ", " ","|"," " },
		{ "c", " ", " ", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ","|"," " },
		{ "d", "-", "-", " ", " ", " ", "|", " ", " ", " ", "-", "-", "-", " ","|"," " },
		{ "e", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ", "|", " "," "," " },
		{ "f", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ", "|", " "," "," " },
		{ "g", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "|", " "," "," " },
		{ "h", " ", " ", "|", " ", " ", " ", " ", " ", "|", " ", " ", " ", " "," "," " },
		{ "i", "-", "-", "|", " ", "-", "-", "-", " ", "|", " ", " ", " ", " "," "," " },
		{ "j", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "," "," " },
		{ "k", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "-", "-", " "," "," " },
		{ "l", " ", " ", " ", " ", "-", "-", "-", "-", " ", " ", " ", " ", "|"," "," " },
		{ "m", "-", "-", " ", " ", "|", " ", " ", " ", " ", " ", " ", " ", " "," "," " },
		{ "n", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "-", "-", "-"," "," " },
		{ "o", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "|"," "," " },
		{ "p", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "|"," "," " },

	};

	// Rules for the medium level
	cout << "=================================================================================================\n";
	cout << "The Rules for the Medium Level are as follow:\n";
	cout << "You cant move more than 1 space \n";
	cout << "You are only allowed to move vertically or horizontally\n";
	cout << "There are 8 Mines randomly located throughout the map\n";
	cout << "You step on a mine you lose a life you only have 2 for this level\n";
	cout << "You have __ many moves. Use to many you Loose 1 life\n";
	cout << "If you make it to the end of the maze YOU WIN!!!\n";
	cout << "Lastly have fun!\n";
	cout << "=================================================================================================\n";
	cout << endl;
	//The Medium Maze

	for (int row = 0; row < 17; row++)
	{
		for (int col = 0; col < 17; col++)
		{
			cout << medmap[row][col] << " ";

		}
		cout << endl;

	}

	// moving one spot
	char rowmove;
	char colmove;
	cout << "Move your player 1 spot\n";
	cout << "Enter the row you would like to move to: ";
	cin >> rowmove;
	cout << "Enter the column you would like to move to: ";
	cin >> colmove;
	int rownum, colnum;
	// converting char to an int
	if (rowmove >= 'a' && rowmove <= 'z')
	{
		// the ascii value for a is 97 but subrtracted by 96 becaucse of the postion in the array
		rownum = rowmove - 96;
	}
	if (colmove >= 'a' && colmove <= 'z')
	{
		// the ascii value for a is 97 but i subrtacted by 96 because of the postion in the array
		colnum = colmove - 96;
	}

	//placing the player at a postion
	for (int row = 0; row < 17; row++)
	{
		for (int col = 0; col < 17; col++)
		{
			if (colnum == col && rownum == row)
			{
				medmap[row][col] = "x";
				cout << medmap[row][col] << " ";

			}
			else
			{
				cout << medmap[row][col] << " ";
			}

		}
		cout << endl;
	}

}