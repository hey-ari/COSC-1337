//*************************************************************************
//  Postal Packages
//  Programmer: Ariadna Ayala
//  Completed: 11/07/2019
//  Status: Completed
//
//  This program collects user input for package weight and 3 dimensions. It displays packages' status
//  and, if accepted, siaplays shipping fee. It accepted the packages of weight below 50 lbs and/or of
//  girth not more than 5 feet (60 inches). If -1 is entered, the program displays the number of
//  accepted and rejected packages.
//*************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Function prototypes
void shipInfo (int, string, int, double);
int largest (int, int, int, int);
int girth (int, int, int, int, int);
string shipStatus (int, int, string);
int arraySearch (int [], int, int, int);

// Global int constant for the amount of values in parallel arrays.
int const ARRAY_SIZE = 15;

int main ()
{
    
    // PART 1: array and variable assignment.
    int shipWeight[ARRAY_SIZE] = {1, 2, 3, 5, 7, 10, 13, 16, 20, 25, 30,
                                  35, 40, 45, 50};
    double shipFee[ARRAY_SIZE] = {1.50, 2.10, 4.00, 6.75, 9.90, 14.95,
                                  19.40, 24.20, 27.30, 31.90, 38.50, 43.50,
                                  44.80, 47.40, 55.20};
    
    int shipNum,                // Amount of transactions.
        index,                  // Holder variable for index location of weight vs. shipping fee.
        weight,                 // Package weight.
        dimension1,             // Three dimensions.
        dimension2,
        dimension3,
        pkgGirth,               // Package girth.
        lrgstDimension,         // Largest side of a package.
        shipAccepted,           // Amount of accepted packages.
        shipDeclined;           // Amount of rejected packages.
    double cost;                // Cost of a given package.
    string status;              // Status of a package.
    
    shipNum = 0;
    weight = 0;
    dimension1 = 0;
    dimension2 = 0;
    dimension3 = 0;
    pkgGirth = 0;
    lrgstDimension = 0;
    shipAccepted = 0;
    shipDeclined = 0;
     status = " ";
    
    // PART 2: while loop continues until user enters -1 for weight. Will ask to re-enter the values
    //         if a value lesser than 0 is entered; if a package is accepted, it will search the
    //         shipWeight array, then the shipFee array for a corresponding location.
    cout << fixed << showpoint << setprecision (2);
    cout << "Please enter package weight in pounds and 3 dimensions in inches. Enter -1 to exit"
         << endl;
    while(true)
    {
        cout << "Enter package weight and 3 dimensions: ";
        cin >> weight;
        if (weight == -1)
        {
            break;
        }
        cin >> dimension1 >> dimension2 >> dimension3;
        

        if ((weight <= 0)||(dimension1 <= 0)||(dimension2 <= 0)||(dimension3 <= 0))
        {
            cout << "ERROR! Package dimensions must be greater than 0, try again" << endl;
            continue;
        }
    
        shipNum = shipNum + 1;
        
        lrgstDimension = largest(dimension1, dimension2, dimension3, lrgstDimension);
        
        pkgGirth = girth (dimension1, dimension2, dimension3, lrgstDimension, pkgGirth);
        
        status = shipStatus (pkgGirth, weight, status);
        
        if (status == "Rejected")
        {
            shipDeclined = shipDeclined + 1;
            cost = -1;
        }
        else
        {
            shipAccepted = shipAccepted + 1;
            
            index = arraySearch(shipWeight, ARRAY_SIZE, weight, index);
            cost = shipFee[index];
        }
        shipInfo (shipNum, status, weight, cost);
    }
    cout << "Packages Accepted: " << shipAccepted << endl;
    cout << "Packages Rejected: " << shipDeclined << endl;
    
    return 0;
}


// Outputs information about each shipment.
void shipInfo (int shipNum, string status, int weight, double cost)
{
    cout << left << setw(15) << "Transaction :  " << right << setw(11)<< shipNum << endl;
    cout << left << setw(15) << "Status :  " << right << setw(11) << status << endl;
    cout << left << setw(15) << "Weight :  " << right << setw(11) << weight << endl;
    if (cost == -1)
    {
        cout << left << setw(15) << "Cost : " << right << setw(11) << " n/a" << endl;
    }
    else
    {
        cout << left << setw(15) << "Cost :  " << right << setw(11) << cost << endl;
    }
}


// Function determines the largest side of a package.
int largest(int side1, int side2, int side3, int lrgstDimension)
{
    
    if (side1 > side2 && side1 > side3)
        lrgstDimension = side1;
    else if (side2 > side1 && side2 > side3)
        lrgstDimension = side2;
    else if (side3 > side1 && side3 > side2)
        lrgstDimension = side3;
    return lrgstDimension;
}

// Function calculates girth using given formula.
int girth (int dimension1, int dimension2, int dimension3, int lrgstDimension, int pkgGirth)
{
    pkgGirth = 2 * (dimension1 + dimension2 + dimension3 - lrgstDimension);
    return pkgGirth;
}


// Functions determines package's status: rejected if the weight AND/OR girth
// exceed 60 lbs or 50 inches.
string shipStatus (int pkgGirth, int weight, string status)
{

    if ((pkgGirth > 60)||(weight > 50))
    {
        status = "Rejected";
    }
    else {
        status = "Accepted";
    }
    return status;
}

// Function search both arrays for values that correspond to index.
int arraySearch (int shipWeight[], int const ARRAY_SIZE, int weight, int index)
{
    //search the arrays for memory location
    index = 0;
    for (int i = 0; i < ARRAY_SIZE; i = i + 1)
    {
        if (weight == shipWeight[i])
        {
            index = i;
            break;
        }
        else if (weight > shipWeight[i])
            continue;
        else
        {
            weight = shipWeight[i];
            index = i;
            break;
        }
        
    }
    return index;
}
