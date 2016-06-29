/*********************************************************************
** Program Filename:	barbarian.cpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Barbarian class implementation
*********************************************************************/
#include "barbarian.hpp"

/*********************************************************************
** Function:			Barbarian::Barbarian()
** Description:		Constructor
*********************************************************************/
Barbarian::Barbarian()
	: Creature("Barbarian", 0, 12, 2, 6, 2, 6)
{

}


/*********************************************************************
** Function:			Barbarian::~Barbarian()
** Description:		Destructor 
*********************************************************************/
Barbarian::~Barbarian()
{

}


/*********************************************************************
** Function:			Barbarian::takeHit()
** Description:		Reduces strength points by
**					(attack - defense) - armor
** Parameters:			int hp
** Pre-Conditions:		attack roll > defense roll
*********************************************************************/
void Barbarian::takeHit(int a, int d)
{
	/*discard negative hp with armor - don't add points*/

	int hit = (a - d) - this->getArmor();
	if (hit > 0)
	{
		this->strength -= hit;
	}
}


/*********************************************************************
** Function:			Barbarian::replenish()
** Description:		Restores 50% of points lost during round
** Pre-Conditions:		strength > 0
*********************************************************************/
void Barbarian::replenish()
{
	int HP;
	HP = this->getOriginalStrength() - this->strength;

	if (HP > 0)
	{
		HP = (HP / 2);
		this->setStrength(HP);
	}
}
