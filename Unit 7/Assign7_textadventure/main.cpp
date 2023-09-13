/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Lab 7
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/5/23
******************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

/******************************************************************************
 * TEXT ADVENTURE GAME
 * ____________________________________________________________________________
 * This program accepts two string inputs and using those inputs, sets up a
 *  text-based game. There are four rooms, or paths, that the program can run.
 *  The user inputs the room direction to enter and the program will run a
 *  function depending on the direction.
 * ____________________________________________________________________________
 * INPUT
 *   name: name of user, user input
 *   monster: monster name, user input
 *   door_direction: program path to take, user input
 * OUTPUT
 *   bananas: amount of bananas
 *   oranges: number of oranges
******************************************************************************/

/******************************************************************************
 * monsterRoom
 *  This function recieves a string as a input, and then turns the amount of
 *   bananas and oranges to 0.
 *   - returns nothing -> converts bananas and oranges values to 0
******************************************************************************/
void monsterRoom(string, int&, int&);

/******************************************************************************
 * genieRoom
 *  This function recieves a string as a input, and then adds 2 to bananas and
 *  1 to oranges.
 *   - returns nothing -> adds 2 to bananas and 1 to orange
******************************************************************************/
void genieRoom(int&, int&);

/******************************************************************************
 * pictureRoom
 *  This function recieves nothing as parameters, calls the drawPicture
 *   function
 *   - returns nothing -> calls the drawPicture function
******************************************************************************/
void pictureRoom();

/******************************************************************************
 * drawPicture
 *  This function recieves nothing as parameters, outputs a drawing
 *   - returns nothing -> outputs a drawing
******************************************************************************/
void drawPicture();

int main()
{
    srand(500);

    //variable declaration
    string name;               //INPUT - a name
    string monster_name;       //INPUT - name of monster
    char door_direction;       //INPUT - direction to take
    int alignment;             //OUTPUT - random alignment of the doors
    int bananas, oranges;      //OUTPUT - amount of bananas and oranges

    //INPUT - getting name and monster name
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Name your scariest monster: ";
    cin >> monster_name;

    bananas = 5;
    oranges = 3;

    //PROCESSING & OUT - each loop will output current state of the game
    while (1)
    {
        cout << name << ", you are in a room with 4 doors.\n" << endl;
        cout << "You are carrying " << bananas << " bananas and "
             << oranges << " oranges." << endl;

        //IN & PROC - gets a direction input, and depending on the
        //             random alignment, will run its corresponding functions
        //          - while loop runs as long as input is not valid
        while (1)
        {
            cout << "Pick a door to enter by typing the direction it is in (N/E/S/W): ";
            cin >> door_direction;
            if ((door_direction != 'N') && (door_direction != 'E') &&
                ((door_direction != 'S') && (door_direction != 'W')))
            {
                continue;
            }
            else
            {
                break;
            }
        }
        alignment = rand()%2;

        //alignment 0 layout
        if (alignment == 0)
        {
            //PROCESSING - runs different functions depending on door direction
            if (door_direction == 'N')
            {
                //monsterRoom - reverts bananas and oranges to 0
                monsterRoom(monster_name, bananas, oranges);
            }
            else if (door_direction == 'E')
            {
                //pictureRoom - outputs a picture
                pictureRoom();
            }
            else if (door_direction == 'S')
            {
                //genieRoom - adds 2 to bananas and 1 to oranges
                genieRoom(bananas, oranges);
            }
            else if (door_direction == 'W')
            {
                break;
            }
        }
        //alignment 1 layout
        if (alignment == 1)
        {
            //PROCESSING - runs different functions depending on door direction
            if (door_direction == 'N')
            {
                break;
            }
            else if (door_direction == 'E')
            {
                //genieRoom - adds 2 to bananas and 1 to oranges
                genieRoom(bananas, oranges);
            }
            else if (door_direction == 'S')
            {
                //monsterRoom - reverts bananas and oranges to 0
                monsterRoom(monster_name, bananas, oranges);
            }
            else if (door_direction == 'W')
            {
                //pictureRoom - outputs a picture
                pictureRoom();
            }
        }
    }

    //OUTPUT - outputs results
    cout << "\nYou found the exit!" << endl;
    cout << "Your score is " << bananas + oranges
         << "(" << bananas << " bananas and " << oranges
         << " oranges)." << endl;
    cout << "Bye bye!!!" << endl;

    return 0;
}

/******************************************************************************
 * FUNCTION monsterRoom
 *_____________________________________________________________________________
 *  This function recieves a string as a input, and then turns the amount of
 *   bananas and oranges to 0.
 *_____________________________________________________________________________
 * PRECONDITIONS
 *   monster - monster name
 *   bananas - amount of bananas
 *   oranges - amount of oranges
 *
 * POST-CONDITIONS
 *   bananas - sets value to 0
 *   oranges - sets value to 0
******************************************************************************/
void monsterRoom(string monster, int& bananas, int& oranges)
{
    bananas = 0;
    oranges = 0;
    cout << "\nWATCH OUT!!!" << endl;
    cout << monster << " attacks you and steals all of your"
                       " bananas and oranges." << endl;
}

/******************************************************************************
 * FUNCTION genieRoom
 *_____________________________________________________________________________
 *  This function recieves bananas and oranges as paramaters, then adds 2 to
 *   bananas and 1 to oranges
 *_____________________________________________________________________________
 * PRECONDITIONS
 *   bananas - amount of bananas
 *   oranges - amount of oranges
 *
 * POST-CONDITIONS
 *   bananas - adds 2 to value
 *   oranges - adds 1 to value
******************************************************************************/
void genieRoom(int& bananas, int& oranges)
{
    bananas = bananas + 2;
    oranges = oranges + 1;
    cout << "A genie pops out and grants you 2 bananas and 1 orange." << endl;
}

/******************************************************************************
 * FUNCTION drawPicture
 *_____________________________________________________________________________
 *  This function outputs a drawing.
 *_____________________________________________________________________________
 * PRECONDITIONS
 *   None
 *
 * POST-CONDITIONS
 *   outputs a picture of a drawing
******************************************************************************/
void drawPicture()
{
    cout << "        _--~~--_" << endl;
    cout << "      /~/_|  |_\\~\\" << endl;
    cout << "     |____________|" << endl;
    cout << "     |[][][][][][]|" << endl;
    cout << "   __| __         |__" << endl;
    cout << "  |  ||. |   ==   |  |" << endl;
    cout << " (|  ||__|   ==   |  |)" << endl;
    cout << "  |  |[] []  ==   |  |" << endl;
    cout << "  |  |____________|  |" << endl;
    cout << "  /__\\            /__\\" << endl;
    cout << "   ~~              ~~ " << endl;
    cout << endl;
}

/******************************************************************************
 * FUNCTION drawPicture
 *_____________________________________________________________________________
 *  This function calls drawPicture to output a drawing.
 *_____________________________________________________________________________
 * PRECONDITIONS
 *   drawPicture -
 *
 * POST-CONDITIONS
 *   outputs a picture of a drawing
******************************************************************************/
void pictureRoom()
{
    cout << "\nYou found a picture!" << endl;

    //drawPicture - outputs picture of a drawing
    drawPicture();
}
