/*********************************************************************
** Program Filename:	harrypotter.cpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		HarryPotter class implementation
*********************************************************************/
#include "harrypotter.hpp"

/*********************************************************************
** Function:		HarryPotter::HarryPotter()
** Description:	Constructor
*********************************************************************/
HarryPotter::HarryPotter()
	: Creature("Harry Potter", 0, 10, 2, 6, 2, 6)
{
	hwChance = 1;
}


/*********************************************************************
** Function:			HarryPotter::~HarryPotter()
** Description:		Destructor deallocates memory allocated to
**					arrays of pointers to Die
*********************************************************************/
HarryPotter::~HarryPotter()
{

}


/*********************************************************************
** Function:			HarryPotter::takeHit()
** Description:		Reduces strength points by
**					(attack - defense) - armor,
**					then calls hogwarts()
** Parameters:			int hp
** Pre-Conditions:		attack roll > defense roll
*********************************************************************/
void HarryPotter::takeHit(int a, int d)
{
	/*discard negative hp with armor - don't add points*/

	int hit = (a - d) - this->getArmor();
	if (hit > 0)
	{
		this->strength -= hit;
	}

	hogwarts();
}


/*********************************************************************
** Function:		HarryPotter::hogwarts()
** Description:	Brings Harry Potter back to life with 20 strength
**				points
** Pre-Conditions:  strength points <= 0
** Post-Conditions: Harry has 20 strength points and no more chances to
**				use Hogwarts
*********************************************************************/
void HarryPotter::hogwarts()
{
	if ((strength <= 0) && (hwChance == 1))
	{
		strength = 20;
		hwChance -= 1;		/*subtract 1 from hwChance; will not be replenished*/
		std::cout << "Harry Potter has returned with 20 strength points!" << endl;
	}
}


/*********************************************************************
** Function:			HarryPotter::replenish()
** Description:		Restores 50% of points lost during round
** Pre-Conditions:		strength > 0
*********************************************************************/
void HarryPotter::replenish()
{
	int HP;
	HP = this->getOriginalStrength() - this->strength;

	if (HP > 0)
	{
		HP = (HP / 2);
		this->setStrength(HP);
	}
}
