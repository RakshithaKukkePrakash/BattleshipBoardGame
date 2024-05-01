/*
 * GridPosition.h
 *
 *  Created on: 01-Jan-2024
 *      Author: acer
 */
#include <iostream>

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

class GridPosition
{
	char row;     //: char {'A' ¬ `row` ¬ 'Z'}
	int column;   //: int {column >=1 }

public:
	/**
	 * Constructor for GridPosition that takes a character representing the
	 * row and an integer representing the column.
	 * \param char row     : [IN] Character representing the row (A-Z).
	 * \param int column   : [IN] Integer representing the column (1 and above)
	 */
	GridPosition(char row, int column);

	/**
	 * Constructor for GridPosition that takes a string in the format "A1"
	 * and extracts the row and column.
	 * \param std::string position : [IN] String in the format "A1".
	 */
	GridPosition(std::string position);

	/**
	 * Check if the GridPosition is valid, ensuring that the row is a
	 * character between 'A' and 'Z' and the column is 1 or greater.
	 * \return bool : True if the GridPosition is valid, false otherwise.
	 */
	bool isValid();

	/**
	 * Getter function to retrieve the row character of the GridPosition.
	 * \return char : Row character.
	 */
	char getRow() const;

	/**
	 * Getter function to retrieve the column integer of the GridPosition.
	 * \return int : Column integer.
	 */
	int getColumn()const;

	/**
	 * Conversion operator to convert the GridPosition to a string in the
	 * format "A1".
	 * \return std::string : String representation of the GridPosition.
	 */
	operator std::string() const;

	/**
	 * Equality operator to check if two GridPositions are equal.
	 * \param const GridPosition& other : [IN] Other GridPosition for
	 * 					comparison
	 * \return bool : True if the two GridPositions are equal,
	 * 					false otherwise
	 */
	bool operator== (const GridPosition& other) const;

	/**
	 * Less than operator to check if one GridPosition is less than another.
	 * \param const GridPosition& other : [IN] Other GridPosition for
	 * 						comparison
	 * \return bool : True if this GridPosition is less than the other, false
	 * 					otherwise.
	 */
	bool operator< (const GridPosition& other) const;

	/**
	 * Destructor for GridPosition.
	 */
	virtual ~GridPosition();
};

#endif /* GRIDPOSITION_H_ */
