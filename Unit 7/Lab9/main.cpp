/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Lab 6
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/3/23
******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;
/******************************************************************************
 * CALCULATING MIN, MAX, AND AVERAGE
 * ____________________________________________________________________________
 * This program finds lowest, highest, and average of the values in a
 *  valid file
 * ____________________________________________________________________________
 * INPUT
 *   exercise_num - determines which path program takes, user input
 *   filename - name of the file to retrieve values from, user input
 * OUTPUT
 *   min - smallest value
 *   max - biggest value
 *   average - average of all the values
 *   count - amount of numbers in file, used to calculate average
 *   prev_number_high = previous value to compare with current value, highest
 *   prev_number_low = previous value to compare with current value, lowest
******************************************************************************/

/******************************************************************************
 * FUNCTION findMinMax
 *   This function finds the lowest, highest, and average of the set of numbers
 *   in the file parameter
 *  - returns nothing -> changes the values of min, max, and average
******************************************************************************/
void findMinMax(string, int&, int&, float&);

/******************************************************************************
 * FUNCTION checkFile
 *   This function checks if the inputted file name is valid file, then runs
 *   the findMinMax function to find the lowest, highest, and average of the
 *    set of numbers in the file
 *  - returns bool value - true if valid, false if invalid
******************************************************************************/
bool checkFile(string, int&, int&, float&);

int main()
{
    //variable declaration
    int exercise_num;      //INPUT - exercise to run
    int min;               //OUTPUT - lowest number found
    int max;               //OUTPUT - highest number found
    float average;         //OUTPUT - average of all the numbers

    //INPUT - getting exercise number
    cout << "Which exercise? " << endl;
    cin >> exercise_num;

    //PROCESSING - exercise path 1
    //           - finds the lowest, highest, and average values of
    //              a set of numbers in a file from the storage
    if (exercise_num == 1)
    {
        //findMinMax - calculates the lowest, highest, and average values
        //              from the numbers in the file
        findMinMax("numbers.dat", min, max, average);

        //OUTPUT - outputs results
        cout << "The min is: " << min << endl;
        cout << "The max is: " << max << endl;
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1);
        cout << "The average is: " << average << endl;

    }
    //PROCESSING - exercise path 2
    else if (exercise_num == 2)
    {
        //variable declaration
        string filename;          //INPUT - name of file

        //INPUT - getting the file name
        cout << "Enter the name of the file: " << endl;
        cin >> filename;

        //PROCESSING - checks if the file name is a valid file
        //           - if file is valid, the function finds the lowest highest
        //            and average of the set of numbers in the file
        //           - if not valid the program outputs a seperate message
        if (checkFile(filename, min, max, average) == true)
        {
            //OUTPUT - outputs results of processing
            cout << "The max number is: " << max << endl;
            cout << "The min number is: " << min << endl;
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(1);
            cout << "The average is: " << average << endl;
        }
        else
            //OUTPUT - outputs unable to open file message
            cout << "Cannot open the file!" << endl;

    }
    return 0;
}
/******************************************************************************
 * FUNCTION findMinMax
 * ____________________________________________________________________________
 * This function finds the lowest, highest, and average of the set of numbers
 *   in the file parameter
 * ____________________________________________________________________________
 * PRE-CONDTIIONS
 *   filename: name of file
 *   min: lowest value
 *   max: highest value
 *   average: average of values
 *
 * POST-CONDITION
 *   This function changes the values of min, max, and averages according to
 *     values in the file
 *   min: lowest value in the file
 *   max: highest value in the file
 *   average: average of the values in the file
******************************************************************************/
void findMinMax(string filename,   //INPUT - name of file
                int& min,          //OUTPUT - lowest value in file
                int& max,          //OUTPUT - highest value in file
                float& average)    //OUTPUT - average of values in the file
{
    //variable declaration
    int number;             //OUTPUT - current number from the file
    float total;            //OUTPUT - total value of the numbers in the file
    int prev_number_low;    //OUTPUT - value prior to current number, comparison
                            //           for lowest number
    int prev_number_high;   //OUTPUT - value prior to current number,
                            //           comparison for higest number
    int count;              //OUTPUT - amount of values in the file
    fstream infile;         //INPUT - file to get numbers from

    //PROCESSING - setting up for finding max min and average
    infile.open(filename);
    total = 0;
    prev_number_low = 0;
    prev_number_high = 0;
    count = 0;

    //PROCESSING - looks through each number in the file and
    //               and finds the biggest and smallest numbers
    //           - counts the amount of numbers found in the file
    while (infile >> number)
    {
        count++;
        total = total + number;
        if (number > prev_number_high)
        {
            prev_number_high = number;
        }
        if (number < prev_number_low)
        {
            prev_number_low = number;
        }

        max = prev_number_high;
        min = prev_number_low;

    }
    //PROCESSING - finds the average of all the numbers in the file
    average = total/count;

    //PROCESSING - closes the file
    infile.close();
}

/******************************************************************************
 * FUNCTION checkFile
 * ____________________________________________________________________________
 * This function checks if the file valid. If file is valid, the function calls
 *   the findMinMax function to find the min max and average values, then
 *   returns true. If invalid, the function returns false.
 * ____________________________________________________________________________
 * PRE-CONDTIIONS
 *   filename: name of file to check
 *   min: lowest value
 *   max: highest value
 *   average: average of values
 *
 * POST-CONDITION
 *   returns a true/false if file is valid or not
 *   min: finds lowest value in the file and sets to min
 *   max: finds highest value in the file and sets to max
 *   average: average of the values in the file and sets to average
******************************************************************************/
bool checkFile(string filename,  //INPUT - name of file
               int& min,         //OUTPUT - lowest number in file
               int& max,         //OUTPUT - highest number in file
               float& average)   //OUTPUT - average of numbers in file
{
    fstream infile;          //INPUT - file to recieve input

    //PROCESSING - if able to open the file, program runs the findMinMax
    //                 and returns true
    //           - if unable to open file, program returns false
    infile.open(filename);
    if (infile)
    {
        //findMinMax - finds and returnslowest, highest, and average of numbers
        findMinMax(filename, min, max, average);

        return true;
    }
    else
        return false;
}
