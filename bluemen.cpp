/*********************************************************************
** Program Filename:	bluemen.cpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		BlueMen class implementation
*********************************************************************/
#include "bluemen.hpp"

/*********************************************************************
** Function:		BlueMen::BlueMen()
** Description:	Constructor
*********************************************************************/
BlueMen::BlueMen()

	: Creature("Blue Men", 3, 12, 2, 6, 3, 6)
{

}


/*********************************************************************
** Function:			BlueMen::~BlueMen()
** Description:		Destructor
*********************************************************************/
BlueMen::~BlueMen()
{

}


/*********************************************************************
** Function:			BlueMen::takeHit()
** Description:		Reduces strength points by
**					(attack - defense) - armor
** Parameters:			int hp
** Pre-Conditions:		attack roll > defense roll
*********************************************************************/

void BlueMen::takeHit(int a, int d)
{
	/*discard negative hp with armor - don't add points*/
	int hit = (a - d) - this->getArmor();
	if (hit > 0)
	{
		this->strength -= hit;
	}

	/*UPDATE # OF DEFENSE DICE*/
	if (this->getStrength() == 8)
	{
		this->setDefenseDieQ(2);
	}

	if (this->getStrength() == 4)
	{
		this->setDefenseDieQ(1);
	}
}


/*********************************************************************
** Function:			BlueMen::replenish()
** Description:		Restores 50% of points lost during round
** Pre-Conditions:		strength > 0
*********************************************************************/
void BlueMen::replenish()
{
	int HP;
	HP = this->getOriginalStrength() - this->strength;

	if (HP > 0)
	{
		HP = (HP / 2);
		this->setStrength(HP);
	}
}