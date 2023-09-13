/******************************************************************************
 * AUTHOR       : Atticus Wong
 * Assignment #3: Mathematics Specification
 * CLASS        : CS 002
 * SECTION      : TRF: 7a - 10:50a
 * Due Date     : 5/21/23
******************************************************************************/
#include <iostream>
#include <cmath>
/******************************************************************************
 * Mathematics Operation from User Input
 * ____________________________________________________________________________
 * This program takes in a string input from the user. If the input is
 *  acceptable, the program will ask for multiple floating point numbers
 *  depending on the string input, and performs their corresponding
 *  mathematical operations.
 * ____________________________________________________________________________
 * INPUT:
 *  operation_name: name of the operation, determines the path of the program
 *  num1: first float to perform mathematical operations on, input from user
 *  num2: second float for mathematical operations, input from user
 *  num3: third float for mathematical operations, input from user
 * OUTPUT:
 *  result1: holds solution of all mathematical operations
 *  result2: holds the second solution for quadratic operations if necessary
******************************************************************************/
using namespace std;

int main()
{
    //variable declaration
    string operation_name;   //INPUT - operation name to determine program path

    //INPUT - geting string input from user to determine the program path
    cout << "Please choose an operation: ";
    cin >> operation_name;

    //PROCESSING - checks if input matches an operation
    if ((operation_name != "addition") && (operation_name != "subtraction") &&
        (operation_name != "division") && (operation_name != "multiplication") &&
        (operation_name != "fabs") && (operation_name != "sqrt") &&
        (operation_name != "quadratic") && (operation_name != "pythagorean"))
    {
        //OUTPUT - if the input doesn't match an operation, an error message
        //                                               will be outputted
        cout << "Error: Operation not supported." << endl;
    }
    //PROCESSING - if input matches an operation, the program continues running
    else
    {
        //variable declaration
        float num1;           //INPUT - first float for math operations
        float result1;        //CALC & OUT - contain solution of math operation

        //INPUT - getting first float for math operations
        cout << "Enter your first number: ";
        cin >> num1;

        //PROCESSING - makes and outputs calculations based on the user input
        if (operation_name == "sqrt")
        {
            //OUTPUT - outputs equation of the operation with inputted number
            cout << "Equation: sqrt(" << num1 << ")" << endl;

            //PROCESSING - if the inputted number is negative, the
            //                              program outputs an error message
            if (num1 < 0)
            {
                //OUTPUT - output error message
                cout << "\nError: Cannot take square "
                        "root of a negative number." << endl;
            }
            //PROCESSING - if the number is not negative the program
            //                         takes square root of the inputted number
            else
            {
                result1 = sqrt(num1);   //CALC - take square root of the number

                //OUTPUT - output result
                cout << "\nResult: " << result1 << endl;
            }
        }
        else if (operation_name == "fabs")
        {
            //OUTPUT - output equation with input number
            cout << "Equation: fabs(" << num1 << ") " << endl;

            result1 = fabs(num1);  //CALC - calculate absolute value of input number

            //OUTPUT - outputs result of equation
            cout << "\nResult: " << result1 << endl;
        }
        else
        {
            //variable declaration
            float num2;      //num2 - second float for operations

            //INPUT - getting float input for num2
            cout << "Enter your second number: ";
            cin >> num2;

            //PROCESSING - calculations for operations involving two numbers
            //PROCESSING - adding two numbers
            if (operation_name == "addition")
            {
                //OUTPUT - outputs equation with the two floats
                cout << "Equation: " << num1 << " + " << num2 << endl;

                result1 = num1 + num2;   //CALC & OUT - adds the numbers
                                         //         together and outputs result
                cout << "\nResult: " << result1 << endl;
            }

            //PROCESSING - subtracting one number from the other
            else if (operation_name == "subtraction")
            {
                //OUTPUT - output equation with the two floats
                cout << "Equation: " << num1 << " - " << num2 << endl;

                result1 = num1 - num2;  //CALC - subtracts the two numbers
                //OUTPUT - outputs result of the calculations
                cout << "\nResult: " << result1 << endl;
            }
            //PROCESSING - runs if operation input is multiplication
            else if (operation_name == "multiplication")
            {
                //PROCESSING - multiplies the two floats
                result1 = num1 * num2;

                //OUTPUT - outputs the equation and the result
                cout << "Equation: " << num1 << " * " << num2 << endl;
                cout << "\nResult: " << result1 << endl;
            }
            //PROCESSING - runs if operation input is division
            else if (operation_name == "division")
            {
                //OUTPUT - outputs equation with user inputs
                cout << "Equation: " << num1 << " / " << num2 << endl;

                //PROCESSING - checks if the divisor is 0.
                //                        if it is, output error messsage
                if (num2 == 0)
                {
                    //OUTPUT - output divide by zero error message
                    cout << "\nError: Cannot divide by zero." << endl;
                }
                else
                {
                    //PROCESSING - divides the first float by the second float
                    result1 = num1 / num2;
                    //OUTPUT - outputs results
                    cout << "\nResults: " << result1 << endl;
                }
            }
            //PROCESSING - checks if the string input is "pythagorean"
            else if (operation_name == "pythagorean")
            {
                //PROCESSING - squares both numbers, adds them
                //                    together, and takes square root of result
                result1 = sqrt((num1 * num1) + (num2 * num2));

                //OUTPUT - outputs pythagorean equation and result
                cout << "Equation: sqrt(" << num1
                     << "^2 + " << num2 << "^2)" << endl;
                cout << "\nResult: " << result1 << endl;
            }
            //PROCESSING - checks if string input is "quadratic"
            else if (operation_name == "quadratic")
            {
                //variable declaration
                float num3;        //INPUT - third float to use in operation
                float test_4ac;    //CALC - check for square rooting a negative

                //INPUT - getting third float for quadratic equation
                cout << "Enter your third number: ";
                cin >> num3;

                //OUTPUT - outputs equation with the three floats
                cout << "Equation: " << num1 <<"x^2 + "
                     << num2 << "x + " << num3 << " = 0" << endl;

                //PROCESSING - checks if the number inside
                //                      the square root will be negative
                test_4ac = (num2 * num2) - (4 * num1 * num3);
                if (test_4ac < 0)
                {
                    //OUTPUT - square root of a negative number error message
                    cout << "\nError: Cannot take square"
                            " root of a negative number." << endl;
                }
                else
                {
                    //PROCESSING - checks for dividing by zero error
                    //     if num1 is zero, then equation is solved differently
                    if (num1 == 0)
                    {
                        //PROCESSING - isolates the x in the equation to get it
                        result1 = (0 - num3)/ num2;

                        //OUTPUT - outputs results
                        cout << "\nResult: " << result1 << endl;
                    }
                    else
                    {
                        //variable declaration
                        float result2;      //OUTPUT - holds the second result

                        //PROCESSING - calculates the two results of
                        //                                      the quadratic
                        result1 = ((-1 * num2) + sqrt(test_4ac))/ (2 * num1);
                        result2 = ((-1 * num2) - sqrt(test_4ac))/ (2 * num1);

                        //OUTPUT - outputs results of the quadratic
                        cout << "\nResults: " << result1
                             << ", " << result2 << endl;
                    }

                }
            }
        }

    }

    return 0;
}
