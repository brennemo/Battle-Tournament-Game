/*********************************************************************
** Program Filename:	stack.hpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Struct PileNode declaration & 
**					Pile class interface 
*********************************************************************/

#ifndef PILE_HPP
#define PILE_HPP
 
#include "creature.hpp"
#include <iostream>
#include <iomanip>

struct PileNode
{
	Creature* value; 
	PileNode *next;
	PileNode(Creature* value1, PileNode *next1 = NULL)
	{
		value = value1;
		next = next1; 
	}
};

class Pile
{
private:
	PileNode *head;
	int first;
	int second;
	int third; 

public: 
	Pile();
	~Pile();
	void add(Creature*);
	Creature* remove();
	void display() const; 
	void scoreBoard() const;

	int firstPlace();
	int secondPlace();
	int thirdPlace();
	void displayFirst();
	void displaySecond();
	void displayThird();
};

#endif 