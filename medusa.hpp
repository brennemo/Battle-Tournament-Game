/*********************************************************************
** Program Filename:	medusa.hpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Medusa class interface
*********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "creature.hpp"

class Medusa : public Creature
{
public:
	Medusa();
	~Medusa();

	int attack();
	void takeHit(int a, int d);
	void replenish();
};

#endif 