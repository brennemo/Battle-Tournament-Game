/*********************************************************************
** Program Filename:	barbarian.hpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Barbarian class interface
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "creature.hpp"

class Barbarian : public Creature
{
public:
	Barbarian();
	~Barbarian();

	void takeHit(int a, int d);
	void replenish();
};

#endif 