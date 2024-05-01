/*
 * OpponentGrid.h
 *
 *  Created on: 04-Jan-2024
 *      Author: acer
 */
#include <map>
#include <vector>
#include "Ship.h"
#include "Shot.h"
#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

class OpponentGrid
{
	/**
	 * Number of rows in the opponent grid.
	 */
	int rows;
	/**
	 * Number of columns in the opponent grid.
	 */
	int columns;

	/*
	 * Set to store information about sunken ships.
	 */
	std::set<GridPosition> sunkenShips;

	/*
	 * Map to track shots fired on the grid with their impact.
	 */
	std::map<GridPosition, Shot::Impact> shots;

public:
	/**
	 * Constructor for OpponentGrid that takes the number of rows and columns
	 * as parameters.
	 * \param int rows     : [IN] Number of rows for the opponent grid.
	 * \param int columns  : [IN] Number of columns for the opponent grid.
	 */
	OpponentGrid(int rows, int columns);

	/**
	 * Getter function to retrieve the number of rows in the opponent grid.
	 * \return int : Number of rows in the opponent grid.
	 */
	int getRows()const;

	/**
	 * Getter function to retrieve the number of columns in the opponent grid.
	 * \return int : Number of columns in the opponent grid.
	 */
	int getColumn()const;

	/**
	 * Updates the grid with the result of a shot, including marking the
	 * shot position and handling sunken ships.
	 * \param const Shot& shot          : [IN] The shot fired.
	 * \param Shot::Impact impact       : [IN] The impact of the shot.
	 */
	void shotResult(const Shot& shot, Shot::Impact impact);

	/**
	 * Getter function to retrieve the map of shots at positions on the
	 * opponent grid.
	 * \return const std::map<GridPosition, Shot::Impact>& : Map of shots at
	 * positions with their impact.
	 */
	const std::map<GridPosition, Shot::Impact>& getShotsAt() const;

	/**
	 * Getter function to retrieve the vector of sunken ships
	 * \return const std::set<GridPosition> : Vector of the ships that have
	 * received finalBlow
	 */
	const std::set<GridPosition>& getSunkenShips();

	/**
	 * Destructor for OpponentGrid.
	 */
	virtual ~OpponentGrid();
};

#endif /* OPPONENTGRID_H_ */
