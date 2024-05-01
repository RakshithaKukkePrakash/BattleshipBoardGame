/*
 * part1tests.cpp
 *
 *  Created on: 06-Jan-2024
 *      Author: acer
 */

#include "Board.h"
#include <iostream>
using namespace std;


/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue2(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Part2 test for console output, placing Ships correctly and
 * checking blocked area
 */
void part2tests () {
	// Ships cant touch each other
	cout<<"Test2"<<endl;
	assertTrue2(OwnGrid(10,10).placeShip(Ship(GridPosition("B6"),
			GridPosition("C6")))== true, "Ships touch each other");

	assertTrue2(OwnGrid(10,10).placeShip(Ship(GridPosition("C10"),
			 GridPosition("D10")))== true, "Ships touch each other");

	// The grid fields occupied by a ship form a straight line
	assertTrue2(OwnGrid(10,10).placeShip(Ship(GridPosition("D2"),
			GridPosition("G5")))== false, "Ship do not form a straight line");


	// Ships may be positioned at the edges of the grid
	// !!!!Exception!!!!
	assertTrue2(OwnGrid(10,10).placeShip(Ship(GridPosition("A7"),
			GridPosition("A10")))== true, "Ship positioned within edge");
	assertTrue2(OwnGrid(10,10).placeShip(Ship(GridPosition("B10"),
			GridPosition("F10")))== true, "Ship positioned within edge");

	// Ships must be positioned horizontally or vertically
	assertTrue2(OwnGrid(10,10).placeShip(Ship(GridPosition("A7"),
			GridPosition("C9")))== false, "Ship not placed horizontally or"
					"vertically");
	assertTrue2(OwnGrid(10,10).placeShip(Ship(GridPosition("H1"),
			GridPosition("F3")))== false, "Ship not placed horizontally or"
						"vertically");


	// Blocked area
	assertTrue2(Ship{GridPosition{"B2"}, GridPosition{"B4"}}.blockedArea()
			== set<GridPosition>{GridPosition{"A1"}, GridPosition{"A2"},
		GridPosition{"A3"},GridPosition{"A4"},GridPosition{"A5"},
		GridPosition{"B1"}, GridPosition{"B2"},
		GridPosition{"B3"},GridPosition{"B4"},GridPosition{"B5"},
		GridPosition{"C1"}, GridPosition{"C2"},
					GridPosition{"C3"},GridPosition{"C4"},GridPosition{"C5"}},
			"Blocked area not correct");
	assertTrue2(Ship{GridPosition{"C10"}, GridPosition{"D10"}}.blockedArea()
			== set<GridPosition>{GridPosition{"B10"}, GridPosition{"B9"},
			GridPosition{"B11"},GridPosition{"C11"},GridPosition{"D11"},
		GridPosition{"C10"},GridPosition{"C9"},GridPosition{"D9"},
		GridPosition{"D10"}, GridPosition{"E9"},
		GridPosition{"E10"},GridPosition{"E11"}},
			"Blocked area not correct");
}




