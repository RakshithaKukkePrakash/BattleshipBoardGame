/*
 * Shot.h
 *
 *  Created on: 03-Jan-2024
 *      Author: acer
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * Class representing a shot in the game.
 */
class Shot
{
	/*
	 * Target position for the shot.
	 */
    GridPosition targetPosition;

public:
    /**
     * Enumeration representing the impact of a shot.
     * - NONE: No impact.
     * - HIT: Shot hits a ship.
     * - SUNKEN: Shot results in sinking a ship.
     */
    typedef enum{
        NONE,
        HIT,
        SUNKEN
    } Impact;

    /**
     * Constructor for Shot that takes a target position as a parameter.
     * \param GridPosition targetPosition : [IN] Target position for the shot.
     */
    Shot(GridPosition targetPosition);

    /**
     * Getter function to retrieve the target position of the shot.
     * \return GridPosition : Target position of the shot.
     */
    GridPosition getTargetPosition() const;

    /**
     * Destructor for Shot.
     */
    virtual ~Shot();
};

#endif /* SHOT_H_ */
