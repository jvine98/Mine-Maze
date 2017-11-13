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



int main()
{

	// ======================================
	// Map variables
	// ======================================
	string easyLevel = ""; // Placeholders for later.
	// 10 x 10 Grid
	string mediumLevel = "";
	// 15 x 15 Grid
	string hardLevel = "";
	// 25 x 25 Grid

	// ======================================
	// Player variables
	// ======================================
	int lives; // Placeholder for later, will depend on the level.
	int moves; // Placeholder for later, limited amount of moves depending on the level.

	const int medrow = 17, medcolm = 17;
	string medmap[medrow][medrow] = {
	{" ","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p"},
	{"a", " ", " ", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " "," "," "},
	{"b", " ", " ", "-", "-", "-", " ", " ", "|", " ", " ", " ", " ", " ","|"," "},
	{"c", " ", " ", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ","|"," "},
	{"d", "-", "-", " ", " ", " ", "|", " ", " ", " ", "-", "-", "-", " ","|"," "},
	{"e", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ", "|", " "," "," "},
	{"f", " ", " ", " ", " ", " ", "|", " ", " ", " ", " ", " ", "|", " "," "," "},
	{"g", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "|", " "," "," "},
	{"h", " ", " ", "|", " ", " ", " ", " ", " ", "|", " ", " ", " ", " "," "," "},
	{"i", "-", "-", "|", " ", "-", "-", "-", " ", "|", " ", " ", " ", " "," "," "},
	{"j", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "," "," "},
	{"k", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "-", "-", " "," "," "},
	{"l", " ", " ", " ", " ", "-", "-", "-", "-", " ", " ", " ", " ", "|"," "," "},
	{"m", "-", "-", " ", " ", "|", " ", " ", " ", " ", " ", " ", " ", " "," "," "},
	{"n", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "-", "-", "-"," "," "},
	{"o", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "|"," "," " },
	{"p", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "|"," "," " },

	};

	displayStartup();
	for (int row = 0; row < 17; row++)
	{
		for (int col = 0; col < 17; col++)
		{
			cout << medmap[row][col] << " ";
		
		}
		cout << endl;
	
	}


	system("pause");
    return 0;
}

