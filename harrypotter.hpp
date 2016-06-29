/*********************************************************************
** Program Filename:	harrypotter.hpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		HarryPotter class interface
*********************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "creature.hpp"

class HarryPotter : public Creature
{
protected:
	std::string charName;
	int hwChance;

public:
	HarryPotter();
	~HarryPotter();

	void takeHit(int a, int d);
	void hogwarts();
	void replenish();
};

#endif 	   