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
void MedUp(int, int, string map[16][16]);
void MedDown(int, int, string map [16][16]);
void MedLeft(int, int, string map[16][16]);
void MedRight(int ,int, string map[16][16]);

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
	int selection;

	// Start up menu;
	displayStartup();

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
	char select;
	int lastrow = 1;
	int lastcol = 1;
	const int medrow = 16, medcolm = 16;
	string medmap[medrow][medcolm] = {
		{ " ", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m" ,"n", "o" },
		{ "a", " ", " ", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ", " ", " " },
		{ "b", " ", " ", "-", "-", "-", " ", " ", "|", " ", " ", " ", " ", " ", "|", " " },
		{ "c", " ", " ", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ", "|", " " },
		{ "d", "-", "-", " ", " ", " ", "|", " ", " ", " ", "-", "-", "-", " ", "|", " " },
		{ "e", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ", "|", " ", " ", " " },
		{ "f", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ", "|", " ", " ", " " },
		{ "g", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "|", " ", " ", " " },
		{ "h", " ", " ", "|", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ", " " },
		{ "i", "-", "-", "|", " ", "-", "-", "-", " ", "|", " ", " ", " ", " ", " ", " " },
		{ "j", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
		{ "k", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "-", "-", " ", " ", " " },
		{ "l", " ", " ", " ", " ", "-", "-", "-", "-", " ", " ", " ", " ", "|", " ", " " },
		{ "m", "-", "-", " ", " ", "|", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
		{ "n", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "-", "-", "-", " ", " " },
		{ "o", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "|", " ", " " },

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

	for (int row = 0; row < 16; row++)
	{
		for (int col = 0; col < 16; col++)
		{
			if (col == 1 && row == 1)
			{
				medmap[1][1] = "x";
				cout << medmap[1][1];
			}
			else
			{
				cout << medmap[row][col] << " ";
			}

		}
		cout << endl;

	}
	

	// first move
	cout << "Enter 'u' to move up 'd' to move down 'l' to move left or 'r' to move right: ";
	cin >> select;
	if (select == 'd')
	{
		medmap[lastrow][lastcol] = " ";
		system("cls");
		MedDown(lastrow, lastcol, medmap);
		lastrow = 2;

	}

	
}
void MedUp(int row, int col, string map[16][16])
{
	string let = "x";
	map[row - 1][col] = let;
}
void MedDown(int row, int col, string map[16][16])
{
	
	string let = "x";
	map[row + 1][col] = let;
	for (int i = 0; i < 16; i++)
	{
		for (int a = 0; a < 16; a++)
		{
			cout << map[i][a] << " ";
		}
		cout << endl;
	}
}
void MedLeft(int row, int col, string map[16][16])
{
	string let = "x";
	map[row][col - 1] = let;

}
void MedRight(int row, int col, string map[16][16])
{
	string let = "x";
	map[row][col + 1] = let;

}