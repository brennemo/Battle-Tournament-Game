/*********************************************************************
** Program Filename:	vampire.hpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Vampire class interface
*********************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "creature.hpp"

class Vampire : public Creature
{
public:
	Vampire();
	~Vampire();

	int defend();
	void takeHit(int a, int d);
	void replenish();
};

#endif 