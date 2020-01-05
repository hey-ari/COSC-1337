//
//  main.cpp
//  Program 6
//
//  Created by Ariadna on 10/19/19.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int const NUM_MONKEYS = 3,
          NUM_DAYS = 7;

// Function prototypes for five functions to be used.
void monkeyInput (double[][NUM_DAYS], int const);
void monkeyTable (double[][NUM_DAYS], int const);
double monkeyAverage (double[][NUM_DAYS], int const);
double monkeyLeast (double[][NUM_DAYS], int const);
double monkeyGreatest(double[][NUM_DAYS], int const);


// Main function calls all the 5 funtions that collect user input, compose table, and
// calculate average, least, and greatest food eaten.
int main ()
{
    // PART 1: array and variables definition.

    double monkeyEats[NUM_MONKEYS][NUM_DAYS],
           allAverage = monkeyAverage(monkeyEats, NUM_MONKEYS),
           allLeast = monkeyLeast(monkeyEats, NUM_MONKEYS),
           allGreatest = monkeyGreatest(monkeyEats, NUM_MONKEYS);
    cout << fixed << showpoint << setprecision (2);
    
    // PART 2: calling functions.
    monkeyInput (monkeyEats, NUM_MONKEYS);
    cout << "Punds of food eaten by each monkey every day of the week" << endl;
    monkeyTable(monkeyEats, NUM_MONKEYS);
    cout << "\nThe average of food eaten per day by each monkey: " << allAverage << endl;
    cout << "The least amount of food eaten by any monkey: " << allLeast << endl;
    cout << "The greatest amount of food eaten by any monkey: " << allGreatest << endl;
    system ("pause");
    
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



// Function composes and displays the table based on data intered into the array.
void monkeyTable(double array [][NUM_DAYS], int const NUM_MONKEYS)
{
 
    cout << "Monkey" << setw(8) << "Mon" << setw(5) << "Tue" << setw(5) << "Wed"
         << setw(5) << "Thu" << setw(5) << "Fri" << setw(5) << "Sat" << setw(5)
         << "Sun" << setw(5) << endl;
    for (int i = 0; i < NUM_MONKEYS; i=i+1)
    {
        cout << left << setw(10) << (i+1);
        for (int j = 0; j < NUM_DAYS; j=j+1)
        {
            cout << left << setw(5) << array[i][j] << endl;
        }
    }
    
}

double monkeyAverage(double array [][NUM_DAYS], int const NUM_MONKEYS)
{
    double  average = 0.0,
            total = 0.0;
    for (int i = 0; i < NUM_MONKEYS; i=i+1)
    {
        for (int j = 0; j < NUM_DAYS; j=j+1)
        {
            total = total + array[i][j];
            average = total/(NUM_MONKEYS*NUM_DAYS);
        }
    }
    return average;
}

double monkeyLeast (double array [][NUM_DAYS], int const NUM_MONKEYS)
{
    double least = array[0][0];
    for (int i=0; i < NUM_MONKEYS; i=i+1)
    {
        for (int j=0; j < NUM_DAYS; j=j+1)
        {
            if (array[0][0] < least)
            {
                least = array[i][j];
            }
        }
    }
    return least;

}

double monkeyGreatest (double array [][NUM_DAYS], int const NUM_MONKEYS)
{
    double greatest = array[0][0];
    for (int i=0; i < NUM_MONKEYS; i=i+1)
    {
        for (int j=0; j < NUM_DAYS; j=j+1)
        {
            if (array[0][0] > greatest)
            {
                greatest = array[0][0];
            }
        }
    }
    return greatest;
}

