//
//  main.cpp
//  2048_2.0
//
//  Created by Kionte Brown on 5/7/16.
//  Copyright © 2016 Kionte Brown. All rights reserved.
//

#include <iostream>
#include <string>
#include "GB.h"


void playGame() {
	//int move;
	GB game;

	while (game.gameOverCheck()) {
		//std::cin >> move;
		game.updateTempGB();
		//game.setCommand(move);
		game.changeGB();
	}
	std::cout << "Game Over!\nScore: " << game.getScore() << std::endl;

}
int main() {
	playGame();
	return 0;
}