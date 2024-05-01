/*
 * Board.cpp
 *
 *  Created on: 01-Jan-2024
 *      Author: acer
 */

#include "Board.h"
/**
 * Constructor for Board that initializes both own and opponent grids in
 * the specified row and column.
 * \param int rows    :[IN] Number of rows for both own and opponent grids
 * \param int columns :[IN] Number of columns for both own and opponent
 * 							 grids
 */
Board::Board(int rows, int columns):
		ownGrid(rows, columns), opponentGrid(rows, columns)
{
}

/**
 * Getter function to retrieve the number of rows in the own grid.
 * \return int : Number of rows in the own grid.
 */
int Board::getRows() const
{
	return ownGrid.getRows();
}

/**
 * Getter function to retrieve the number of columns in the own grid.
 * \return int : Number of columns in the own grid.
 */
int Board::getColumns() const
{
	return ownGrid.getColumns();
}

/**
 * Getter function to retrieve the reference to the player grid.
 * \return OwnGrid& : Reference to the own grid.
 */
OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

/**
 * Getter function to retrieve the reference to the opponent grid.
 * \return OpponentGrid& : Reference to the opponent grid.
 */
OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}

/**
 * Destructor for Board.
 */
Board::~Board()
{
}
