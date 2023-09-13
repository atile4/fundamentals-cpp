#include <iostream>
using namespace std;


//clue: 10, division, modular tradition
int main()
{
    int ex;
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;
    if ( ex == 1 )
    {
        // All Exercise 1 code
        int isbn;
        int num1, num2, num3, num4, num5, num6, num7, num8, num9;
        int checksum;

        cout << "Please enter the first 9 digits of the ISBN: ";
        cin >> isbn;

        num9 = isbn % 10;
        isbn = isbn / 10;

        num8 = isbn % 10;
        isbn = isbn / 10;

        num7 = isbn % 10;
        isbn = isbn / 10;

        num6 = isbn % 10;
        isbn = isbn / 10;

        num5 = isbn % 10;
        isbn = isbn / 10;

        num4 = isbn % 10;
        isbn = isbn / 10;

        num3 = isbn % 10;
        isbn = isbn / 10;

        num2 = isbn % 10;
        isbn = isbn / 10;

        num1 = isbn % 10;
        isbn = isbn / 10;

        checksum = (1 * num1) + (2 * num2) + (3 * num3) +
                   (4 * num4) + (5 * num5) + (6 * num6) +
                   (7 * num7) + (8 * num8) + (9 * num9);
        checksum = checksum % 11;
        cout << "Checksum: " << checksum << "\n";
    }
    else if ( ex == 2 )
    {
        char letter;
        int number;

        cout << "Enter a character: ";

        cin >> letter;
        number = letter - 96;

        cout << letter << " is letter " << number << endl;
    }

    return 0;
}
