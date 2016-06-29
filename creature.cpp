/*********************************************************************
** Program Filename:	creature.cpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Creature class implementation
*********************************************************************/

#include "creature.hpp"

/*********************************************************************
** Function:			Creature::Creature()
** Description:		Default Constructor
*********************************************************************/
Creature::Creature()
{
	int seed = time(0);
	srand(seed);					/*generate random seed with time function*/

	setID("");
	setArmor(0);
	setStrength(0);
	setOriginalStrength(0);

	setAttackDieQ(0);
	setAttackDieS(0);
	setDefenseDieQ(0);
	setDefenseDieS(0);

	setAttackRoll(0);
	setDefenseRoll(0);

	setName("");
	setTeamID(0);
	setScore(0);
}


Creature::Creature(std::string id, int armor, int strength, int aq, int as, int dq, int ds)
{
	int seed = time(0);
	srand(seed);					/*generate random seed with time function*/
	
	setID(id);
	setArmor(armor);
	setStrength(strength);
	setOriginalStrength(strength);

	setAttackDieQ(aq);
	setAttackDieS(as);
	setDefenseDieQ(dq);
	setDefenseDieS(ds);

	setAttackRoll(0);
	setDefenseRoll(0);

	setTeamID(0);
	setScore(0);
}


/*********************************************************************
** Function:			Creature::~Creature()
** Description:		Virtual Destructor
*********************************************************************/
Creature::~Creature()
{

}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int Creature::attack()
{
	int total = 0;
	for (int i = 0; i < this->attackDieQuant; i++)
	{
		total += rand() % this->attackDieSides + 1;
	}
	setAttackRoll(total);
	return this->attackRoll;
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int Creature::defend()
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
** Function:			Creature::setID()
** Description:		Mutator
** Parameters:			std::string id
*********************************************************************/

void Creature::setID(std::string id)
{
	this->id = id;
}


/*********************************************************************
** Function:			Creature::setStrength()
** Description:		Mutator
** Parameters:			int strength
*********************************************************************/
void Creature::setStrength(int strength)
{
	this->strength = strength;
}

/*********************************************************************
** Function:			Creature::setOriginalStrength()
** Description:		Mutator
** Parameters:			int originalStrength
*********************************************************************/
void Creature::setOriginalStrength(int originalStrength)
{
	this->originalStrength = originalStrength;
}


/*********************************************************************
** Function:			Creature::setArmor()
** Description:		Mutator
** Parameters:			int armor
*********************************************************************/
void Creature::setArmor(int armor)
{
	this->armor = armor;
}

/*********************************************************************
** Function:			Creature::setAttackDieQ()
** Description:		Mutator
** Parameters:			int attackDieQuant
*********************************************************************/
void Creature::setAttackDieQ(int attackDieQuant)
{
	this->attackDieQuant = attackDieQuant;
}

void Creature::setAttackDieS(int attackDieSides)
{
	this->attackDieSides = attackDieSides;
}

void Creature::setDefenseDieQ(int defenseDieQuant)
{
	this->defenseDieQuant = defenseDieQuant;
}

void Creature::setDefenseDieS(int defenseDieSides)
{
	this->defenseDieSides = defenseDieSides;
}


void  Creature::setAttackRoll(int attackRoll)
{
	this->attackRoll = attackRoll;
}

void  Creature::setDefenseRoll(int defenseRoll)
{
	this->defenseRoll = defenseRoll;
}

int Creature::getAttackRoll() const
{
	return this->attackRoll;
}

int Creature::getDefenseRoll() const
{
	return this->defenseRoll;
}

/*********************************************************************
** Function:			Creature::getID() const
** Description:		Accessor
*********************************************************************/
std::string Creature::getID() const
{
	return this->id;
}


/*********************************************************************
** Function:			Creature::getArmor() const
** Description:		Accessor
*********************************************************************/
int Creature::getArmor() const
{
	return this->armor;
}


/*********************************************************************
** Function:			Creature::getStrength() const
** Description:		Accessor
*********************************************************************/
int Creature::getStrength() const
{
	return this->strength;
}

int Creature::getOriginalStrength() const
{
	return this->originalStrength;
}


void Creature::setName(std::string name)
{
	this->name = name;
}


std::string Creature::getName() const
{
	return this->name;
}


void Creature::setTeamID(int teamID)
{
	this->teamID = teamID;
}

int Creature::getTeamID() const
{
	return this->teamID;
}

void Creature::setScore(int score)
{
	this->score = score;
}

int Creature::getScore() const
{
	return this->score; 
}


void Creature::incScore()
{
	this->score += 1; 
}