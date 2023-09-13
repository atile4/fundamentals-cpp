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
 *  lower - lower bound of random numbers
 *  upper - upper bound of random numbers
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
double rand_mv(double, double);

int main()
{
    srand(500);
    //variable declaration
    const double LOWER = 4;       //INPUT - min range of random numbers
    const double UPPER = 10;      //INPUT - max range of random numbers
    const int SIZE_100 = 100;     //INPUT - length of first sequence
    const int SIZE_10000 = 10000; //INPUT - length of second sequence
    const int SIZE_500 = 500;     //INPUT - length of sequences 3-6

    double list1[SIZE_100];       //OUT - random floats array from sequence 1
    double list2[SIZE_10000];     //OUT - random floats array from sequence 2
    double list3[SIZE_500];       //OUT - random floats array from sequence 3
    double list4[SIZE_500];       //OUT - random floats array from sequence 4
    double list6[SIZE_500];       //OUT - random floats array from sequence 5
    double list5[SIZE_500];       //OUT - random floats array from sequence 6
    double lower, upper;          //OUT - lower and upperbound of generated num
    double theor_mean, theor_var; //OUT - theoretical mean and variance
    double prat_mean, prat_var;   //OUT - practical mean and variance
    double total;                 //OUT - total for calculating mean
    double mean_input;            //IN - theoretical average, user input
    double variance_input;        //IN - theoretical variance, user input


    //PART 1
    //PROCESSING - gets a random float from 4 to 10 and assigns to index
    //               in array
    //           - adds the float to a total sum
    total = 0;
    for (int i = 0; i < SIZE_100; i++)
    {
        list1[i] = randFloat(LOWER, UPPER);
        total = total + list1[i];
    }
    //PROCESSING - calculates theoretical mean and variance
    theor_mean = (LOWER + UPPER) / 2;
    theor_var = ((UPPER - LOWER) * (UPPER - LOWER))/12;

    //PROCESSING - calculates practical mean from the total
    prat_mean = total/SIZE_100;

    //PROCESSING - calculating practical variance
    total = 0;
    for (int i = 0; i < SIZE_100; i++)
    {
        list1[i] = pow(list1[i] - prat_mean, 2);
        total = total + list1[i];
    }
    prat_var = total/(SIZE_100);

    //OUTPUT - outputting restults
    cout << theor_mean << " " << prat_mean << " "
         << theor_var << " " << prat_var << endl;

    //PROCESSING - gets a random float from 4 to 10 and assigns to index
    //               in array
    //           - adds the float to a total sum
    total = 0;
    for (int i = 0; i < SIZE_10000; i++)
    {
        list2[i] = randFloat(LOWER, UPPER);
        total = total + list2[i];
    }

    //PROCESSING - calculates practical mean from the total
    prat_mean = total/(SIZE_10000);

    //PROCESSING - calculating practical variance
    total = 0;
    for (int i = 0; i < SIZE_10000; i++)
    {
        list2[i] = pow(list2[i] - prat_mean, 2);
        total = total + list2[i];
    }

    //PROCESSING - calculate practical variance
    prat_var = total/SIZE_10000;

    //OUTPUT - output results
    cout << theor_mean << " " << prat_mean << " "
         << theor_var << " " << prat_var << endl;
    cout << "\n";

    //PART 2
    //PROCESSING - setting lower and upper to values based on mean and variance
    lower = 2.7752551286084109509013579626471;
    upper = 5.2247448713915890490986420373529;

    //PROCESSING - getting random floats and setting to array
    //           - adds to total
    total = 0;
    for (int i = 0; i < SIZE_500; i++)
    {
        list3[i] = randFloat(lower, upper);
        total = total + list3[i];
    }

    //PROCESSING - calculating theoretical mean and var, and practical mean
    theor_mean = (lower + upper)/2;
    theor_var = ((upper - lower) * (upper - lower))/12;
    prat_mean = total/SIZE_500;

    //PROCESSING - calculating practical variance
    total = 0;
    for (int i = 0; i < SIZE_500; i++)
    {
        list3[i] = (list3[i] - prat_mean) * (list3[i] - prat_mean);
        total = total + list3[i];
    }
    prat_var = total/SIZE_500;

    //OUTPUT - outputting results
    cout << theor_mean << " " << prat_mean << " "
         << theor_var << " " << prat_var << endl;

    //PROCESSING - setting upper and lower based on mean(-4.0) and variance(3)
    lower = 1.550510257216822;
    upper = 6.449489742783178;

    //PROCESSING - getting random floats in range and setting to array
    //           - adds to total
    total = 0;
    for (int i = 0; i < SIZE_500; i++)
    {
        list4[i] = randFloat(lower, upper);
        total = total + list4[i];
    }

    //PROCESSING - calculating theoretical mean and var, and practical mean
    theor_mean = (lower + upper) / 2;
    theor_var = ((upper - lower) * (upper - lower)) / 12;
    prat_mean = total / SIZE_500;

    //PROCESSING - calculating practical variance using equation
    total = 0;
    for (int i = 0; i < SIZE_500; i++)
    {
        list4[i] = pow(list4[i] - prat_mean, 2);
        total = total + list4[i];
    }
    prat_var = total / SIZE_500;

    //OUTPUT - outputting results of calculations
    cout << theor_mean << " " << prat_mean << " "
         << theor_var << " " << prat_var << endl;
    cout << "\n";

    //PART 3
    //PROCESSING - setting lower and upper based on mean(0) and variance(-3)
    lower = -3;
    upper = 3;

    //PROCESSING - getting random floats in range and setting to array
    //           - adds to total
    total = 0;
    for (int i = 0; i < SIZE_500; i++)
    {
        list5[i] = randFloat(lower, upper);
        total = total + list5[i];
    }

    //PROCESSING - calculating theoretical mean and var, and practical mean
    theor_mean = (lower + upper) / 2;
    theor_var = pow(upper - lower, 2) / 12;
    prat_mean = total / SIZE_500;

    //PROCESSING - calculating practical mean
    total = 0;
    for (int i = 0; i < SIZE_500; i++)
    {
        list5[i] = pow(list5[i] - prat_mean, 2);
        total = total + list5[i];
    }
    prat_var = total / SIZE_500;

    //OUTPUT - output results of calulations
    cout << theor_mean << " " << prat_mean << " "
         << theor_var << " " << prat_var << endl;

    //PROCESSING - setting upper and lower based on mean(-4) and variance(3)
    lower = -7;
    upper = -1;
    total = 0;

    //PROCESSING - getting random floats in range and setting to array
    //           - adds to total
    for (int i = 0; i < SIZE_500; i++)
    {
        list6[i] = randFloat(lower, upper);
        total = total + list6[i];
    }

    //PROCESSING - calculating theoretical mean and var, and practical mean
    theor_mean = (lower + upper) / 2;
    theor_var = ((upper - lower) * (upper - lower)) / 12;
    prat_mean = total / SIZE_500;

    total = 0;
    for (int i = 0; i < SIZE_500; i++)
    {
        list6[i] = pow(list6[i] - prat_mean, 2);
        total = total + list6[i];
    }
    prat_var = total / SIZE_500;
    cout << theor_mean << " " << prat_mean << " "
         << theor_var << " " << prat_var << endl;
    cout << "\n";

    //PART 4
    //INPUT - getting theoretical mean and variance values
    cout << "Enter Mean: " << endl;
    cin >> mean_input;
    cout << "Enter Variance: " << endl;
    cin >> variance_input;

    //rand_mv - generates random float between a
    //          calculated range with mean and variance paramters
    //OUTPUT - outputs the generated random float
    cout << rand_mv(mean_input, variance_input) << endl;


    return 0;

}

/*This function generates a random double value between a and b*/
double randFloat (double a, double b)
{
    return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}

/*This function calculates a float between a calculated range
 * using a mean and variance input*/
double rand_mv(double mean, double variance)
{
    double a, b;
    //PROCESSING - calculating lower and upper range with mean and variance
    a = mean - sqrt(variance * 12)/2;
    b = (mean * 2) - a;

    //OUTPUT - outputting lower and upper bounds
    cout << a << " " << b << endl;
    return randFloat(a, b);
}
