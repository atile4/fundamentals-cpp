/******************************************************************************
 * NAME      : Atticus Wong
 * Assignment: Assignment 11 - Breakfast Billing System
 * CLASS     : CS 002
 * SECTION   : TuThF: 7a - 10:50a
 * Due Date  : 6/17/23
******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;
/******************************************************************************
 * BREAKFAST BILLING SYSTEM
 * ____________________________________________________________________________
 * This program accepts a file input containing a menu list, and then creates
 *  an object with struct of the menu item types with the information from the
 *  file. The program then lets the user pick how much of each item on the list
 *  and calculates the total money.
 * ____________________________________________________________________________
 * INPUT
 *  filename - name of input file
 *  infile - opening input file
 *  item - item on the menu
 *  item_amount - amount of the item
 * OUTPUT
 *  showMenu - outputs the menu
 *  printCheck - outputs the amount of money owed
******************************************************************************/

struct MenuItemType
{
    string menuItem;
    double menuPrice;
    int count = 0;
};

/******************************************************************************
 * FUNCTION getData
 * ____________________________________________________________________________
 * This function reads data from a text file and appends it to a vector
 * - returns nothing -> adds data to a vector
******************************************************************************/
void getData(vector <MenuItemType> &m, string filename);
void showMenu(vector <MenuItemType> &m);

/******************************************************************************
 * FUNCTION printCheck
 *  This function multiplies the cost of each item by how much the item was
 *  chosen and multiplies that total by 0.05 as tax and outputs the result
 *  - returns nothing -> outputs total cost
******************************************************************************/
void printCheck(vector <MenuItemType> &m);

int main()
{
    //variable declaration
    ifstream infile;                 //INPUT - input file open
    string filename;                 //INPUT - input file name
    vector <MenuItemType> menuList;  //OUTPUT - vector of items information
    int item;                        //INPUT - item name
    int item_amount;                 //INPUT - item amount

    //INPUT - getting and opening file name
    cout << "Enter filename: " << endl;
    cin >> filename;
    infile.open(filename);
    cout << endl;

    //getData - reading in data from the input file and putting in menuList
    getData(menuList, filename);

    item = 1;
    //PROCESSING - gets item index and amount while item name is not 0
    while (item != 0)
    {
        //showMenu - outputs the menu
        showMenu(menuList);

        //INPUT - getting item index
        cout << "\nEnter the item number: ";
        cin >> item;

        //PROCESSING - if the index is 0 the program skips to the check
        if (item == 0)
        {
            cout << "\n\n\n";
            break;
        }

        //INPUT - getting item amount
        cout << "\nHow many would you like to order? ";
        cin >> item_amount;
        cout << "\n\n\n";

        //PROCESSING - adds the inputted count to the specific item
        menuList[item - 1].count = menuList[item - 1].count + item_amount;

    }
    //printCheck - prints the tax and total
    printCheck(menuList);
    cout << "\n";
    return 0;
}

/******************************************************************************
 * FUNCTION getData
 * ____________________________________________________________________________
 * This function reads data from a text file and appends it to a vector
 * - returns nothing -> adds data to a vector
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  menuList - structure of items, cost, and amount chosen
 *  filename - name of the file
 * POST-CONDITIONS
 *  menuList - adds data from file into the menu
******************************************************************************/
void getData(vector <MenuItemType> &m,  //INPUT - menu item types
                      string filename)  //INPUT - file name
{
    //variable declaration
    string item;     //INPUT - item name
    string price;    //INPUT - item price
    ifstream infile; //INPUT - file name

    infile.open(filename);

    //PROCESSING - reads in data for item name from the file up to $
    //           - after the $ is the cost of the item
    while ((getline(infile, item, '$')))
    {
        getline(infile, price);
        m.push_back({item, stod(price), 0});
    }
}

/******************************************************************************
 * FUNCTION showMenu
 * ____________________________________________________________________________
 * This function outputs a display menu with data from the input file
 * - returns nothing -> outputs a menu
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  menuList - menuList - structure of item names and costs
 * POST-CONDITIONS
 *  displays the menu to console
******************************************************************************/
void showMenu(vector <MenuItemType> &m)
{
    //OUTPUT - outputs the menu with data from the input file
    cout << "Welcome to Johnny's Restaurant\n" << endl;
    cout << setw(18) << "Menu\n" << endl;
    for (size_t i = 0; i < m.size(); i++)
    {
        cout << setprecision(2);
        cout << fixed;
        cout << i + 1 << ". ";
        cout << left << setw(20) << m[i].menuItem << right << "$ " << m[i].menuPrice << endl;
    }
    cout << "\nEnter 0 when you finish your order." << endl;
}

/******************************************************************************
 * FUNCTION printCheck
 * ____________________________________________________________________________
 * This function multiplies the cost of each item by how much the item was
 *  chosen and multiplies that total by 0.05 as tax and outputs the result
 *  - returns nothing -> outputs total cost
 * ____________________________________________________________________________
 * PRE-CONDITIONS
 *  menuList - structure of items, cost, and amount chosen
 * POST-CONDITIONS
 *  tax - 0.05 of the total before tax
 *  total - total cost plus tax
******************************************************************************/
void printCheck(vector <MenuItemType> &m)  //INPUT - items, cost, and amount of
                                           //         items chosen
{
    //variable declaration
    double tax;     //OUTPUT - 5% of total before tax
    double total;   //OUTPUT - total cost with tax

    total = 0;

    //OUTPUT - outputs the check and total cost of the combined items
    cout << "Welcome to Johnny's Restaurant\n" << endl;
    cout << setw(18) << "SALE\n" << endl;

    //PROCESSING - checks if an item amount is more than 0
    //           - if more than 0, it is included in the total
    for (size_t i = 0; i < m.size(); i++)
    {
        if (m[i].count > 0)
        {
            cout << setprecision(2);
            cout << fixed;
            cout << left << setw(3) << m[i].count << left << setw(20)
                 << m[i].menuItem << right << "$" << setw(5)
                 << m[i].menuPrice * m[i].count << endl;

            total = total + m[i].menuPrice * m[i].count;
        }
    }

    //PROCESSING - calculates tax and total
    tax = total * 0.05;
    total = total + tax;

    //OUTPUT - outputs tax amount and total cost
    cout << setprecision(2);
    cout << fixed;
    cout << left << setw(23) << "Tax" << right << "$ " << tax << endl;
    cout << setw(29) << setfill('-') << "-" << endl;
    cout << setfill(' ');
    cout << left << setw(23) << "Amount Due" << right << "$" << total << endl;

}

