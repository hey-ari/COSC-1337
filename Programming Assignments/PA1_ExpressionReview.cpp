//*************************************************************************
//  Expression Review Program
//  Programmer: Ariadna Ayala
//  Completed: 09/06/2019
//  Status: Completed
//
//  This program collects user input of 2 integer values, then calculates and displays the following:
//  sum of integers, product of integers, their quotient and remainder as an integer,
//  quotient as a floating point number, and the average of two integers.
//*************************************************************************

#include <iostream>                                 // input/output declarations.
#include <iomanip>                                  // i/o manipulator declarations.
using namespace std;


int main()
{
    // Part 1: Collecting user's input for two variables.
    
    int inputOne;
    int inputTwo;
    
    cout << fixed << showpoint << setprecision(2);  // Setting floating point output format to two decimal places.
    
    cout << "Enter your first integer: ";           // Get 1st integer value.
    cin >> inputOne;
    cout << "Enter your second integer: ";          // Get 2nd integer value.
    cin >> inputTwo;
    
    
    //Part 2: Calculating variables using input variables.
    
    int sum,                                        // Used to calculate a sum of inputOne and inputTwo.
        product,                                    // Used to calculate a product of inputOne and inputTwo.
        intQuot,                                    // Used to calculate a quotient of inputOne and inputTwo (integer).
        intRem;                                     // Used to calculate a remainder of inputOne and inputTwo (integer).
    
    float floatQuot,                                // Used to calculate a quotient of input One and inputTwo (floating point).
          average;                                  // Used to calculate an average of inputOne and inputTwo.
    
    // Performing required calsulations:
    sum = inputOne +inputTwo;                       // Calculate sum of input variables.
    product = inputOne * inputTwo;                  // Calculate product of input variables.
    intQuot = inputOne/inputTwo;                    // Calculate quotient (Integer).
    intRem = inputOne % inputTwo;                   // Calculate remainder (Integer).
    floatQuot = (float)inputOne/(float)inputTwo;    // Calculate quotient (Floating point).
    average = sum/2.0;                              // Calculate average.
    
    
    // Part 3: Printing calculated sum, product, quotients, remainder, and average.
    
    cout << "For the integers you entered: " << endl;
    cout << "Sum\t\t\t\t\t\t" << "is "<< sum << endl;                   // Print sum of two integers
    cout << "Product\t\t\t\t\t" << "is "<< product << endl;             // Print product of two integers.
    cout << "Integer Qoutient\t\t" << "is "<< intQuot << endl;          // Print result of division as an integer.
    cout << "Integer remainder\t\t" << "is "<< intRem << endl;          // Print a remainder.
    cout << "Floating-point qoutient\t" << "is "<< floatQuot << endl;   // Print result for division as a floating point.
    cout << "Average\t\t\t\t\t" << "is "<< average << endl;             // Print an average of two integers as floating point number.
    return 0;
}
