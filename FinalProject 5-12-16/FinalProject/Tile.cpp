#include <iostream>
#include <string>
#include "Tile.h"
#include <ctime>
using namespace std;

Tile::Tile()//defualt constrcuctor
{
	srand(time(0));
	int x = rand() % 20;//sets the value to either 2 or 4. there is a one in 20 chance to get a 4
	if (x != 19) {
		value = 2;
	}
	else {
		value = 4;
	}
	digits = 1;
	data = makeData();
}

Tile::Tile(int num)//creates a tile witht he sepcified value
{
	value = num;
	digits = numDigits();
	data = makeData();
}

int Tile::getValue() const
{
	return value;
}

string Tile::getData() const
{
	return data;
}

void Tile::changeValue(int num)
{
	value = num;
	digits = numDigits();
	data = makeData();
}

int Tile::numDigits()//returns the number of digits in value;
{
	string temp = to_string(value);//determines the number of digits in value
	return temp.length();
}

string Tile::makeData()//creates the apropriate string based on the number of digits and the value
{
	string temp;
	if (value == 0)
	{
		temp = "[     ]";
	}
	else
	{
		switch (digits)
		{
		case 1:
			temp = "[  ";
			temp += to_string(value);
			temp += "  ]";
			break;
		case 2:
			temp = "[  ";
			temp += to_string(value);
			temp += " ]";
			break;
		case 3:
			temp = "[ ";
			temp += to_string(value);
			temp += " ]";
			break;
		case 4:
			temp = "[ ";
			temp += to_string(value);
			temp += "]";
			break;
		case 5:
			temp = "]";
			temp += to_string(value);
			temp += "[";
			break;
		default:
			temp = "[ERROR]";
			break;

		}
	}
	return temp;
}
