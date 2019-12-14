//*************************************************************************
//  Payroll V2.0
//  Programmer: Ariadna Ayala
//  Completed: 12/10/2019
//  Status: Completed

//  This program reads the data in two input files ("master9" and "trans9") and outputs processed data
//  into a designated file named "paroll9." The data will not be output into file if an employee
//  worked less than 0 hrs. Output visible in IDE: list of employees with invalid hrs & amount of
//  successful transactions.
//*************************************************************************

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class Employee
{
  private:
    int id;             // employee ID
    string name;        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type
    
  public:
    Employee( int initId=0, string initName="",
              double initHourlyPay=0.0,
              int initNumDeps=0, int initType=0 );  // Constructor

    bool set(int newId, string newName, double newHourlyPay,
             int newNumDeps, int newType);
    
    int getEmployeeID();
    string getName();
    double getHourlyPay();
    int getDeps();
    int getEmployeeType();
    
};

Employee::Employee( int initId, string initName,
                    double initHourlyPay,
                    int initNumDeps, int initType )
{
  bool status = set( initId, initName, initHourlyPay,
                     initNumDeps, initType );

  if ( !status )
  {
    id = 0;
    name = "";
    hourlyPay = 0.0;
    numDeps = 0;
    type = 0;
  }
}

bool Employee::set( int newId, string newName, double newHourlyPay,
                                 int newNumDeps, int newType )
{
  bool status = false;

  if ( newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 &&
       newType >= 0 && newType <= 1 )
  {
    status = true;
    id = newId;
    name = newName;
    hourlyPay = newHourlyPay;
    numDeps = newNumDeps;
    type = newType;
  }
  return status;
}

// get functions of Employee class.

// Functionc gets employee ID.
int Employee::getEmployeeID()
{
    return id;
}
// Function gets employee name.
string Employee::getName()
{
    return name;
}
// Function getsget employee hourly pay.
double Employee::getHourlyPay()
{
    return hourlyPay;
}
// Function gets employee number of dependents.
int Employee::getDeps()
{
    return numDeps;
}
// Function gets employee type.
int Employee::getEmployeeType()
{
    return type;
}


//Struct Declaration for TransInfo

struct TransInfo
{
     int empID;
     double hoursWorked;
     double normalPay;
};

int main ()
{
    // PART 1: declaring constant variable, arrays, and variables.
    const int NUM_EMPLOYEES = 6;                // Number of employees.
    Employee masterFile[NUM_EMPLOYEES];         // Array of class Employee;
    TransInfo paycheck[NUM_EMPLOYEES];          // Array of structure TransInfo
    
    int i;                                      // Index variable;
    double  grossPay = 0.0,                     // Gross pay (before Tax);
            netPay = 0.0,                       // Net pay (afyer Tax);
            insurance = 0,                      // insurance amount;
            tax = 0.0,                          // Tax amount;
            totalGrossPay = 0.0,                // Employees' total Gross Pay;
            totalNetPay = 0.0;                  // Employees' total Net Pay
    //* int count = 0;                          // Counter variable *//

    int tempId;                                 // Temporary Employee ID variable;
    string tempName;                            // Temporary Employee name variable;
    double tempHourlyPay;                       // Temporary Hourly rate variable;
    int tempNumDeps,                            // Temporary Number of dependents variable;
        tempType,                               // Temporary Employee type variable;
        // hoursWorked,                            // Hours worked by each employee;
        countTrans = 0;                         // Counter variable.
    
    
    
    // PART 2: Defining a name and opening an input file. Fill masterFile class array
    //         from file "master9.txt" or display an error message.
    ifstream inputfile1 ("master9.txt");
    if (!inputfile1)
    {
      cout << "ERROR: Unable to open file" << endl;
    }
    else
    {
        for (i = 0; i < NUM_EMPLOYEES; i++)
        {
            inputfile1 >> tempId;
            getline (inputfile1,tempName, '#');
            inputfile1 >> tempHourlyPay >> tempNumDeps >> tempType;
            masterFile[i].set(tempId, tempName, tempHourlyPay, tempNumDeps, tempType);
         }
    }
    inputfile1.close();
    
    
    // PART 3: Defining a name and opening an input file. Fill TransInfo struct array
    //         from file "trans9.txt" or display an error message.
    
    ifstream inputfile2("trans9.txt");
    if (!inputfile2)
    {
       cout << "ERROR: Unable to open file" << endl;
    }
    else
    {
        for (i = 0; i < NUM_EMPLOYEES; i++)
        {
            inputfile2 >> paycheck[i].empID >> paycheck[i].hoursWorked;
            paycheck[i].normalPay = (paycheck[i].hoursWorked * masterFile[i].getHourlyPay());
        }
    }
    inputfile2.close();
    
    // PART 4: Defining a name and open an output file.
    ofstream outputFile("payroll9.txt");
    outputFile << fixed << showpoint << setprecision (2);
    outputFile << "ID" << setw(20) << "Name" << setw(25) << "Gross Pay" << setw(15) << "Tax" << setw (15) << "Insurance" << setw(15) << "Net Pay"<<endl;
    
    // PART 5: Processing the payroll. Read the arrays if employee ID is greater than 0.
    //         Output employee information. If an employee worked <= 0 hours , print a
    //         message of exclusion from a payroll.
    for (i =0; i< NUM_EMPLOYEES; i++)
    {
        if (masterFile [i].getEmployeeID()>0)
        {
           if (paycheck[i].hoursWorked > 0)
           {
              if ((masterFile[i].getEmployeeType() == 0) && (paycheck[i].hoursWorked > 40))
              {
                 grossPay = (paycheck[i].hoursWorked - 40)* 1.5 * masterFile[i].getHourlyPay() + 40 * masterFile[i].getHourlyPay();
              }
              else
              {
                  grossPay= paycheck[i].hoursWorked * masterFile[i].getHourlyPay();
              }
              insurance = masterFile[i].getDeps() * 20;
              tax = grossPay * 0.15;
              netPay = (grossPay - tax - insurance);
              outputFile << left << setw(17) << masterFile[i].getEmployeeID() << setw(11) << right << masterFile[i].getName() << setw(9)<< grossPay << setw(15)<< tax << setw(15)<< insurance << setw(15)<< netPay << endl;
              
              totalGrossPay = totalGrossPay + grossPay;
              totalNetPay = totalNetPay + netPay;
              countTrans++;
            }
          else
          {
              cout <<masterFile[i].getName()<<" worked less than 0.0 hours and will not be included in the payroll report" << endl;
          }
        }
    }
    
    // PART 6: Output a number of successful transactions and enter a payroll report into
    //         a file: one transaction in one line; then enter total gross pay and total
    //         net pay information.
    cout <<"Successful transactions: "<< countTrans <<endl;
     for (i =0; i< NUM_EMPLOYEES; i++)
    {
        
     }
     outputFile << "Total Gross Pay: " << totalGrossPay << "\nTotal Net Pay  : " << totalNetPay <<endl;
           
     outputFile.close();

    return 0;
}
