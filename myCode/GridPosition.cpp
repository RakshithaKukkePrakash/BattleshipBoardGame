/*
 * GridPosition.cpp
 *
 *  Created on: 01-Jan-2024
 *      Author: acer
 */

#include "GridPosition.h"
#include <iostream>
#include <string>

/**
 * Constructor for GridPosition that takes a character representing the row
 * and an integer representing the column.
 * \param char row     : [IN] Character representing the row (A-Z).
 * \param int column   : [IN] Integer representing the column (1 and above)
 */
GridPosition::GridPosition(char row, int column): row{row}, column{column}
{
}

/**
 * Constructor for GridPosition that takes a string in the format "A1"
 * and extracts the row and column.
 * \param std::string position : [IN] String in the format "A1".
 */
GridPosition::GridPosition(std::string position)
{
	row = position[0];
	int digitPos = position.find_first_of("0123456789");
	column = std::stoi(position.substr(digitPos, position.size()-1));
}

/**
 * Check if the GridPosition is valid, ensuring that the row is a character
 * between 'A' and 'Z' and the column is 1 or greater.
 * \return bool : True if the GridPosition is valid, false otherwise.
 */
bool GridPosition::isValid()
{
	if(row>='A'&& row<='Z' && column >=1){
		return true;
	}
	return false;
}

/**
 * Getter function to retrieve the row character of the GridPosition.
 * \return char : Row character.
 */
char GridPosition::getRow() const
{
	return row;
}

/**
 * Getter function to retrieve the column integer of the GridPosition.
 * \return int : Column integer.
 */
int GridPosition::getColumn() const
{
	return column;
}

/**
 * Conversion operator to convert the GridPosition to a string in the
 * format "A1".
 * \return std::string : String representation of the GridPosition.
 */
GridPosition::operator std::string() const
{
	return std::string(1,row) + std::to_string(column);
}

/**
 * Equality operator to check if two GridPositions are equal.
 * \param const GridPosition& other : [IN] Other GridPosition for comparison
 * \return bool : True if the two GridPositions are equal, false otherwise
 */
bool GridPosition::operator ==(const GridPosition& other) const
{
	return (row == other.row && column == other.column);
}

/**
 * Less than operator to check if one GridPosition is less than another.
 * \param const GridPosition& other : [IN] Other GridPosition for comparison
 * \return bool : True if this GridPosition is less than the other, false
 * 					otherwise.
 */
bool GridPosition::operator <(const GridPosition& other) const
{
	if (row< other.row){
		return true;
	}
	else if (row> other.row){
		return false;
	}
	return column<other.column;
}

/**
 * Destructor for GridPosition.
 */
GridPosition::~GridPosition()
{
}
