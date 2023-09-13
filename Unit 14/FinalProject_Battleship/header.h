#ifndef HEADER_H
#define HEADER_H

/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Final Project - Battleship
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/23/23
******************************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//variable declaration
const int CARRIER_SIZE = 5;      //CONSTANT - size of carrier
const int BATTLESHIP_SIZE = 4;   //CONSTANT - size of battleship
const int CRUISER_SIZE = 3;      //CONSTANT - size of cruiser
const int SUBMARINE_SIZE = 3;    //CONSTANT - size of submarine
const int DESTROYER_SIZE = 2;    //CONSTANT - size of destroyer
const int FLEET_SIZE = 5;        //CONSTANT - size of fleet

enum Shipnames {CARRIER, BATTLESHIP, CRUISER, SUBMARINE, DESTROYER};

//structure Point
struct Point
{
    int row;    //row - row section of point
    int column; //column - column section of point
};

//structure Ship
struct Ship
{
    string name;             //name - name of ship
    int size;                //size - size of ship
    int hitcount;            //hitcount - hitcount of ship
    vector <Point> points;   //points - points that ship occupies
};

//structure PlayerBoard
struct PlayerBoard
{
    char board[10][10];       //board - player board
    Ship ships[FLEET_SIZE];   //ships - the ships in the fleet
};

/******************************************************************************
 * displayBoards
 *  Outputs the two playerboards in the paramaters
 *  - returns nothing: outputs player grids
******************************************************************************/
void displayBoards(char [][10],    //IN - current player
                   char [][10]);   //IN - opposing player

/******************************************************************************
 * boardSetup
 * This function sets up all the ships for a player.
 *  - returns nothing
******************************************************************************/
void boardSetup(PlayerBoard &player1,   //IN - current player
                PlayerBoard &player2);  //IN - opposing player

/******************************************************************************
 * placeShip
 *  This function places a ship on the player board.
 * - returns a vector of the points for the ship number
******************************************************************************/
vector <Point> placeShip(PlayerBoard &player,  //IN - current player board
                             size_t shipnum);  //IN - ship index

/******************************************************************************
 * initFleet
 * This function initializes the player fleet with its name, size, and hitpoint
 * - returns nothing
******************************************************************************/
void initFleet(PlayerBoard &player);  //IN - player to initialize

/******************************************************************************
 * getValidShipInfo
 * This function takes in a valid ship placement coordinate from the user
 *  - returns nothing
******************************************************************************/
void getValidShipInfo(PlayerBoard &player,   //IN - current player
                                     int&,   //IN - row index
                                     int&,   //IN - column index
                                    char&,   //IN - ship orientation
                                     int);   //IN - ship index

/******************************************************************************
 * spaceOccupied
 * This function checks if a coordinate has been occupied.
 *  - returns true if unoccupied, false if occupied
******************************************************************************/
bool spaceOccupied(PlayerBoard &player,   //IN - player
                               int row,   //IN - row index
                               int col,   //IN - column index
                             char ornt,   //IN - ship orientation
                       int ship_index);   //IN - ship index

/******************************************************************************
 * getHit
 * ____________________________________________________________________________
 * This function gets a hit on an opposing player
 *  - returns nothing: marks a spot on the enemy boards
******************************************************************************/
void getHit(PlayerBoard &enemy_board,    //IN - enemy board
            PlayerBoard &enemy_hidden);  //IN - enemy game board

/******************************************************************************
 * checkHit
 * This function checks if a ship has been hit
 *  - returns nothing: outputs if hit, marks a spot on the enemy boards
******************************************************************************/
void checkHit(PlayerBoard &enemy,       //IN - enemy board
              PlayerBoard &enemyhidden, //IN - enemy hidden ships board
                               int row, //IN - row index
                               int col, //IN - column index
                           bool &cont); //IN - continue boolean

/******************************************************************************
 * FUNCTION checkLoss
 * This function checks if the opposing player has all the ships sunken
 *  - returns true if player has lost
******************************************************************************/
bool checkLoss(PlayerBoard enemy);  //IN - enemy hitcount

/******************************************************************************
 * checkDestroyed
 * This function checks if a ship has been destroyed
 *  - returns nothing
******************************************************************************/
void checkDestroyed(PlayerBoard enemy,  //IN - enemy ship
                      int ship_index);  //IN - ship index

/******************************************************************************
 * computerBoardSetup
 *   This function sets up the game board.
 *  - returns nothing
******************************************************************************/
void computerBoardSetup(PlayerBoard &computer); //IN - computer board

/******************************************************************************
 * computerPlaceShip
 * This function places a ship on the computer board.
 *  - returns nothing: marks a ship on the board
******************************************************************************/
vector <Point> computerPlaceShip(PlayerBoard &computer, //IN - computer board
                                       size_t shipnum); //IN - ship index

/******************************************************************************
 * computerGetValidShipInfo
 * This function gets valid ship coordinates and orientation for the ship
 *  - returns nothing
******************************************************************************/
void computerGetValidShipInfo(PlayerBoard &computer,  //IN - computer player
                                           int &row,  //IN - row index
                                           int &col,  //IN - column index
                                         char &ornt,  //IN - ship orientation
                                    int ship_index);  //IN - ship index

/******************************************************************************
 * computerGetHit
 * This function gets a valid hit for the computer
 *  - returns nothing: gets a valid hit
******************************************************************************/
void computerGetHit(PlayerBoard &computer,          //IN - computer board
                    PlayerBoard &computer_hidden);  //IN - computer game board

/******************************************************************************
 * computerCheckHit
 * This function checks if a hit or miss or invalid.
 *  - returns true if a hit is valid, false if invalid
******************************************************************************/
bool computerCheckHit(PlayerBoard &enemy,        //IN - player board
                      PlayerBoard &enemyhidden,  //IN - player hidden board
                                       int row,  //IN - row index
                                       int col,  //IN - column index
                                   bool &cont);  //IN - continue boolean

/******************************************************************************
 * FUNCTION subtractHitCount
 * If a hit lands on a ship, this function subtracts 1 from the ship's hitcount
 * - returns nothing: subtracts from hitcount
******************************************************************************/
void subtractHitCount(PlayerBoard &enemy,  //IN - enemy hitcount
                                 int row,  //IN - row index
                                int col);  //IN - column index

#endif // HEADER_H
