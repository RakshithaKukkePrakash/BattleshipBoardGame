/*
 * Ship.cpp
 *
 *  Created on: 04-Jan-2024
 *      Author: acer
 */

#include "Ship.h"
#include <iostream>
using namespace std;

/**
 * Constructor for Ship that takes the bow and stern positions.
 * \param const GridPosition& bow   : [IN] Bow position of the ship.
 * \param const GridPosition& stern : [IN] Stern position of the ship.
 */
Ship::Ship(const GridPosition &bow, const GridPosition &stern): bow{bow},
		stern{stern}
{
}

/**
 * Check if the ship is valid, satisfying the conditions of a valid
 * ship placement.
 * \return bool : True if the ship is valid, false otherwise.
 */
bool Ship::isValid() const
{
	int shipLength = length();
	if ((bow.getRow() == stern.getRow() ||
			bow.getColumn() == stern.getColumn()) &&
			(shipLength >= 2 && shipLength <= 5 )){
		return true;
	}
	return false;
}

/**
 * Getter function to retrieve the bow position of the ship.
 * \return GridPosition : Bow position of the ship.
 */
GridPosition Ship::getBow() const
{
	return bow;
}

/**
 * Getter function to retrieve the stern position of the ship.
 * \return GridPosition : Stern position of the ship.
 */
GridPosition Ship::getStern() const
{
	return stern;
}

/**
 * Calculate and return the length of the ship.
 * \return int : Length of the ship.
 */
int Ship::length() const
{
	if (bow.getColumn() == stern.getColumn()){
		return abs(stern.getRow()-bow.getRow())+1;
	}
	else if (bow.getRow()== stern.getRow()){
		return abs(stern.getColumn()- bow.getColumn())+1;
	}
	return 0;
}

/**
 * Calculate and return a set of GridPositions representing the
 * occupied area by the ship.
 * \return std::set<GridPosition> : Set of GridPosition objects
 * 					representing the occupied area.
 */
std::set<GridPosition> Ship::occupiedArea() const
{
	std::set<GridPosition> occupiedPositions;

	int rowPosition, colPosition;
	if (bow.getRow() == stern.getRow()){
		rowPosition = bow.getRow();
		colPosition = bow.getColumn();
		while(colPosition<=stern.getColumn()){
			occupiedPositions.insert(GridPosition(rowPosition,colPosition));
			colPosition++;
		}
	}
	else if (bow.getColumn()== stern.getColumn()){
		rowPosition = bow.getRow();
		colPosition = bow.getColumn();
		while(rowPosition<=stern.getRow()){
			occupiedPositions.insert(GridPosition(rowPosition,colPosition));
			rowPosition++;
		}
	}

	return occupiedPositions;
}

/**
 * Calculate and return a set of GridPositions representing the blocked
 * 			area around the ship.
 * \return std::set<GridPosition> : Set of GridPosition objects representing
 * 			the blocked area.
 */
std::set<GridPosition> Ship::blockedArea() const
{
    std::set<GridPosition> blocked;
	for (int row = bow.getRow() - 1; row <= stern.getRow() + 1; ++row) {
		for (int col = bow.getColumn() - 1; col <= stern.getColumn() + 1;
						++col) {
			if(GridPosition(row, col).isValid()){
				blocked.insert(GridPosition(row, col));
			}
		}
    }

    return blocked;
}

/**
 * Destructor for Ship.
 */
Ship::~Ship()
{
}
