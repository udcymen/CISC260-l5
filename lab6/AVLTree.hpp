/*
 * AVLTree.hpp
 *
 *  Created on: Nov 18, 2017
 *      Author: SK
 */

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_

#include "NodeT.hpp"
#include <iostream>
using namespace std;

class AVLTree {
	friend class Game;
	friend class LL;
	NodeT *root;
	bool AVLflag;

public:
	AVLTree(bool flag);
	bool findWord(string s, NodeT *n);
	void addNode(string s, NodeT *r);
	void printIO(NodeT *root);
	void printPre(NodeT *root);
	void printPost(NodeT *root);
	void adjustHeights(NodeT *n);
	int getMax(NodeT *n);
	NodeT *rotateRight(NodeT *n);
	NodeT *rotateLeft(NodeT *n);
	int getDiff(NodeT *n);
	NodeT *helper(NodeT *n);

};



#endif /* AVLTREE_HPP_ */
