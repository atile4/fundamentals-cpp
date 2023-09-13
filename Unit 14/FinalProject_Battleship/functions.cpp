#include <header.h>

/******************************************************************************
 * FUNCTION displayBoards
 * ____________________________________________________________________________
 * Outputs the two playerboards in the paramaters
 *  - returns nothing: outputs player grids
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 * player1 - player 1 board
 * player2 - player 2 game board
 * POST-CONDITIONS
 * this function outputs player boards
******************************************************************************/
void displayBoards(char player1[][10],  //INPUT - player 1 board
                   char player2[][10])  //INPUT - player 2 game board
{
    //OUTPUT - outputs both grids in a format
    cout << setw(28) << "Your Board" << setw(53) << "Enemy Board" << endl;
    cout << " ";
    for (int i = 0; i < 10; i++)
    {
        cout << setw(4) << i+1;
    }
    cout << "\t      ";
    for (int i = 0; i < 10; i++)
    {
        cout << setw(4) << i+1;
    }
    cout << endl;
    cout << "  " << setw(41) << setfill('-') << "-";
    cout << "\t       ";
    cout << setw(41) << setfill('-') << "-" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << static_cast<char>(i + 65) << " |";
        for (int j = 0; j < 10; j++)
        {
            cout << " " << player1[i][j] << " |";
        }
        cout << "\t     ";

        cout << static_cast<char>(i + 65) << " |";
        for (int j = 0; j < 10; j++)
        {
            cout << " " << player2[i][j] << " |";
        }

        cout << endl;
        cout << "  " << setw(41) << setfill('-') << "-";
        cout << "\t       ";
        cout << setw(41) << setfill('-') << "-" << endl;
        cout << setw(0) << setfill(' ');
    }

}

/******************************************************************************
 * FUNCTION spaceOccupied
 * ____________________________________________________________________________
 * This function checks if a coordinate has been occupied.
 *  - returns true if unoccupied, false if occupied
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  player - current player
 *  row - ship row index
 *  col - ship column index
 *  ornt - orientation of ship
 *  ship_index - index of ship
 * POST-CONDITIONS
 *  returns true if coordinate is not taken, false if taken yet
******************************************************************************/
bool spaceOccupied(PlayerBoard &player,  //INPUT - player
                               int row,  //INPUT - ship row index
                               int col,  //INPUT - ship column index
                             char ornt,  //INPUT - ship orientation
                        int ship_index)  //INPUT - ship index
{
    Ship player_ship = player.ships[ship_index];  //INPUT - player ship name

    //PROCESSING - checks if a spot on the ship overlaps with an
    //              existing placement
    for (int i = 0; i < player_ship.size; i++)
    {
        if ((player.board[row][col + i] == 's') && ornt == 'h')
        {
            return false;
        }
        else if ((player.board[row + i][col] == 's') && ornt == 'v')
        {
            return false;
        }
    }
    return true;
}

/******************************************************************************
 * FUNCTION getValidShipInfo
 * ____________________________________________________________________________
 * This function takes in a valid ship placement coordinate from the user
 *  - returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  player - the current player
 *  row - row index on the board
 *  col - column index on the board
 *  ornt - orientation of the ship
 *  ship_index - index of the ship
 * POST-CONDITIONS
 *  row - a valid row coordinate
 *  col - valid column coordinate on the board
******************************************************************************/
void getValidShipInfo(PlayerBoard &player,  //INPUT - current player
                                 int &row,  //INPUT - row index
                                 int &col,  //INPUT - column index
                               char &ornt,  //INPUT - ship orientation
                           int ship_index)  //INPUT - ship index
{
    //variable declaration
    Ship player_ship;       //INPUT - player ship name
    char row_letter;        //OUTPUT - row letter on the game board
    bool cont;              //INPUT - continue variable

    player_ship = player.ships[ship_index];

    cont = false;

    //PROCESSING - getting valid ship placement coordinates
    while (cont == false)
    {
        //INPUT - getting input coordinates and orientation from board for ship
        cout << "Enter the starting coordinates of your "
             << player_ship.name << ": ";
        cin >> row_letter >> col;
        row = static_cast<int>(row_letter) - 65;
        col = col - 1;
        cout << "Enter the orientation of your carrier "
                "(horizontal(h) or vertical(v)): ";
        cin >> ornt;

        //PROCESSING - checks if coordinates are outside of the board
        if (((row > 9) || (row < 0)) || ((col > 9) || (col < 0)))
        {
            cout << "Error: Ship placement is out of board." << endl;
            continue;
        }

        //PROCESSING - checking horizontal orientation coordinates
        if (ornt == 'h')
        {
            //PROCESSING - checks if ship extends outside of the board
            for (int i = 0; i < player.ships[ship_index].size; i++)
            {
                if (col + i > 9)
                {
                    cout << "Error: Ship placement is out of board." << endl;
                    cont = false;
                    break;
                }

                else
                {
                    //PROCESSING - if ship doesn't extend out of board
                    //              the program continues
                    if (player.ships[ship_index].size - 1 == i)
                    {
                        cont = true;
                        break;
                    }
                }

            }

            if (cont == true)
            {
                //spaceOccupied - checks if ship placement overlaps
                //                 with another ship
                if (spaceOccupied(player, row, col, ornt, ship_index) == false)
                {
                    cout << "Error: Space already occupied." << endl;
                    cont = false;
                    continue;
                }

            }
        }

        //PROCESSING - checking vertical orientation coordinates
        else if (ornt == 'v')
        {
            //PROCESSING - checks if ship goes beyond the board
            for (int i = 0; i < player.ships[ship_index].size; i++)
            {
                if (row + i > 9)
                {
                    cout << "Error: Ship placement is out of board." << endl;
                    break;
                }
                else if (player.ships[ship_index].size - 1 == i)
                {
                    cont = true;
                    break;
                }
            }
            if (cont == true)
            {
                //spaceOccupied - checks if inputted ship placement overlaps
                //                 with another ship
                if (spaceOccupied(player, row, col, ornt, ship_index) == false)
                {
                    cout << "Error: Space already occupied." << endl;
                    cont = false;
                    continue;
                }
            }

        }
    }

}

/******************************************************************************
 * FUNCTION placeShip
 * ____________________________________________________________________________
 * This function places a ship on the player board.
 * - returns a vector of the points for the ship number
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  player - current player board
 *  shipnum - ship index
 * POST-CONDITIONS
 *  player - plots a ship on the player board
 *  points - the coordinates of the ship
******************************************************************************/
vector <Point> placeShip(PlayerBoard &player,  //INPUT - current player board
                              size_t shipnum)  //INPUT - ship index
{
    //variable declaration
    int row;              //INPUT - row index
    int column;           //INPUT - column index
    char orient;          //INPUT - orientation of ship
    Ship player_ship;     //OUTPUT - player ship

    player_ship = player.ships[shipnum];

    //getValidShipInfo - gets valid coordinates and orientation for the ship
    getValidShipInfo(player, row, column, orient, shipnum);

    //PROCESSING - places the first coordinate of the ship on the baord
    player.board[row][column] = 's';

    //PROCESSING - places the ship on the board
    if (orient == 'h')
    {
        for (int i = 0; i < player_ship.size; i++)
        {
            player_ship.points.push_back({row, column + i});
            player.board[row][column + i] = 's';
        }

    }
    else if (orient == 'v')
    {
        for (int i = 0; i < player_ship.size; i++)
        {
            player_ship.points.push_back({row + i, column});
            player.board[row + i][column] = 's';

        }
    }

    return player_ship.points;

}

/******************************************************************************
 * FUNCTION boardSetup
 * ____________________________________________________________________________
 * This function sets up all the ships for a player.
 *  - returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  player1 - player to set board up
 * POST-CONDITIONS
 *  player1 board - sets ships on the board
 *  player1 points - sets the ship coordinates in the points vector
******************************************************************************/
void boardSetup(PlayerBoard &player1,  //INPUT - current player
                PlayerBoard &player2)  //OUTPUT - opposing player
{
    //PROCESSING - sets each ship in the fleet on the board
    for (int i = CARRIER; i < FLEET_SIZE; i++)
    {
        //placeShip - places a ship on the player board
        player1.ships[i].points = placeShip(player1, i);
        //displayBoards - outputs the player boards
        displayBoards(player1.board, player2.board);
    }
}

/******************************************************************************
 * FUNCTION initFleet
 * ____________________________________________________________________________
 * This function initializes the player fleet with its name, size, and hitpoint
 * - returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  player - player to initialize
 * POST-CONDITIONS
 *  player - player with added information
******************************************************************************/
void initFleet(PlayerBoard &player)  //IN - player to initialize
{
    //PROCESSING - gives the player information
    player.ships[CARRIER] = {"Carrier", CARRIER_SIZE, CARRIER_SIZE};
    player.ships[BATTLESHIP] = {"Battleship", BATTLESHIP_SIZE, BATTLESHIP_SIZE};
    player.ships[CRUISER] = {"Cruiser", CRUISER_SIZE, CRUISER_SIZE};
    player.ships[SUBMARINE] = {"Submarine", SUBMARINE_SIZE, SUBMARINE_SIZE};
    player.ships[DESTROYER] = {"Destroyer", DESTROYER_SIZE, DESTROYER_SIZE};
}

/******************************************************************************
 * FUNCTION getHit
 * ____________________________________________________________________________
 * This function gets a hit on an opposing player
 *  - returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *   enemy - enemy board with plotted ships
 *   enemy_hidden - enemy game board, ships are hidden from current player
 * POST-CONDITIONS
 *   enemy - plots a hit or miss on the board
 *   enemy_hiden - plots a hit or miss on the board
******************************************************************************/
void getHit(PlayerBoard &enemy,         //INPUT - player opponent board
            PlayerBoard &enemy_hidden)  //INPUT - player opponent game board
{
    //variable declaration
    char row_letter;    //OUTPUT - row letter on the board
    int col_num;        //OUTPUT - column number on the board
    int row_index;      //INPUT - row index
    int col_index;      //INPUT - column index
    bool cont;          //OUTPUT - continue boolean

    cont = false;

    //PROCESSING - gets a valid hit on
    while (cont == false)
    {
        //INPUT - getting a hit coordinate
        cout << "Fire a shot: ";
        cin >> row_letter >> col_num;

        //PROCESSING - converts the coordinates to index format
        row_index = static_cast<int>(row_letter) - 65;
        col_index = col_num - 1;

        //PROCESSING - validity check: checks if hit is on the board
        if ((row_index > 9) || (col_index > 9))
        {
            //OUTPUT - outputs invalid message
            cout << "Invalid" << endl;
            continue;
        }

        //checkHit - checks if the coordinate hit a ship
        checkHit(enemy, enemy_hidden, row_index, col_index, cont);

        //subtractHitCount - subtracts hitcount from enemy if a ship is hit
        subtractHitCount(enemy, row_index, col_index);
    }


}

/******************************************************************************
 * FUNCTION checkHit
 * ____________________________________________________________________________
 * This function checks if a ship has been hit
 *  - returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  enemy - enemy board
 *  enemyhidden - enemy game board
 * POST-CONDITIONS
 *  enemy board - sets the coordinate to hit or miss
 *  enemy game board - sets the coordinate to hit or miss
 *  cont - continue boolean
******************************************************************************/
void checkHit(PlayerBoard       &enemy,   //INPUT - enemy board
              PlayerBoard &enemyhidden,   //INPUT - hidden enemy board
                      int          row,   //INPUT - row index
                      int          col,   //INPUT - column index
                      bool       &cont)   //INPUT - continue boolean
{
    //PROCESSING - checks the state of the chosen coordiante and runs
    //               their corresponding functions
    //           - if a coordinate is valid, program can continue
    //empty spot: miss
    if (enemy.board[row][col] == ' ')
    {
        //PROC & OUT - outputs missed message and sets coordinate to miss
        cout << "You missed." << endl;
        enemyhidden.board[row][col] = 'M';
        enemy.board[row][col] = 'M';
        cont = true;
    }
    //rehit spot: invalid hit
    else if ((enemy.board[row][col] == 'H') || enemy.board[row][col] == 'M')
    {
        cout << "Invalid" << endl;
        cont = false;
    }
    //ship spot: valid hit
    else if (enemy.board[row][col] == 's')
    {
        //PROC & OUT - outputs hit message and sets coordinate to hit
        cout << "Hit!!!" << endl;
        enemyhidden.board[row][col] = 'H';
        enemy.board[row][col] = 'H';
        cont = true;
    }
}

/******************************************************************************
 * FUNCTION checkLoss
 * ____________________________________________________________________________
 * This function checks if the opposing player has all the ships sunken
 *  - returns true if player has lost
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  enemy - opposing player ships
 * POST-CONDITIONS
 *  this function returns true if all the ship hitcounts of the player are 0
******************************************************************************/
bool checkLoss(PlayerBoard enemy)  //IN - enemy hitcount
{
    for (int i = CARRIER; i < FLEET_SIZE; i++)
    {
        if (enemy.ships[i].hitcount == 0)
        {
            continue;
        }
        else if (enemy.ships[i].hitcount > 0)
        {
            return false;
        }
    }
    return true;
}

/******************************************************************************
 * FUNCTION checkDestroyed
 * ____________________________________________________________________________
 * This function checks if a ship has been destroyed
 *  - returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  enemy - opposing player ship hitcount
 *  ship_index - index of ship
 * POST-CONDITIONS
 *  outputs the name of a destroyed ship
******************************************************************************/
void checkDestroyed(PlayerBoard enemy, int ship_index)
{
    //PROCESSING - checks if a ship has been sunk
    if (enemy.ships[ship_index].hitcount == 0)
    {
        cout << "\n";
        cout << enemy.ships[ship_index].name << " has been destroyed!\n" << endl;
    }
}

/******************************************************************************
 * FUNCTION computerBoardSetup
 * ____________________________________________________________________________
 * This function sets up the game board.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *   computer - computer board
 * POST-CONDITIONS
 *   computer board - places ships on the board
******************************************************************************/
void computerBoardSetup(PlayerBoard &computer)
{
    //PROCESSING - places ships on the board
    for (int i = CARRIER; i < FLEET_SIZE; i++)
    {
        computer.ships[i].points = computerPlaceShip(computer, i);
    }
}

/******************************************************************************
 * FUNCTION computerPlaceShip
 * ____________________________________________________________________________
 * This function places a ship on the computer board.
 *  - returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  computer - computer board
 *  shipnum - ship index
 *  - returns a vector of the points that the ship takes up
 * POST-CONDITIONS
 *  computer - places a ship on the board
******************************************************************************/
vector <Point> computerPlaceShip(PlayerBoard &computer,//INPUT - computer board
                                        size_t shipnum)//INPUT - ship index
{
    //variable declaration
    int row;            //INPUT - row index
    int column;         //INPUT - column index
    char orient;        //INPUT - ship orientation
    Ship computer_ship; //INPUT - computer ship

    computer_ship = computer.ships[shipnum];

    //computerGetValidShipInfo - gets valid coordinates for ship placement
    computerGetValidShipInfo(computer, row, column, orient, shipnum);

    //PROCESSING - horizontal orientation
    if (orient == 'h')
    {
        //PROCESSING - adds all of the ship's coordinates to a vector
        //           - sets the position on the board to a ship point
        for (int i = 0; i < computer_ship.size; i++)
        {
            computer_ship.points.push_back({row, column + i});
            computer.board[row][column + i] = 's';
        }
    }
    //PROCESSING - vertical orientation
    else if (orient == 'v')
    {
        //PROCESSING - adds all of the ship's coordinates to a vector
        //           - sets the position on the board to a ship point
        for (int i = 0; i < computer_ship.size; i++)
        {
            computer_ship.points.push_back({row + i, column});
            computer.board[row + i][column] = 's';

        }
    }

    //returns a vector of the points that the ship takes up
    return computer_ship.points;

}

/******************************************************************************
 * FUNCTION computerGetValidShipInfo
 * ____________________________________________________________________________
 * This function gets valid ship coordinates and orientation for the ship
 *  - returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  computer - computer ship and board
 *  row - row index
 *  col - column index
 *  ornt - ship orientation
 *  ship_index - index of ship
 * POST-CONDITIONS
 *  row - valid row coordinate on the board
 *  col - valid column coordinate on the board
 *  ornt - valid orientation of the ship
******************************************************************************/
void computerGetValidShipInfo(PlayerBoard &computer, //INPUT - computer ship
                                           int &row, //INPUT - row index
                                           int &col, //INPUT - column index
                                         char &ornt, //INPUT - ship orientation
                                     int ship_index) //INPUT - ship index
{
    //variable declaration
    Ship comp_ship;          //INPUT - computer ship
    bool direction;          //INPUT - ship direction
    bool cont;               //OUTPUT - continuation boolean

    cont = false;

    comp_ship = computer.ships[ship_index];

    //PROCESSING - sets the orientation as horizontal or vertical
    direction = rand()%2;
    if (direction == 0)
    {
        ornt = 'h';
    }
    else if (direction == 1)
    {
        ornt = 'v';
    }

    //PROCESSING - getting a valid row and column index number
    while (cont == false)
    {
        //PROCESSING - getting random row and column number
        row = rand()%10;
        col = rand()%10;

        //PROCESSING - checks if placement of a ship is valid
        if (ornt == 'h')
        {
            //spaceOccupied - checks if ship placement overlaps with another
            if (spaceOccupied(computer, row, col, ornt, ship_index) == false)
            {
                continue;
            }

            //PROCESSING - checks if a ship goes out of boundaries
            for (int i = 0; i < computer.ships[ship_index].size; i++)
            {
                if (col + i > 9)
                {
                    break;
                }

                else
                {
                    if (computer.ships[ship_index].size - 1 == i)
                    {
                        cont = true;
                        break;
                    }
                }
            }
        }

        //PROCESSING - checks if placement of a ship is valid
        else if (ornt == 'v')
        {
            //spaceOccupied - checks if ship placement overlaps with another
            if (spaceOccupied(computer, row, col, ornt, ship_index) == false)
            {
                continue;
            }

            //PROCESSING - checks if a ship goes out of boundaries
            for (int i = 0; i < computer.ships[ship_index].size; i++)
            {

                if (row + i > 9)
                {
                    break;
                }
                else if (computer.ships[ship_index].size - 1 == i)
                {
                    cont = true;
                    break;
                }
            }
        }
    }
}

/******************************************************************************
 * FUNCTION computerGetHit
 * ____________________________________________________________________________
 * This function gets a valid hit for the computer
 *  - returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  enemy - enemy board
 *  enemy_hidden - enemy hidden board
 * POST-CONDITIONS
 *  enemy - marks a hit or miss on the board
 *  enemy_hidden - marks a hit or miss on the board
******************************************************************************/
void computerGetHit(PlayerBoard &enemy, PlayerBoard &enemy_hidden)
{
    //variable declaration
    int row_index;                     //INPUT - row index
    int col_index;                     //INPUT - column index
    bool cont;                         //INPUT - continue boolean
    size_t target_index;               //INPUT - random index in targets to hit
    static vector<Point> targets;      //OUTPUT - list of targets to hit
    static string fire_mode = "hunt";  //INPUT - firing mode

    targets.reserve(44);

    cont = false;

    //PROCESSING - depending on firing mode, program runs different functions
    while (cont == false)
    {
        //PROCESSING - hunt mode: computer fires at random spots on the board
        if (fire_mode == "hunt")
        {
            //PROCESSING - gets random numbers for row and column index
            row_index = rand()%10;
            col_index = rand()%10;

            //computerCheckHit - checks if hit a ship
            if (computerCheckHit(enemy, enemy_hidden, row_index,
                                 col_index, cont) == true)
            {
                //PROCESSING - if hit, firing mode is set to target, and
                //              points surrounding the hit are added to a list
                //              of targets to hit
                //           - firing mode is set to target
                fire_mode = "target";

                if (enemy_hidden.board[row_index - 1][col_index] == ' ')
                {
                    targets.push_back({row_index - 1, col_index});
                }
                if (enemy_hidden.board[row_index + 1][col_index] == ' ')
                {
                    targets.push_back({row_index + 1, col_index});
                }
                if (enemy_hidden.board[row_index][col_index - 1] == ' ')
                {
                    targets.push_back({row_index, col_index - 1});
                }
                if (enemy_hidden.board[row_index][col_index + 1] == ' ')
                {
                    targets.push_back({row_index, col_index + 1});
                }
            }

//            cout << "Computer is in " << fire_mode << " mode." << endl;
//            cout << "Computer has " << targets.size() << " targets." << endl;
        }

        //PROCESSING - target mode: computer htis points in a list
        else if (fire_mode == "target")
        {
            //PROCESSING - gets a random point in targets to hit
            target_index = static_cast<int>(rand()%targets.size());
            row_index = targets.at(target_index).row;
            col_index = targets.at(target_index).column;

            //computerCheckHit - checks if computer hit a ship
            if (computerCheckHit(enemy, enemy_hidden, row_index,
                                 col_index, cont) == true)
            {
                //PROCESSING - adds surrounding points of a successful hit
                //               to targets list
                if (enemy_hidden.board[row_index - 1][col_index] == ' ')
                {
                    targets.push_back({row_index - 1, col_index});
                }
                if (enemy_hidden.board[row_index + 1][col_index] == ' ')
                {
                    targets.push_back({row_index + 1, col_index});
                }
                if (enemy_hidden.board[row_index][col_index - 1] == ' ')
                {
                    targets.push_back({row_index, col_index - 1});
                }
                if (enemy_hidden.board[row_index][col_index + 1] == ' ')
                {
                    targets.push_back({row_index, col_index + 1});
                }
            }

            //PROCESSING - deletes a hit from the targets vector
            targets.erase(targets.begin() + target_index);

            //PROCESSING - if there are no more targets, firing mode is hunt
            if (targets.size() == 0)
            {
                fire_mode = "hunt";
            }

        }
        //subtractHitCount - marks off hitcount from a successful hit
        subtractHitCount(enemy, row_index, col_index);
    }

}

/******************************************************************************
 * FUNCTION computerCheckHit
 * ____________________________________________________________________________
 * This function checks if a hit or miss or invalid.
 *  - returns true if a hit is valid, false if invalid
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *   enemy - enemy board
 *   enemyhidden - enemy game board
 *   row - row index
 *   col - column index
 *   cont - continue boolean
 * POST-CONDITIONS
 *   enemy - marks a successful hit or miss
 *   enemyhidden - marks a successful hit or miss
******************************************************************************/
bool computerCheckHit(PlayerBoard &enemy,         //INPUT - enemy baord
                      PlayerBoard &enemyhidden,   //INPUT - enemy game board
                                       int row,   //INPUT - row of hit
                                       int col,   //INPUT - column of hit
                                    bool &cont)   //INPUT - continue boolean
{
    //variable declaration
    static int hits_remaining = 17;   //OUTPUT - number of hits left for player
    static int hits = 0;              //OUTPUT - number of hits dealt by computer

    //PROCESSING - if missed, program marks off the board as a miss
    if (enemy.board[row][col] == ' ')
    {
        //OUTPUT - outputs results of a the hit
        cout << "Computer: " << static_cast<char>(row + 65) << " " << col + 1 << endl;
        cout << "Computer missed." << endl;
        hits = hits + 1;
//        cout << "Fired shots: " << hits << endl;
//        cout << "Hits remaining: " << hits_remaining << endl;

        //PROCESSING - marks the point as a miss
        enemyhidden.board[row][col] = 'M';
        enemy.board[row][col] = 'M';
        cont = true;
        return false;
    }
    //PROCESSING - invalid hit
    else if ((enemy.board[row][col] == 'H') || enemy.board[row][col] == 'M')
    {
        cont = false;
        return false;
    }

    //PROCESSING - if hit, program marks the point as a hit
    else if (enemy.board[row][col] == 's')
    {
        //OUTPUT - outputs result of the hit
        cout << "Computer: " << static_cast<char>(row + 65)
             << " " << col + 1 << endl;
        cout << "Computer hit!!!" << endl;

        //PROCESSING - adds to hit and subtracts from hits remaining
        hits_remaining = hits_remaining - 1;
        hits = hits + 1;

        //OUTPUT - outputs results of hit
        cout << "Fired shots: " << hits << endl;
        cout << "Hits remaining: " << hits_remaining << endl;

        //PROCESSING - sets the attack point as hit
        enemyhidden.board[row][col] = 'H';
        enemy.board[row][col] = 'H';

        cont = true;
        return true;
    }
}

/******************************************************************************
 * FUNCTION subtractHitCount
 * ____________________________________________________________________________
 * If a hit lands on a ship, this function subtracts 1 from the ship's hitcount
 * - returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *   enemy - enemy board
 *   row - row index of the hit
 *   col - column index of the hit
 * POST-CONDITIONS
 *   enemy - subtracts from a ship's hitcount
******************************************************************************/
void subtractHitCount(PlayerBoard &enemy, int row, int col)
{
    //variable declaration
    bool cont;           //INPUT - continuation boolean
    int ship_index;      //INPUT - ship index

    cont = false;
    ship_index = 0;

    //PROCESSING - searches through the coordinates of each ship
    //           - if a hit matches a point in a ship, the hitcount of that
    //              ship is deducted
    while ((ship_index < FLEET_SIZE) && cont == false)
    {
//        cout << "size of points vector: " << (enemy.ships[ship_index].points).size() << endl;
        for (size_t i = 0; i < (enemy.ships[ship_index].points).size(); i++)
        {

            if ((enemy.ships[ship_index].points.at(i).row == row) &&
                (enemy.ships[ship_index].points.at(i).column == col))
            {
                enemy.ships[ship_index].hitcount -= 1;

                cont = true;

                enemy.ships[ship_index].points.erase(enemy.ships[ship_index].points.begin() + i);

                //checkDestroyed - checks if a ship has been destroyed
                checkDestroyed(enemy, ship_index);
                break;
            }
        }
        ship_index++;
    }
}
