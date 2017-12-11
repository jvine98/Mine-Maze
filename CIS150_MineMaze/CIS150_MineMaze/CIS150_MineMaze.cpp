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

int pX = 1; // Column Position
int pY = 1; // Row Position
bool isAdmin = false;
string easyMap;
string medMap;
string eventName;

// Evan: New functions for displaying the maps and handling events (such as running into a mine, for instance)
void displayMap(string easyMap[11][12], string medMap[16][16], int pX, int pY, int pLives, int pmoves, int selection);

void displayStartup() {
	cout << "============================================================================================================" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                                   Mine Maze                                                          " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "============================================================================================================" << endl;
}
// Evan
//========
void easyMapCode();
// Justin
//========
void MediumMapCode();

void playerMovement(int selection, string easyMap[11][12], string easyBTS[11][12], string medMap[16][16], string medBTS[16][16], int xAxis, int yAxis, int pLives, int pmoves );
void clear();
void displayGrid(string easyBTS[11][12], string medBTS[16][16], int pX, int pY, int selection);

int main()
{
	system("cls");

	int selection;
	// Start up menu;
	displayStartup();

	// Justin
	//========
	cout << "Hello welcome to The Mine Maze\n";
	cout << "Select the Level you want to Play\n";
	cout << "1. Easy\n";
	cout << "2. Medium\n";
	cout << "==================================================================================================\n";
	cout << "Enter your selection: ";
	// Cin the selection
	cin >> selection;
	cout << endl;
	string pass = "";
	if (selection == 1) 
	{
		// Checks for admin password
		while (pass != "" || pass != "123" || pass != "SKIP") {

			if (isAdmin) {
				easyMapCode();
			}
			else {

				cout << "Enter admin password or type SKIP to skip: ";
				cin >> pass;
				if (pass == "123" && isAdmin == false) {
					isAdmin = true;
					easyMapCode();
				}
				else if (pass == "SKIP") {
					easyMapCode();
				}
			}
		}
	}
	else if (selection == 2)
	{

		while (pass != "" || pass != "123" || pass != "SKIP") {

			if (isAdmin) {
				MediumMapCode();
			}
			else {

				cout << "Enter admin password or type SKIP to skip: ";
				cin >> pass;
				if (pass == "123" && isAdmin == false) {
					isAdmin = true;
					MediumMapCode();
				}
				else if (pass == "SKIP") {
					MediumMapCode();
				}
			}
		}
	}

		system("pause");
		return 0;
}

void easyMapCode() {
	// Code for Easy Level


	// Evan
	//========


	// Colors for console
	HANDLE  console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
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


	// Grid for Easy Map
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


	// Grid for behind the scenes functionality
	string easyBTS[easyRow][easyCol];

	int placeMine;
	int mineCount = 0;
	srand(time(NULL));


	// Random mine-placing functionality
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
			cout << easyMap[i][j] << " ";

		}
		cout << endl;
	}


	// Registering Movement
	// Source: http://www.cplusplus.com/forum/general/55170/
	string medMap[16][16];
	string medBTS[16][16];
	playerMovement(1, easyMap, easyBTS, medMap, medBTS, 1, 1, 10, 40);
}

void MediumMapCode()
{


	// Justin
	//========

	// Map for the medium level
	const int medRow = 16, medCol = 16;
	string medMap[medRow][medCol] = {
		{ "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", "X", " ", " ", " ", "X", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", "X", " ", " ", " ", " ", "X", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", "X", " ", " ", " ", " ", " ", "X", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", "X", " ", " ", " ", " ", " ", " ", "X", " ", " ", " ", "X", "X", "X", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", "X", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", "X", " ", " ", "X", "X", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "X" },
		{ "X", " ", " ", "X", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "P", "X" },
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

	int placeMine;
	int mineCount = 0;
	srand(time(NULL));

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) {

			placeMine = rand() % 7;

			if (placeMine == 0) {
				if (medMap[i][j] == "P") {
					medBTS[i][j] = "P";
				}
				else if (medMap[i][j] == "X") {
					medBTS[i][j] = "X";
				}
				else {
					medBTS[i][j] = "&";
					mineCount++;
				}

			}
			else {

				if (medMap[i][j] == "P") {
					medBTS[i][j] = "P";
				}
				else if (medMap[i][j] == "X") {
					medBTS[i][j] = "X";
				}
				else {
					medBTS[i][j] = ".";
				}
			}
		}
	}

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) {
			cout << medMap[i][j] << " ";

		}
		cout << endl;
	}

	string easyMap[11][12];
	string easyBTS[11][12];
	playerMovement(2, easyMap, easyBTS, medMap, medBTS, 1, 1, 5, 75);
}

void clear() {
	system("cls");
}

void playerMovement(int selection, string easyMap[11][12], string easyBTS[11][12], string medMap[16][16], string medBTS[16][16], int pX, int pY, int pLives, int pmoves)
{

	// Evan
	//========
	if (selection == 1) {
		cout << "Use WASD to move up, down, left, or right." << endl;
		char move = 0;
		do
		{
			if (pLives != 0 && pmoves != 0)
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
						pmoves--;
						pX = 1;
						pY = 1;
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
						pmoves--;
					}
					system("cls");
					displayMap(easyMap, medMap, pX, pY, pLives, pmoves, selection);
					displayGrid(easyBTS, medMap, pX, pY, selection);
					break;

					// Player moving left
				case 'A':
				case 'a':
					cout << " < ";
					if (easyBTS[pY][pX - 1] == "&") {
						pLives--;
						pmoves--;
						pX = 1;
						pY = 1;
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
						pmoves--;
					}
					system("cls");
					displayMap(easyMap, medMap, pX, pY, pLives, pmoves, selection);
					displayGrid(easyBTS, medMap, pX, pY, selection);
					break;

					// Player moving right
				case 'D':
				case 'd':
					cout << " > ";
					if (easyBTS[pY][pX + 1] == "&") {
						pLives--;
						pmoves--;
						pX = 1;
						pY = 1;
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
						pmoves--;
					}

					system("cls");
					displayMap(easyMap, medMap, pX, pY, pLives, pmoves, selection);
					displayGrid(easyBTS, medMap, pX, pY, selection);
					break;

					// Player moving down
				case 'S':
				case 's':
					cout << " V ";
					if (easyBTS[pY + 1][pX] == "&") {
						pLives--;
						pmoves--;
						pX = 1;
						pY = 1;
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
						pmoves--;
					}
					system("cls");
					displayMap(easyMap, medMap, pX, pY, pLives, pmoves, selection);
					displayGrid(easyBTS, medMap, pX, pY, selection);
					break;
				}
			}
			if (pLives == 0 || pmoves == 0)
			{
				cout << "You suck!\n";
				system("pause");
				clear();
				main();
			}
		} while (selection == 1);

	}
	// Justin
	//========
	if (selection == 2) 
	{
		cout << "Use WASD to move up, down, left, or right." << endl;
		char move = 0;
		do
		{
			if (pLives != 0 && pmoves != 0)
			{
				move = _getch();

				switch (move)
				{
					// Player moving upwards
				case 'W':
				case 'w':
					cout << " ^ ";
					if (medBTS[pY - 1][pX] == "&") {
						pLives--;
						pmoves--;
						pX = 1;
						pY = 1;
					}
					if (medMap[pY - 1][pX] == "P") {
						system("cls");
						cout << "Level complete." << endl;
						system("pause");
						main();
					}
					if (medMap[pY - 1][pX] == "X") {
					}
					else {
						pY--;
						pmoves--;
					}
					system("cls");
					displayMap(easyMap, medMap, pX, pY, pLives, pmoves, selection);
					displayGrid(easyBTS, medBTS, pX, pY, selection);
					break;

					// Player moving left
				case 'A':
				case 'a':
					cout << " < ";
					if (medBTS[pY][pX - 1] == "&") {
						pLives--;
						pmoves--;
						pX = 1;
						pY = 1;
					}
					if (medMap[pY][pX - 1] == "P") {
						system("cls");
						cout << "Level complete." << endl;
						system("pause");
						main();
					}
					if (medMap[pY][pX - 1] == "X") {
					}
					else {
						pX--;
						pmoves--;
					}
					system("cls");
					displayMap(easyMap, medMap, pX, pY, pLives, pmoves, selection);
					displayGrid(easyBTS, medBTS, pX, pY, selection);
					break;

					// Player moving right
				case 'D':
				case 'd':
					cout << " > ";
					if (medBTS[pY][pX + 1] == "&") {
						pLives--;
						pmoves--;
						pX = 1;
						pY = 1;
					}
					if (medMap[pY][pX + 1] == "P") {
						system("cls");
						cout << "Level complete." << endl;
						system("pause");
						main();
					}
					if (medMap[pY][pX + 1] == "X") {
					}
					else {
						pX++;
						pmoves--;
					}

					system("cls");
					displayMap(easyMap, medMap, pX, pY, pLives, pmoves, selection);
					displayGrid(easyBTS, medBTS, pX, pY, selection);
					break;

					// Player moving down
				case 'S':
				case 's':
					cout << " V ";
					if (medBTS[pY + 1][pX] == "&") {
						pLives--;
						pmoves--;
						pX = 1;
						pY = 1;
					}
					if (medMap[pY + 1][pX] == "P") {
						system("cls");
						cout << "Level complete." << endl;
						system("pause");
						main();
					}
					if (medMap[pY + 1][pX] == "X") {
					}
					else {
						pY++;
						pmoves--;
					}
					system("cls");
					displayMap(easyMap, medMap, pX, pY, pLives, pmoves, selection);
					displayGrid(easyBTS, medBTS, pX, pY, selection);
					break;


				}
			}
			if (pLives == 0 || pmoves == 0)
			{
				cout << "You suck!\n";
				system("pause");
				clear();
				main();
			}
		} while (selection == 2);
	}
	

}

// Functionality for displaying the map each time the player moves
void displayMap(string easyMap[11][12], string medMap[16][16], int pX, int pY, int pLives, int pmoves, int selection) {

	HANDLE  console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	// Evan
	//========
	if (selection == 1)
	{
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
				}

			}
			cout << endl;
		}
	}
	// Justin
	//========
	if (selection == 2)
	{
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
					if (medMap[row][col] == "P") {
						SetConsoleTextAttribute(console, 12);
						cout << medMap[row][col] << " ";
						SetConsoleTextAttribute(console, 7);
					}
					else {
						cout << medMap[row][col] << " ";
					}
				}
			}
			cout << endl;
		}
	}
	// Justin
	//========
	cout << "X Lives: " << pLives;
	cout << endl;
	cout << "X Moves: " << pmoves << endl;

}

void displayGrid(string easyBTS[11][12], string medBTS[16][16], int pX, int pY, int selection) {

	HANDLE  console;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 2);

	if (isAdmin == false) {

	}
	else if (isAdmin == true) {
	
		// Evan
		//========
		if (selection == 1)
		{
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
		}
		// Justin
		//========
		if (selection == 2)
		{
			for (int i = 0; i < 16; i++) {

				for (int j = 0; j < 16; j++) {
					if (medBTS[i][j] == ".") {
					}
					if (j == pX && i == pY) {
						cout << "O";
						cout << " ";
					}
					else {
						cout << medBTS[i][j] << " ";
					}
				}
				cout << endl;
			}
		}
	}
	SetConsoleTextAttribute(console, 7);

}