/******************************************************************************
 * AUTHOR      : Atticus Wong
 * ASSIGNMENT 1: Madlibs
 * CLASS       : CS 002
 * SECTION     : TRF: 7a - 10:50a
 * DUE DATE    : 5/18/23
******************************************************************************/
#include <iostream>

using namespace std;
/******************************************************************************
 * Make a Madlib
 * ____________________________________________________________________________
 * This program takes 17 string inputs from the user and creates a story based
 *  off a prewritten template, and outputs the result.
 * ____________________________________________________________________________
 * INPUT:
 *  verb1: a verb, input from user
 *  verb2: a verb, input from user
 *  verb3: a verb, input from user
 *  teacher_name: name of a teacher, input from user
 *  female_name: name of a female friend, input from user
 *  male_name: name of a male friend, input from user
 *  city_name: name of a city, input from user
 *  street_name: name of a street, input from user
 *  adjective1: an adjective, input from user
 *  adjective2: another adjective, input from user
 *  small_number: a small number in string format, input from user
 *  number_in_words: a number in word format, input from user
 *  time_unit: unit measurement of time(hrs, min, etc), input from user
 *  liquid: the name of a liquid, input from user
 *  beverage: the name of a beverage, input from user
 *  school_subject: name of a school subject, input from user
 *  famous_painting_name, name of a famous painting, input from user
 * OUTPUT:
 *  story: outputs the story using the 17 user inputs inserted into the story
******************************************************************************/
int main()
{
    //constants
    const string measuringStick(80, '-'); //OUTPUT - tool for measuring

    //variables - Data Table
    string verb1, verb2, verb3;                   //INPUT - three verbs
    string teacher_name, female_name, male_name;  //INPUT - names of 3 people
    string city_name, street_name;                //INPUT - city and street name
    string adjective1, adjective2;                //INPUT - two adjectives
    string small_number, number_in_words;         //INPUT - two numbers
    string time_unit;                             //INPUT - unit of time
    string liquid;                                //INPUT - a liquid
    string beverage;                              //INPUT - a beverage
    string school_subject;                        //INPUT - a school subject
    string famous_painting_name;                  //INPUT - painting name

    //OUTPUT - display header information
    cout << "**************************************************************\n";
    cout << "     Programmed by: Atticus Wong\n";
    cout << "     Student ID   : 10646506\n";
    cout << "     CS 002       : TRF -- 7a-10:50a\n";
    cout << "     Assignment 1 : Madlibs \n";
    cout << "**************************************************************\n";
    cout << "\n";

    //INPUT - getting various inputs from user to create the story
    cout << "Please enter a verb: ";
    cin >> verb1;

    cout << "\nPlease enter a male name: ";
    cin >> teacher_name;

    cout << "\nPlease enter another verb: ";
    cin >> verb2;

    cout << "\nPlease enter a small number: ";
    cin >> small_number;

    cout << "\nPlease enter a liquid: ";
    cin >> liquid;

    cout << "\nPlease enter the name of a beverage: ";
    cin >> beverage;

    cout << "\nPlease enter an adjective: ";
    cin >> adjective1;

    cout << "\nPlease enter the name of a city: ";
    cin >> city_name;

    cout << "\nPlease enter a number in word format: ";
    cin >> number_in_words;

    cout << "\nPlease enter the name of a female friend: ";
    cin >> female_name;

    cout << "\nPlease enter the name of a street: ";
    cin >> street_name;

    cout << "\nPlease enter a unit of time: ";
    cin >> time_unit;

    cout << "\nPlease enter a school subject: ";
    cin >> school_subject;

    cout << "\nPlease enter an adjective: ";
    cin >> adjective2;

    cout << "\nPlease enter a verb: ";
    cin >> verb3;

    cout << "\nPlease enter the name of a male friend: ";
    cin >> male_name;

    cout << "\nPlease enter the name of a famous painting: ";
    cin >> famous_painting_name;

    //OUTPUT - display story with user inputs put in the story
    cout << "\n\n\n" << measuringStick << endl;

    //first paragraph
    cout << "\tI really like to " << verb1 << " while in class. My teacher, "
         << teacher_name << ", really\n";
    cout << "hates it when I " << verb2 << ". Sometimes he will put "
         << small_number << " grams of " << liquid << "\n";
    cout << "into my " << beverage << ", making me feel " << adjective1
         << " for the rest of the day.\n\n";

    //second paragraph
    cout << "\tI go to school at " << city_name
         << " high school. Every week we have " << number_in_words << "\n";
    cout << "hours of work to do. I feel " << adjective1
         << " after class, but my friend " << female_name << "\n";
    cout << "tells me she wants to sleep. Sometimes I have to drag her back home to\n";
    cout << street_name << ", which is 69 " << time_unit << "s away.\n\n";

    //third paragraph
    cout << "\tMy favorite subject is " << school_subject
         << ", but the teacher is just so " << adjective2 << "\n";
    cout << "that I just want to " << verb3 << ". My buddy "
         << male_name << " really likes the class.\n";
    cout << "He will even draw a " << famous_painting_name
         << " and give it to the teacher.\n";
    cout << measuringStick << endl;

    return 0;
}
