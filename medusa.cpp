/*********************************************************************
** Program Filename:	medusa.cpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Medusa class implementation
*********************************************************************/
#include "medusa.hpp"

/*********************************************************************
** Function:			Medusa::Medusa()
** Description:		Constructor
*********************************************************************/
Medusa::Medusa()
	: Creature("Medusa", 3, 8, 2, 6, 1, 6)
{
	
}


/*********************************************************************
** Function:			Medusa::~Medusa()
** Description:		Destructor
*********************************************************************/
Medusa::~Medusa()
{

}


/*********************************************************************
** Function:			Medusa::attack()
** Description:	     Returns sum of 2 d6 rolls
** Pre-Conditions:		Strength points > 0
*********************************************************************/
int Medusa::attack()
{
	int total = 0;
	for (int i = 0; i < this->attackDieQuant; i++)
	{
		total += rand() % this->attackDieSides + 1;
	}
	
	/*Medusa's Glare*/
	if (total == 12)
	{
		total = 100;
		std::cout << std::endl << "Medusa's Glare! Opponent automatically defeated." << std::endl << std::endl;
	}
	
	setAttackRoll(total);
	return this->attackRoll;
}


/*********************************************************************
** Function:			Medusa::takeHit()
** Description:		Reduces strength points by
**					(attack - defense) - armor
** Parameters:			int hp
** Pre-Conditions:		attack roll > defense roll
*********************************************************************/

void Medusa::takeHit(int a, int d)
{
	/*discard negative hp with armor - don't add points*/
	int hit = (a - d) - this->getArmor();
	if (hit > 0)
	{
		this->strength -= hit;
	}

	/*
	if ((a - d) - this->getArmor() > 0)
	this->strength -= ((a - d) + this->getArmor());
	*/
	//else
	//	std::cout << "No hit taken." << std::endl << std::endl;
}   


/*********************************************************************
** Function:			Medusa::replenish()
** Description:		Restores 50% of points lost during round
** Pre-Conditions:		strength > 0
*********************************************************************/
void Medusa::replenish()
{
	int HP;
	HP = this->getOriginalStrength() - this->strength;

	if (HP > 0)
	{
		HP = (HP / 2);
		this->setStrength(HP);
	}
}