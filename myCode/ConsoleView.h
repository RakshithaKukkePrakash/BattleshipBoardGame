/*
 * ConsoleView.h
 *
 *  Created on: 04-Jan-2024
 *      Author: acer
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_
#include "Board.h"
class ConsoleView
{
	/*
	 * Reference of Board
	 */
	Board* board;

	/**
	 * Print function to display the own grid of the player.
	 * Displays the occupied positions with '#' for ships, '0' for hit
	 * positions, '^' for missed shots,
	 * and '~' for unoccupied positions.
	 */
	void printOwnGrid();

	/**
	 * Print function to display the opponent grid.
	 * Displays the occupied positions with '0' for hit
	 * positions, '^' for missed shots, '#' if all the ships are sunken
	 * and '~' for unoccupied positions.
	 */
	void printOpponentGrid();

public:
	/**
	 * Constructor for ConsoleView that takes a Board object as a parameter.
	 * \param Board *board : [IN] Pointer to the Board object.
	 */
	ConsoleView(Board* board);


	/**
	 * Print function to display the own and opponent grids
	 */
	void print();

	/**
	 * Destructor for ConsoleView.
	 */
	virtual ~ConsoleView();
};

#endif /* CONSOLEVIEW_H_ */
