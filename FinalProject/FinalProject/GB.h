//
//  GB.h
//  2048_2.0
//
//  Created by Kionte Brown on 5/7/16.
//  Copyright © 2016 Kionte Brown. All rights reserved.
//

#ifndef GB_h
#define GB_h
#include "Tile.h"
class GB {

private:
	int size;
	int score;
	Tile** GBValues;
	int** tempGBValues;
public:
	int getScore() const;
	Tile** getGBValues();
	int** getTempGBValues() const;
	int getSize() const;

	int command(); // input move and return move
	//int setCommand(int newCommand); // main
	void changeGB(); // switch statement call one o next 4 functions

	bool save() const;

	bool checkMove();
	bool gameOverCheck();

	GB(); // intit gameboard
	~GB();

	void initGB();
	void initTempGB();
	void initGB(string data);//overload for loading a save file
	void initTempGB(string data);//overload for loading a save file
	int loadScore(string data);//loads the score from the file data
	void updateTempGB();
	void outputGB();

	void leftGB();
	void rightGB();
	void upGB();
	void downGB();
	void randomInput();
};

#endif /* GB_h */

