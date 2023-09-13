/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Lab 13
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/10/23
******************************************************************************/

/******************************************************************************
 * Lab 13 - Word Separator and Replacing Substrings
 * ____________________________________________________________________________
 * Exercise 1
 *   Prompts user for a string sentence, and then seperates it into words from
 *   capitalized letters.
 * Exercise 2
 *   Prompts user for a string sentence, a substring to replace, and another
 *   substring to replace it with
 * ____________________________________________________________________________
 * INPUT
 *   exercise_num: number to decide which exercise runs, user input
 *   string_sentence: sentence to seperate, user input
 *   main_string: string to look for subscript in
 *   replaced_string: string to replace
 *   replacement_string: string to replace with
 * OUTPUT
 *   new_sentence: new sentence with seperated words
 *   pushback: cancels out the added whitespace
 *   replaced substring: string with replaced words
******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

/******************************************************************************
 * replaceSubstring
 *   replaces a substring in a string with another substring, returns
 *   the new string
******************************************************************************/
string replaceSubstring(string s1, string s2, string s3);

int main()
{
    //variable declaration
    int exercise_num;      //INPUT - exercise to run

    //INPUT - getting exercise number
    cout << "Which exercise?" << endl;
    cin >> exercise_num;
    cout << "\n";

    //EXERCISE 1
    if (exercise_num == 1)
    {
        //variable declaration
        string string_sentence;    //INPUT - a sentence
        string new_sentence;       //OUTPUT - the new sentence
        int pushback;              //OUTPUT - number to cancel out
                                   //       whitespace added to the string

        //INPUT - getting sentence
        cout << "Enter a sentence (no spaces, 1st letter of each word is uppercase): " << endl;
        cin >> string_sentence;

        new_sentence = string_sentence;
        pushback = 0;

        //PROCESSING - adds a whitespace before each capital letter and
        //              sets the capital letter to lower case
        for (int i = 0; i < string_sentence.size(); i++)
        {
            if (isupper(string_sentence.at(i)) && (i != 0))
            {
                new_sentence.at(i + pushback) = tolower(string_sentence.at(i));
                new_sentence.insert(i + pushback, " ");
                pushback = pushback + 1;
            }

        }

        //OUTPUT - outputs the new sentence
        cout << "\n" << new_sentence << "\n" << endl;
    }

    //EXERCISE 2
    else if (exercise_num == 2)
    {
        //VARIABLE DECLARATION
        string main_string;          //INPUT - main sentence
        string replaced_string;      //INPUT - substring to get replaced
        string replacement_string;   //INPUT - susbtring to replace it with

        cin.ignore();

        //INPUT - getting main string and the two substrings
        cout << "Enter the main string: ";
        getline(cin, main_string, '\n');

        cout << "\nEnter the string to replace: ";
        getline(cin, replaced_string, '\n');

        cout << "\nEnter the replacement string: ";
        getline(cin, replacement_string, '\n');

        //replaceSubstring - replaces all instances of the substring with another
        //OUTPUT - outputs result
        cout << "\n" << replaceSubstring(main_string, replaced_string, replacement_string) << endl;
        cout << "\n";
    }

    return 0;
}

/******************************************************************************
 * FUNCTION replaceSubstring
 * ____________________________________________________________________________
 * This function replaces a substring in a string sentence with another
 * substring
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *   s1 - string sentence
 *   s2 - substring to replace
 *   s3 - substring that gets replaced
 * POST-CONDITIONS
 *   s1 - returns new sentence with its replaced substrings
******************************************************************************/

string replaceSubstring(string s1,  //INPUT - string sentence
                        string s2,  //INPUT - substring to replace
                        string s3)  //INPUT - substring that gets replaced
{
    //variable declaration
    int start_pos;    //OUT - index where substring in sentence starts
    int pos2;         //OUT - position after the first substring
    pos2 = 0;

    //PROCESSING - finds all instances of the substring, and replaces it with
    //             another substring input
    while (s1.find(s2, pos2) != string::npos)
    {
        start_pos = s1.find(s2, start_pos);
        s1.replace(start_pos, s2.length(), s3);
        pos2 = pos2 + start_pos + s3.length();
    }

    return s1;
}
