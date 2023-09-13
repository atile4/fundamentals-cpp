/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Lab 10
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/7/23
******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
/******************************************************************************
 * FINDING MEAN AND VARIANCE
 * ____________________________________________________________________________
 * This program calculates the theoretical and practical mean and variance from
 *   a random sequence, sequences of 100 and 10,000. The sequence have random
 *   floating point values between 4 and 10.
 * ____________________________________________________________________________
 * INPUT
 *  LOWER - lower bound of random numbers, 4
 *  UPPER - upper bound of random numbers, 10
 *  SIZE1 - size of sequence 1, 100
 *  SIZE2 - size of sequence 2, 10000
 * OUTPUT
 *  list1 - contain numbers from sequence 1
 *  list2 - contain numbers from sequence 2
 *  theor_mean - theoretical mean
 *  theor_var - theoretical variance
 *  prat_mean - practical mean
 *  prat_var - practical variance
 *  total - total sum
******************************************************************************/

/*This function generates a random double value between a and b*/
double randFloat(double, double);

int main()
{
    srand(500);
    //variable declaration
    const double LOWER = 4;       //INPUT - min range of random numbers
    const double UPPER = 10;      //INPUT - max range of random numbers
    const int SIZE1 = 100;        //INPUT - length of first sequence
    const int SIZE2 = 10000;      //INPUT - length of second sequence

    double list1[SIZE1];          //OUTPUT - array of numbers from sequence 1
    double list2[SIZE2];          //OUTPUT - array of numbers from sequence 2
    double theor_mean, theor_var; //OUTPUT - theoretical mean and variance
    double prat_mean, prat_var;   //OUTPUT - practical mean and variance
    double total;                 //OUTPUT - total sum


    total = 0;

    //PROCESSING - gets a random float from 4 to 10 and assigns to index
    //               in array
    //           - adds the float to a total sum
    for (int i = 0; i < SIZE1; i++)
    {
        list1[i] = randFloat(LOWER, UPPER);
        total = total + list1[i];
    }
    //PROCESSING - calculates theoretical mean and variance
    theor_mean = (LOWER + UPPER) / 2;
    theor_var = ((UPPER - LOWER) * (UPPER - LOWER))/12;

    //PROCESSING - calculates practical mean from the total
    prat_mean = total/SIZE1;

    //PROCESSING - calculating practical variance
    total = 0;
    for (int i = 0; i < SIZE1; i++)
    {
        list1[i] = pow(list1[i] - prat_mean, 2);
        total = total + list1[i];
    }
    prat_var = total/(SIZE1);

    //OUTPUT - outputting restults
    cout << theor_mean << " " << prat_mean << " " << theor_var << " " << prat_var << endl;

    total = 0;

    //PROCESSING - gets a random float from 4 to 10 and assigns to index
    //               in array
    //           - adds the float to a total sum
    for (int i = 0; i < SIZE2; i++)
    {
        list2[i] = randFloat(LOWER, UPPER);
        total = total + list2[i];
    }

    //PROCESSING - calculates practical mean from the total
    prat_mean = total/(SIZE2);

    //PROCESSING - calculating practical variance
    total = 0;
    for (int i = 0; i < SIZE2; i++)
    {
        list2[i] = pow(list2[i] - prat_mean, 2);
        total = total + list2[i];
    }

    //PROCESSING - calculate practical variance
    prat_var = total/SIZE2;

    //OUTPUT - output results
    cout << theor_mean << " " << prat_mean << " " << theor_var << " " << prat_var << endl;

    return 0;
}

/*This function generates a random double value between a and b*/
double randFloat (double a, double b)
{
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

