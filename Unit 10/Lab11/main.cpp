/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Lab 11
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/8/23
******************************************************************************/
#include <iostream>

using namespace std;

/******************************************************************************
 * ADDING AND MULTIPLYING MATRICES
 * ____________________________________________________________________________
 * This program takes two sets of integer inputs and assigns them to a
 *  2x3 matrix, then adds them together and outputs the result. The program
 *  then accepts inputs for a 2x3 matrix and a 3x3 matrix, and multiplies them
 *  together and outputs the result.
 * ____________________________________________________________________________
 * INPUT
 *  matrix_A: 2x3 matrix of integers, user input
 *  matrix_B: 2x3 matrix of integers, user input
 *  matrix_C: 2x3 matrix of integers, user input
 *  matrix_D: 3x3 matrix of integers, user input
 * OUTPUT
 *  sum_matrix: sum of matrix_A and matrix_B, 2x3 matrix
 *  product_matrix: product of matrix_C and matrix_D, 2x3 matrix
******************************************************************************/

const int M = 2;   //global variable, matrix dimension
const int N = 3;   //global variable, matrix dimension
const int Q = 2;   //global variable, matrix dimension
const int R = 3;   //global variable, matrix dimension
const int S = 3;   //global variable, matrix dimension

/******************************************************************************
 * matrixAdd
 *   This function recieves two matrices and adds them together and assigns
 *   to a sum matrix.
 *   - returns nothing -> changes the sum matrix with new values from addition
******************************************************************************/
void matrixAdd(const int a[][N], const int b[][N], int sum[][N] = 0);

/******************************************************************************
 * matrixMult
 *   This function recieves two matrices and multiplies them together, and
 *     assigns to a product matrix.
 *   - returns nothing -> changes the product matrix with new values
******************************************************************************/
void matrixMult(const int a[][R], const int b[][S], int product[][S]);

int main()
{
    //variable declaration
    int matrix_A[M][N];       //INPUT - 2x3 matrix
    int matrix_B[M][N];       //INPUT - 2x3 matrix
    int sum_matrix[M][N];     //OUTPUT - 2x3 matrix, sum of matrix A and B
    int matrix_C[M][N];       //INPUT - 2x3 matrix
    int matrix_D[N][N];       //INPUT - 3x3 matrix
    int product_matrix[M][N]; //OUTPUT - 2x3 matrix, product of matrix C and D

    //INPUT - getting integers for matrix_A
    cout << "Enter Matrix A(size 2x3): ";
    for (int rows = 0; rows < M; rows++)
    {
        for (int cols = 0; cols < N; cols++)
        {
            cin >> matrix_A[rows][cols];
        }
    }

    //INPUT - getting integers for matrix_B
    cout << "Enter Matrix B(size 2x3): ";
    for (int rows = 0; rows < M; rows++)
    {
        for (int cols = 0; cols < N; cols++)
        {
            cin >> matrix_B[rows][cols];
        }
    }
    //matrixAdd - adds matrix_A and matrix_B
    matrixAdd(matrix_A, matrix_B, sum_matrix);

    //OUTPUT - outputs the values stored in sum_matrix
    cout << "Res:" << endl;
    for (int rows = 0; rows < M; rows++)
    {
        for (int cols = 0; cols < N; cols++)
        {
            cout << sum_matrix[rows][cols] << " ";
        }
        cout << "\n";
    }

    //INPUT - getting integers for matrix_C
    cout << "Enter Matrix A(size 2x3): ";
    for (int rows = 0; rows < M; rows++)
    {
        for (int cols = 0; cols < N; cols++)
        {
            cin >> matrix_C[rows][cols];
        }
    }

    //INPUT - getting integers for matric_D
    cout << "Enter Matrix B(size 3x3): ";
    for (int rows = 0; rows < N; rows++)
    {
        for (int cols = 0; cols < N; cols++)
        {
            cin >> matrix_D[rows][cols];
        }
    }

    //matrixMult - multiplying matrix C and D together
    matrixMult(matrix_C, matrix_D, product_matrix);

    //OUTPUT - outputs each value in the product matrix
    cout << "Res:" << endl;
    for (int rows = 0; rows < Q; rows++)
    {
        for (int cols = 0; cols < R; cols++)
        {
            cout << product_matrix[rows][cols] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/******************************************************************************
 * matrixAdd
 *_____________________________________________________________________________
 *   This function recieves two matrices and adds them together and assigns
 *   to a sum matrix.
 *_____________________________________________________________________________
 * PRECONDITIONS
 *   matrix_A: first matrix
 *   matrix_B: second matrix
 *
 * POSTCONDITIONS
 *   sum_matrix: sum of first and second matrix
******************************************************************************/
void matrixAdd(const int a[][N], const int b[][N], int sum[][N])
{
    //PROCESSING - adds each value of matrix A with its corresponding value
    //              in matrix B, and sets it to a sum matrix
    for (int rows = 0; rows < M; rows++)
    {
        for (int cols = 0; cols < N; cols++)
        {
            sum[rows][cols] = a[rows][cols] + b[rows][cols];
        }
    }
}

/******************************************************************************
 * matrixMult
 *_____________________________________________________________________________
 *   This function recieves two matrices, one 2x3 and one 3x3 matrix, and
 *   multiplies them together
 *_____________________________________________________________________________
 * PRECONDITIONS
 *   matrix_C: first matrix
 *   matrix_D: second matrix
 *
 * POSTCONDITIONS
 *   product_matrix: product of the two matrices
******************************************************************************/
void matrixMult(const int a[][R], const int b[][S], int product[][S])
{
    //PROCESSING - loops through rows and columns of matrix C and D and
    //               multiplies those values together, and assigns to
    //               the product matrix.
    for (int i = 0; i < Q; i++)
    {
        for (int j = 0; j < R; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < R; k++)
            {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
