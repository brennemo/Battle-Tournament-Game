/*********************************************************************
** Program Filename:	stack.hpp
** Author:			Morgan Brenner
** Date:				02/28/2016
** Description:		Pile class implementation
*********************************************************************/

#include "pile.hpp"

Pile::Pile()
{
	head = NULL;
}

Pile::~Pile()
{
	PileNode *nodePtr = head;
	while (nodePtr != NULL)
	{
		/*
		**traverse from head to end of
		**list and remove each node
		*/
		PileNode *removeNode = nodePtr;
		nodePtr = nodePtr->next;
		delete removeNode;
	}
}			   

/*********************************************************************
** Function:			Pile::add() 
** Description:		Adds integer to end of PileNode list 
** Parameters:			Creature* i
*********************************************************************/
void Pile::add(Creature* i)
{
	/*point head to new StackNode if node is empty*/
	if (head == NULL)
		head = new PileNode(i);

	/*traverse list from head to rear of "stack"*/
	else
	{
		PileNode *nodePtr = head;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;

		/*at rear of "queue," add new StackNode*/
		nodePtr->next = new PileNode(i);
	}
}

/*********************************************************************
** Function:			Pile::remove()
** Description:		Removes last integer from PileNode list
**					and returns pointer to Creature removed
*********************************************************************/
Creature* Pile::remove()
{
	/*if list is empty, return 0*/
	if (head == NULL)
		return 0;
	else
	{
		/*traverse list to end*/
		PileNode *lastPtr = head;
		PileNode *penultimatePtr = lastPtr;

		if (head->next == NULL)			/*if there is only one element left*/
		{
			PileNode *nodePtr = head;
			head = head->next;

			Creature* returnVal = nodePtr->value;
			delete nodePtr;

			return  returnVal;
		}

		else 
		{
			while (lastPtr->next != NULL)
			{
				penultimatePtr = lastPtr;
				lastPtr = lastPtr->next;
			}
			/*
			** make 2nd last node last, and delete last ptr and
			** store value of last element before deleting, to return
			*/										
			penultimatePtr->next = lastPtr->next;				/*2nd last ptr's next == NULL*/
			Creature* returnVal = lastPtr->value;
			delete lastPtr;

			return  returnVal; 
		}
	}
}	

/*********************************************************************
** Function:			Pile::display()
** Description:		Displays name and ID of each Creature in  
**					PileNode list
*********************************************************************/
void Pile::display() const
{
	PileNode *nodePtr = head;
	if (head != NULL)
	{
		int count = 1; 
		while (nodePtr)
		{
			std::cout << count << ".";
			std::cout << nodePtr->value->getName() << " the ";
			std::cout << nodePtr->value->getID() << " " << std::endl;
			nodePtr = nodePtr->next;
			count++;
		}
		std::cout << std::endl << std::endl;

	}
}


/*********************************************************************
** Function:			Pile::scoreBoard() const
** Description:		Displays name, ID, team, armor, strength, 
**					and score of each Creature in PileNode list
*********************************************************************/
void Pile::scoreBoard() const
{
	PileNode *nodePtr = head;
	if (head != NULL)
	{
		int count = 1;
		while (nodePtr)
		{
			std::cout << count << std::setw(4) << std::left << "."
				<< std::left << nodePtr->value->getName() << " the "
				<< nodePtr->value->getID() << ": " << std::endl
				<< std::setw(15) << std::left << "Team: "
				<< std::setw(4) << std::right << nodePtr->value->getTeamID() << std::endl
				<< std::setw(15) << std::left << "Armor: "
				<< std::setw(4) << std::right << nodePtr->value->getArmor() << std::endl
				<< std::setw(15) << std::left << "Strength: "
				<< std::setw(4) << std::right << nodePtr->value->getStrength() << std::endl
				<< std::setw(15) << std::left << "Score: "
				<< std::setw(4) << std::right << nodePtr->value->getScore() << std::endl;
			nodePtr = nodePtr->next;
			count++;
		}
		std::cout << std::endl << std::endl;

	}
}


/*********************************************************************
** Function:			Pile::firstPlace()
** Description:		Determines & returns highest score in Pile
*********************************************************************/
int Pile::firstPlace()
{
	PileNode *nodePtr = head;
	int max = nodePtr->value->getScore();
	if (head != NULL)
	{
		while (nodePtr)
		{
			if (nodePtr->value->getScore() > max)
			{
				max = nodePtr->value->getScore();
			}

			nodePtr = nodePtr->next;
		}
	}
	first = max; 
	return first;
}


/*********************************************************************
** Function:			Pile::secondPlace()
** Description:		Determines & returns 2nd highest score in Pile
** Pre-Conditions:		first determined 
*********************************************************************/
int Pile::secondPlace()
{
	PileNode *nodePtr = head;
	int max = nodePtr->value->getScore();
	if (head != NULL)
	{
		while (nodePtr)
		{
			if ((nodePtr->value->getScore() > max) && (nodePtr->value->getScore() < first))
			{
				max = nodePtr->value->getScore();
			}

			nodePtr = nodePtr->next;
		}
	}
	second = max;
	return second;
}


/*********************************************************************
** Function:			Pile::thirdPlace()
** Description:		Determines & returns 3rd highest score in Pile
** Pre-Conditions:		first and second determined
*********************************************************************/
int Pile::thirdPlace()
{
	PileNode *nodePtr = head;
	int max = nodePtr->value->getScore();
	if (head != NULL)
	{
		while (nodePtr)
		{
			if ((nodePtr->value->getScore() > max) && (nodePtr->value->getScore() < second))
			{
				max = nodePtr->value->getScore();
			}

			nodePtr = nodePtr->next;
		}
	}
	third = max;
	return third;
}


/*********************************************************************
** Function:			Pile::displayFirst()
** Description:		Displays name and ID of each Creature with 
**					the #1 highest score				
*********************************************************************/
void Pile::displayFirst()
{
	PileNode *nodePtr = head;
	if (head != NULL)
	{
		while (nodePtr)
		{
			if (nodePtr->value->getScore() == first)
			{
				std::cout << nodePtr->value->getName() << " the ";
				std::cout << nodePtr->value->getID() << " " << std::endl;
			}
			nodePtr = nodePtr->next;

		}
		std::cout << std::endl << std::endl;

	}
}


/*********************************************************************
** Function:			Pile::displaySecond()
** Description:		Displays name and ID of each Creature with
**					the #2 highest score
*********************************************************************/
void Pile::displaySecond()
{
	PileNode *nodePtr = head;
	if (head != NULL)
	{
		while (nodePtr)
		{
			if (nodePtr->value->getScore() == second)
			{
				std::cout << nodePtr->value->getName() << " the ";
				std::cout << nodePtr->value->getID() << " " << std::endl;
			}
			nodePtr = nodePtr->next;

		}
		std::cout << std::endl << std::endl;

	}
}


/*********************************************************************
** Function:			Pile::displayThird()
** Description:		Displays name and ID of each Creature with
**					the #3 highest score
*********************************************************************/
void Pile::displayThird()
{
	PileNode *nodePtr = head;
	if (head != NULL)
	{
		while (nodePtr)
		{
			if (nodePtr->value->getScore() == third)
			{
				std::cout << nodePtr->value->getName() << " the ";
				std::cout << nodePtr->value->getID() << " " << std::endl;
			}
			nodePtr = nodePtr->next;

		}
		std::cout << std::endl << std::endl;

	}
}
