#ifndef GAME_HPP
#define GAME_HPP   

#include "creature.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"
#include "medusa.hpp"
#include "vampire.hpp"

#include "lineup.hpp"
#include "pile.hpp"  

#include <iostream>
#include <iomanip>

class Game
{
private:
	Lineup q1;
	Lineup q2;
	Pile s1;
	
	Creature* fightRing[2];

	int num;
	int round;

	int firstPlace;
	int secondPlace;
	int thirdPlace;
	
public:
	Game();
	~Game();
	void fillQ1();
	void fillQ2();

	void promptNum();
	void promptName(Creature* c);
	void fight12();
	void fight21();
	void moveToLoserPile(Creature* c);
	void moveToLoserPileNoDisplay(Creature* c);

	void runGame();

};


#endif 