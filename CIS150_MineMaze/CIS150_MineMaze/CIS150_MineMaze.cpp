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

int pX = 2; // Column Position
int pY = 2; // Row Position
string easyMap;
string medMap;
string eventName;



// Evan: New functions for displaying the maps and handling events (such as running into a mine, for instance)
void displayMap(string easyMap[11][12], int pX, int pY, int pLives);

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
void playerMovement(int selection, string easyMap[11][12], string easyBTS[11][12], string medMap[16][16], string medBTS[16][16], int xAxis, int yAxis, int pLives);
void clear();
void displayGrid(string easyBTS[11][12], string medBTS[16][16], int pX, int pY);

int main()
{
	system("cls");

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

	HANDLE  console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);

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
		{ "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", "X", " ", "X" },
		{ "X", " ", " ", " ", "X", "X", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", "X", "X", " ", " ", " ", "X", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", "X", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", "P", "X" },
		{ "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X" }
	};

	string easyBTS[easyRow][easyCol];

	int placeMine;
	int mineCount = 0;
	srand(time(NULL));

	for (int i = 0; i < 11; i++) {

		for (int j = 0; j < 12; j++) {

			

			placeMine = rand() % 8;

			if (placeMine == 0) {
				if (easyMap[i][j] == "P") {
					easyBTS[i][j] = "P";
				}
				else if (easyMap[i][j] == "X") {
					easyBTS[i][j] = "X";
				}
				else {
					easyBTS[i][j] = "&";
					mineCount++;
				}

			}
			else {

				if (easyMap[i][j] == "P") {
					easyBTS[i][j] = "P";
				}
				else if (easyMap[i][j] == "X") {
					easyBTS[i][j] = "X";
				}
				else {
					easyBTS[i][j] = ".";
				}
				
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
string medBTS[16][16];
playerMovement(1, easyMap, easyBTS, medMap, medBTS, 2, 2, 10);
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

	string medBTS[medRow][medCol];

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
	playerMovement(2, easyMap, easyBTS, medMap, medBTS, 1, 1, 5);



}

void clear() {
	system("cls");
}



void playerMovement(int selection, string easyMap[11][12], string easyBTS[11][12], string medMap[16][16], string medBTS[16][16], int pX, int pY, int pLives)
{

	while (5 == 5) {


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
				if (easyMap[pY - 1][pX] == "P") {
					system("cls");
					cout << "Level complete." << endl;
					system("pause");
					main();
				}
				if (easyMap[pY - 1][pX] == "X") {
				}
				else {
					pY--;
				}
				system("cls");
				displayMap(easyMap, pX, pY, pLives);
				displayGrid(easyBTS, medBTS, pX, pY);
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
				if (easyMap[pY][pX - 1] == "P") {
					system("cls");
					cout << "Level complete." << endl;
					system("pause");
					main();
				}		
				if (easyMap[pY][pX - 1] == "X") {
				}
				else {
					pX--;
				}
				system("cls");
				displayMap(easyMap, pX, pY, pLives);
				displayGrid(easyBTS, medBTS, pX, pY);
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
				if (easyMap[pY][pX + 1] == "P") {
					system("cls");
					cout << "Level complete." << endl;
					system("pause");
					main();
				}
				if (easyMap[pY][pX + 1] == "X") {
				}
				else {
					pX++;
				}

				system("cls");
				displayMap(easyMap, pX, pY, pLives);
				displayGrid(easyBTS, medBTS, pX, pY);
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
				if (easyMap[pY + 1][pX] == "P") {
					system("cls");
					cout << "Level complete." << endl;
					system("pause");
					main();
				}
				if (easyMap[pY + 1][pX] == "X") {
				}
				else {
					pY++;
				}
				system("cls");
				displayMap(easyMap, pX, pY, pLives);
				displayGrid(easyBTS, medBTS, pX, pY);
				break;


			}

		} while (selection == 1);

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

}


void displayMap(string easyMap[11][12], int pX, int pY, int pLives) {

	HANDLE  console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);

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
				if (easyMap[row][col] == "P") {
					SetConsoleTextAttribute(console, 12);
					cout << easyMap[row][col] << " ";
					SetConsoleTextAttribute(console, 7);
				}
				else {
				cout << easyMap[row][col] << " ";
				}
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


}

void displayGrid(string easyBTS[11][12], string medBTS[16][16], int pX, int pY) {
	cout << endl;

	HANDLE  console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 2);
	for (int i = 0; i < 11; i++) {

		for (int j = 0; j < 11; j++) {
			if (easyBTS[i][j] == ".") {
			}
			if (j == pX && i == pY) {
				cout << "O";
				cout << " ";
			}
			else {
				cout << easyBTS[i][j] << " ";
			}
			

		}
		cout << endl;

	}
	SetConsoleTextAttribute(console, 7);


}

