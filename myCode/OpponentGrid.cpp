/*
 * OpponentGrid.cpp
 *
 *  Created on: 04-Jan-2024
 *      Author: acer
 */

#include "OpponentGrid.h"
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Constructor for OpponentGrid that takes the number of rows and columns
 * as parameters.
 * \param int rows     : [IN] Number of rows for the opponent grid.
 * \param int columns  : [IN] Number of columns for the opponent grid.
 */
OpponentGrid::OpponentGrid(int rows, int columns):rows{rows}, columns{columns}
{
}

/**
 * Getter function to retrieve the number of rows in the opponent grid.
 * \return int : Number of rows in the opponent grid.
 */
int OpponentGrid::getRows() const
{
	return rows;
}

/**
 * Getter function to retrieve the number of columns in the opponent grid.
 * \return int : Number of columns in the opponent grid.
 */
int OpponentGrid::getColumn() const
{
	return columns;
}

/**
 * Getter function to retrieve the map of shots at positions on the
 * opponent grid.
 * \return const std::map<GridPosition, Shot::Impact>& : Map of shots at
 * positions with their impact.
 */
const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt() const
{

	return shots;
}

/**
 * Getter function to retrieve the vector of sunken ships
 * \return const std::set<GridPosition> : Vector of the ships that have
 * received finalBlow
 */
const std::set<GridPosition>& OpponentGrid::getSunkenShips()
{
	return sunkenShips;
}

/**
 * Updates the grid with the result of a shot, including marking the
 * shot position and handling sunken ships.
 * \param const Shot& shot          : [IN] The shot fired.
 * \param Shot::Impact impact       : [IN] The impact of the shot.
 */

void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact)
{
    std::set<GridPosition> orderedShips;
    std::set<GridPosition> ships;

    if (impact == Shot::Impact::SUNKEN)
    {
        for (const auto &prevShots : shots)
        {
            if (prevShots.second == Shot::Impact::HIT)
            {
                orderedShips.insert(shot.getTargetPosition());
                orderedShips.insert(prevShots.first);
            }
        }
    }

    if (!orderedShips.empty())
    {
        GridPosition sunkenPos = shot.getTargetPosition();
        auto it = orderedShips.find(sunkenPos);
        if (it != orderedShips.end())
        {
            std::set<GridPosition> closestShips;
            closestShips.insert(*it);

            auto prevIt = it;
            while (prevIt != orderedShips.begin())
            {
                --prevIt;
                if (prevIt->getRow() == sunkenPos.getRow() || prevIt->getColumn() == sunkenPos.getColumn())
                {
                    closestShips.insert(*prevIt);
                }
                else
                {
                    break;
                }
            }

            auto nextIt = it;
            while (nextIt != orderedShips.end())
            {
                ++nextIt;
                if (nextIt->getRow() == sunkenPos.getRow() || nextIt->getColumn() == sunkenPos.getColumn())
                {
                    closestShips.insert(*nextIt);
                }
                else
                {
                    break;
                }
            }

            if (!closestShips.empty())
            {

                for (const GridPosition &shipPos : closestShips)
                {
                    if (GridPosition(shipPos).isValid())
                    {
                    	sunkenShips.insert(shipPos);
                    }
                }
            }
        }
    }

    shots.insert({shot.getTargetPosition(), impact});
}

/**
 * Destructor for OpponentGrid.
 */
OpponentGrid::~OpponentGrid()
{
    // TODO: Implement any necessary cleanup.
}
