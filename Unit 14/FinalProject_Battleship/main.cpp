#include <header.h>
/******************************************************************************
 * BATTLESHIP
 * ____________________________________________________________________________
 * This program simulates the game Battleship. It first prompts the user to
 *  play against another player or to play against the computer, and then
 *  prompts all players to input coordinates on the battleship grid for ship
 *  placements. After all ships have been placed, the program prompts both
 *  players for coordinates on the opposing player's grid to attack. Both
 *  players attack until all of a player's ships have been sunk, then the
 *  program displays a victory message and ends.
 * ____________________________________________________________________________
 * INPUT
 *  player1 - player 1 information, board, ships, hitcounts, coordinates
 *  player2 - player 2 information, board, ships, hitcounts, coordinates
 *  player1_game - grid of player1 with ship spots hidden, used for player2
 *  player2_game - grid of player2 with ship spots hidden, used for player1
 *  mode - game mode: singleplayer or multiplayer
 *  cont - boolean to determine if program should continue
 * OUTPUT
 *  displayGrid - outputs both players grids
 *  currPlayer - current player of each turn
 *  winner - outputs the winner
******************************************************************************/
int main()
{
    srand(300);

    //variable declaration
    PlayerBoard player1;       //INPUT - player 1
    PlayerBoard player1_game;  //OUTPUT - player 1 hidden ships
    PlayerBoard player2;       //INPUT - player 2 or computer
    PlayerBoard player2_game;  //OUTPUT - player 2 hidden ships
    char mode;                 //INPUT - game mode
    bool cont;                 //INPUT - if loop should continue or restart
    bool currPlayer;           //OUTPUT - current player
    bool winner;               //OUTPUT - if there is a winner

    cout << "*****************************************\n";
    cout << " Programmed by : Atticus Wong\n";
    cout << " Student ID    : 10646506\n";
    cout << " CS 002        : TuThF - 7a-10:50a\n";
    cout << " Final Project : Battleship \n";
    cout << "*****************************************\n";

    //PROCESSING - setting all the grid spaces as empty
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            player1.board[i][j] = ' ';
            player2.board[i][j] = ' ';

            player1_game.board[i][j] = ' ';
            player2_game.board[i][j] = ' ';
        }
    }

    cont = false;

    //PROCESSING - setting the mode
    while (cont == false)
    {
        cout << "Multiplayer (m) or Singleplayer(s)? ";
        cin >> mode;
        switch (mode)
        {
        case 'm':
            cont = true;
            cout << "Multiplayer mode." << endl;
            break;

        case 's':
            cont = true;
            cout << "Singleplayer mode." << endl;
            break;

        default:
            cout << "Invalid input." << endl;
            break;
        }
    }

    //PROCESSING - setting player 1 board
    cout << "Player 1 set your board." << endl;
    //displayBoards - outputs player 1 board and player 2 game board
    displayBoards(player1.board, player2_game.board);
    //initFleet - sets up game information for player1
    initFleet(player1);
    //boardSetup - sets up the board for player 1
    boardSetup(player1, player2_game);

    cout << "\n\n\n\n";

    //initFleet - sets up game information for player 2
    initFleet(player2);

    //PROCESSING - setting up player 2 board
    //multiplayer path
    if (mode == 'm')
    {
        //PROCESSING - setting up player 2 board
        cout << "Player 2 set your board." << endl;
        //displayBoards - outputs the boards
        displayBoards(player2.board, player1_game.board);
        //boardSetup - sets up player 2 board
        boardSetup(player2, player1_game);
    }
    //singleplayer path
    else if (mode == 's')
    {
        //PROCESSING - plots points on the player 2 board
        cout << "Computer setting up the board.\n" << endl;
        //computerBoardSetup - randomly plots points on the player 2 board
        computerBoardSetup(player2);
        //displayBoards - outputs the boards
        displayBoards(player2.board, player1_game.board);
    }



    //currPlayer: 0 = player1, 1 = player2

    currPlayer = false;
    winner = false;

    //PROCESSING - runs as long as there is no winner
    while (winner == false)
    {
        cout << "\n\n\n\n";

        //PROCESSING - player 1 turn
        if (currPlayer == 0)
        {
            cout << "Player 1:" << endl;
            //displayBoards - outputs the board
            displayBoards(player1.board, player2_game.board);
            //getHit - gets a hit on player 2
            getHit(player2, player2_game);
            displayBoards(player1.board, player2_game.board);

            //checkLoss - checks if a player has lost
            //PROCESSING - if a player has lost, outputs victory message
            //           - otherwise, switches player and continues running

            if (checkLoss(player2) == true)
            {
                //OUTPUT - win message
                cout << "Player 1 has won!" << endl;
                winner = true;
            }
            else
            {
                currPlayer = 1;
            }
        }

        //PROCESSING - player 2 turn
        else if (currPlayer == 1)
        {
            //PROCESSING - if multiplayer, prompt user for attack coordinate
            //           - if singleplayer, computer chooses a spot to hit
            //multiplayer
            if (mode == 'm')
            {
                cout << "Player 2:" << endl;
                //displayBoards - outputs the board
                displayBoards(player2.board, player1_game.board);
                //getHit - gets a hit on player 1
                getHit(player1, player1_game);
                displayBoards(player2.board, player1_game.board);
            }
            //singleplayer
            else if (mode == 's')
            {
                //computerGetHit - computer gets a hit on player 1
                computerGetHit(player1, player1_game);
            }

            //checkLoss - checks if a player has lost
            //PROCESSING - if a player has lost, outputs victory message
            //           - otherwise, switches player and continues running
            if (checkLoss(player1) == true)
            {
                //multiplayer
                if (mode == 'm')
                {
                    //OUTPUT - outputs win message for player 2
                    cout << "\n\n\n\nPlayer 2 has won!" << endl;
                }
                else if (mode == 's')
                {
                    //OUTPUT - outputs win message for computer
                    cout << "\n\n\n\nComputer has won!" << endl;
                }
                winner = true;
            }
            else
            {
                currPlayer = 0;
            }

        }
    }

    return 0;
}
