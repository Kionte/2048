//
//  GB.cpp
//  2048_2.0
//
//  Created by Kionte Brown on 5/7/16.
//  Copyright © 2016 Kionte Brown. All rights reserved.
//

#include <iostream>
#include <conio.h>
#include "GB.h"
#include "Tile.h"
#include <stdio.h>
#include <stdlib.h> 
#include <fstream>
#include <string>
using namespace std;


void GB::initGB() {
	GBValues = new Tile*[size];
	for (int r = 0; r < size; r++) {
		GBValues[r] = new Tile[size];
		for (int c = 0; c < size; c++) {
			GBValues[r][c].changeValue(0);
		}
	}
}
void GB::initTempGB() {
	tempGBValues = new int*[size];
	for (int r = 0; r < size; r++) {
		tempGBValues[r] = new int[size];
		for (int c = 0; c < size; c++) {
			tempGBValues[r][c] = 0;
		}
	}
}

void GB::initGB(string data)
{
	GBValues = new Tile*[size];
	for (int r = 0; r < size; r++) {
		GBValues[r] = new Tile[size];
		for (int c = 0; c < size; c++) {
			//gets the correct letter from the save data
			char temp = data.at(1 + ((r*size) + c));
			switch (temp)
			{
			case 'a':
				GBValues[r][c].changeValue(0);
				break;
			case 'b':
				GBValues[r][c].changeValue(2);
				break;
			case 'c':
				GBValues[r][c].changeValue(4);
				break;
			case 'd':
				GBValues[r][c].changeValue(8);
				break;
			case 'e':
				GBValues[r][c].changeValue(16);
				break;
			case 'f':
				GBValues[r][c].changeValue(32);
				break;
			case 'g':
				GBValues[r][c].changeValue(64);
				break;
			case 'h':
				GBValues[r][c].changeValue(128);
				break;
			case 'i':
				GBValues[r][c].changeValue(256);
				break;
			case 'j':
				GBValues[r][c].changeValue(512);
				break;
			case 'k':
				GBValues[r][c].changeValue(1024);
				break;
			case 'l':
				GBValues[r][c].changeValue(2048);
				break;
			case 'm':
				GBValues[r][c].changeValue(4096);
				break;
			case 'n':
				GBValues[r][c].changeValue(8192);
				break;
			case 'o':
				GBValues[r][c].changeValue(16384);
				break;
			case 'p':
				GBValues[r][c].changeValue(32768);
				break;
			case 'q':
				GBValues[r][c].changeValue(65536);
				break;
			default:
				GBValues[r][c].changeValue(0);
				break;
			}
		}
	}
}


void GB::initTempGB(string data)
{
	tempGBValues = new int*[size];
	for (int r = 0; r < size; r++) {
		tempGBValues[r] = new int[size];
		for (int c = 0; c < size; c++) {
			//gets the correct letter from the save data
			char temp = data.at(1 + ((r*size) + c));
			switch (temp)
			{
			case 'a':
				tempGBValues[r][c] = 0;
				break;
			case 'b':
				tempGBValues[r][c] = 2;
				break;
			case 'c':
				tempGBValues[r][c] = 4;
				break;
			case 'd':
				tempGBValues[r][c] = 8;
				break;
			case 'e':
				tempGBValues[r][c] = 16;
				break;
			case 'f':
				tempGBValues[r][c] = 32;
				break;
			case 'g':
				tempGBValues[r][c] = 64;
				break;
			case 'h':
				tempGBValues[r][c] = 124;
				break;
			case 'i':
				tempGBValues[r][c] = 256;
				break;
			case 'j':
				tempGBValues[r][c] = 512;
				break;
			case 'k':
				tempGBValues[r][c] = 1024;
				break;
			case 'l':
				tempGBValues[r][c] = 2048;
				break;
			case 'm':
				tempGBValues[r][c] = 4096;
				break;
			case 'n':
				tempGBValues[r][c] = 8192;
				break;
			case 'o':
				tempGBValues[r][c] = 16384;
				break;
			case 'p':
				tempGBValues[r][c] = 32768;
				break;
			case 'q':
				tempGBValues[r][c] = 65536;
				break;
			default:
				tempGBValues[r][c] = 0;
				break;
			}
		}
	}
}

int GB::loadScore(string data)//gets the score from the save data
{
	string scoreStr;
	int scorelength = (data.size()-((size*size)+1));
	for (int i = 0;i < scorelength;i++)
	{
		scoreStr += data.at(((size*size) + 1) + i);
	}

	int score = atoi(scoreStr.c_str());
	return score;
}


GB::GB()
{
	ifstream save;
	save.open("save.txt");
	if (save.fail())
	{
		cout << "Enter the size: ";
		cin >> size;
		score = 0;
		initGB();
		randomInput();
		randomInput();
		initTempGB();
	}
	else
	{
		cout << "Do you want to load your save? (y/n)\n" ;
		char choice;
		cin >> choice;
		if (toupper(choice) == 'Y')
		{
			//gets the data from the file
			string data;
			getline(save, data);
			save.close();

			//starts constructing the board from the data in the file
			
			size = data.at(0)-'0';
			initGB(data);
			initTempGB(data);
			score = loadScore(data);
		}
		else
		{
			cout << "Enter the size: ";
			cin >> size;
			score = 0;
			initGB();
			randomInput();
			randomInput();
			initTempGB();
		}

	}
	outputGB();
}



GB::~GB()//Destroys the game;
{
	for (int i = 0;i < size;i++)
	{
		delete[] GBValues[i];
	}
	delete[]GBValues;

	for (int i = 0;i < size;i++)
	{
		delete[] tempGBValues[i];
	}
	delete[]tempGBValues;
}


int GB::getScore() const { // gets score
	return score;
}
int GB::getSize() const { // gets size
	return size;
}
int GB::command()
{
	int move = 0;
	move = _getch();
	return move;
}

Tile** GB::getGBValues() { // gets GB values
	return GBValues;
}
int** GB::getTempGBValues() const { // gets tempGBValues
	return tempGBValues;
}




bool GB::gameOverCheck() { // checks if game is over

	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (GBValues[r][c].getValue() == 0) {
				return true;
			}
		}
	}

	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (c != size - 1) {
				if (GBValues[r][c].getValue() == GBValues[r][c + 1].getValue()) {
					return true;
				}
			}
			if (r != size - 1) {
				if (GBValues[r][c].getValue() == GBValues[r + 1][c].getValue()) {
					return true;
				}
			}
		}
	}

	return false;
}
/*int GB::setCommand(int newCommand) { // sets the new command
	command = newCommand;
	return command;
}*/



void GB::updateTempGB() { // updates temp GB for checkmove function
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			tempGBValues[r][c] = GBValues[r][c].getValue();
		}
	}
}


void GB::leftGB() { // move left
	int n;
	bool quitLoop;

	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) { // checker to go through the entire array
			if (GBValues[r][c].getValue() == 0) { // if current location is empty
				n = 1;
				while (GBValues[r][c].getValue() == 0 && n < (size - c)) { // while current location is empty and n is in range of table

					if (GBValues[r][c + n].getValue() != 0) { // if next location has value put that value in current location
						GBValues[r][c] = GBValues[r][c + n];
						GBValues[r][c + n] = 0;
					}
					else { //increment n to check next column
						n++;
					}
				}
			}
			n = 1;
			quitLoop = false;

			while (!quitLoop && n < (size - c)) { // loop checks if the locations will have same value when moved
				if (GBValues[r][c + n].getValue() == GBValues[r][c].getValue()) {
					GBValues[r][c].changeValue(GBValues[r][c].getValue()*2);
					GBValues[r][c + n] = 0;
					score += GBValues[r][c].getValue();
					quitLoop = true;
				}
				else if (GBValues[r][c + n].getValue() == 0) { // check next col
					n++;
				}
				else {
					quitLoop = true; // nothing left to check end loop
				}
			}
		}
	}
}

void GB::rightGB() { // moves right
	int n;
	bool quitLoop;
	int g = -1;

	for (int r = 0; r < size; r++) {
		g = -1;
		for (int c = size - 1; c > 0; c--) { // checker to go through the entire array
			n = 1;
			g++;
			if (GBValues[r][c].getValue() == 0) { // if current location is empty
				n = 1;
				while (GBValues[r][c].getValue() == 0 && n < (size - g)) { // while current location is empty and n is in range of table

					if (GBValues[r][c - n].getValue() != 0) { // if next location has value put that value in current location
						GBValues[r][c] = GBValues[r][c - n];
						GBValues[r][c - n] = 0;
					}
					else { //increment n to check next column
						n++;
					}
				}
			}
			n = 1;
			quitLoop = false;

			while (!quitLoop && n < (size - g)) { // loop checks if the locations will have same value when moved
				if (GBValues[r][c - n].getValue() == GBValues[r][c].getValue()) {
					GBValues[r][c].changeValue(GBValues[r][c].getValue() * 2);
					score += GBValues[r][c].getValue();
					GBValues[r][c - n] = 0;
					quitLoop = true;
				}
				else if (GBValues[r][c - n].getValue() == 0) { // check next col
					n++;
				}
				else {
					quitLoop = true; // nothing left to check end loop
				}
			}
		}
	}
}

void GB::upGB() { // moves up
	int n;
	bool quitLoop;

	for (int c = 0; c < size; c++) {
		for (int r = 0; r < size; r++) { // checker to go through the entire array
			if (GBValues[r][c].getValue() == 0) { // if current location is empty
				n = 1;
				while (GBValues[r][c].getValue() == 0 && n < (size - r)) { // while current location is empty and n is in range of table

					if (GBValues[r + n][c].getValue() != 0) { // if next location has value put that value in current location
						GBValues[r][c] = GBValues[r + n][c];
						GBValues[r + n][c] = 0;
					}
					else { //increment n to check next column
						n++;
					}
				}
			}
			n = 1;
			quitLoop = false;

			while (!quitLoop && n < (size - r)) { // loop checks if the locations will have same value when moved
				if (GBValues[r + n][c].getValue() == GBValues[r][c].getValue()) {
					GBValues[r][c].changeValue(GBValues[r][c].getValue() * 2);
					GBValues[r + n][c] = 0;
					score += GBValues[r][c].getValue();
					quitLoop = true;
				}
				else if (GBValues[r + n][c].getValue() == 0) { // check next col
					n++;
				}
				else {
					quitLoop = true; // nothing left to check end loop

				}
			}
		}
	}
}
void GB::downGB() { // moves down
	int n;
	bool quitLoop;
	int g = -1;

	for (int c = 0; c < size; c++) {
		g = -1;
		for (int r = size - 1; r > 0; r--) { // checker to go through the entire array
			n = 1;
			g++;
			if (GBValues[r][c].getValue() == 0) { // if current location is empty
				while (GBValues[r][c].getValue() == 0 && n < (size - g)) { // while current location is empty and n is in range of table

					if (GBValues[r - n][c].getValue() != 0) { // if next location has value put that value in current location
						GBValues[r][c] = GBValues[r - n][c];
						GBValues[r - n][c] = 0;
					}
					else { //increment n to check next column
						n++;
					}
				}
			}
			n = 1;
			quitLoop = false;

			while (!quitLoop && n < (size - g)) { // loop checks if the locations will have same value when moved
				if (GBValues[r - n][c].getValue() == GBValues[r][c].getValue()) {
					GBValues[r][c].changeValue(GBValues[r][c].getValue() * 2);
					GBValues[r - n][c] = 0;
					score += GBValues[r][c].getValue();
					quitLoop = true;
				}
				else if (GBValues[r - n][c].getValue() == 0) { // check next col
					n++;
				}
				else {
					quitLoop = true; // nothing left to check end loop
				}
			}
		}
	}
}

bool GB::checkMove() { // checks to see if move is valid
	for (int r = 0; r < size; r++) { // checker to see see if there is a difference between board before and after move
		for (int c = 0; c < size; c++) {
			if (GBValues[r][c].getValue() != tempGBValues[r][c]) {
				return true;
			}
		}
	}

	return false;
}

void GB::randomInput() { // inputs random number
	int r, c, x = 0;

	bool foundEmpty = false;

	while (foundEmpty == false) { // finds empty location randomly
		r = rand() % size; //
		c = rand() % size;
		x = rand() % 25;
		if (GBValues[r][c].getValue() == 0) { // if random location is empty
			if (x != 21) {
				GBValues[r][c] = 2; // random location = )
			}
			else {
				GBValues[r][c] = 4; // random location = 4
			}
			foundEmpty = true; // end loop
		}
	}
}

void GB::outputGB() {
	system("cls");
	cout << "          Score: " << score << endl;
	for (int r = 0; r < size; r++) { // output new array
		
				 //the following code works... 

		for (int i = 0;i < size;i++)
		{
			cout << "-------";
		}
		cout << endl; 
		for (int c = 0; c < size; c++) {
				cout << GBValues[r][c].getData();
		}

		cout << endl;
	}
	for (int i = 0;i < size;i++)
	{
		cout << "-------";
	}
	cout << endl;
}



void GB::changeGB() {//takes an input and performs the apropriate action
	switch (command()) {
	case 75:
		leftGB();
		if (checkMove()) {
			randomInput();
		}
		outputGB();
		break;
	case 77:
		rightGB();
		if (checkMove()) {
			randomInput();
		}
		outputGB();
		break;
	case 72:
		upGB();
		if (checkMove()) {
			randomInput();
		}
		outputGB();
		break;
	case 80:
		downGB();
		if (checkMove()) {
			randomInput();
		}
		outputGB();
		break;
	case 's':
		save();
		break;
	default:
		//non valid moves
		break;
	}
}

bool GB::save() const//this will save the current board configuration and score to a file
{
	remove("save.txt");//deletes the previous save file
	ofstream save;//opens the file
	save.open("save.txt");//checks if the file opened
	if (save.fail())
	{
		cout << "Save failed!";
		return true;
	
	}

	//this will actually save the data

	save << size;

	for (int i = 0; i < size;i++)
	{
		for (int j = 0; j < size;j++)
		{
			switch (GBValues[i][j].getValue())//saves a letter for each possible value with 5 or less digits
			{
			case 0:
				save << 'a';
				break;
			case 2:
				save << 'b';
				break;
			case 4:
				save << 'c';
				break;
			case 8:
				save << 'd';
				break;
			case 16:
				save << 'e';
				break;
			case 32:
				save << 'f';
				break;
			case 64:
				save << 'g';
				break;
			case 128:
				save << 'h';
				break;
			case 256:
				save << 'i';
				break;
			case 512:
				save << 'j';
				break;
			case 1024:
				save << 'k';
				break;
			case 2048:
				save << 'l';
				break;
			case 4096:
				save << 'm';
				break;
			case 8192:
				save << 'n';
				break;
			case 16384:
				save << 'o';
				break;
			case 32768:
				save << 'p';
				break;
			case 65536:
				save << 'q';
				break;
			default:
				save << 'a';
				break;

			}
		}
	}
	save << score;
	cout << "Saved!";
	save.close();
	return false;

}


