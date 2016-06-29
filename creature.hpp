/*********************************************************************
** Program Filename:	creature.hpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Creature class interface
*********************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP	

#include <cstdlib>				
#include <ctime>

#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Creature
{
protected:
	std::string id;
	int armor;
	int strength;
	int originalStrength;

	int attackDieQuant;
	int attackDieSides;
	int defenseDieQuant;
	int defenseDieSides;

	int attackRoll;
	int defenseRoll;

	std::string name;
	int teamID;
	int score;

public:
	Creature();
	Creature(std::string id, int armor, int strength, int aq, int as, int dq, int ds);
	virtual ~Creature();   

	virtual int attack();
	virtual int defend();

	virtual void takeHit(int a, int d) = 0;
	virtual void replenish() = 0;

	void setID(std::string id);
	void setStrength(int strength);
	void setArmor(int armor);
	void setOriginalStrength(int originalStrength);

	void setAttackDieQ(int attackDieQuant);
	void setAttackDieS(int attackDieSides);
	void setDefenseDieQ(int defenseDieQuant);
	void setDefenseDieS(int defenseDieSides);

	void setAttackRoll(int attackRoll);
	void setDefenseRoll(int defenseRoll);
	int getAttackRoll() const;
	int getDefenseRoll() const;

	std::string getID() const;
	int getArmor() const;
	int getStrength() const;
	int getOriginalStrength() const; 

	void setName(std::string name);
	std::string getName() const;

	void setTeamID(int teamID);
	int getTeamID() const;

	void setScore(int score);
	int getScore() const;
	void incScore();
};

#endif 