/*
 * LL.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: SK
 */


#include "LL.hpp"
#include "NodeL.hpp"
#include <iostream>
using namespace std;

LL::LL(){
	first = NULL;
	last = NULL;
	size = 0;
	score = 0;
}


void LL::push(string s){
	NodeL *n = new NodeL(s);
	last->next = n;
	last = n;
	size++;
}

void LL::addFirst(string s){
	NodeL *n = new NodeL(s);
	first = n;
	last = n;
	size++;
}

void LL::printList(){
	NodeL *tmp = first;
	while (tmp != NULL){
		if(tmp != last){
			cout<<tmp->word<<", ";
		}
		else{
			cout<<tmp->word;
		}
		tmp = tmp->next;
	}
	cout<<endl;
}

void LL::getScore(){
	NodeL *tmp = first;
	while (tmp != NULL){
		score += tmp->wscore;
		tmp = tmp->next;
	}
}
