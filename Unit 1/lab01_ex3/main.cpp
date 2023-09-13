/******************************************************************************
 *  AUTHOR      : Atticus Wong
 *  Excercise #3: lab01_ex3
 *  CLASS       : CS 002
 *  SECTION     : TRF: 7:00a - 10:50a
 *  Due Date    : 5/16/23
******************************************************************************/
#include <iostream>

using namespace std;
/******************************************************************************
 * TARGET HEART RATE CALCULATIONS WITH FLOATING POINT NUMBERS
 * ____________________________________________________________________
 * The program gets a floating point number input from the user, and subtracts
 *  it from 220. Then it multiplies that number by both 0.6 and 0.75 and
 *  outputs the result into the console.
 * ________________________________
 * INPUT:
 *     age: integer to plug into equation, recieved as input
 *
 * OUTPUT:
 *     lower_limit_bpm: result of lower bpm equation
 *     upper_limit_bpm: result of upper bpm equation
******************************************************************************/
int main()
{
    //variables   - Data Table
    int age;              //INPUT - age, input from user
    float lower_limit_bpm;//CALC & OUT - float value of lower bpm limit
    float upper_limit_bpm;//CALC & OUT - float value of upper bpm limit

    //INPUT -- get the age value from the user
    cout << "What is your age: ";
    cin >> age;

    //PROCESSING -- calculating lower and upper bpm with the equation
    lower_limit_bpm = (220 - age) * 0.60;
    upper_limit_bpm = (220 - age) * 0.75;

    //OUTPUT -- output the result of the equations
    cout << "Your target heart rate is between " <<
        lower_limit_bpm << " and " << upper_limit_bpm << " bpm.\n";

    return 0;
}
