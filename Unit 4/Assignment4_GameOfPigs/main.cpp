/******************************************************************************
 * NAME        : Atticus Wong
 * Assignment 4: Game of Pig
 * CLASS       : CS 002
 * SECTION     : TuThF: 7a - 10:50a
 * Due Date    : 5/25/23
******************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

/******************************************************************************
* GAME OF PIGS SCORES PROBABILITY CALCULATION
* _____________________________________________________________________________
* The program takes in an integer for a value to hold the turn at, and another
*  integer for how many turns to calculate the probability of. The program then
*  calculates the occurence of each possible score and outputs the result
*  to the user.
* _____________________________________________________________________________
*  INPUT:
*    hold_at_value: value to hold the turn at, user input
*    simulation_num: number of times to run a turn, user input
*  OUPUT:
*   data table: outputs a datatable with all the scores and their probabilities
*   score1: first possible score with the inputted hold value
*   score2: second possible score
*   score3: third possible score
*   score4: fourth possible score
*   score5: fifth possible score
*   score6: sixth possible score
*   score0_chance: percentage of the score 0 appearing
*   score1_chance: percentage of the hold at value score appearing
*   score2_chance: percentage of the score plus 1 appearing
*   score3_chance: percentage of the score plus 2 appearing
*   score4_chance: percentage of the score plus 3 appearing
*   score5_chance: percentage of the score plus 4 appearing
*   score6_chance: percentage of the score plus 5 appearing
******************************************************************************/

int main()
{
    //variable declaration
    int hold_at_value;    //INPUT - integer value to hold the turn at
    int simulation_num;   //INPUT - number of times to run the turn
    int roll;             //CALC - integer to contain random number between 1-6
    int total;            //CALC - total from adding the rolls

    int score1, score2, score3, score4, score5, score6;
            //CALC & OUT - the different possible scores
    int score0_instances, score1_instances, score2_instances, score3_instances,
        score4_instances, score5_instances, score6_instances;
            //CALC - number of times the corresponding score occurs

    double score0_chance, score1_chance, score2_chance, score3_chance,
           score4_chance, score5_chance, score6_chance;
            //CALC & OUT - percentage of each score being rolled

    srand(333);

    //INPUT - getting hold at value and number of simulations value
    cout << "What value should we hold at? ";
    cin >> hold_at_value;
    cout << "\nHold-at-N turn simulations? ";
    cin >> simulation_num;

    //PROCESSING - setting the possible scores based on the hold at value
    score1 = hold_at_value;
    score2 = hold_at_value + 1;
    score3 = hold_at_value + 2;
    score4 = hold_at_value + 3;
    score5 = hold_at_value + 4;
    score6 = hold_at_value + 5;

    //PROCESSING - setting the instances of each score appearing to 0
    score0_instances = 0;
    score1_instances = 0;
    score2_instances = 0;
    score3_instances = 0;
    score4_instances = 0;
    score5_instances = 0;
    score6_instances = 0;

    //OUTPUT - title of data table
    cout << "\nScore\tEstimated Probability" << endl;

    //PROCESSING - loop runs for the number of inputted simulations
    //             each loop simulates a turn
    for(int i = 0; i < simulation_num; i++)
    {
        total = 0;

        //PROCESSING -  runs as long as the total is
        //               less than the hold at value
        //             simulates rolling the dice until the hold at value
        while (total < hold_at_value)
        {
            //PROCESSING - calculates a random number between 1 and 6
            roll = rand() % 6 + 1;

            //PROCESSING - if the rolled value is 1 then the turn ends and
            //                                   total is set to 0
            //
            if (roll == 1)
            {
                total = 0;
                break;
            }

            //adds the roll value to the total
            total = total + roll;
        }

        //PROCESSING - calculates the instances of each score occuring
        if (total == 0)
        {
            score0_instances = score0_instances + 1;
        }
        else if (total == score1)
        {
            score1_instances = score1_instances + 1;
        }
        else if (total == score2)
        {
            score2_instances = score2_instances + 1;
        }
        else if (total == score3)
        {
            score3_instances = score3_instances + 1;
        }
        else if (total == score4)
        {
            score4_instances = score4_instances + 1;
        }
        else if (total == score5)
        {
            score5_instances = score5_instances + 1;
        }
        else if (total == score6)
        {
            score6_instances = score6_instances + 1;
        }


    }

    //PROCESSING - calculating the percentage of each score occuring
    score0_chance = static_cast<double>(score0_instances) / simulation_num;
    score1_chance = static_cast<double>(score1_instances) / simulation_num;
    score2_chance = static_cast<double>(score2_instances) / simulation_num;
    score3_chance = static_cast<double>(score3_instances) / simulation_num;
    score4_chance = static_cast<double>(score4_instances) / simulation_num;
    score5_chance = static_cast<double>(score5_instances) / simulation_num;
    score6_chance = static_cast<double>(score6_instances) / simulation_num;

    //PROCESSING - sets the following double numbers to 6 digits after decimal
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(6);
    //OUTPUT - outputs the results in a data table
    cout << 0 << "\t" << score0_chance << endl;
    cout << score1 << "\t" << score1_chance << endl;
    cout << score2 << "\t" << score2_chance << endl;
    cout << score3 << "\t" << score3_chance << endl;
    cout << score4 << "\t" << score4_chance << endl;
    cout << score5 << "\t" << score5_chance << endl;
    cout << score6 << "\t" << score6_chance << endl;

    return 0;
}
