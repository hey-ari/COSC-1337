//*************************************************************************
//  Payroll V3.0
//  Programmer: Ariadna Ayala
//  Completed: 12/13/2019
//  Status: Completed

//  This program reads the data in two input files ("master10.txt" and "trans10.txt") and outputs processed data
//  into a designated file named "paroll10.txt" The data will not be output into file if an employee worked less
//  than 0 hrs. The program searches the transactions file to assure the IDs in it match and will display an error
//  message if an ID entered into a transaction file is invalid (not present in master file). Output visible in IDE:
//  list of employees with invalid hrs, amount of employees listed in transaction file, and amount of successful transactions.
//*************************************************************************


#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Class declaration for Employee
class Employee
{
private:
    int id;                         // Employee ID
    char name[20];                  // Employee name
    double hourlyPay;               // Pay per hour
    int numDeps;                    // number of dependents
    int type;                       // employee type

public:
    Employee();
    Employee( char initName [], int initId=0,
             double initHourlyPay=0.0,
             int initNumDeps=0, int initType=0 );  // Constructor
    bool set(char newName [], int newId, double newHourlyPay,
             int newNumDeps, int newType);
    int getEmpId();
    const char *getName();
    double getHourlyPay();
    int getDependents();
    int getType();

};


//Employee class Constructor
Employee::Employee()
{
    id = 0;
    name[0] = '\0';
    hourlyPay = 0.0;
    numDeps = 0;
    type = 0;
}


Employee::Employee( char initName [], int initId,
                   double initHourlyPay,
                   int initNumDeps, int initType )
{
    bool status = set( initName, initId, initHourlyPay,
                      initNumDeps, initType );

    if ( !status )
    {
        id = 0;
        name[0] = ' ';
        hourlyPay = 0.0;
        numDeps = 0;
        type = 0;
    }
}


//Employee class set function

bool Employee::set( char newName [], int newId, double newHourlyPay,
                   int newNumDeps, int newType )
{
    bool status = false;

    if ( newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 &&
        newType >= 0 && newType <= 1 )
    {
        status = true;
        id = newId;
        for (int i=0; i<20; i++)
            name[i] = newName[i];
        hourlyPay = newHourlyPay;
        numDeps = newNumDeps;
        type = newType;
    }
    return status;
}

// Function gets employee ID.
int Employee::getEmpId()
{
    return id;
}
// Function gets employee name.
const char * Employee::getName()
{
    return name;
}
// Function gets employee hourly rate.
double Employee::getHourlyPay()
{
    return hourlyPay;
}
// Function gets employee number of depensents.
int Employee::getDependents()
{
    return numDeps;
}
// Function gets employee type.
int Employee::getType()
{
    return type;
}


// Declaration of a structure.
struct TransInfo
{
    int empID;
    double hoursWorked;
    double normalPay;
};

int search (int emdID, Employee [], int);

int main ()
{
    
    // PART 1: declaring constant variable, arrays, and variables.
    const int NUM_EMPLOYEES = 100;                  // Predetermined max amount of employees.
    Employee masterFile[NUM_EMPLOYEES];             // Array of class Employee.
    TransInfo paycheck;                             // Array of structures TransInfo.

    int i;
    double  grossPay = 0.0,
            netPay = 0.0,
            insurance = 0,
            tax = 0.0,
            totalGrossPay = 0.0,
            totalNetPay = 0.0;


    int tempId;                                     // Employee ID;
    char tempName [20];                             // Employee name;
    double tempHourlyPay;                           // Hourly pay;
    int tempNumDeps;                                // Amount of dependents;
    int tempType;                                   // Employee type;
    char gender;                                    // Employees gender;
    int countTrans = 0;                             // Counter variable;
    int numMasterEmps = 0;                          // Amount of employees in master file;
    int position;                                   // Emplyee position.
    
    // PART 2: Defining a name and opening an input file. Fill masterFile class array
    //         from file "master10.txt" or display an error message.
    ifstream inputfile1 ("master10.txt");
    if (inputfile1.fail())
    {
        cout << "ERROR: Unable to open a file" << endl;
    }
    else
    {
        for (i = 0; i < NUM_EMPLOYEES; i++)
        {
            inputfile1 >> tempId;
            inputfile1.ignore();
            inputfile1.get(tempName, 20, '\n');
            inputfile1 >> tempHourlyPay >> tempNumDeps >> tempType >> gender;
            if (inputfile1.eof())
                break;
            masterFile[i].set(tempName, tempId, tempHourlyPay, tempNumDeps, tempType);
            numMasterEmps++;
        }
    }
    cout << "Number of employees in master file = " << numMasterEmps << endl;
    inputfile1.close();

    // PART 3: Defining a name and opening an input file. Fill TransInfo struct array
    //         from file "trans10.txt" or display an error message. In the if-else loop,
    //         defining a name and opening an outpur file.
    
    // INPUT FILE 2 OPERATIONS BEGIN.
    ifstream inputfile2("trans10.txt");
    if (inputfile2.fail())
    {
        cout << "ERROR: Unable to open a file" << endl;

    }
    else
    {
    // OUTPUT FILE OPERATIONS BEGIN.
    ofstream outputFile("payroll10.txt");
    outputFile << fixed << showpoint << setprecision (2);
    outputFile << "ID" << setw(20) << "Name" << setw(25) << "Gross Pay" << setw(12) << "Tax" << setw (16) << "Insurance" << setw(15) << "Net Pay"<<endl;

        i=0;
        inputfile2 >> paycheck.empID >> paycheck.hoursWorked;
        while (inputfile2)
        {
            i++;
            position = search (paycheck.empID, masterFile, numMasterEmps);
            if (position == -1)
            {
                cout << "ERROR: ID # " << paycheck.empID << " is not found in master file." << endl;
            }
            else
            {
                if (paycheck.empID >0)
                {
                if (paycheck.hoursWorked > 0)
                {
                if ((masterFile[position].getType() == 0) && (paycheck.hoursWorked > 40))
                {
                    grossPay = (paycheck.hoursWorked - 40)*    1.5 * masterFile[position].getHourlyPay() + 40 * masterFile[position].getHourlyPay();
                }
                else
                {
                    grossPay= paycheck.hoursWorked * masterFile[position].getHourlyPay();
                }

                insurance = masterFile[position].getDependents() * 20;
                tax = grossPay * 0.15;
                netPay = (grossPay - tax - insurance);
                outputFile << left << setw(17) << paycheck.empID << setw(11) << right << masterFile[position].getName() << setw(9)<< grossPay << setw(15)<< tax << setw(15)<< insurance << setw(15)<< netPay << endl;

                totalGrossPay = totalGrossPay + grossPay;
                totalNetPay = totalNetPay + netPay;
                countTrans++;

            }
            else
            {
                cout <<masterFile[position].getName()<<" worked less than 0.0 hours and will not be included in the payroll report" << endl;
            }
        }
            }
        inputfile2 >> paycheck.empID >> paycheck.hoursWorked;
        }
    // END OF INPUT FULE 2 OPERATIONS.
    inputfile2.close();

    cout << "Employees in transaction file = " << i << endl;
    cout << "Successful transactions: "<< countTrans << endl;
    outputFile << "Total Gross Pay: " << totalGrossPay << "\nTotal Net Pay  : " << totalNetPay <<endl;
    
    // END OF OUTPUT FILE OPERATIONS.
    outputFile.close();
    }
    return 0;
}


// FUNCTION search: search for employee ID and return its position if found.


int search ( int empID, Employee masterFile[], int length)
{
    int i = 0;
    while (i < length)
    {
        if (empID == masterFile[i].getEmpId())
            return i;
        i++;
    }
    return -1;
}
