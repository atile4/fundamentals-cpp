/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Lab 12
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/9/23
******************************************************************************/
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/******************************************************************************
 * Lab 12
 * ____________________________________________________________________________
 * Prompts user for a sentence, and then outputs a menu list with the functions
 *   that the user can do on the sentence. The program runs the chosen function
 *   until it is stopped.
 * ____________________________________________________________________________
 * INPUT
 *  text_input[]: a sentence, 100 characters max, user input
 *  menu_selection: option on the menu, user input
 * OUTPUT
 *  menu: display menu prompted upon specific input
 *  vowels: amount of vowels in the sentence
 *  consonants: amount of consonants in the sentence
 *  sentence: displays the sentence
******************************************************************************/

/*countVowel - counts the number of vowels in the array parameter*/
int countVowel(char[]);

/*countConsonant - counts the number of consonants in the array parameter*/
int countConsonant(char[]);

/*convertUpper - converts all the letter characters into uppercase */
void convertUpper(char[]);

/*convertLower - converts all the letter characters into lowercase */
void convertLower(char[]);

/*displayMenu - outputs the menu*/
void displayMenu();

const int SIZE = 100;     //global variable, array size 100
int main()
{
    //variable declaration
    char menu_selection;    //INPUT - picks which option to run
    char text_input[SIZE];  //INPUT - a sentence

    //INPUT - getting sentence from user
    cout << "Input a line of text, up to 100 characters: " << endl;
    cin.getline(text_input, SIZE);

    //OUTPUT - outputting display menu
    cout << "A)  Count the number of vowels in the string\n"
            "B)  Count the number of consonants in the string\n"
            "C)  Convert the string to uppercase\n"
            "D)  Convert the string to lowercase\n"
            "E)  Display the current string\n"
            "F)  Enter another string\n\n"

            "M)  Display this menu\n"
            "X)  Exit the program\n" << endl;

    //PROCESSING - getting user menu selection input, then runs
    //               their corresponding functions
    while (menu_selection != 'x')
    {
        //INPUT - getting menu_selection input
        cout << "Enter your menu selection: ";
        cin >> menu_selection;

        if (tolower(menu_selection) == 'a')
        {
            //countVowel - counts number of vowels in sentence
            cout << "\nNumber of vowels: " << countVowel(text_input) << endl;
            cout << "\n";
        }
        else if (tolower(menu_selection) == 'b')
        {
            //countVowel - counts number of consonants in sentence
            cout << "\nNumber of consonants: "
                 << countConsonant(text_input) << endl;
            cout << "\n";
        }
        else if (tolower(menu_selection) == 'c')
        {
            //convertUpper - converts all letters to uppercase
            convertUpper(text_input);
            cout << "\n";
        }
        else if (tolower(menu_selection) == 'd')
        {
            //convertLower - converts all letters to lowercase
            convertLower(text_input);
            cout << "\n";
        }
        else if (tolower(menu_selection) == 'e')
        {
            //OUTPUT - outputs the current array
            cout << "\n" << text_input << endl;
            cout << "\n";
        }
        else if (tolower(menu_selection) == 'f')
        {
            //PROCESSING - sets new array to text_input
            cin.ignore();
            cout << "\nInput a new line of text, "
                    "up to 100 characters: " << endl;
            cin.getline(text_input, SIZE);
        }
        else if (tolower(menu_selection) == 'm')
        {
            //displayMenu - outputs menu
            displayMenu();
        }

        else if (tolower(menu_selection) == 'x')
        {
            cout << "\n";
            break;
        }
    }

    return 0;
}
/******************************************************************************
 * FUNCTION countVowel
 * ____________________________________________________________________________
 * This function counts the amount of vowels in the array parameter and returns
 *   the number of vowels.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  text[]: sentence input
 * POST-CONDITIONS
 *  returns amount of vowels
******************************************************************************/
int countVowel(char text[]) //INPUT - a sentence
{
    int count = 0;
    //PROCESSING - checks if a character is a vowel
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] == 'a') || (text[i] == 'A'))
        {
            count = count + 1;
        }
        else if ((text[i] == 'e') || (text[i] == 'E'))
        {
            count = count + 1;
        }
        else if ((text[i] == 'i') || (text[i] == 'I'))
        {
            count = count + 1;
        }
        else if ((text[i] == 'o') || (text[i] == 'O'))
        {
            count = count + 1;
        }
        else if ((text[i] == 'u') || (text[i] == 'U'))
        {
            count = count + 1;
        }
    }

    return count;
}

/******************************************************************************
 * FUNCTION countConsonant
 * ____________________________________________________________________________
 * This function counts the amount of consonants in the array parameter and
 *   returns the number of consonants.
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  text[]: sentence input
 * POST-CONDITIONS
 *  returns amount of consonants
******************************************************************************/
int countConsonant(char text[]) //INPUT - a sentence
{
    int count = 0;

    //PROCESSING - checks if the letter is not a vowel
    //           - filters out non alphabetical characters
    for (int i = 0; text[i] != '\0'; i++)
    {

        if (isalpha(text[i]))
        {
            if (((((tolower(text[i]) != 'a') && (tolower(text[i]) != 'e')) &&
                  (tolower(text[i]) != 'i')) && (tolower(text[i]) != 'o')) &&
                (tolower(text[i]) != 'u'))
            {
                count = count + 1;
            }
        }

    }
    return count;
}

/******************************************************************************
 * FUNCTION convertUpper
 * ____________________________________________________________________________
 * This function converts all the characters into upper case, returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  text[]: sentence input
 * POST-CONDITIONS
 *  returns nothing -> changes all the lower case letters into upper case
******************************************************************************/
void convertUpper(char text[]) //INPUT - a sentence
{
    //PROCESSING - if a letter is not upper case, it is changed into uppercase
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]) == false)
        {
            text[i] = toupper(text[i]);
        }
    }
}

/******************************************************************************
 * FUNCTION convertLower
 * ____________________________________________________________________________
 * This function converts all the characters into lower case, returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  text[]: sentence input
 * POST-CONDITIONS
 *  returns nothing -> changes all the upper case letters into lower case
******************************************************************************/
void convertLower(char text[]) //INPUT - a sentence
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (islower(text[i]) == false)
        {
            text[i] = tolower(text[i]);
        }
    }
}

/******************************************************************************
 * FUNCTION displayMenu
 * ____________________________________________________________________________
 * This function outputs the display menu, returns nothing
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  None
 * POST-CONDITIONS
 *  returns nothing -> outputs a display menu
******************************************************************************/
void displayMenu()
{
    //OUTPUT - outputs menu options
    cout << "\nA)  Count the number of vowels in the string\n"
            "B)  Count the number of consonants in the string\n"
            "C)  Convert the string to uppercase\n"
            "D)  Convert the string to lowercase\n"
            "E)  Display the current string\n"
            "F)  Enter another string\n\n"

            "M)  Display this menu\n"
            "X)  Exit the program\n" << endl;
}
