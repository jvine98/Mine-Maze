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
#include <stdlib.h> // www.cplusplus.com/reference/cstdlib/rand/
#include <time.h> // www.cplusplus.com/reference/cstdlib/rand/



using namespace std;
// GLOBAL VARIABLE

int pX = 2; // Column Position
int pY = 2; // Row Position
string easyMap;
string medMap;

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





int MedMinePlacement(int, int);
void playerMovement(int selection, string easyMap[11][12], string easyBTS[11][12], string medMap[16][16], int xAxis, int yAxis, int pLives);



void clear();

int main()
{


	// Mine placer



	

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


	const int easyRow = 11, easyCol = 12;
	string easyMap[easyRow][easyCol] = {
		{ " ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" },
		{ "1", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X" },
		{ "2", "X", " ", " ", " ", " ", " ", " ", "X", " ", "X" },
		{ "3", "X", " ", " ", "X", "X", " ", " ", " ", " ", "X" },
		{ "4", "X", " ", " ", "X", "X", " ", " ", " ", "X", "X" },
		{ "5", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "6", "X", " ", " ", " ", " ", " ", " ", "X", " ", "X" },
		{ "7", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "8", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "9", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "0", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X" }
	};

	string easyBTS[easyRow][easyCol];

	int placeMine;
	int mineCount = 0;
	srand(time(NULL));

	for (int i = 0; i < 11; i++) {

		for (int j = 0; j < 12; j++) {

			

			placeMine = rand() % 8;

			if (placeMine == 0) {
				easyBTS[i][j] = "&";
				mineCount++;
			}
			else {
				easyBTS[i][j] = ".";
			}

		}

	}

	for (int i = 0; i < 11; i++) {

		for (int j = 0; j < 12; j++) {
			cout << easyBTS[i][j] << " ";

		}
		cout << endl;

	}


	// Registering Movement
	// Source: http://www.cplusplus.com/forum/general/55170/
	string medMap[16][16];
	playerMovement(1, easyMap, easyBTS, medMap, 2, 2, 10);
}

void MediumMapCode()
{

	// Map for the medium level
	const int medRow = 16, medCol = 16;
	string medMap[medRow][medCol] = {
		{ "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X" },
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
	string easyMap[11][12];
	string easyBTS[11][12];
	playerMovement(2, easyMap, easyBTS, medMap, 1, 1, 5);



}
// Notes: I made a clear() function that will clear the screen so we don't have to type out system("cls") everytime we want to clear the screen.
void clear() {
	system("cls");
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

void playerMovement(int selection, string easyMap[11][12], string easyBTS[11][12], string medMap[16][16], int pX, int pY, int pLives)
{

	if (selection == 1) {
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
				if (easyBTS[pY - 1][pX] == "&") {
					pLives--;
					pX = 2;
					pY = 2;
				}
				if (easyMap[pY - 1][pX] == "X") {
				}
				else {
					pY--;
				}
				// Mine grid

 
				system("cls");
				for (int row = 0; row < 11; row++)
				{
					int xX = 0, xY = 0;
					for (int col = 0; col < 12; col++)
					{
						if (easyMap[row][col] == " ") {
						}
						if (col == pX && row == pY) {
							cout << "O";
							cout << " ";
						}

						else {
							cout << easyMap[row][col] << " ";
							if (col > 1 && row > 1 && col < 10 && row < 10) {
								xX = row;
								xY = col;
							}
						}

					}
					cout << endl;
				}
				cout << "Lives: " << pLives;
				cout << endl;
				break;

				// Player moving left
			case 'A':
			case 'a':
				cout << " < ";
				if (easyBTS[pY][pX - 1] == "&") {
					pLives--;
					pX = 2;
					pY = 2;
				}
				if (easyMap[pY][pX - 1] == "X") {
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
				cout << "Lives: " << pLives;
				cout << endl;
				break;

				// Player moving right
			case 'D':
			case 'd':
				cout << " > ";
				if (easyBTS[pY][pX + 1] == "&") {
					pLives--;
					pX = 2;
					pY = 2;
				}
				if (easyMap[pY][pX + 1] == "X") {
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
				cout << "Lives: " << pLives;
				cout << endl;
				break;

				// Player moving down
			case 'S':
			case 's':
				cout << " V ";
				if (easyBTS[pY + 1][pX] == "&") {
					pLives--;
					pX = 2;
					pY = 2;
				}
				if (easyMap[pY + 1][pX] == "X") {
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
				cout << "Lives: " << pLives;
				cout << endl;
				break;


			}

		} while (true);

	}
	if (selection == 2) {
		cout << "Use WASD to move up, down, left, or right." << endl;
		char move = 0;
		do
		{
			move = _getch();

			switch (move)
			{
				// Player moving upwards			switch (move)
					// Player moving upwards
			case 'W':
			case 'w':
				cout << " ^ ";
				if (medMap[pY - 1][pX] == "X") {
				}
				else {
					pY--;
				}
				system("cls");
				for (int row = 0; row < 16; row++)
				{
					int xX = 0, xY = 0;
					for (int col = 0; col < 16; col++)
					{
						if (medMap[row][col] == " ") {
						}
						if (col == pX && row == pY) {
							cout << "O";
							cout << " ";
						}

						else {
							cout << medMap[row][col] << " ";
							if (col > 1 && row > 1 && col < 10 && row < 10) {
								xX = row;
								xY = col;
							}
						}

					}
					cout << endl;

				}
				break;

				// Player moving left
			case 'A':
			case 'a':
				cout << " < ";
				if (medMap[pY][pX - 1] == "X") {
				}
				else {
					pX--;
				}
				system("cls");
				for (int row = 0; row < 16; row++)
				{
					for (int col = 0; col < 16; col++)
					{
						if (medMap[row][col] == " ") {
						}
						if (col == pX && row == pY) {
							cout << "O";
							cout << " ";
						}

						else {
							cout << medMap[row][col] << " ";
						}

					}
					cout << endl;

				}
				break;

				// Player moving right
			case 'D':
			case 'd':
				cout << " > ";
				if (medMap[pY][pX + 1] == "X") {
				}
				else {
					pX++;
				}

				system("cls");
				for (int row = 0; row < 16; row++)
				{
					for (int col = 0; col < 16; col++)
					{
						if (medMap[row][col] == " ") {
						}
						if (col == pX && row == pY) {
							cout << "O";
							cout << " ";
						}

						else {
							cout << medMap[row][col] << " ";
						}

					}
					cout << endl;

				}
				break;

				// Player moving down
			case 'S':
			case 's':
				cout << " V ";
				if (medMap[pY + 1][pX] == "X") {
				}
				else {
					pY++;
				}
				system("cls");
				for (int row = 0; row < 16; row++)
				{
					for (int col = 0; col < 16; col++)
					{
						if (medMap[row][col] == " ") {
						}
						if (col == pX && row == pY) {
							cout << "O";
							cout << " ";
						}

						else {
							cout << medMap[row][col] << " ";
						}

					}
					cout << endl;

				}
				break;

				
			}

			// Player moving down

		} while (true);



	}

}


