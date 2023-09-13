/******************************************************************************
 *  AUTHOR      : Atticus Wong
 *  Excercise #1: lab01_ex1
 *  CLASS       : CS 002
 *  SECTION     : TRF: 7:00a - 10:50a
 *  Due Date    : 5/16/23
******************************************************************************/

#include <iostream>

using namespace std;
/******************************************************************************
 * MATHEMATICAL OPERATIONS WITH INTEGERS
 * ____________________________________________________________________
 * This program takes in two integer inputs from the user and adds them,
 *  multiplies them, divides them, finds the remainder of the two integers,
 *  and outputs it to the console.
 * ____________________________________________________________________
 * INPUT:
 *     int1: first integer to perform mathematical operations on, user input
 *     int2: second integer to perform mathematical operations on, user input
 * OUTPUT:
 *     sum      : the sum of the two integers (num1 and num2)
 *     product  : the product of the two integers (num1 and num2)
 *     quotient : the quotient of the two integers (num1 divided by num2)
 *     remainder: the remainder of num1 divided by num2
******************************************************************************/

int main()
{
    //variables   - Data Table
    int int1;                              // INPUT - first integer to perform
                                           //     mathematical operations
    int int2;                              // INPUT - second integer to perform
                                           //     mathematical operations
    int sum;                               // contains sum of two inputs
    int product;                           // contains product of two inputs
    int quotient;                          // contains quotient of two inputs
    int remainder;                         // contains remainder of two inputs

    // INPUT -- retrieve numbers to perform mathematical operations on
    cout << "Enter the first integer: ";
    cin >> int1;
    cout << "Enter the second integer: ";
    cin >> int2;


    // PROCESSING -- calculating mathematical operations
    sum = int1 + int2;
    product = int1 * int2;
    quotient = int1 / int2;
    remainder = int1 % int2;

    // OUTPUT -- output result of the operations
    cout << int1 << " + " << int2 << " = " << sum << endl;
    cout << int1 << " * " << int2 << " = " << product << endl;
    cout << int1 << " / " << int2 << " = " << quotient << endl;
    cout << int1 << " % " << int2 << " = " << remainder << endl;

    return 0;
}
