/*
 * part3tests.cpp
 *
 *  Created on: 10-Jan-2024
 *      Author: acer
 */

#include "part3tests.h"


using namespace std;


/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue3(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Part2 test for console output, check takeBlow method of OwnGrid
 * to verify the implementation of HIT, MISS and SUNKEN cases
 * Also checking the update of Opponent Grid
 */
void part3tests()
{
	Board board(10, 10);
	cout<<"Test3"<<endl;

//test Place Ship
	assertTrue3(
			board.getOwnGrid().placeShip(
					Ship(GridPosition("A8"), GridPosition("A10"))),
			"Ship should be placed at A8 - A10");

	assertTrue3(
			board.getOwnGrid().placeShip(
					Ship(GridPosition("B1"), GridPosition("B4"))),
			"Ship(B1-B4) should be placed");

	assertTrue3(
			board.getOwnGrid().placeShip(
					Ship(GridPosition("D1"), GridPosition("D2"))),
			"Ship(D1-D2) should be placed");

	assertTrue3(
			board.getOwnGrid().placeShip(
					Ship(GridPosition("D4"), GridPosition("F4"))),
			"Ship(D4 - F4) should be placed");

	assertTrue3(
			board.getOwnGrid().placeShip(
					Ship(GridPosition("F6"), GridPosition("G6"))),
			"Ship(F6 - G6) should be placed");
	assertTrue3(
			board.getOwnGrid().placeShip(
					Ship(GridPosition("D8"), GridPosition("H8"))),
			"Ship(D8 -H8) should be placed");
	assertTrue3(
			board.getOwnGrid().placeShip(
					Ship(GridPosition("G2"), GridPosition("J2"))),
			"Ship(G2-J2) should be placed");
	assertTrue3(
			board.getOwnGrid().placeShip(
					Ship(GridPosition("I4"), GridPosition("I5"))),
			"Ship(I4-I5) should be placed");
	assertTrue3(
			board.getOwnGrid().placeShip(
					Ship(GridPosition("J8"), GridPosition("J9"))),
			"Ship(J8 -J9) should be placed");


//	Test TakeBlow
	assertTrue3(
			board.getOwnGrid().takeBlow(GridPosition { "A1" })
					== Shot::Impact::NONE, "Blow is a miss");
	assertTrue3(
			board.getOwnGrid().takeBlow(GridPosition { "E4" })
					== Shot::Impact::HIT, "Blow is a HIT");
	assertTrue3(
			board.getOwnGrid().takeBlow(GridPosition { "J6" })
					== Shot::Impact::NONE, "Blow is a miss");
	assertTrue3(
			board.getOwnGrid().takeBlow(GridPosition { "H8" })
					== Shot::Impact::HIT, "Blow is a HIT");
	assertTrue3(
			board.getOwnGrid().takeBlow(GridPosition { "A6" })
					== Shot::Impact::NONE, "Blow is a miss");
	assertTrue3(
			board.getOwnGrid().takeBlow(GridPosition { "D2" })
					== Shot::Impact::HIT, "Blow is a HIT");
	assertTrue3(
			board.getOwnGrid().takeBlow(GridPosition { "D1" })
					== Shot::Impact::HIT, "Blow is a HIT");
	assertTrue3(
			board.getOwnGrid().takeBlow(GridPosition { "D2" })
					== Shot::Impact::HIT, "Blow is a HIT");

	//Opponent Grid
	board.getOpponentGrid().shotResult(Shot(GridPosition{"C2"}),
		 Shot::Impact::NONE);

	 board.getOpponentGrid().shotResult(Shot(GridPosition{"C3"}),
	 Shot::Impact::HIT);
	 board.getOpponentGrid().shotResult(Shot(GridPosition{"C4"}),
	 Shot::Impact::HIT);
	 board.getOpponentGrid().shotResult(Shot(GridPosition{"F5"}),
	 Shot::Impact::NONE);
	 board.getOpponentGrid().shotResult(Shot(GridPosition{"C5"}),
	 Shot::Impact::SUNKEN);

	 board.getOpponentGrid().shotResult(Shot(GridPosition{"D8"}),
	 Shot::Impact::HIT);
	 board.getOpponentGrid().shotResult(Shot(GridPosition{"G4"}),
	 Shot::Impact::NONE);
	 board.getOpponentGrid().shotResult(Shot(GridPosition{"F6"}),
	 Shot::Impact::HIT);
	 board.getOpponentGrid().shotResult(Shot(GridPosition{"G6"}),
	 Shot::Impact::SUNKEN);
	 board.getOpponentGrid().shotResult(Shot(GridPosition{"J6"}),
	 Shot::Impact::NONE);
	 	ConsoleView console(&board);
	 	console.print();
}

