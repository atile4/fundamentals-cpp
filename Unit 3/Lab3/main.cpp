/******************************************************************************
 * AUTHOR    : Atticus Wong
 * Assignment: Lab 3
 * CLASS     : CS 002
 * SECTION   : TRF: 7a - 10:50a
 * Due Date  : 5/20/23
******************************************************************************/
#include <iostream>

using namespace std;
/******************************************************************************
 * Calculating Time and Simple Menu
 * ____________________________________________________________________________
 * The program takes in an integer input, and based off of it, it will either
 *  prompt the user for a integer number in seconds to calculate the time or
 *  prompt the user for a string to answer a set of options.
 * ____________________________________________________________________________
 * INPUT:
 *  exercise_number: integer that determines what the program runs, user input
 *  seconds: number of seconds, input from user
 *  response: string to pick the option from the menu, input from user
 * OUTPUT:
 *  days: number of days contained in seconds
 *  hours: number of hours contained in seconds
 *  minutes: number of minutes contained in seconds
 *  program answer: outputs a message based on the response value
******************************************************************************/
int main()
{
    //variable declaration
    int exercise_number;  //INPUT - integer to determine which path the
                                //                             program takes

    //INPUT - getting integer input for the exercise path
    cout << "Which exercise? ";
    cin >> exercise_number;

    //PROCESSING - EXERCISE PATH 1
    if (exercise_number == 1)
    {
        //variable declaration
        int seconds;        //INPUT - numnber of seconds

        //INPUT - getting integer input from user for amount of seconds
        cout << "Enter a number of seconds: ";
        cin >> seconds;

        if (seconds >= 86400)
        {
            //variable declaration
            int days;          //INPUT - number of days

            //PROCESSING - calculating amount of days in value of seconds
            days = seconds / 86400;

            if (days == 1)
            {
                //OUTPUT - outputs a singular day if only one day is found
                cout << "There is " << days << " day in "
                     << seconds << " seconds." << endl;
            }
            else
            {
                //OUTPUT - outputs amount of days found in seconds
                cout << "There are " << days << " days in "
                     << seconds << " seconds." << endl;
            }
        }
        else if (seconds >= 3600)
        {
            //variable declaration
            int hours;         //INPUT - number of hours

            //PROCESSING - calculating amount of hours found in seconds
            hours = seconds / 3600;

            if (hours == 1)
            {
                //OUTPUT - outputs a singular hour if only one day is found
                cout << "There is " << hours << " hour in "
                     << seconds << " seconds." << endl;
            }
            else
            {
                //OUTPUT - outputs amount of hours found in seconds
                cout << "There are " << hours << " hours in "
                     << seconds << " seconds." << endl;
            }

        }
        else if (seconds >= 60)
        {
            //variable declaration
            int minutes;      //INPUT - number of minutes

            //PROCESSING - calculating amount of minutes found in seconds
            minutes = seconds / 60;

            if (minutes == 1)
            {
                //OUTPUT - outputs a singular minute if only one day is found
                cout << "There is " << minutes << " minute in "
                     << seconds << " seconds." << endl;
            }
            else
            {
                //OUTPUT - outputs amount of minutes found in seconds
                cout << "There are " << minutes << " minutes in "
                     << seconds << " seconds." << endl;
            }
        }
    }
    //PROCESSING - EXERCISE PATH 2
    else if (exercise_number == 2)
    {
        //variable declaration
        string response;    //INPUT - response to menu of options

        //INPUT - getting input from user to use for a menu of options
        cout << "What do you want to do tonight?\n"
                "a. Go to the movies\n"
                "b. Eat out\n"
                "c. Hang out at the Mall\n"
                "d. Go watch the Dodgers\n";
        cin >> response;

        //PROCESSING - outputs different messages depending on user input
        //response A
        if ((response == "a") || (response == "A"))
        {
            //OUTPUT - message corresponding to A
            cout << "I know just the movie to see!" << endl;
        }
        //response B
        else if ((response == "b") || (response == "B"))
        {
            //OUTPUT - message corresponding to B
            cout << "Great! I've been wanting to try "
                    "that new Tuvaluan restaurant!" << endl;
        }
        //response C
        else if ((response == "c") || (response == "C"))
        {
            //OUTPUT - message corresponding to C
            cout << "You bring the cash!" << endl;
        }
        //response D
        else if ((response == "d") || (response == "D"))
        {
            //OUTPUT - message corresponding to D
            cout << "Take me out to the ball game ..." << endl;
        }
        //response none of the above
        else
        {
            //OUTPUT - message that does not correspond to any letter
            cout << "Nothing suits you, then? I guess "
                    "we'll just stay and program!" << endl;
        }

    }
    return 0;
}
