/*
 * mainWordHub.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: Debra
 */


//#include "AVLTree.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Game.hpp"

using namespace std;

int main() {

	srand(time(NULL));

//	Game *game = new Game("testdict.txt", false);
	Game *game = new Game("commondict.txt", false);

	game->startGame();

	return 0;
}

