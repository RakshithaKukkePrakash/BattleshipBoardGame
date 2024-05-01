/*
 * Ship.h
 *
 *  Created on: 04-Jan-2024
 *      Author: acer
 */

#ifndef SHIP_H_
#define SHIP_H_
#include "GridPosition.h"
#include <iostream>
#include <set>
class Ship
{
	/*
	 * Bow position of the ship
	 */
	GridPosition bow;
	/*
	 * Stern position of the ship
	 */
	GridPosition stern;

public:

	/**
	 * Constructor for Ship that takes the bow and stern positions.
	 * \param const GridPosition& bow   : [IN] Bow position of the ship.
	 * \param const GridPosition& stern : [IN] Stern position of the ship.
	 */
	Ship(const GridPosition& bow, const GridPosition& stern);

	/**
	 * Check if the ship is valid, satisfying the conditions of a valid
	 * ship placement.
	 * \return bool : True if the ship is valid, false otherwise.
	 */
	bool isValid() const;

	/**
	 * Getter function to retrieve the bow position of the ship.
	 * \return GridPosition : Bow position of the ship.
	 */
	GridPosition getBow() const;

	/**
	 * Getter function to retrieve the stern position of the ship.
	 * \return GridPosition : Stern position of the ship.
	 */
	GridPosition getStern() const;

	/**
	 * Calculate and return the length of the ship.
	 * \return int : Length of the ship.
	 */
	int length() const;

	/**
	 * Calculate and return a set of GridPositions representing the
	 * occupied area by the ship.
	 * \return std::set<GridPosition> : Set of GridPosition objects
	 * 					representing the occupied area.
	 */
	std::set<GridPosition> occupiedArea()const;

	/**
	 * Calculate and return a set of GridPositions representing the blocked
	 * 			area around the ship.
	 * \return std::set<GridPosition> : Set of GridPosition objects representing
	 * 			the blocked area.
	 */
	std::set<GridPosition> blockedArea()const;

	/**
	 * Destructor for Ship.
	 */
	virtual ~Ship();
};

#endif /* SHIP_H_ */
