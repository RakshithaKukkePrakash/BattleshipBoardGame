/**
 * @mainpage
 * Battleship Game
 *
 * The battleship is a game played by 2 players who have ships arranged
 * in their boards. Each player calls out a grid and if the other player
 * has a ship, they say hit else miss. If all the holes in the ship is
 * hit, then the ship has sunken. The player makes note of each other's
 * hits and misses. The player who sinks all the ships of the opponent
 * wins the game
 */

/*
 * Standard (system) header files
 */
#include <iostream>
#include <cstdlib>

using namespace std;

#include "Board.h"
#include "ConsoleView.h"
#include "part1tests.h"
#include "part2tests.h"
#include "part3tests.h"

#include "GridPosition.h"
#include "Ship.h"

int main ()
{
	cout << "BattleShip started." << endl << endl;

//	part1tests();
//	part2tests();
	part3tests();

	return 0;
}
