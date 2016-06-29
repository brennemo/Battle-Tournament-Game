/*********************************************************************
** Program Filename:		lineup.cpp
** Author:				Morgan Brenner
** Date:					02/28/2016
** Description:			LineUp class implementation
*********************************************************************/
#include "lineup.hpp"

Lineup::Lineup()
{
	head = NULL;
}

Lineup::~Lineup()
{
	QueueNode *nodePtr = head;
	while (nodePtr != NULL)
	{
		/*
		**traverse from head to rear of 
		**list and remove each node 
		*/
		QueueNode *removeNode = nodePtr; 
		nodePtr = nodePtr->rear; 
		delete removeNode; 
	}
}

/*********************************************************************
** Function:			Stack::add()
** Description:		Adds integer to end of QueueNode list
** Parameters:			int i
*********************************************************************/
void Lineup::add(Creature* i)
{
	/*point head to new QueueNode if node is empty*/
	if (head == NULL)
	{
		head = new QueueNode(i);
	}
	/*traverse list from head to rear of "queue"*/
	else
	{
		QueueNode *nodePtr = head;
		while (nodePtr->rear != NULL)
			nodePtr = nodePtr->rear; 

	/*at rear of "queue," add new QueueNode*/
		nodePtr->rear = new QueueNode(i);
	}
}

/*********************************************************************
** Function:			Queue::remove()
** Description:		Removes 1st integer from QueueNode list
**					and returns value of int removed
*********************************************************************/
Creature* Lineup::remove()
{
	/*if list is empty, return 0*/
	if (head == NULL)
		return 0;
	else
	{
	/*
	** Remove 1st element and store value of 
	** 1st element before deleting, to return
	*/
		QueueNode *nodePtr = head;
		head = head->rear;
		
		Creature* returnVal = nodePtr->value;
		delete nodePtr; 

		return  returnVal;
	}
}

/*********************************************************************
** Function:			Queue::display()
** Description:		Displays each Creature in QueueNode list
*********************************************************************/
void Lineup::display() const
{
	if (head == NULL)
	{
		std::cout << "Team is empty." << std::endl;
	}
	else if (head != NULL)
	{
		QueueNode *nodePtr = head;
		int count = 1;
		while (nodePtr)
		{
			std::cout << count << ".";
			std::cout << nodePtr->value->getName() << " the ";
			std::cout << nodePtr->value->getID() << " " << std::endl;
			nodePtr = nodePtr->rear;
			count++;
		}
		std::cout << std::endl;
	}
}


/*********************************************************************
** Function:			
** Description:		
*********************************************************************/
void Lineup::teamID(int i) 
{
	if (head == NULL)
	{
		std::cout << "Team is empty." << std::endl;
	}
	else if (head != NULL)
	{
		QueueNode *nodePtr = head;
		while (nodePtr)
		{
			nodePtr->value->setTeamID(i);
			nodePtr = nodePtr->rear;
		}
	}
}

Creature* Lineup::get1stInLine()
{
	if (head != NULL)
	{
		QueueNode *nodePtr = head;
		return &*(nodePtr->value);
	}
	else 
		return NULL;
}


Creature* Lineup::get2ndInLine()
{
	if (head != NULL)
	{
		QueueNode *nodePtr = head;
		if (head->rear != NULL)
		{
			nodePtr = nodePtr->rear;
			return &*(nodePtr->value);
		}
		else
			return NULL;
	}	
	else 
		return NULL;
}


/*********************************************************************
** Function:			Queue::display()
** Description:		Displays each integer in QueueNode list
*********************************************************************/
void Lineup::scoreBoard() const
{
	if (head == NULL)
	{
		std::cout << "Team is empty." << std::endl;
	}
	else if (head != NULL)
	{
		QueueNode *nodePtr = head;
		int count = 1;
		while (nodePtr)
		{
			std::cout << count << std::setw(4) << std::left << "."
				<< std::left << nodePtr->value->getName() << " the "
				<< nodePtr->value->getID() << ": " << std::endl

				<< std::setw(15) << std::left << "Armor: " 
				<< std::setw(4) << std::right << nodePtr->value->getArmor() << std::endl
				<< std::setw(15) << std::left << "Strength: " 
				<< std::setw(4) << std::right << nodePtr->value->getStrength() << std::endl
				<< std::setw(15) << std::left << "Score: "
				<< std::setw(4) << std::right << nodePtr->value->getScore() << std::endl;
			nodePtr = nodePtr->rear;
			count++;
		}
		std::cout << std::endl;
	}
}