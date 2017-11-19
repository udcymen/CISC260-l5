/*
 * AVLTree.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: SK
 */


#include "AVLTree.hpp"
#include "NodeT.hpp"
#include <iostream>
using namespace std;


AVLTree::AVLTree(bool flag){
	root = NULL;
	AVLflag = flag;
}

bool AVLTree::findWord(string s, NodeT *n){
	if(s == n->word){
		return true;
	}
	else if(s < n->word){
		findWord(s, n->left);
	}
	else{
		findWord(s, n->right);
	}
	return false;
}

void AVLTree::addNode(string s, NodeT *r){
	if(root == NULL){
		NodeT *n = new NodeT(s);
		root = n;
		cout<<"Made root"<<endl;
		return;
	}

	if(s < r->word){
		if(r->left == NULL){
			NodeT *n = new NodeT(s);
			r->left = n;
			n->parent = r;
			n->height = 1;
			cout<<"Inserting to left of "<<r->word<<endl;
			AVLTree::adjustHeights(n);
			cout<<"                             "<<endl;
		}
		else{
			cout<<"Looking left of "<<r->word<<endl;
			addNode(s, r->left);
		}
	}
	else if(s > r->word){
		if(r->right == NULL){
			NodeT *n = new NodeT(s);
			r->right = n;
			n->parent = r;
			n->height = 1;
			cout<<"Inserting to right of "<<r->word<<endl;
			AVLTree::adjustHeights(n);
			cout<<"                             "<<endl;
		}
		else{
			cout<<"Looking right of "<<r->word<<endl;
			addNode(s, r->right);
		}
	}
	return;
}

void AVLTree::printIO(NodeT *root){
	if(root == NULL){
		return;
	}
	else{
		printIO(root->left);
		root->printTNode();
		printIO(root->right);
	}
}

void AVLTree::printPre(NodeT *root){
	if(root == NULL){
		return;
	}
	else{
		root->printTNode();
		printPre(root->left);
		printPre(root->right);
	}
}

void AVLTree::printPost(NodeT *root){
	if(root == NULL){
		return;
	}
	else{
		printPost(root->left);
		printPost(root->right);
		root->printTNode();
	}
}

NodeT* AVLTree::helper(NodeT *n){
	NodeT *tmp = n;
	while(tmp != NULL){
		if(getDiff(tmp) >= 2 || getDiff(tmp) <= -2){
			return tmp;
		}
		else{
			tmp = tmp->parent;
		}
	}
	return NULL;
}

void AVLTree::adjustHeights(NodeT *n){
	NodeT *tmp = n;
	while(tmp->parent != NULL){
		tmp->parent->height = getMax(tmp->parent) + 1;
		tmp = tmp->parent;
	}

	if(AVLflag == true){
		NodeT *tmp2 = helper(n);
		if(tmp2 != NULL){
			if(getDiff(tmp2) >= 2){
				rotateRight(tmp2);
			}
			if(getDiff(tmp2) <= -2){
				rotateLeft(tmp2);
			}
			tmp2->height = getMax(tmp2) + 1;
			while(tmp2->parent != NULL){
				tmp2->parent->height = getMax(tmp2->parent) + 1;
				tmp2 = tmp2->parent;
			}
		}
	}
}

int AVLTree::getMax(NodeT *n){
	if(n->left != NULL && n->right != NULL){
		if(n->left->height > n->right->height){
			return n->left->height;
		}
		else{
			return n->right->height;
		}
	}
	else if(n->left != NULL || n->right != NULL){
		if(n->right != NULL)
			return n->right->height;
		else
			return n->left->height;
	}
	else{
		return 1;
	}
}

NodeT* AVLTree::rotateRight(NodeT *n){
	NodeT *x = n->left;
	NodeT *tmp = x->right;

	cout << endl;
	cout<<"Rotating right around "<<n->word<<endl;
	cout<<"Height of node before: "<<n->word<<": "<<n->height<<endl;
	cout<<"Height of left child before: "<<x->word<<": "<<x->height<<endl;

	x->parent = n->parent;
	x->right = n;
	n->parent = x;
	n->left = tmp;
	if(tmp != NULL){
		tmp->parent = n;
		cout<<n->word<<" left child is: "<<n->left->word<<endl;
	}
	return x;
}

NodeT* AVLTree::rotateLeft(NodeT *n){
	NodeT *x = n->right;
	NodeT *tmp = x->left;

	cout << endl;
	cout<<"Rotating left around "<<n->word<<endl;
	cout<<"Height of node before: "<<n->word<<": "<<n->height<<endl;
	cout<<"Height of right child before: "<<x->word<<": "<<x->height<<endl;

	x->parent = n->parent;
	x->left = n;
	n->parent = x;
	n->right = tmp;
	if(tmp != NULL){
		tmp->parent = n;
		cout<<n->word<<" right child is: "<<n->right->word<<endl;
	}

	return x;
}

int AVLTree::getDiff(NodeT *n){
	int diff = 0;
	if(n->left != NULL && n->right != NULL){
		diff = n->left->height - n->right->height;
	}
	else if(n->left != NULL || n->right != NULL){
		if(n->left != NULL){
			diff = n->left->height;
		}
		else if(n->right != NULL){
			diff = 0 - n->right->height;
		}
	}
	return diff;
}

