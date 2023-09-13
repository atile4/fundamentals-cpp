/******************************************************************************
 * NAME        : Atticus Wong
 * Assignment 5: Cipher
 * CLASS       : CS 002
 * SECTION     : TuThF: 7a - 10:50a
 * Due Date    : 5/27/23
******************************************************************************/
#include <iostream>

using namespace std;
/******************************************************************************
 * ENCRYPTING AND DECRYPTING A WORD
_______________________________________________________________________________
 * The program takes in a string input, either encryption or decryption, and
 *  a translation map string input, default or custom, and a word, and will
 *  encrypt or decrypt it based off user input. If there are errors, the
 *  program will output an error message.
_______________________________________________________________________________
 * INPUT
 *  method - string to either encrypt or decrypt, user input
 *  translation_map - string to use for encryption/decryption, user input
 *  word - word to encrypt or decrypt, user input
 * OUTPUT
 *  translated_word - the word after encryption/decryption
******************************************************************************/

int main()
{
    //variable declaration
    string method;             //INPUT - method of translating the word
    string translation_map;    //INPUT - translation map for translating word
    string word;               //INPUT - word to translate
    string translated_word;    //OUTPUT - word after translation
    int ch_place;              //CALC - location of character in the alphabet
    char current_ch;           //CALC - holds character before encryption

    //INPUT - getting method of translating word
    cout << "What is the method (encryption or decryption)? ";
    cin >> method;

    //PROCESSING - checks if the method input is valid.
    //             if it is not, error message is output
    if ((method == "encryption") || (method == "decryption"))
    {
        //INPUT - getting translation map to use for encryption/decryption
        cout << "\nWhat is the translation map "
                "(type 'default' to use default): ";
        cin >> translation_map;

        //PROCESSING - checks if the inputted translation map is valid
        if ((translation_map.size() == 26) || (translation_map == "default"))
            {
                //INPUT - gets word input from user
                cout << "\nWhat is the single word to translate: ";
                cin >> word;

                //PROCESSING - setting translated_word to
                //               word for same size string, easier to compute
                translated_word = word;

                //PROCESSING - if default was set for the translation map,
                //                  then the default map is used
                if (translation_map == "default")
                {
                    translation_map = "zyxwvutsrqponmlkjihgfedcba";
                }

                //PROCESSING - runs if the method is encryption
                if (method == "encryption")
                {
                    //PROCESSING - iterates through each letter in the word
                    //             replaces each letter in the word to its
                    //             encrypted version and stores in a variable
                    for (int i = 0; i < word.size(); i++)
                    {
                        //PROCESSING - sets the character being iterated
                        //              into a char variable
                        //             then subtracts 97 to convert the char
                        //              variable, which is an ascii value,
                        //              to an alphabetical value
                        current_ch = word.at(i);
                        ch_place = current_ch - 97;

                        //PROCESSING - checks for valid word input
                        //             if input is valid the character iterated
                        //              is replaced with its encrypted version
                        if ((ch_place >= 0) && (ch_place <= 25))
                        {
                          translated_word.at(i) = translation_map.at(ch_place);
                        }
                        else
                        {
                            //OUTPUT - invalid word input error message
                            cout << "\nError: encryption "
                                    "cannot be performed." << endl;
                            return 0;
                        }
                    }
                    //OUTPUT - outputs result of encryption
                    cout << "\nEncrypted word: " << translated_word << endl;
                }
                //PROCESSING - runs if the method is decryption
                else if (method == "decryption")
                {
                    //PROCESSING - iterates through each letter in the word
                    //             replaces it with its decrypted version
                    //             and stores in a variable
                    for (int i = 0; i < word.size(); i++)
                    {
                        //PROCESSING - locates where on the map the iterated
                        //             character is, then converts it to an
                        //             ascii symbol character
                        ch_place = translation_map.find(word.at(i));
                        current_ch = ch_place + 97;

                        //PROCESSING - checks for valid word input
                        //             if input is valid the character iterated
                        //              is replaced with its decrypted version
                        if ((current_ch >= 97) && (current_ch <= 123))
                        {
                           translated_word.at(i)=static_cast<char>(current_ch);
                        }
                        else
                        {
                            cout << "\nError: decryption "
                                    "cannot be performed." << endl;
                            return 0;
                        }
                    }
                    //OUTPUT - outputs result of decryption
                    cout << "\nDecrypted word: " << translated_word << endl;
                }



            }
        //PROCESSING & OUT - if translation map input is
        //                   invalid, error message is output

        else
        {
            cout << "\nError: invalid translation map size." << endl;
            return 0;
        }
    }
    //PROCESSING & OUT - if method input is invalid, error message is output
    else
    {
        cout << "\nError: invalid method choice." << endl;
        return 0;
    }


    return 0;
}
