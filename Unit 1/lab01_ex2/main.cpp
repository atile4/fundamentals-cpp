/******************************************************************************
 *  AUTHOR      : Atticus Wong
 *  Excercise #2: lab01_ex2
 *  CLASS       : CS 002
 *  SECTION     : TRF: 7:00a - 10:50a
 *  Due Date    : 5/16/23
******************************************************************************/
#include <iostream>

using namespace std;
/******************************************************************************
 * CALCULATING THE SUM AND AVERAGE OF 6 FLOATS
 * ____________________________________________________________________
 * This program takes six floating point inputs from the user and finds the
 *  sum and average, then outputs it to the console.
 * ____________________________________________________________________
 * INPUT:
 *     num1   : first floating point number, input from user
 *     num2   : second floating point number, input from user
 *     num3   : third floating point number, input from user
 *     num4   : fourth floating point number, input from user
 *     num5   : fifth floating point number, input from user
 *     num6   : sixth floating point number, input from user
 * OUTPUT:
 *     num_sum  : the sum of all six floating point numbers
 *     average  : the average of the six floating point numbers
******************************************************************************/
int main()
{
    //variables   - Data Table
    float num1;                      //INPUT - first value to average
    float num2;                      //INPUT - second value to average
    float num3;                      //INPUT - third value to average
    float num4;                      //INPUT - fourth value to average
    float num5;                      //INPUT - fifth value to average
    float num6;                      //INPUT - sixth value to average
    float num_sum;                   //CALC & OUT - float sum of the six values
    float average;                   //CALC & OUT - average of the six values

    // INPUT -- retrieve numbers to take the average of
    cout << "Enter six fp numbers on a single line, "
                "separated by spaces: ";
    cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6;

    // PROCESSING -- taking the sum of numbers and calculating the average
    num_sum = num1 + num2 + num3 + num4 + num5 + num6;
    average = num_sum / 6;

    // OUTPUT -- output the full sum and the average
    cout << "Sum of " << num1 << " + " << num2 <<
        " + " << num3 << " + " << num4 << " + " <<
        num5 << " + " << num6 << " = " << num_sum << endl;
    cout << "Average = " << average << endl;

    return 0;
}
