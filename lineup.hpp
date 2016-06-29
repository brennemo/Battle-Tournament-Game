/*********************************************************************
** Program Filename:	lineup.hpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Struct QueueNode declaration &
**					LineUp class interface
*********************************************************************/

#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "creature.hpp"
#include <iostream>
#include <iomanip>

struct QueueNode
{
	Creature* value;
	QueueNode *front;
	QueueNode *rear; 

	QueueNode(Creature* value1, QueueNode *front1 = NULL, QueueNode *rear1 = NULL)
	{
		value = value1; 
		front = front1;
		rear = rear1; 
	}
};

class Lineup
{
private:
	QueueNode *head;

public:
	Lineup();
	~Lineup();
	void add(Creature*);
	Creature* remove();
	void display() const;

	void teamID(int i);
	Creature* get1stInLine();
	Creature* get2ndInLine();

	void scoreBoard() const; 
};

#endif 