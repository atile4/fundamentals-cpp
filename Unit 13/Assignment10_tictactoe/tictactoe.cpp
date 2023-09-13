/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Assignment 10 - Tic Tac Toe
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/15/23
******************************************************************************/
#include <vector>
#include <iostream>

using namespace std;

/******************************************************************************
 * TIC-TAC-TOE GAME
 * ____________________________________________________________________________
 * The program takes in a valid input for a position on the tictactoe board for
 *  player 1, then switches to player 2. This process repeats until the board
 *  is filled or when a player wins.
 * ____________________________________________________________________________
 * INPUT
 *  curPlay - position on the board
 *  turn - player turn
 *  player_letter - symbol of corresponding player
 *  PLAYER1 - player 1, x
 *  PLAYER2 - player 2, o
 * OUTPUT
 *  board - tic tac toe grid after a turn
 *  result - player1/player2 win message or tie message
******************************************************************************/


const bool CLEAR_SCREEN = true;
/// @brief Utilizes an escape character sequence to clear the screen
/******************************************************************************
 * FUNCTION clearScreen
 * ____________________________________________________________________________
 * clears the output screen
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  None
 * POST-CONDITIONS
 *  clears the output screen
******************************************************************************/
void clearScreen()
{
    cout << endl;

    if (CLEAR_SCREEN)
    {
        cout << "\033c";
    }

    cout << endl;
}

/******************************************************************************
 * FUNCTION drawBoard
 * ____________________________________________________________________________
 * outputs the tictactoe board with characters in the board vector
 *  - returns nothing: outputs the current tictactoe board
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  board - tictactoe grid
 * POST-CONDITIONS
 *  board - outputs the current grid
******************************************************************************/
void drawBoard(const vector <char> &board) //OUTPUT - tictactoe board
{
    //OUTPUT - outputs each element of the board vector in a tictactoe format
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << board.at(i) << "  |  " << board.at(i + 1) << "  |  "
             << board.at(i + 2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;
}

/******************************************************************************
 * FUNCTION initVector
 * ____________________________________________________________________________
 * sets up the vector -> returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  vector - vector with 9 empty spaces
 * POST-CONDITIONS
 *  vector - new vector with alphabetical characters
******************************************************************************/
void initVector(vector <char> &v)  //OUTPUT - vector board
{
    char letter;      //OUTPUT - current letter
    letter = 97;

    //PROCESSING - fills the vector from characters a to i
    for (size_t i = 0; i < v.size(); i++)
    {
        v.at(i) = letter;
        letter++;
    }
}

/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
/******************************************************************************
 * FUNCTION convertPosition
 * ____________________________________________________________________________
 * converts a character position into a numerical value and subtracts 97 to
 *  match the vector index
 *  - returns the index on the vector where the character is found
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  position - position on the grid
 * POST-CONDITIONS
 *  board_index - returns index on the vector
******************************************************************************/
int convertPosition(char position)  //INPUT - initial position on grid
{
    int board_index;   //OUTPUT - index on the vector

    //PROCESSING - converts the position to an index on the vector
    board_index = position - 97;
    return board_index;
}

/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
/******************************************************************************
 * FUNCTION validPlacement
 * ____________________________________________________________________________
 * This function checks if the inputted position is a valid placement on the
 * board.
 *  - returns true if valid and false if invalid
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  board - current tictactoe grid
 *  position - inputted position after conversion
 * POST-CONDITIONS
 *  returns true if valid and false if invalid
******************************************************************************/
bool validPlacement(const vector <char> &board, //OUTPUT - board vector
                                  int position) //INPUT - position on board
{
    //PROCESSING - checks if the inputted position is a valid position
    //             on the board
    //           - returns false if invalid and true if valid
    if ((position >= 9) || (position < 0))
    {
        return false;
    }
    if ((board.at(position) == 'x') || (board.at(position) == 'o'))
    {
        return false;
    }
    return true;
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board
/// @return an integer index in board vector of a chosen available board spot
/******************************************************************************
 * FUNCTION getPlay
 * ____________________________________________________________________________
 * This function prompts the user to input a move, and checks if the move is
 *  valid. If it is, it will convert it to a position in the vector and return
 *  its position.
 *  - returns index in the vector
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  board - tictactoe grid
 * POST-CONDITIONS
 *  board_index - returns the index in the vector
******************************************************************************/
int getPlay(const vector <char> &board) //OUTPUT - board
{
    char pos;           //INPUT - position on the board, user input
    int board_index;    //OUTPUT - index in the vector derived from input pos

    //PROCESSING - gets char position from user and converts to an index on
    //             the vector, and returns the index
    do
    {
        //INPUT - getting pos
        cout << "Please choose a position: ";
        cin >> pos;

        //convertPosition - converts char pos to an index on the vector
        board_index = convertPosition(pos);

        //validPlacement - checks if the index is a valid position
    } while (validPlacement(board, board_index) != true);

    return board_index;
}

/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board
/// @return true if the game has been won, false otherwise
/******************************************************************************
 * FUNCTION gameWon
 * ____________________________________________________________________________
 * This function checks if a player has won the game.
 *  - returns true if a player won and false otherwise
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  board - tictactoe grid in current turn
 * POST-CONDITIONS
 *  returns true if a player won and false otherwise
******************************************************************************/
bool gameWon(const vector <char> &board)  //OUTPUT - the board
{
    //PROCESSING - checks every possible win combination to see if a player
    //             has won
    //           - if a possible winning sequence has matches then a player won
    //           - returns true if a player has won and false if not won
    if (((board.at(0) == board.at(1)) && (board.at(0) == board.at(2))) ||
        ((board.at(3) == board.at(4)) && (board.at(3) == board.at(5))) ||
        ((board.at(6) == board.at(7)) && (board.at(6) == board.at(8))) ||

        ((board.at(0) == board.at(3)) && (board.at(0) == board.at(6))) ||
        ((board.at(1) == board.at(4)) && (board.at(1) == board.at(7))) ||
        ((board.at(2) == board.at(5)) && (board.at(2) == board.at(8))) ||

        ((board.at(0) == board.at(4)) && (board.at(0) == board.at(8))) ||
        ((board.at(2) == board.at(4)) && (board.at(2) == board.at(6))))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board
/// @return true iff the board is full (no cell is available)
/******************************************************************************
 * FUNCTION boardFull
 * ____________________________________________________________________________
 * This function checks if the board is full
 *  - returns true if board is full and false if board is not full
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  board - tictactoe board in current turn
 * POST-CONDITIONS
 *  returns true if full and false if not
******************************************************************************/
bool boardFull(const vector <char> &board)  //OUTPUT - tictactoe board
{
    //PROCESSING - checks if each position in the board is not an x or o
    //           - if there is a position on the board that is not an x or o,
    //             it means the board is not filled, and returns false
    for (size_t i = 0; i < board.size(); i++)
    {
        if ((board.at(i) != 'x') && (board.at(i) != 'o'))
        {
            return false;
        }
    }

    return true;
}
void winnerCheck(const vector <char> & board)
{
    char player_letter;
    player_letter = 'x';
    if (((board.at(0) == player_letter) && (board.at(1) == player_letter) && (board.at(2) == player_letter)) ||
        ((board.at(3) == player_letter) && (board.at(4) == player_letter) && (board.at(5) == player_letter)) ||
        ((board.at(6) == player_letter) && (board.at(7) == player_letter) && (board.at(8) == player_letter)) ||

        ((board.at(0) == player_letter) && (board.at(3) == player_letter) && (board.at(6) == player_letter)) ||
        ((board.at(1) == player_letter) && (board.at(4) == player_letter) && (board.at(7) == player_letter)) ||
        ((board.at(2) == player_letter) && (board.at(5) == player_letter) && (board.at(8) == player_letter)) ||

        ((board.at(0) == player_letter) && (board.at(4) == player_letter) && (board.at(8) == player_letter)) ||
        ((board.at(2) == player_letter) && (board.at(4) == player_letter) && (board.at(6) == player_letter)))
    {
        cout << "Player 1 wins!!" << endl;
    }
    else
        cout << "Player 2 wins!!" << endl;
}

// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;
int main()
{
    //variable declaration
    vector <char> board(9);  //OUTPUT - tictactoe board
    int curPlay;             //OUTPUT - current play, move a player makes
    int turn = PLAYER1;      //OUTPUT - player turn, x or o, start with player1
    char player_letter;      //OUTPUT - letter of current player

    //initVector - sets up the board
    initVector(board);
    //drawBoard - outputs the board state at current turn
    drawBoard(board);

    //PROCESSING - while there is no winner and board is not full, gets a
    //             position from each player and sets them on the board
    while (boardFull(board) != true)
    {
        //getPlay - getting a valid move from player
        curPlay = getPlay(board);

        //PROCESSING - places x on desired position of PLAYER1 and o if player2
        if (turn == PLAYER1)
        {
            board.at(curPlay) = 'x';
            turn = PLAYER2;
        }
        else if (turn == PLAYER2)
        {
            board.at(curPlay) = 'o';
            turn = PLAYER1;
        }
        //drawBoard - outputs the board at its current state
        drawBoard(board);

        //PROCESSING - checks if there is a winner, and outputs
        //             the winner, if any.
        //gameWon - checks if there is a winner for the game
        if (gameWon(board) == true)
        {
            //winnerCheck - checks to see which player won
            winnerCheck(board);
            break;
        }
        //boardFull - checks if the board is full
        if (boardFull(board) == true)
        {
            if (gameWon(board) == true)
            {
                winnerCheck(board);
                break;
            }
            else
            {
                cout << "No one wins." << endl;
                break;
            }

        }
    }

    return 0;
}
