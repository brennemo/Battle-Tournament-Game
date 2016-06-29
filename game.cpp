/*********************************************************************
** Program Filename:	game.cpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Game class interface
** Input:				pointers to Creature objects 
** Output:			Rounds of game and final scores
*********************************************************************/
#include "game.hpp"

/*********************************************************************
** Function:			Game::Game()
** Description:		Constructor
*********************************************************************/
Game::Game()
{
	round = 1;
}


/*********************************************************************
** Function:			Game::~Game()
** Description:		Destructor 
*********************************************************************/
Game::~Game()
{

}


/*********************************************************************
** Function:			fillQ1()
** Description:		Prompts user for type of creature, name of
**					each creature, and adds to LineUp q1 
** Pre-Conditions:		num of creatures on each team entered by user		
** Post-Conditions:		n Creatures of type selected by user added 
**					to LineUp q1 
*********************************************************************/
void Game::fillQ1()
{
	for (int j = 0; j < 40; j++)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "Create Team 1:" << std::endl;
	
	std::cout << "1: Barbarian" << std::endl;		
	std::cout << "2: Blue Men" << std::endl;
	std::cout << "3: Harry Potter" << std::endl;
	std::cout << "4: Medusa" << std::endl;
	std::cout << "5: Vampire" << std::endl;

	int creat;
	Creature* c1;				/*placeholder pointer variable to add Creatures to queue*/
	/*
	** Prompt user for type and name of each creature on Team 1
	*/
	for (int i = 0; i < num; i++)
	{
		std::cout << "Enter # of type of creature #" << (i + 1) << ": ";
		std::cin >> creat;
		if (creat == 1)
		{
			c1 = new Barbarian;
			q1.add(c1);
			promptName(c1);
		}
		else if (creat == 2)
		{
			c1 = new BlueMen;
			q1.add(c1);
			promptName(c1);
		}
		else if (creat == 3)
		{
			c1 = new HarryPotter;
			q1.add(c1);
			promptName(c1);
		}
		else if (creat == 4)
		{
			c1 = new Medusa;
			q1.add(c1);
			promptName(c1);
		}
		else if (creat == 5)
		{
			c1 = new Vampire;
			q1.add(c1);
			promptName(c1);
		}
		/*default to Barbarian if input is invalid*/
		else	if ((creat != 1) && (creat != 2) && (creat != 3) && (creat != 4) && (creat != 5))
		{
			c1 = new Barbarian;
			q1.add(c1);
			promptName(c1);
		}
	}
	std::cout << std::endl;
	std::cout << "Team 1 Roster:" << std::endl;
	q1.display();
}


/*********************************************************************
** Function:			fillQ2()
** Description:		Prompts user for type of creature, name of
**					each creature, and adds to LineUp q2
** Pre-Conditions:		num of creatures on each team entered by user
** Post-Conditions:		n Creatures of type selected by user added
**					to LineUp q2
*********************************************************************/
void Game::fillQ2()
{
	for (int j = 0; j < 40; j++)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "Create Team 2:" << std::endl;

	std::cout << "1: Barbarian" << std::endl;
	std::cout << "2: Blue Men" << std::endl;
	std::cout << "3: Harry Potter" << std::endl;
	std::cout << "4: Medusa" << std::endl;
	std::cout << "5: Vampire" << std::endl;

	int creat;
	Creature* c1;			/*placeholder pointer variable to add Creatures to queue*/
	/*
	** Prompt user for type and name of each creature on Team 2
	*/
	for (int i = 0; i < num; i++)
	{
		std::cout << "Enter # of type of creature #" << (i + 1) << ": ";
		std::cin >> creat;
		
		if (creat == 1)
		{
			c1 = new Barbarian;
			q2.add(c1);
			promptName(c1);
		}
		else if (creat == 2)
		{
			c1 = new BlueMen;
			q2.add(c1);
			promptName(c1);
		}
		else if (creat == 3)
		{
			c1 = new HarryPotter;
			q2.add(c1);
			promptName(c1);
		}
		else if (creat == 4)
		{
			c1 = new Medusa;
			q2.add(c1);
			promptName(c1);
		}
		else if (creat == 5)
		{
			c1 = new Vampire;
			q2.add(c1);
			promptName(c1);
		}
		/*default to Barbarian if input is invalid*/
		else	if ((creat != 1) && (creat != 2) && (creat != 3) && (creat != 4) && (creat != 5))
		{
			c1 = new Barbarian;
			q2.add(c1);
			promptName(c1);
		}  
	}
	std::cout << std::endl;
	std::cout << "Team 2 Roster:" << std::endl;
	q2.display();
}


/*********************************************************************
** Function:			Game::promptNum()
** Description:		Gets number of Creatures on each team, > 3,
**					from user and stores in class attribute num
*********************************************************************/
void Game::promptNum()
{
	std::cout << "Enter number of fighters on each team (>= 3): "; 
	std::cin >> num;
	std::cout << std::endl;

	while (num < 3)			//user input control: at least 3 per team 
	{
		std::cout << "ERROR: Teams must have at least 3 fighters." << std::endl;
		std::cout << "Enter number of fighters on each team (>= 3): ";
		std::cin >> num;
		std::cout << std::endl;
	}
}


/*********************************************************************
** Function:			Game::promptName()
** Description:		Prompts user for name of Creature, and sets it
** Parameters:			Creature* c
** Pre-Conditions:		fillQ1 or fillQ2 called
** Post-Conditions:		name of Creature set to user input
*********************************************************************/
void Game::promptName(Creature* c)
{
	std::string name;
	std::cout << "Enter name: "; 
	std::cin >> name;
	c->setName(name);

}


/*********************************************************************
** Function:			Game::fight12()
** Description:		Front of Team 1 LineUp attacks front of Team 2
** Pre-Conditions:		Teams set with fillQ1() and fillQ2(), front of 
**					each queue's strength > 0
** Post-Conditions:		Front of Team 2 takes hit if net attack 
**					(after defense and armor) is > 0
*********************************************************************/
void Game::fight12()
{
	int attack;
	int defense;

	/*Print attacker's name, ID, and value of attack*/
	std::cout << q1.get1stInLine()->getName() << " the "
		<< q1.get1stInLine()->getID() << " Attacks: ";
	attack = q1.get1stInLine()->attack();
	std::cout << attack << std::endl;

	/*Print defender's name, ID, and value of defense*/
	std::cout << q2.get1stInLine()->getName() << " the "
		<< q2.get1stInLine()->getID() << " Defends: ";
	defense = q2.get1stInLine()->defend();
	std::cout << defense << std::endl;

	/*
	** If attack > defense, and hit is taken (i.e. attack > defense + armor),
	** Net attack subtracted from q2's strength
	*/
	if (attack > defense)
	{
		int oldStrength;
		oldStrength = q2.get1stInLine()->getStrength();

		q2.get1stInLine()->takeHit(attack, defense);
	
		/*if there is change in strength*/
		if (((attack - defense) - q2.get1stInLine()->getArmor() > 0) && (oldStrength != q2.get1stInLine()->getStrength()))	
		{
			std::cout << q2.get1stInLine()->getName() << " the "
				<< q2.get1stInLine()->getID() << "'s strength reduced from " << oldStrength
				<< " to " << q2.get1stInLine()->getStrength() << std::endl << std::endl;

			q1.get1stInLine()->incScore();						/*increment score for attacker*/
		}
		else
		{
			std::cout << "No hit taken." << std::endl << std::endl;
		}
	}
	else
	{
		std::cout << "No hit taken." << std::endl << std::endl;
	}
}


/*********************************************************************
** Function:			Game::fight21()
** Description:		Front of Team 2 LineUp attacks front of Team 2
** Pre-Conditions:		Teams set with fillQ1() and fillQ2(), front of
**					each queue's strength > 0
** Post-Conditions:		Front of Team 1 takes hit if net attack
**					(after defense and armor) is > 0
*********************************************************************/
void Game::fight21()
{
	int attack;
	int defense;

	/*Print attacker's name, ID, and value of attack*/
	std::cout << q2.get1stInLine()->getName() << " the "
		<< q2.get1stInLine()->getID() << " Attacks: ";
	attack = q2.get1stInLine()->attack();
	std::cout << attack << std::endl;

	/*Print defender's name, ID, and value of defense*/
	std::cout << q1.get1stInLine()->getName() << " the "
		<< q1.get1stInLine()->getID() << " Defends: ";
	defense = q1.get1stInLine()->defend();
	std::cout << defense << std::endl;
	
	/*
	** If attack > defense, and hit is taken (i.e. attack > defense + armor),
	** Net attack subtracted from q1's strength
	*/
	if (attack > defense)									//if net attack before armor is > 0, 
	{
		int oldStrength;									//holds strength before takehit() 
		oldStrength = q1.get1stInLine()->getStrength();

		q1.get1stInLine()->takeHit(attack, defense);
		
		/*if there is change in strength*/
		if (((attack - defense) - q1.get1stInLine()->getArmor() > 0) && (oldStrength != q1.get1stInLine()->getStrength()))		
		{ 
			std::cout << q1.get1stInLine()->getName() << " the "
				<< q1.get1stInLine()->getID() << "'s strength reduced from " << oldStrength 
				<< " to " << q1.get1stInLine()->getStrength() << std::endl << std::endl;

			q2.get1stInLine()->incScore();					/*increment score for attacker*/
		}
		else
		{
			std::cout << "No hit taken." << std::endl << std::endl;
		}
	}
	else
	{
		std::cout << "No hit taken." << std::endl << std::endl;
	}
}
   

/*********************************************************************
** Function:			Game::moveToLoserPile()
** Description:		Checks Team of Creature, adds to pile, and 
**					removes from appropriate lineup
** Parameters:			Creature* c
** Pre-Conditions:		Creature's strength <= 0
** Post-Conditions:		Creature removed from lineup, added to pile
*********************************************************************/
void Game::moveToLoserPile(Creature* c)
{
	s1.add(c);					/*add to pile*/
	
	int id = c->getTeamID();
	if (id == 1)
	{
		q1.remove();				/*remove from lineup*/
		std::cout << c->getName() << " the " << c->getID() <<  " removed from Team 2 and added to loser pile." 
			<< std::endl << std::endl;
	}
	else if (id == 2)
	{
		q2.remove();				/*remove from lineup*/
		std::cout << c->getName() << " the " << c->getID() << " removed from Team 2 and added to loser pile." 
			<< std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl << std::endl;
	}
}


/*********************************************************************
** Function:			Game::moveToLoserPileNoDisplay()
** Description:		Checks Team of Creature, adds to pile, and
**					removes from appropriate lineup, without 
**					printing
** Parameters:			Creature* c
** Pre-Conditions:		Creature's strength <= 0
** Post-Conditions:		Creature removed from lineup, added to pile
*********************************************************************/
void Game::moveToLoserPileNoDisplay(Creature* c)
{
	s1.add(c);			/*add to pile*/

	int id = c->getTeamID();
	if (id == 1)
	{
		q1.remove();		/*remove from lineup*/
	}
	else if (id == 2)
	{
		q2.remove();		/*remove from lineup*/
	}
}

/*********************************************************************
** Function:			Game::runGame()
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::runGame()
{
	promptNum();

	/*
	** Fill Teams and print names & IDs of each
	*/
	fillQ1();
	q1.teamID(1);
	fillQ2();
	q2.teamID(2);

	/*
	** Run Game until one team has only one member left in line up
	*/
	do
	{
		/*
		** Print round and name & ID of opponents
		*/
		for (int j = 0; j < 40; j++)
			std::cout << "*";
		std::cout << std::endl;

		std::cout << "Round " << round << std::endl; 

		std::cout << q1.get1stInLine()->getName() << " the " << q1.get1stInLine()->getID() << " vs "
			<< q2.get1stInLine()->getName() << " the " << q2.get1stInLine()->getID() << std::endl;
		
		/*
		** Front of Team 1 attacks front of Team 2, and front of Team 2
		** added to loser pile if strength hits 0 or below
		*/
		fight12();
		if (q2.get1stInLine()->getStrength() <= 0)
		{
			fightRing[1] = q2.get1stInLine();
			moveToLoserPile(fightRing[1]);
		}

		/*
		** Front of Team 2 attacks front of Team 1, and front of Team 1
		** added to loser pile if strength hits 0 or below
		*/
		fight21();
		if (q1.get1stInLine()->getStrength() <= 0)
		{
			fightRing[0] = q1.get1stInLine();
			moveToLoserPile(fightRing[0]);
		}
		

		/*Replenish 50% of winner's lost HP & move to end of queue*/
		if (q1.get1stInLine() != NULL)			
		{
			q1.get1stInLine()->replenish(); 

			fightRing[0] = q1.get1stInLine();		/*temp array index for moving from line up to pile*/
			q1.add(fightRing[0]);
			q1.remove();
		}
		
		if (q2.get1stInLine() != NULL)			
		{
			q1.get1stInLine()->replenish();

			fightRing[1] = q2.get1stInLine();		/*temp array index for moving from line up to pile*/
			q2.add(fightRing[1]);
			q2.remove();
		}
		round++;
	} while ((q1.get2ndInLine() != NULL) && (q2.get2ndInLine() != NULL));

	/*DISPLAY TEAM 1*/
	if (q1.get1stInLine() != NULL)
	{
		for (int j = 0; j < 40; j++)
			std::cout << "*";
		std::cout << std::endl;

		std::cout << "Team 1: " << std::endl;

		for (int k = 0; k < 40; k++)
			std::cout << "*";
		std::cout << std::endl;

		q1.scoreBoard();
	}

    /*DISPLAY TEAM 2*/
	if (q2.get1stInLine() != NULL)
	{
		for (int j = 0; j < 40; j++)
			std::cout << "*";
		std::cout << std::endl;

		std::cout << "Team 2: " << std::endl;

		for (int k = 0; k < 40; k++)
			std::cout << "*";
		std::cout << std::endl;

		q2.scoreBoard();
	}

	/*DISPLAY LOSER PILE*/
	for (int j = 0; j < 40; j++)
		std::cout << "*";
	std::cout << std::endl;

	std::cout << "Loser Pile: " << std::endl;

	for (int k = 0; k < 40; k++)
		std::cout << "*";	   
	std::cout << std::endl;

	s1.scoreBoard();
	std::cout << round << " rounds played." << std::endl << std::endl;
	/*
	** Display winning team 
	*/
	if (q1.get2ndInLine() != NULL)
	{
		std::cout << "Team 1 Wins!" << std::endl; 
	}
	else if (q2.get2ndInLine() != NULL)
	{
		std::cout << "Team 2 Wins!" << std::endl;
	}

	/*
	** Calculate & Display highest scores:
	*/ 

	/*Move remaining Creatures in q1 to s1*/
	while (q1.get1stInLine() != NULL)
	{
		for (int i = 0; i < 5; i++)
		{
			q1.get1stInLine()->incScore();
		} 
		std::cout << std::endl << q1.get1stInLine()->getName() << " the " << q1.get1stInLine()->getID() << "'s score increased by 5 for surviving battle." << std::endl
			<< "New Score: " << q1.get1stInLine()->getScore() << std::endl;

		fightRing[0] = q1.get1stInLine();
		moveToLoserPileNoDisplay(fightRing[0]);
	}

	/*Move remaining Creatures in q2 to s1*/
	while (q2.get1stInLine() != NULL)
	{
		for (int i = 0; i < 5; i++)
		{
			q2.get1stInLine()->incScore();
		}
		std::cout << std::endl << q2.get1stInLine()->getName() << " the " << q2.get1stInLine()->getID() << "'s score increased by 5 for surviving battle." << std::endl
			<< "New Score: " << q2.get1stInLine()->getScore() << std::endl;
		
		fightRing[1] = q2.get1stInLine();
		moveToLoserPileNoDisplay(fightRing[1]);
	}

	for (int j = 0; j < 40; j++)
		std::cout << "*";
	std::cout << std::endl;

	/*Store high scores*/
	std::cout << "Top 3 Fighters: " << std::endl;
	firstPlace = s1.firstPlace();
	secondPlace = s1.secondPlace();
	thirdPlace = s1.thirdPlace();

	/*Display # 1*/
	std::cout << "First Place: " << std::endl;
	std::cout << "(Score = " << firstPlace << ")" << std::endl;
	s1.displayFirst();

	/*Display # 2*/
	std::cout << "Second Place: " << std::endl;
	std::cout << "(Score = " << secondPlace << ")" << std::endl;
	s1.displaySecond();

	/*Display # 3*/
	std::cout << "Third Place: " << std::endl;
	std::cout << "(Score = " << thirdPlace << ")" << std::endl;
	s1.displayThird();
}
