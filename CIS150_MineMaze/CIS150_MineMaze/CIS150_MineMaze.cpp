//=================================================================================================================================
//Group Name: Mine Maze
//Desc: A player will have to get one from side of the room to the other with a limited amount of moves per turn and amount of
//		lives per level
//=================================================================================================================================

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h> // For player movement input
#include <windows.h>
using namespace std;
// GLOBAL VARIABLE
int MedLives = 2;
int MedMoves = 30;
int medlastrow = 1;
int medlastcol = 1;

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
void easyMapCode();
void MediumMapCode();
void MedUp(int, int, string map[16][16]);
void MedDown(int, int, string map [16][16]);
void MedLeft(int, int, string map[16][16]);
void MedRight(int ,int, string map[16][16]);
int MedWallCheck(int, int);
int MedOutOfBounds(int, int);
int MedMinePlacement(int, int);


void clear();

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
	cout << "==================================================================================================\n";
	cout << "Enter your selection: ";
	// CIN THE SELECTION
	cin >> selection;
	cout << endl;
	if (selection == 1) 
	{
		easyMapCode();
	}
	else if (selection == 2)
	{
		MediumMapCode();
	}

		system("pause");
		return 0;

}




void easyMapCode() {
	// Code for Easy Level

	clear();
	cout << "=================================================================================================\n";
	cout << "The Rules for the Easy Level are as follow:\n";
	cout << "You cant move more than 1 space \n";
	cout << "You are only allowed to move vertically or horizontally\n";
	cout << "There are 8 Mines randomly located throughout the map\n";
	cout << "You step on a mine you lose a life you only have 2 for this level\n";
	cout << "You have __ many moves. Use to many you Loose 1 life\n";
	cout << "If you make it to the end of the maze YOU WIN!!!\n";
	cout << "Lastly have fun!\n";
	cout << "=================================================================================================\n";




	// Map Code



	const int easyRow = 11, easyCol = 12;
	string easyMap[easyRow][easyCol] = {
		{ " ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" },
		{ "1", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X" },
		{ "2", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "3", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "4", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "5", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "6", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "7", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "8", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "9", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "0", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X" }
	};

	// Player Position
	int pX = 2; // Column Position
	int pY = 2; // Row Position
	string playerPosition = easyMap[pX][pY];

	// Display map
	for (int row = 0; row < 11; row++)
	{
		for (int col = 0; col < 12; col++)
		{
			if (easyMap[row][col] == " ") {
				// Do nothing
			}
			if (col == pX && row == pY) {
				cout << "O";
				cout << " ";
			}

			else {
				cout << easyMap[row][col] << " ";
			}


			/*
			if (col == 2 && row == 2)
			{

			cout << easyMap[row][col] << "O";
			}
			else
			{
			cout << easyMap[row][col] << " ";
			} */

		}
		cout << endl;

	}


	// TODO

	// Registering Movement
	// Source: http://www.cplusplus.com/forum/general/55170/


	cout << "Use WASD to move up, down, left, or right." << endl;
	char move = 0;
	do
	{
		move = _getch();

		switch (move)
		{
			// Player moving upwards
		case 'W':
		case 'w':
			cout << " ^ ";
			if (easyMap[pX][pY - 1] == "X") {
				// Do Nothing
			}
			else {
				pY--;
			}
			system("cls");
			for (int row = 0; row < 11; row++)
			{
				for (int col = 0; col < 12; col++)
				{
					if (easyMap[row][col] == " ") {
						// Do nothing
					}
					if (col == pX && row == pY) {
						cout << "O";
						cout << " ";
					}

					else {
						cout << easyMap[row][col] << " ";
					}

				}
				cout << endl;

			}
			break;

			// Player moving left
		case 'A':
		case 'a':
			cout << " < ";
			if (easyMap[pX - 1][pY] == "X") {
				// Do Nothing
			}
			else {
				pX--;
			}
			system("cls");
			for (int row = 0; row < 11; row++)
			{
				for (int col = 0; col < 12; col++)
				{
					if (easyMap[row][col] == " ") {
						// Do nothing
					}
					if (col == pX && row == pY) {
						cout << "O";
						cout << " ";
					}

					else {
						cout << easyMap[row][col] << " ";
					}

				}
				cout << endl;

			}
			break;

			// Player moving right
		case 'D':
		case 'd':
			cout << " > ";
			if (easyMap[pX + 1][pY] == "X") {
				// Do Nothing
			}
			else {
				pX++;
			}

			system("cls");
			for (int row = 0; row < 11; row++)
			{
				for (int col = 0; col < 12; col++)
				{
					if (easyMap[row][col] == " ") {
						// Do nothing
					}
					if (col == pX && row == pY) {
						cout << "O";
						cout << " ";
					}

					else {
						cout << easyMap[row][col] << " ";
					}

				}
				cout << endl;

			}
			break;

			// Player moving down
		case 'S':
		case 's':
			cout << " V ";
			if (easyMap[pX][pY + 1] == "X") {
				// Do Nothing
			}
			else {
				pY++;
			}
			system("cls");
			for (int row = 0; row < 11; row++)
			{
				for (int col = 0; col < 12; col++)
				{
					if (easyMap[row][col] == " ") {
						// Do nothing
					}
					if (col == pX && row == pY) {
						cout << "O";
						cout << " ";
					}

					else {
						cout << easyMap[row][col] << " ";
					}

				}
				cout << endl;

			}
			break;

		}
	} while (true);




}

void MediumMapCode()
{

	// Map for the medium level
	char select;
	const int medrow = 16, medcolm = 16;
	string medmap[medrow][medcolm] = {
		{ " ", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m" ,"n", "o" },
		{ "a", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " },
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
	

	//MOVEMENT
	cout << "Enter 'u' to move up 'd' to move down 'l' to move left or 'r' to move right: ";
	cin >> select;

	for (int i = 0; i < 30; i++)
	{
		if (select == 'd')
		{
			medmap[medlastrow][medlastcol] = " ";
			MedDown(medlastrow, medlastcol, medmap);
			cout << "Enter 'u' to move up 'd' to move down 'l' to move left or 'r' to move right: ";
			cin >> select;
			medlastrow++;
		}
		if (select == 'u')
		{
			medmap[medlastrow][medlastcol] = " ";
			MedUp(medlastrow, medlastcol, medmap);
			cout << "Enter 'u' to move up 'd' to move down 'l' to move left or 'r' to move right: ";
			cin >> select;
			medlastrow--;
		}
		if (select == 'l')
		{
			medmap[medlastrow][medlastcol] = " ";
			MedLeft(medlastrow, medlastcol, medmap);
			cout << "Enter 'u' to move up 'd' to move down 'l' to move left or 'r' to move right: ";
			cin >> select;
			medlastcol--;
		}
		if (select == 'r')
		{
			medmap[medlastrow][medlastcol] = " ";
			MedRight(medlastrow, medlastcol, medmap);
			cout << "Enter 'u' to move up 'd' to move down 'l' to move left or 'r' to move right: ";
			cin >> select;
			medlastcol++;
		}
	}

	
}
void MedUp(int row, int col, string map[16][16])
{
	system("cls");
	string let = "x";
	map[row - 1][col] = let;
	for (int i = 0; i < 16; i++)
	{
		for (int a = 0; a < 16; a++)
		{
			cout << map[i][a] << " ";
		}
		cout << endl;
	}
}
void MedDown(int row, int col, string map[16][16])
{
	system("cls");
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
	system("cls");
	string let = "x";
	map[row][col - 1] = let;
	for (int i = 0; i < 16; i++)
	{
		for (int a = 0; a < 16; a++)
		{
			cout << map[i][a] << " ";
		}
		cout << endl;
	}

}
void MedRight(int row, int col, string map[16][16])
{
	system("cls");
	string let = "x";
	map[row][col + 1] = let;
	for (int i = 0; i < 16; i++)
	{
		for (int a = 0; a < 16; a++)
		{
			cout << map[i][a] << " ";
		}
		cout << endl;
	}

}


// Notes: I made a clear() function that will clear the screen so we don't have to type out system("cls") everytime we want to clear the screen.
void clear() {
	system("cls");
}


int MedWallCheck(int row, int col)
{
	int i = 1;
	if (row < 16)
	{
		if (row == 0)
		{
			if (col == 0 || col == 1 || col == 2 || col == 3 || col == 4 || col == 5 || col == 6 || col == 7 || col == 8 || col == 9 || col == 10 || col == 11 || col == 12 || col == 13 || col == 14 || col == 15)
			{
				i--;
			}
		}
		else if (row == 1)
		{
			if (col == 0)
			{
				i--;
			}

		}
		else if (row == 2)
		{
			if (col == 0 || col == 3 || col == 4 || col == 5 || col == 8 || col == 14)
			{
				i--;
			}
		}
		else if (row == 3)
		{
			if (col == 0 || col == 8 || col == 14)
			{
				i--;
			}
		}
		else if (row == 4)
		{
			if (col == 0 || col == 1 || col == 2 || col == 6 || col == 10 || col == 11 || col == 12 || col == 14)
			{
				i--;
			}
		}
		else if (row == 5)
		{
			if (col == 0 || col == 6 || col == 12)
			{
				i--;
			}
		}
		else if (row == 6)
		{
			if (col == 0 || col == 6 || col == 12)
			{
				i--;
			}
		}
		else if (row == 7)
		{
			if (col == 0 || col == 12)
			{
				i--;
			}
		}
		else if (row == 8)
		{
			if (col == 0 || col == 3 || col == 9)
			{
				i--;
			}
		}
		else if (row == 9)
		{
			if (col == 0 || col == 1 || col == 2 || col == 3 || col == 5 || col == 6 || col == 7 || col == 9)
			{
				i--;
			}
		}
		else if (row == 10)
		{
			if (col == 0)
			{
				i--;
			}
		}
		else if (row == 11)
		{
			if (col == 0 || col == 11 || col == 12)
			{
				i--;
			}
		}
		else if (row == 12)
		{
			if (col == 0|| col == 5 || col == 6 || col == 7 || col == 8 || col == 13)
			{
				i--;
			}
		}
		else if (row == 13)
		{
			if (col == 0 || col == 1 || col == 2 || col == 5)
			{
				i--;
			}
		}
		else if (row == 14)
		{
			if (col == 0 || col == 11 || col == 12 || col == 13)
			{
				i--;
			}
		}
		else if (row == 15)
		{
			if (col == 0 || col == 13)
			{
				i--;
			}
		}
	}
	return i;
}

int MedMinePlacement(int row, int col)
{
	int i = 0;
	if (row < 16)
	{
		// i need a randomize number function
	}
	return i;
}

int MedOutOfBounds(int row, int col)
{
	int i = 0;
	if (row >= 16)
	{
		i = 1;
	}
	if (col >= 16)
	{
		i = 1;
	}
	return i;
}