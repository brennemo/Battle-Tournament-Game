/*********************************************************************
** Program Filename:	bluemen.hpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		BlueMen class interface
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "creature.hpp"

class BlueMen : public Creature
{
public:
	BlueMen();
	~BlueMen();

	void takeHit(int a, int d);
	void replenish();
};

#endif 