/*
 * Shot.cpp
 *
 *  Created on: 03-Jan-2024
 *      Author: acer
 */

#include "Shot.h"

/**
 * Constructor for Shot that takes a target position as a parameter.
 * \param GridPosition targetPosition : [IN] Target position for the shot.
 */
Shot::Shot(GridPosition targetPosition): targetPosition{targetPosition}
{
}

/**
 * Getter function to retrieve the target position of the shot.
 * \return GridPosition : Target position of the shot.
 */
GridPosition Shot::getTargetPosition() const
{
	return targetPosition;
}

/**
 * Destructor for Shot.
 */
Shot::~Shot()
{
}
