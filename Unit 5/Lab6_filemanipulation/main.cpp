/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Lab 06
 * Class     : CS 002
 * Section   : 7a-10:50a
 * Due Date  : 5/30/23
******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
/******************************************************************************
Reading and Outputting in Files
______________________________________________________________________________
The program reads a set of raw data stored in a text file and using that
 data, it makes calculations and outputs the result into another text file.
______________________________________________________________________________
 * INPUT
 *  infile: input file to open the input file
 *  length: rectange length, input from file
 *  width: rectangle width, input from file
 *  radius: radius of the circle, input from file
 *  first_name, last_name: first and last name, input from file
 *  age: age of person, input from file
 *  beg_balance: principle balance, input from file
 *  rate: rate of interest, input from file
 *  ch1: character prior to processing, input from file
 * OUTPUT
 *  outfile: used to open the file to put the output
 *  area: area of the rectangle
 *  perimeter: rectangle perimeter
 *  circle_area: area of circle
 *  circumfrence: circumfrence of circle
 *  first_name, last_name: first and last name
 *  age: the age
 *  end_balance: balance after a month of simple interest
 *  ch2: character after ch1 in the ASCII set
******************************************************************************/

int main()
{
    //variable declaration
    ifstream infile;                 //INPUT - file to recieve input
    ofstream outfile;                //OUTPUT - file to output data

    float length, width;             //INPUT - length and width of rectangle
    float area, perimeter;           //OUTPUT - area and perimeter of rectangle
    float radius;                    //INPUT - radius of circle
    float circle_area, circumference; //OUTPUT - circle area and circumfrence

    string first_name, last_name;    //INP & OUT - name of person
    int age;                         //INP & OUT - age of person

    float beg_balance, rate;         //INPUT: principle balance & interest rate
    float end_balance;               //OUTPUT: balance after 1 month interest

    char ch1;                        //INPUT: inputted character
    char ch2;                        //OUTPUT: character after ch1 on ASCII set

    //PROCESSING - opening the specified file
    infile.open("inData.txt");

    //PROCESSING - checks if the file opened is a valid file
    if(infile)
    {
        //INPUT - retrieving data from text file and setting to variables
        infile >> length >> width;
        infile >> radius;
        infile >> first_name >> last_name >> age;
        infile >> beg_balance >> rate;
        infile >> ch1;

        //PROCESSING - rectangle calculations, area and width
        area = length * width;
        perimeter = (2 * length) + (2 * width);

        //PROCESSING - circle calculations, area and circumfrence
        circle_area = 3.14159 * (radius * radius);
        circumference = 2 * 3.14159 * radius;

        //PROCESSING - calculating balance after interest (P * R * T)
        end_balance = beg_balance + (beg_balance * (rate/100) * (1.0/12.0));

        //PROCESSING - calculating the character after ch1 on ASCII set
        ch2 = ch1 + 1;

        //OUTPUT - sending results to console
        //PROCESSING - floats are rounded to two decimal places
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "Rectangle:" << endl;
        cout << "Length = " << length << ", width = "
                << width << ", area = " << area
                << ", perimeter = " << perimeter << endl;

        cout << "\nCircle:" << endl;
        cout << "Radius = " << radius << ", area = " << circle_area
                << ", circumference = " << circumference << endl;

        cout << "\nName: " << first_name << " " << last_name << ", age: " << age << endl;
        cout << "Beginning balance = $" << beg_balance << ", interest rate = " << rate << endl;
        cout << "Balance at the end of the month = $" << end_balance << endl;
        cout << "\nThe character that comes after " << ch1 << " in the ASCII set is " << ch2 << endl;

        //OUTPUT - sending results to an output file
        outfile << "Rectangle: " << endl;
        outfile << "Length = " << length << ", width = "
             << width << ", area = " << area
             << ", perimeter = " << perimeter << endl;

        outfile << "\nCircle:" << endl;
        outfile << "Radius = " << radius << ", area = " << circle_area
             << ", circumfrence = " << circumference << endl;

        outfile << "\nName: " << first_name << " " << last_name << ", age: " << age << endl;
        outfile << "\nBeginning balance = $" << beg_balance << ", interest rate = " << rate << endl;
        outfile << "Balance at the end of the month = $" << end_balance << endl;
        outfile << "\nThe character that comes after " << ch1 << " in the ASCII set is " << ch2 << endl;

        //PROCESSING - closing the opened files
        infile.close();
        outfile.close();

    }
    else
    {
        cout << "File open failure." << endl;
    }

    infile.close();

    return 0;
}
