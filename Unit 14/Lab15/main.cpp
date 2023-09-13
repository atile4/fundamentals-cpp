/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Lab 15 - Movie Data
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/15/23
******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;
/******************************************************************************
 * OUTPUTTING MOVIE DATA
 * ____________________________________________________________________________
 * This program accepts 2 string inputs, a movie title director, and 2 integer
 *  inputs, year and runtime, and from data from another txt file and an
 *  intialized movie data structure, outputs all the movie data.
 * ____________________________________________________________________________
 * INPUT
 *  data -
 *  infile - input file
 * OUTPUT
 *  movie data - outputs movie data from txt file and from user input
******************************************************************************/

/******************************************************************************
 * struct MovieData
 * ____________________________________________________________________________
 * title - title of movie
 * director - director of movie
 * year_released - year movie was released
 * run_time - run time of movie in minutes
******************************************************************************/
struct MovieData
{
    string title;
    string director;
    int year_released;
    int run_time;
};
/******************************************************************************
 * FUNCTION printMovieData
 * ____________________________________________________________________________
 * Outputs the data in the MovieData struct array
 *  - returns nothing -> outputs data
******************************************************************************/
void printMovieData(const MovieData &m);

const int LENGTH = 12;   //INPUT - length of the array
int main()
{
    //variable declaration
    MovieData data[LENGTH];   //OUTPUT - array of structs with movie data
    ifstream infile;          //INPUT - input file

    //PROCESSING - sets first element of data with information
    data[0] = {"Apollo 13", "Ron Howard", 1995, 140};

    //INPUT - getting data to append to second element
    cout << "Enter Title: ";
    getline(cin, data[1].title);
    cout << "\nEnter Director: ";
    getline(cin, data[1].director);
    cout << "\nEnter Year Released: ";
    cin >> data[1].year_released;
    cout << "\nEnter Running Time (in minutes): ";
    cin >> data[1].run_time;
    cout << endl;

    infile.open("movies.txt");

    //PROCESSING - reads in data input from the file and sets to the
    //              variables in the MovieData structure
    for (int index = 2; index < LENGTH; index++)
    {
        getline(infile, data[index].title);
        getline(infile, data[index].director);
        infile >> data[index].year_released >> data[index].run_time;
        infile.ignore();
        infile.ignore();
    }

    //OUTPUT - outputs each element stored in data structure array
    for (int index = 0; index < LENGTH; index++)
    {
        printMovieData(data[index]);
    }

    infile.close();
    return 0;
}

/******************************************************************************
 * FUNCTION printMovieData
 * ____________________________________________________________________________
 * Outputs the data in the MovieData struct'
 * - returns nothing -> outputs data in the array
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  m - an element in the struct data array
 * POST-CONDITIONS
 *  outputs data in the array
******************************************************************************/
void printMovieData(const MovieData &m)
{
    cout << "Title: " << m.title << endl;
    cout << "Director: " << m.director << endl;
    cout << "Year released: " << m.year_released << endl;
    cout << "Running Time: " << m.run_time << endl;
    cout << endl;
}
