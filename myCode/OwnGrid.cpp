/*
 * OwnGrid.cpp
 *
 *  Created on: 04-Jan-2024
 *      Author: acer
 */

#include "OwnGrid.h"
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Parameterized constructor to initialize the OwnGrid with the specified
 * number of rows and columns.
 * \param int rows     : [IN] Number of rows in the grid.
 * \param int columns  : [IN] Number of columns in the grid.
 */
OwnGrid::OwnGrid(int rows, int columns):rows{rows}, columns{columns}
{
}

/**
 * Getter function to retrieve the number of rows in the grid.
 * \return int : Number of rows in the grid.
 */
int OwnGrid::getRows() const
{
    return rows;
}

/**
 * Getter function to retrieve the number of columns in the grid.
 * \return int : Number of columns in the grid.
 */
int OwnGrid::getColumns() const
{
    return columns;
}

/**
 * Function to place a ship on the grid according to specified rules.
 * \param const Ship& ship : [IN] Ship object to be placed on the grid.
 * \return bool : True if the placement is successful, false otherwise.
 */
bool OwnGrid::placeShip(const Ship& ship)
{
    // 1. Ships may not touch each other
    for (const Ship& placedShip : ships) {
        for (const auto& prevBlocked : placedShip.blockedArea()) {
            for (const auto& newOccupied : ship.occupiedArea()) {
                if (prevBlocked == newOccupied) {
                    return false;
                }
            }
        }
    }

    // 3. Ships may be positioned at the edges of the grid
    if(!(ship.getBow().getRow()< ('A'+ rows) && ship.getBow().getColumn()<= columns
    		&& ship.getStern().getRow()<('A'+ rows) && ship.getStern().getColumn()<= columns))
    {
    	return false;
    }

    // 2. The grid fields occupied by a ship form a straight line
    // 4. Ships must be positioned horizontally or vertically
    if (!ship.isValid()) {
        return false;
    }

    // 5. Each player has 10 ships as follows
    int shipLength = ship.length();
    static std::map<int,int> shipsNLength = {{5,1},{4,2},{3,3},{2,4}};
    std::map<int,int>::iterator it = shipsNLength.find(shipLength);
      if (it != shipsNLength.end() && shipLength> 0 && it->second >0)
      {
          shipsNLength.at(shipLength) = (it->second)-1;
      }
      else{
          return false;
      }

    ships.push_back(ship);
    return true;
}

/**
 * Getter function to retrieve the vector of ships placed on the grid.
 * \return const std::vector<Ship> : Vector of Ship objects.
 */
const std::vector<Ship> OwnGrid::getShips() const
{
    return ships;
}

/**
 * Function to determine the impact of a shot on the ships on the grid.
 * \param const Shot& shot : [IN] Shot object representing the target position.
 * \return Shot::Impact : Enum indicating the impact of the shot (HIT, SUNKEN,
 *  or NONE).
 */
Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
    std::set<GridPosition> takenBlows;
    for (Ship &eachShip : ships)
    {
        bool hit = false;
        bool finalHit = false;
        for (const GridPosition &shipPosition : eachShip.occupiedArea())
        {
            shotAt.insert(shot.getTargetPosition());
            if (shot.getTargetPosition() == shipPosition)
            {
                hit = true;
                int finalBlowCount = 0;

                for (const GridPosition &takenBlow : takenBlows)
                {
                    if (takenBlow == shipPosition)
                    {
                        finalBlowCount++;
                    }
                }
                finalHit = (finalBlowCount == (eachShip.length() - 1));
                break;
            }
        }
        if (hit)
        {
            takenBlows.insert(shot.getTargetPosition());
            return finalHit ? Shot::Impact::SUNKEN : Shot::Impact::HIT;
        }
    }
    return Shot::Impact::NONE;
}



/**
 * Getter function to retrieve the set of grid positions that have been
 * shot at
 * \return const std::set<GridPosition> : Set of GridPosition objects
 * representing the shot positions.
 */
const std::set<GridPosition> OwnGrid::getShotAt() const
{
    return shotAt;
}

/**
 * Destructor for OwnGrid.
 */
OwnGrid::~OwnGrid()
{
}
