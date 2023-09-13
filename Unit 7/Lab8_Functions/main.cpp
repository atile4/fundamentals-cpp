/******************************************************************************
 * Name      : Atticus Wong
 * Assignment: Lab 8
 * Class     : CS 002
 * Section   : TuThF - 7a-10:50a
 * Due Date  : 6/1/23
******************************************************************************/
#include <iostream>

using namespace std;

/******************************************************************************
 * Summing digits and Finding Primes
 * ____________________________________________________________________________
 * The program takes in an integer input, which determines the path the program
 *  takes. If the path is 1, the program will sum up the digits of user input,
 *  and if the path is 2, the program will find all the prime numbers within
 *  a range.
 * ____________________________________________________________________________
 * INPUT
 *  exercise_num: determines program path, user input
 *  num_digits: collection of integer digits, user input
 *  min: minimum in prime number location range
 *  max: maximum in prime number location range
 * OUTPUT
 *  sum: sum of the digits in num_digits
 *  prime numbers: the prime numbers located between num1 and num2
******************************************************************************/

/******************************************************************************
 * SumDigits
 *   The function receives an integer number and adds up all the digits in
 *   the number. If the integer is negative, it is converted to a positive.
 *   - returns sum of integers
******************************************************************************/
int SumDigits(int);
/******************************************************************************
 * IsPrime
 *   The function receives an integer, and returns True if the number is a
 *   prime number, and false if the number is a composite number
 *   - returns true/false
******************************************************************************/
bool IsPrime(int);

int main()
{
    //variable declaration
    int exercise_num;      //INPUT - determine which exercise to run

    //INPUT - getting exercise number for which exercise to run
    cout << "Which exercise? " << endl;
    cin >> exercise_num;

    //PROCESSING - if exercise number is 1, program runs the digit path
    //           - if exercise number is 2, program runs the prime path
    //EXERCISE 1
    if (exercise_num == 1)
    {
        //variable declaration
        int num_digits;        //INPUT - collection of digits to add

        //PROCESSING & OUT - accepts an integer input and
        //                 - adds all the digits in the input together
        //                 - if the input is 0, the program outputs
        //                     farewell message and quits
        //                 - outputs results of SumDigits if program passes
        do
        {
            cout << "Please enter an integer (0 to quit): " << endl;
            cin >> num_digits;

            //SumDigits - returns the total of the digits from input parameter
            if (SumDigits(num_digits) == 0)
                cout << "Goodbye " << endl;
            else
                cout << "The sum of the digits of "<< num_digits
                     << " is " << SumDigits(num_digits) << endl;
        }
        while (num_digits != 0);

    }
    //EXERCISE 2
    else if (exercise_num == 2)
    {
        //variable declaration
        int min, max;        //INPUT - min and max range of
                               //         locating prime numbers

        int count_blank;       //CALC - counts number of prime numbers
                               //     - if count reaches 8 it prompts
                               //         program to make a new line
        count_blank = 0;

        //INPUT - getting min and max range to look for prime numbers
        cout << "Please input two positive numbers: " << endl;
        cin >> min >> max;

        //PROC & OUT - outputs all the prime numbers between min and max range
        //           - makes a new line every 8 prime numbers outputted
        cout << "The prime numbers between " << min
             << " and " << max << " are: " << endl;
        for (int i = min; i <= max; i++)
        {
            //IsPrime - returns true if input is a prime, false if input is not
            if (IsPrime(i) == true)
            {
                cout << i << "\t";
                count_blank += 1;
            }
            if ((count_blank%8 == 0) && (count_blank > 0))
            {
                cout << "\n";
                count_blank = 0;
            }
        }
        cout << "\n";

    }
    return 0;
}

/******************************************************************************
 * FUNCTION SumDigits
 * ____________________________________________________________________________
 *   The function receives an integer number and adds up all the digits in
 *   the number. If the integer is negative, it is converted to a positive.
 *   - returns sum of integers
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  digits: program requires digits to calculate the total
 *
 * POST-CONDITIONS
 *  function returns the sum of the digits
******************************************************************************/
int SumDigits(int digits) //INPUT - collection of digits to sum up
{
    //variable declaration
    int sum;        //OUT - sum of digits
    sum = 0;

    //PROCESSING - checks if digits is negative
    //           - if negative, digits is convert to positive
    if (digits < 0)
    {
        digits = digits * -1;
    }

    //PROCESSING - adds each individual digit to the total sum
    while (digits > 0)
    {
        sum = sum + digits % 10;
        digits = digits/10;
    }
    return sum;
}

/******************************************************************************
 * FUNCTION IsPrime
 * ____________________________________________________________________________
 *   The function recieves an integer and determines if it is prime
 *   - returns true if number is prime, false if number is not
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  x: program requires a number to determine if it is prime
 * POST-CONDITIONS
 *  function returns a true or false
******************************************************************************/
bool IsPrime(int x)  //INPUT - number to check if prime or not
{
    //PROCESSING - checks to see if the number divided by at least one integer
    //              between 2 and the number has no remainder
    //           - if there is at least one integer, program returns true
    //           - if there are none, program returns false
    //           - skips if the number and the iterating number are the same
    for (int i = 2; i <= x; i++)
    {
        if (x == i)
            continue;
        else if (x%i == 0)
        {
            return false;
        }
    }
    return true;
}
