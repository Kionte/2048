//
//  GB.h
//  2048_2.0
//
//  Created by Kionte Brown on 5/7/16.
//  Copyright © 2016 Kionte Brown. All rights reserved.
//

#ifndef GB_h
#define GB_h

class GB {

private:
	int size;
	int score;
	int** GBValues;
	int** tempGBValues;
public:
	int getScore() const;
	int** getGBValues();
	int** getTempGBValues() const;
	int getSize() const;

	int command(); // input move and return move
	//int setCommand(int newCommand); // main
	void changeGB(); // switch statement call one o next 4 functions

	bool checkMove();
	bool gameOverCheck();

	GB(); // intit gameboard
	GB(int** savedBoard, int savedScore, int size); // load game
													// ~GB();

	void initGB();
	void initTempGB();
	void updateTempGB();
	void outputGB();

	void leftGB();
	void rightGB();
	void upGB();
	void downGB();
	void randomInput();
};

#endif /* GB_h */

