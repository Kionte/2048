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

GB::GB() {
	size = 4;
	score = 0;
	initGB();
	randomInput();
	randomInput();
	initTempGB();
	outputGB(); // should be in design  class?

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
		std::cout << "----------------------------" << std::endl; //the following code works... 
		for (int c = 0; c < size; c++) {
				std::cout << GBValues[r][c].getData();
		}

		std::cout << std::endl;
	}
	std::cout << "----------------------------" << std::endl;
}



void GB::changeGB() {
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
	default:
		//non valid move
		break;
	}
}


