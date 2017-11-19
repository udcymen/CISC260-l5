/*
 * AVLTree.hpp
 *
 *  Created on: Nov 18, 2017
 *      Author: samue
 */

#ifndef AVLTREE_HPP_
#define AVLTREE_HPP_

#include <string>
#include <iostream>
#include <NodeT.hpp>
using namespace std;

class AVLTree {

	NodeT *root;
	bool AVLflag;

public:
	AVLTree(bool flag);
	bool findWord(string s, NodeT *n);
	void addNode(string s,NodeT *r);
	void printIO(NodeT *root);
	void printPre(NodeT *root);
	void printPost(NodeT *root);
	void adjustHeights(NodeT *n);
	int getMax(NodeT *n);
	NodeT *rotateRight(NodeT *n);
	NodeT * rotateLeft(NodeT *n);
	int getDiff(NodeT *n);
};



#endif /* AVLTREE_HPP_ */
