/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Assignment 9 - Temperature Distribution
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/11/23
******************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
/******************************************************************************
 * Temperature Distribution
 * ____________________________________________________________________________
 * This program accepts an input file and output file, and then based on the
 * information in the input file, it sets up a temperature grid with the four
 * edges from the input file. Then, it calculates each interior point by the
 * four cells adjacent to it until the biggest difference between the new value
 * and the old value is within the tolerance level from the input file.
 * ____________________________________________________________________________
 * INPUT
 *  ROWS - number of rows in grid
 *  COLS - number of columns in grid
 *  infile - input file
 *  infilename - name of input file, user input
 *  outfilename - name of output file, user input
 * OUTPUT
 *  grid - grid of temp distribution
 *  outfile - file to output to
******************************************************************************/
int main()
{
    //variable declaration
    const int ROWS = 6;       //INPUT - number of rows
    const int COLS = 8;       //INPUT - number of columns
    ifstream infile;          //INPUT - input file
    ofstream outfile;         //OUTPUT - output file
    string infilename;        //INPUT - input file name
    string outfilename;       //INPUT - input file name
    double grid[ROWS][COLS];  //OUTPUT - temp distribution grid
    float top_edge;           //INPUT - value of top edge of grid
    float right_edge;         //INPUT - value of right edge of grid
    float bottom_edge;        //INPUT - value of bottom edge of grid
    float left_edge;          //INPUT - value of left edge of grid
    float tolerance_level;    //INPUT - tolerance level of grid

    //INPUT - getting input/output file names and opening the files
    cout << "Enter input file name: " << endl;
    cin >> infilename;
    infile.open(infilename);
    cout << "\nEnter output file name: " << endl;
    cin >> outfilename;
    outfile.open(outfilename);
    cout << endl;


    if (infile)
    {
        //INPUT - getting values from input file
        infile >> top_edge;
        infile >> right_edge;
        infile >> bottom_edge;
        infile >> left_edge;
        infile >> tolerance_level;

        //PROCESSING - setting grid edges to respective values
        for (int i = 0; i < COLS; i++)
        {
            grid[0][i] = top_edge;
            grid[5][i] = bottom_edge;
        }
        for (int i = 1; i < ROWS - 1; i++)
        {
            grid[i][0] = left_edge;
            grid[i][7] = right_edge;
        }

        //PROCESSING - setting inner cells to 0.0
        for (int i = 1; i < ROWS - 1; i++)
        {
            for (int j = 1; j < COLS - 1; j++)
            {
                grid[i][j] = 0.0;
            }
        }

        //variable declaration
        double average;     //OUTPUT - average of 4 adjacent cells
        double curr_value;  //OUTPUT - value of cell before calculation
        double new_value;   //OUTPUT - value of cell after calculation
        double difference;  //OUTPUT - difference of values between new and old
        double max_diff;    //OUTPUT - highest difference in the grid

        //PROCESSING - calculates the average of the 4 cells adjacent to
        //             the current cell, and sets the result to it.
        //           - calculates the difference between the new value and the
        //             old value, and stores the highest value found
        //           - if the max difference is within the tolerance level, the
        //             loop ends
        do
        {
            max_diff = 0;
            for (int i = 1; i < ROWS - 1; i++)
            {
                for (int j = 1; j < COLS - 1; j++)
                {
                    curr_value = grid[i][j];
                    average = (grid[i+1][j] + grid[i-1][j] + grid[i][j+1] + grid[i][j-1]) / 4;
                    new_value = average;
                    grid[i][j] = average;
                    difference = abs(new_value - curr_value);
                    if (difference > max_diff)
                    {
                        max_diff = difference;
                    }
                }
            }

        } while (max_diff > tolerance_level);

        //OUTPUT - outputs the grid
        for (int i = 1; i < ROWS - 1; i++)
        {
            for (int j = 1; j < COLS - 1; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        //OUTPUT - stores the grid in the output file
        for (int i = 1; i < ROWS - 1; i++)
        {
            outfile << grid[i][1] << " " << grid[i][2] << " "
                    << grid[i][3] << " " << grid[i][4] << " "
                    << grid[i][5] << " " << grid[i][6] << " " << endl;
        }
    }

    //PROCESSING - closes the files
    infile.close();
    outfile.close();

    return 0;
}
