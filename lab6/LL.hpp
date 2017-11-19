/*
 * LL.hpp
 *
 *  Created on: Nov 18, 2017
 *      Author: SK
 */

#ifndef LL_HPP_
#define LL_HPP_

#include "NodeL.hpp"
#include <iostream>
using namespace std;

class LL {
	friend class Game;
	friend class AVLTree;
	NodeL *first;
	NodeL *last;
	int size;
	int score;

public:
	LL();
	void push(string s);
	void addFirst(string s);
	void printList();
	void getScore();

};

#endif /* LL_HPP_ */
