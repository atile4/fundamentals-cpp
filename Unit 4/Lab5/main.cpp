/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Lab 5
 * Class     : CS 002
 * Section   : TuThF: 7a - 10:50a
 * Due Date  : 5/25/23
******************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

/******************************************************************************
* Using User Input to determine program path
* _____________________________________________________________________________
* The program takes in an integer input and depending on it the program will
*  take 1 of 3 paths. The first path will output numbers in a sequence, the
*  second will output sorted grades from user input, the third will simulate
*  a coin flip.
* _____________________________________________________________________________
* INPUT
*  exercise_num: value to determine program path
*  num1: minimun number in the sequence, user input, path 1
*  num2: max number in the sequence, user input, path 1
*  grade: value to calculate how many of each letter grade, user input path 2
*  ans: string value to determine if program runs again, user input path 3
* OUTPUT:
*  path 1: different sequences of numbers using values of num1 and num2
*  path 2: outputs amount of each letter grade from inputted grades
*  path 3: outputs result of the coin flip
******************************************************************************/
int main()
{
    //variable delcaration
    int exercise_num;        //INPUT - integer value to determine program path

    //INPUT - getting exercise number
    cout << "Which exercise? " << endl;
    cin >> exercise_num;

    //PROCESSING - Path 1
    if (exercise_num == 1)
    {

        int num1, num2;        //INPUT - min number and max number in sequence

        //INPUT - getting the min and max numbers for the sequence
        cout << "Enter beginning and ending numbers, "
                "separated by space: " << endl;
        cin >> num1 >> num2;
        //PROCESSING & OUT - outputs all the numbers between the inputted
        //                            min and max on the same line
        for (int i = num1; i <= num2; i++)
        {
            //PROCESSING & OUT - prints the number, and a comma if the
            //                                         sequence is not at end
            cout << i;
            if ((i >= num1) && (i < num2))
            {
                cout << ", ";
            }
        }

        //INPUT - getting the min and max numbers for the second sequence
        cout << "\nEnter beginning and ending numbers, "
                "separated by space: " << endl;
        cin >> num1 >> num2;

        //PROCESSING & OUT - outputs every other number in the sequence
        for (int i = num1; i <= num2; i+=2)
        {
            cout << i;
            //PROCESSING & OUT - outputs comma after every number if not at end
            if (i < (num2 - 1))
            {
                cout << ", ";
            }
        }

        //INPUT - getting the min and max numbers for the third sequence
        cout << "\nEnter the beginning and largest positive numbers"
                ", separated by space: " << endl;
        cin >> num1 >> num2;

        //variable declaration
        int j = 0;      //integer to calculate if current
        //                iteration should result in a negative/positive output

        //PROCESSING & OUT - outputs the numbers from min to max, with every
        //                                   iteration the number is doubled
        for (int i = num1; i <= num2; i*=2)
        {
            //PROCESSING & OUT - if j is odd, the number is set to negative
            //                   if j is even, the number is set to positive
            //                   the result of the check is output
            if (j%2 != 0)
            {
                cout << -1 * i;
            }
            else
            {
                cout << i;
            }

            //PROCESSING & OUT - determines if the number should have comma
            if (i < num2)
            {
                cout << ", ";
            }

            //PROCESSING - j is incremented by 1
            j = j + 1;


        }
        cout << "\n";
    }
    //PROCESSING - PATH 2
    else if (exercise_num == 2)
    {
        //variable declaration
        int grade;                        //INPUT - inputted grades, user input
        int As, Bs, Cs, Ds, Fs;           //OUTPUT - letter grade counters

        //PROCESSING - setting the counters to 0
        As = 0;
        Bs = 0;
        Cs = 0;
        Ds = 0;
        Fs = 0;

        //PROCESSING - runs for as long as the value of grade is not -1
        while (grade != -1)
        {
            //INPUT - getting integer value of grade from user
            cout << "Enter one or more grades, or -1 to stop: " << endl;
            cin >> grade;

            //PROCESSING - if the input is the sentinel then the loop breaks
            //           - if input is within a certain range then 1 is added
            //           -   to its corresponding counter
            if (grade == -1)
            {
                break;
            }
            else if ((grade >= 90) && (grade <= 100))
            {
                As = As + 1;
            }
            else if ((grade >= 80) && (grade <= 89))
            {
                Bs = Bs + 1;
            }
            else if ((grade >= 70) && (grade <= 79))
            {
                Cs = Cs + 1;
            }
            else if ((grade >= 60) && (grade <= 69))
            {
                Ds = Ds + 1;
            }
            else if ((grade <= 59) && (grade >= 0))
            {
                Fs = Fs + 1;
            }


        }
        //OUT - outputs results
        cout << "The grades breakdown is: " << endl;
        cout << "As: " << As << endl;
        cout << "Bs: " << Bs << endl;
        cout << "Cs: " << Cs << endl;
        cout << "Ds: " << Ds << endl;
        cout << "Fs: " << Fs << endl;



    }
    //PROCESSING PATH 3
    else if (exercise_num == 3)
    {
        //variable declaration
        string ans;              //INPUT - string input to hold yes or no input
        bool coinflip;           //CALC - random number between 0 and 1

        //PROCESSING - runs as long as ans is not no
        while (1)
        {
            //INPUT - getting input for ans
            cout << "Toss the coin? " << endl;
            cin >> ans;

            //PROCESSING - runs if the ans is yes, if it is no then loop breaks
            if (ans == "yes")
            {
                //PROCESSING - gets random number either 0 and 1 and
                //                                sets to boolean coinflip
                //            if coinflip is 0 result is heads
                //            if coinflip is 1 result is tails
                //                     outputs result of the coin flip
                coinflip = rand()%2 + 0;
                if (coinflip == 0)
                {
                    cout << "heads" << endl;
                }
                else if (coinflip == 1)
                {
                    cout << "tails" << endl;
                }
            }
            else if (ans == "no")
            {
                break;
            }
        }

    }
    return 0;
}
