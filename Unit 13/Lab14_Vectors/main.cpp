/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Lab 14 - Vectors
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/14/22
******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

/******************************************************************************
 * FUNCTION split
 * ____________________________________________________________________________
 * Splits the target string at the delimiter and appends the individual split
 *  strings to a vector
 *   - returns the vector with the strings
 * ____________________________________________________________________________
******************************************************************************/
vector<string> split(string, string);

/******************************************************************************
 * Splitting Strings at Delimiters using Vectors
 * ____________________________________________________________________________
 * This program accepts a target to split and a delimiter to split the string
 *  at, and then splits the string at the inputted delimiter.
 * ____________________________________________________________________________
 * INPUT
 *  target - target string
 *  delimiter - substring to seperate the target string at
 * OUTPUT
 *  split_strings - vector storing the individual split strings
******************************************************************************/
int main()
{
    //variable declaration
    string target;                //INPUT - string to seperate
    string delimiter;             //INPUT - delimiter to seperate string at
    vector<string> split_strings; //OUTPUT - stores seperated strings

    //INPUT - getting target and delimiter strings
    cout << "Enter the target string: " << endl;
    getline(cin, target);
    cout << "Enter the delimiter: " << endl;
    getline(cin, delimiter);

    //split - splits the target string at the delimiter
    split_strings = split(target, delimiter);

    //OUTPUT - outputs the values in the vector
    for (unsigned int i = 1; i < split_strings.size(); i++)
    {
        cout << split_strings.at(i) << endl;
    }
    cout << endl;

    return 0;
}

/******************************************************************************
 * FUNCTION split
 * ____________________________________________________________________________
 * Splits the target string at the delimiter and appends the individual split
 *  strings to a vector
 *   - returns the vector with the strings
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  target - string to split
 *  delimiter - substring in the target to split at
 * POST-CONDITIONS
 *  vector - returns a vector with each individual split string
******************************************************************************/
vector<string> split(string target, string delimiter)
{
    //variable declaration
    size_t start_pos;             //OUTPUT - starting position of seperation
    size_t end_pos;               //OUTPUT - ending position of seperation
    string sub;                   //OUTPUT - resulting substring after
                                  //         seperation
    vector<string> seperated (1); //OUTPUT - vector with seperated strings

    start_pos = 0;
    //PROC - SITATUION 1: if target does not start with delimiter
    if (delimiter.at(0) != target.at(0))
    {
        //PROCESSING - seperates the target string at the delimiter
        //           - program sets a starting position and an ending
        //             position, and then seperates the substring from the
        //             main string and appends to the vector
        while (target.find(delimiter, start_pos) != string::npos)
        {
            end_pos = target.find(delimiter, start_pos + 1);
            sub = target.substr(start_pos, end_pos - start_pos);
            seperated.push_back(sub);
            start_pos = delimiter.length() - 1 + end_pos + 1;
        }
        seperated.push_back(target.substr(start_pos, end_pos - start_pos));
    }
    //PROC - SITATION 2: if target starts with the delimiter
    else
    {
        //PROCESSING - seperates the target string at the delimiter
        //           - program sets a starting position and an ending
        //             position, and then seperates the substring from the
        //             main string and appends to the vector
        while (target.find(delimiter, start_pos) != string::npos)
        {
            start_pos = target.find(delimiter, start_pos) + delimiter.length();

            //PROCESSING - if the delimiter can still be found, program runs
            //             as normal
            //           - if delimiter is out of range, program appends
            //             whatever is left of the string to the vector
            if (target.find(delimiter, start_pos) != string::npos)
            {
                end_pos = target.find(delimiter, start_pos);
                sub = target.substr(start_pos, end_pos - delimiter.length());
            }
            else
            {
                end_pos = target.length() - 1;
                sub = target.substr(start_pos, end_pos);
            }
            seperated.push_back(sub);
            start_pos = end_pos;
        }
    }

    return seperated;
}
