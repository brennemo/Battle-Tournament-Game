/*********************************************************************
** Program Filename:	vampire.cpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Vampire class interface
*********************************************************************/

#include "vampire.hpp"

/*********************************************************************
** Function:			Vampire::Vampire()
** Description:		Constructor
*********************************************************************/
Vampire::Vampire()
	: Creature("Vampire", 1, 18, 1, 12, 1, 6)
{

}


/*********************************************************************
** Function:			Vampire::~Vampire()
** Description:		Destructor 
*********************************************************************/
Vampire::~Vampire()
{

}


/*********************************************************************
** Function:			Vampire::defend()
** Description:		1d6
** Pre-Conditions:		Strength points > 0
** Post-Conditions:		returns int total
*********************************************************************/
int Vampire::defend()
{
	int total = 0;
	for (int i = 0; i < this->defenseDieQuant; i++)
	{
		total += rand() % this->defenseDieSides + 1;
	}
	setDefenseRoll(total);
	return this->defenseRoll;
}


/*********************************************************************
** Function:			Vampire::takeHit()
** Description:		Reduces strength points by
**					(attack - defense) - armor
** Parameters:			int a, int d
** Pre-Conditions:		attack roll > defense roll
*********************************************************************/
void Vampire::takeHit(int a, int d)
{	
	int charm = rand() % 2 + 1;						/*50% chance of charm*/
	if (charm == 2)
	{
		/*discard negative hp with armor - don't add points*/
		int hit = (a - d) - this->getArmor();
		if (hit > 0)
		{
			this->strength -= hit;
		}
	}
	else 
	{
		std::cout << std::endl << "Opponent charmed out of attack! No hit taken." << std::endl;
	}
}


/*********************************************************************
** Function:			Vampire::replenish()
** Description:		Restores 50% of points lost during round
** Pre-Conditions:		strength > 0
*********************************************************************/
void Vampire::replenish()
{
	int HP;
	HP = this->getOriginalStrength() - this->strength;

	if (HP > 0)
	{
		HP = (HP / 2);
		this->setStrength(HP);
	}
}