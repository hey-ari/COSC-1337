//*************************************************************************
//  Monkey Food
//  Programmer: Ariadna Ayala
//  Completed: 10/21/2019
//  Status: Completed
//
//  This program collects user input for amount of food eaten by each one of 3 monkeys
//  in 7 days, stores the data into  a 2D array. It displays a table of the data collected
//  and calculates average amout of food eaten, the least and greatest amount of food eaten.
//*************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int const NUM_MONKEYS = 3,             // Global constant integer for amount of monkeys assigned to 3;
          NUM_DAYS = 7;                // Global constant integer of amount of days assigned to 7.

// Function prototypes for five functions to be used.
void monkeyInput (double[][NUM_DAYS], int const);
void monkeyTable (double[][NUM_DAYS], int const, double, double, double);
double monkeyAverage (double[][NUM_DAYS], int const);
double monkeyLeast (double[][NUM_DAYS], int const);
double monkeyGreatest(double[][NUM_DAYS], int const);


// Main function calls all the 5 funtions that collect user input, compose table, and
// calculate average, least, and greatest food eaten.
int main ()
{
    double monkeyEats[NUM_MONKEYS][NUM_DAYS],   // 2-dementional array to hold amount of food eaten;
                                                // by monkey one of the monkeys on ne of the days;
           average,                             // Double variable holds a value of average food eaten;
           least,                               // Double variable holds a value of least food eaten;
           greatest;                            // Double variable holds a value of greatest amount of
                                                // food eaten.
    
    // Calling an input function and assigning a respective function to the variables (average, least,
    // and greatest). Then calling a function that displays the report.
    monkeyInput (monkeyEats, NUM_MONKEYS);
    
    average = monkeyAverage(monkeyEats, NUM_MONKEYS);
    least = monkeyLeast(monkeyEats, NUM_MONKEYS);
    greatest = monkeyGreatest(monkeyEats, NUM_MONKEYS);
    
    monkeyTable(monkeyEats, NUM_MONKEYS, average, least, greatest);
    return 0;
}


// Function calculates user input for the amount of food each monkey ate throughout the week.
void monkeyInput(double array [][NUM_DAYS], int const NUM_MONKEYS)
{

    for (int i =0; i < NUM_MONKEYS; i=i+1)                 // i for monkey number.
    {
        for (int j = 0; j < NUM_DAYS; j=j+1)               // j for days number.
        {
            cout << "Enter pounds of food eaten by monkey"
            << (i+1) << " on " << (j+1) << ":";
            cin >> array[i][j];
            while (array[i][j] < 0)
            {
                cout << "Amount of food cannot be lesser than 0. Try again: " << endl;
                cin >> array[i][j];
            }
        }
    }
}



// Function composes and displays the table based on data intered into the array followed by
// the report of an average amount of food eaten in 7 days and both the least and the greatest
// amount of food eaten.
void monkeyTable(double array [][NUM_DAYS], int const NUM_MONKEYS, double average, double least, double greatest)
{
    cout << fixed << showpoint << setprecision (2);
    
    cout << "Punds of food eaten by each monkey every day of the week" << endl;
    cout << "\n";
 
    cout << "Monkey" << setw(8) << "Mon" << setw(6) << "Tue" << setw(6) << "Wed"
         << setw(6) << "Thu" << setw(6) << "Fri" << setw(6) << "Sat" << setw(6)
         << "Sun" << setw(6) << endl;
    for (int i = 0; i < NUM_MONKEYS; i=i+1)                 // i for monkey number.
    {
        cout << left << setw(8) << (i+1);
        for (int j = 0; j < NUM_DAYS; j=j+1)                // j for days number.
        {
            cout << left << setw(6) << array[i][j];
        }
        cout << endl;
    }
    cout << "\nThe average of food eaten per day by each monkey: " << average << endl;
    cout << "The least amount of food eaten by any monkey: " << least << endl;
    cout << "The greatest amount of food eaten by any monkey: " << greatest << endl;
}

// Function used to calculate the average amount of food eaten by all monkeys in 7 days.
double monkeyAverage(double array [][NUM_DAYS], int const NUM_MONKEYS)
{
    double  average = 0.0,
            total = 0.0;
    for (int i = 0; i < NUM_MONKEYS; i=i+1)                 // i for monkey number.
    {
        for (int j = 0; j < NUM_DAYS; j=j+1)                // j for days number.
        {
            total = total + array[i][j];
            average = total/(NUM_MONKEYS*NUM_DAYS);
        }
    }
    return average;
}
// Function used to determine the least amount of food eaten by any monkey in 7 days.
double monkeyLeast (double array [][NUM_DAYS], int const NUM_MONKEYS)
{
    double least = array[0][0];
    for (int i = 0; i < NUM_MONKEYS; i++)                   // i for monkey number.
    {
        for (int j = 0; j < NUM_DAYS; j++)                  // j for days number.
        { if (array[i][j] < least)
            least = array[i][j];
        }
    }
    return least;
}

// Function used to determine the greatest amount of food eaten by any monkey in 7 days.
double monkeyGreatest (double array [][NUM_DAYS], int const NUM_MONKEYS)
{
    
    double greatest = array[0][0];
    for (int i = 0; i < NUM_MONKEYS; i++)                   // i for monkey number.
    {
        for (int j = 0; j < NUM_DAYS; j++)                  // j for days number.
        {   if (array[i][j] > greatest)
            greatest = array[i][j];
        }
    }
    return greatest;
}
