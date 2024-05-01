/*
 * Board.h
 *
 *  Created on: 04-Jan-2024
 *      Author: acer
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "OwnGrid.h"
#include "OpponentGrid.h"
class Board
{
	/*
	 * Instance of player's Grid
	 */
	OwnGrid ownGrid;

	/*
	 * Instance of Opponent's Grid
	 */
	OpponentGrid opponentGrid;
public:
	/**
	 * Constructor for Board that initializes both own and opponent grids in
	 * the specified row and column.
	 * \param int rows    :[IN] Number of rows for both own and opponent grids
	 * \param int columns :[IN] Number of columns for both own and opponent
	 * 							 grids
	 */
	Board(int rows, int columns);

	/**
	 * Getter function to retrieve the number of rows in the own grid.
	 * \return int : Number of rows in the own grid.
	 */
	int getRows() const;

	/**
	 * Getter function to retrieve the number of columns in the own grid.
	 * \return int : Number of columns in the own grid.
	 */
	int getColumns() const;

	/**
	 * Getter function to retrieve the reference to the player grid.
	 * \return OwnGrid& : Reference to the own grid.
	 */
	OwnGrid& getOwnGrid();

	/**
	 * Getter function to retrieve the reference to the opponent grid.
	 * \return OpponentGrid& : Reference to the opponent grid.
	 */
	OpponentGrid& getOpponentGrid();

	/**
	 * Destructor for Board.
	 */
	virtual ~Board();
};

#endif /* BOARD_H_ */
