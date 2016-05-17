//
//  Tile.h
//  2048_2.0
//
//  Created by Joel Schroeder on 5/7/16.
//  Copyright © 2016 Joel Schroeder. All rights reserved.
//

#ifndef TILE_H_
#define TILE_H_
#include <string>
#include <iostream>
using namespace std;
class Tile {

private:
	int value;
	int digits;
	string data;
public:
	Tile();//defualt constrcuctor
	Tile(int num);//creates a tile witht he sepcified value or 0 for blank
	int getValue() const;//returns tyhe value
	string getData() const;//will store a string that represents the tile with correct formatting
	void changeValue(int num);//will change the value of the tile
	int numDigits(); //returns the number of digits in value
	string makeData();//creates the apropriate string based on the number of digits and the value
	
};

#endif 


