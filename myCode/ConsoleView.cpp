/*
 * ConsoleView.cpp
 *
 *  Created on: 01-Jan-2024
 *      Author: acer
 */

#include "ConsoleView.h"
#include <iostream>
using namespace std;

/**
 * Constructor for ConsoleView that takes a Board object as a parameter.
 * \param Board *board : [IN] Pointer to the Board object.
 */
ConsoleView::ConsoleView(Board *board): board{board}
{
}

/**
 * Print function to display the own and opponent grids
 */
void ConsoleView::print()
{
    printOwnGrid();
    cout<<endl;
    printOpponentGrid();
}

/**
 * Print function to display the own grid of the player.
 * Displays the occupied positions with '#' for ships, '0' for hit
 * positions, '^' for missed shots,
 * and '~' for unoccupied positions.
 */
void ConsoleView::printOwnGrid() {
	const char ownRows = board->getRows();
	const int ownCols = board->getColumns();
	std::vector<Ship> occupiedShips = board->getOwnGrid().getShips();

	char arrayOwnGrid[ownRows][ownCols];

	for (int i = 0; i < ownRows; i++) {
	    for (int j = 0; j < ownCols; j++) {
	    	arrayOwnGrid[i][j] = '~';
	    }
	}

	for (const Ship& eachShip : occupiedShips) {
	    for (const auto& occupied : eachShip.occupiedArea()) {
	    	arrayOwnGrid[occupied.getRow() - 'A'][occupied.getColumn() - 1]
												  = '#';
	    }
	}

	for (const auto& shot : board->getOwnGrid().getShotAt()) {
	    int row = shot.getRow() - 'A';
	    int col = shot.getColumn() - 1;

	    Shot::Impact impact = board->getOwnGrid().takeBlow(shot);

	    if (impact != Shot::Impact::NONE) {

	    	arrayOwnGrid[row][col] = '0';
	    }
	    else {

	    	arrayOwnGrid[row][col] = '^';
	    }

	}
	cout<<"Own Grid"<<endl;
	for (int colNum = 1; colNum <= ownCols; colNum++) {
		cout<<" "<< colNum;
	}
	cout<<endl;
	for (int rowN = 0;  rowN< ownRows; rowN++) {
	    cout << static_cast<char>('A' + rowN) << " ";
	    for (int colN = 0; colN < ownCols; colN++) {
	        cout << arrayOwnGrid[rowN][colN] << " ";
	    }
	    cout << endl;
	}

}

/**
 * Print function to display the opponent grid.
 * Displays the occupied positions with '0' for hit
 * positions, '^' for missed shots, '#' if all the ships are sunken
 * and '~' for unoccupied positions.
 */
void ConsoleView::printOpponentGrid()
{
    int opponentRows = board->getOpponentGrid().getRows();
    int opponentCols = board->getOpponentGrid().getColumn();
    char arrayOpponentGrid[opponentRows][opponentCols];

    for (int i = 0; i < opponentRows; i++) {
    	    for (int j = 0; j < opponentRows; j++) {
    	    	arrayOpponentGrid[i][j] = '~';
    	    }
    	}

    for(auto shot: board->getOpponentGrid().getShotsAt())
    {
    	int row = GridPosition(shot.first).getRow() - 'A';
    	int col = GridPosition(shot.first).getColumn() - 1;

    	if(shot.second == Shot::Impact::HIT){

    		arrayOpponentGrid[row][col] = '0';
    	}
    	else if (shot.second == Shot::Impact::NONE){

    		arrayOpponentGrid[row][col] = '^';
    	}
    	else{
    		for (auto sunken : board->getOpponentGrid().getSunkenShips()) {

             arrayOpponentGrid[sunken.getRow()-'A'][sunken.getColumn()-1] ='#';


    		    std::cout << std::endl;
    		}
    	}
    }
    cout<<"Opponent Grid"<<endl;
	for (int colN = 1; colN <= opponentCols; colN++) {
		cout<<" "<< colN;
	}
	cout<<endl;
	for (int rowNum = 0;  rowNum< opponentRows; rowNum++) {
		cout << static_cast<char>('A' + rowNum) << " ";
		for (int colNum = 0; colNum < opponentCols; colNum++) {
			cout << arrayOpponentGrid[rowNum][colNum] << " ";
		}
		cout << endl;
	}

}

/**
 * Destructor for ConsoleView.
 */
ConsoleView::~ConsoleView()
{
}

