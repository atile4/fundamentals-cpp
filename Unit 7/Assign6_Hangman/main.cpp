/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Assignment 6 - Hangman
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/3/23
******************************************************************************/
#include <iostream>

using namespace std;
/******************************************************************************
 * Hangman Game
 * ____________________________________________________________________________
 * The program takes a string input, and then continously accepts character
 *   inputs until the user has provided an input for each character in
 *   the string.
 * ____________________________________________________________________________
 * INPUT
 *  phrase: phrase to guess, user input
 *  guess: holds character input guesses, user input
 * OUTPUT
 *  phrase_lower: lower case version of phrase
 *  unsolved: holds all the found and hidden characters
 *  prev_guesses: holds all characters that were guessed
 *  wrong_guesses: number of incorrect guesses
******************************************************************************/

/******************************************************************************
 * setupUnsolved
 *   The function recieves a string input and returns a string with each
 *   character replaced with a '-'
 *   - returns string characters replaced with '-'
******************************************************************************/
string setupUnsolved(string);

/******************************************************************************
 * updateUnsolved
 *   This function finds the position of every instance of the char guess and
 *   replaces that position in string unsolved with the character
 *   - returns unsolved
******************************************************************************/
string updateUnsolved(string, string, char);

/******************************************************************************
 * getGuess
 *   This function will repeatedly prompt the user for a guess until it is
 *   valid.
 *   - returns the valid guess
******************************************************************************/
char getGuess(string);

/******************************************************************************
 * checkSolved
 *   This function checks if the unsolved phrase is solved
 *   - returns a true or false
******************************************************************************/
bool checkSolved(string);

int main()
{
    //variable declaration
    string phrase;            //INPUT - phrase to guess
    char guess;               //INPUT - guessing character
    string phrase_lower;      //PROC - phrase converted to lower case
    string unsolved;          //OUT - phrase with guessed and unguessed letters
    string prev_guesses;      //OUT - string with already guessed letters
    int wrong_guesses;        //OUT - countdown of number of wrong guesses

    //INPUT - getting phrase to use
    cout << "Enter phrase: ";
    getline(cin, phrase);


    //setUpUnsolved - converts letters in phrase to '-' and sets to unsolved
    unsolved = setupUnsolved(phrase);

    //PROCESSING - setting up game
    prev_guesses = "";
    wrong_guesses = 7;
    phrase_lower = phrase;

    //PROCESSING - converts letters in phrase to lower case
    for (int i = 0; i < phrase.size(); i++)
    {
        phrase_lower.at(i) = tolower(phrase.at(i));
    }

    //OUTPUT - outputs phrase
    cout << "Phrase: " << unsolved << endl;

    //PROC & OUT - recieves char input from user, if the input is found in the
    //              phrase, the positions with the char input in the phrase
    //              are replaced with the char input.
    //           - if the input is not found in the phrase, countdown of
    //              wrong_guesses decrements by 1
    //           - the inputted character is added to collection
    //              of guessed characters
    //           - if all letters in the phrase are guessed, program outputs
    //              a congratulatory message and exits.
    while (1)
    {
        //getGuess - gets a valid guess from user
        guess = getGuess(prev_guesses);

        //PROC - if guessed letter is found, unsolved variable is updated
        //     - if guessed letter is not found, the wrong guesses
        //       countdown decrements
        if (phrase_lower.find(guess) != string::npos)
        {
            //updateUnsolved - updates the unsolved variable with guessed chars
            unsolved = updateUnsolved(phrase, unsolved, guess);
        }
        else
        {
            wrong_guesses = wrong_guesses - 1;
        }

        prev_guesses = prev_guesses + string(1, guess);

        //OUTPUT - outputs results
        cout << "Guessed so far: " << prev_guesses << endl;
        cout << "Wrong guesses left: " << wrong_guesses << endl;
        cout << unsolved << "\n" << endl;

        //checkSolved - checks if the phrase has been solved
        if (checkSolved(unsolved) == true)
        {
            cout << "Congratulations!! You won!" << endl;
            break;
        }

    }

    return 0;
}
/******************************************************************************
 * FUNCTION setupUnsolved
 *_____________________________________________________________________________
 * The function recieves a string input and returns a string with each
 *   character replaced with a '-'
 *_____________________________________________________________________________
 * PRECONDITIONS
 *   phrase - phrase to guess
 * POST-CONDITIONS
 *   returns phrase with characters that are replaced with '-'
******************************************************************************/
string setupUnsolved(string phrase)
{
    //PROCESSING - replaces every character in the phrase with '-'
    for (int i = 0; i < phrase.size(); i++)
    {
        if (((phrase.at(i) >= 'a') && (phrase.at(i) <= 'z')) ||
            ((phrase.at(i) >= 'A') && (phrase.at(i) <= 'Z')))
        {
            phrase.at(i) = '-';
        }
    }
    return phrase;
}

/******************************************************************************
 * FUNCTION updateUnsolved
 *_____________________________________________________________________________
 * This function finds the position of every instance of the char guess and
 *   replaces that position in string unsolved with the character
 *_____________________________________________________________________________
 * PRECONDITIONS
 *   phrase - phrase to guess
 *   unsolved - holds the found and hidden characters
 *   guess - character guessed
 * POST-CONDITIONS
 *   returns updated unsolved varaiables
******************************************************************************/
string updateUnsolved(string phrase, string unsolved, char guess)
{
    //PROCESSING - if there is the guessed letter in the phrase, its position
    //              in the unsolved variable is replaced with the letter
    for(int i = 0; i < unsolved.size(); i++)
    {
        if (tolower(phrase.at(i)) == guess)
        {
            unsolved.at(i) = phrase.at(i);
        }
    }
    return unsolved;
}
/******************************************************************************
 * FUNCTION getGuess
 *_____________________________________________________________________________
 * This function will repeatedly prompt the user for a guess until it is valid.
 *_____________________________________________________________________________
 * PRECONDITIONS
 *   prevGuesses - all letters already guessed
 * POST-CONDITIONS
 *   returns valid guesses
******************************************************************************/
char getGuess(string prevGuesses)
{
    //variable declaration
    char guess;                 //INPUT - letter to guess

    //INPUT - getting guess input
    cout << "Enter a guess: ";
    cin >> guess;

    //PROCESSING - finds if the input guess is valid
    //           - sees if input is between a-z and not repeated
    //           - if not valid, prompts user for another input
    while (1)
    {
        if ((guess >= 'a') && (guess <= 'z'))
        {
            if (prevGuesses.size() == 0)
                return guess;

            if (prevGuesses.find(guess) != string::npos)
            {
                cout << "Invalid guess! Please re-enter a guess: ";
                cin >> guess;
            }
            else
                return guess;
        }
        else
        {
            cout << "Invalid guess! Please re-enter a guess: ";
            cin >> guess;
        }
    }
}

/******************************************************************************
 * FUNCTION checkSolved
 *_____________________________________________________________________________
 * This function checks if the unsolved variable is solved and returns
 *  true if phrase is solved, false if not solved yet
 *_____________________________________________________________________________
 * PRECONDITIONS
 *   unsolved - unsolved phrase
 * POST-CONDITIONS
 *   returns true or false if phrase is solved
******************************************************************************/
bool checkSolved(string unsolved)
{
    //PROCESSING - checks if any of the characters are '-',
    //           - if no characters are '-' then the phrase is solved
    for (int i = 0; i < unsolved.size(); i++)
    {
        if (unsolved.at(i) == '-')
            return false;
    }
    return true;
}













