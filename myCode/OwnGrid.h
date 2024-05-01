/*
 * OwnGrid.h
 *
 *  Created on: 04-Jan-2024
 *      Author: acer
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_
#include <iostream>
#include <vector>
#include "Ship.h"
#include "Shot.h"

class OwnGrid
{
	/*
	 * Number of rows in the grid.
	 */
	int rows;
	/*
	 * Number of columns in the grid.
	 */
	int columns;

	/*
	 * Set to track positions where shots have been fired.
	 */
	std::set<GridPosition> shotAt;
	/*
	 * Vector to store the ships
	 */
	std::vector<Ship> ships;
public:

	/**
	 * Parameterized constructor to initialize the OwnGrid with the specified
	 * number of rows and columns.
	 * \param int rows     : [IN] Number of rows in the grid.
	 * \param int columns  : [IN] Number of columns in the grid.
	 */
	OwnGrid(int rows, int columns);

	/**
	 * Getter function to retrieve the number of rows in the grid.
	 * \return int : Number of rows in the grid.
	 */
	int getRows()const;

	/**
	 * Getter function to retrieve the number of columns in the grid.
	 * \return int : Number of columns in the grid.
	 */
	int getColumns()const;

	/**
	 * Function to place a ship on the grid according to specified rules.
	 * \param const Ship& ship : [IN] Ship object to be placed on the grid.
	 * \return bool : True if the placement is successful, false otherwise.
	 */
	bool placeShip(const Ship& ship);

	/**
	 * Getter function to retrieve the vector of ships placed on the grid.
	 * \return const std::vector<Ship> : Vector of Ship objects.
	 */
	const std::vector<Ship> getShips()const;

	/**
	 * Function to determine the impact of a shot on the ships on the grid.
	 * \param const Shot& shot : [IN] Shot object representing the target position.
	 * \return Shot::Impact : Enum indicating the impact of the shot (HIT, SUNKEN,
	 *  or NONE).
	 */
	Shot::Impact takeBlow(const Shot& shot);

	/**
	 * Getter function to retrieve the set of grid positions that have been
	 * shot at
	 * \return const std::set<GridPosition> : Set of GridPosition objects
	 * representing the shot positions.
	 */
	const std::set<GridPosition> getShotAt() const;

	/**
	 * Destructor for OwnGrid.
	 */
	virtual ~OwnGrid();
};

#endif /* OWNGRID_H_ */
