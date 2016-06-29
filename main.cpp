/*********************************************************************
** Program Filename:		main.cpp	
** Author:				Morgan Brenner
** Date:					02/28/2016
** Description:			main client function 
*********************************************************************/
#include "creature.hpp"
#include "lineup.hpp"
#include "pile.hpp" 
#include "game.hpp"

#include <iostream>
#include <iomanip>

int main()
{
	Game g1;

	g1.runGame();
	
	return 0; 
}