//*************************************************************************
//  Payroll Version 1.0
//  Programmer: Ariadna Ayala
//  Completed: 10/13/2019
//  Status: Completed
//
//  This program collects user input for employees' informaton and amount of hours worked,
//  then it generates a payroll output that displays employees weekly pay based on the
//  input. Program also prints total Gross and Ner pay of all employees combined.
//*************************************************************************


#include <iostream>
#include <iomanip>

using namespace std;

struct Employee
{
	int emplID,						// Integer holds employee ID value;
		emplType;					// Integer holds employee type value;
	double payRate;					// Double variable holds employee pay rate;
    char emplName[20];				// Variable holds employee name (20 spaces);

};
int main()
{
	// PART 1: Set constant variables
    int const MAX_EMPL =4;			// Integer constant indicates max amount of employees;
    double const INCOME_TAX = 0.15; // Double constant holds income tax value;

	
	
	// PART 2: Input employee information. Using input validation loops
	// that display error messages and ask user to try again when invalid
	// input occured. Using members of structure Employee to store user input.
	
    Employee employees[MAX_EMPL];
    for (int i = 0; i<MAX_EMPL; i=i+1)
    {
        cout << "Enter information for employee " << (i+1) << endl;
		cout << "Employee ID: ";
		cin >> employees[i].emplID;
		while (employees[i].emplID <= 0)
		{
			cout << "Invalid ID. Try again." << endl;
			cout << "Emplyee ID: ";
			cin >> employees[i].emplID;
		}
		
		cin.ignore();
		cout << "Employee Name: ";
		cin.getline(employees[i].emplName, 20);
		
		cout << "Pay Rate: ";
		cin >> employees[i].payRate;
		while (employees[i].payRate<=0)
		{
			cout << "Invalid value. Try again." << endl;
			cout << "Pay Rate: ";
			cin >> employees[i].payRate;
		}
		cin.ignore();
		cout << " Enter 0 for Union employee, 1 for Management" << endl;
		cout << "Type: ";
		cin >> employees[i].emplType;
		while (employees[i].emplType != 0 && employees[i].emplType != 1)
		{
			cout << "Invalid Employee Type. Please try again." << endl;
			cout << "Type: ";
			cin >> employees[i].emplType;
		}
    }
	
	// PART 3: Payroll loop accepts user input for amount of hours each employee
	// worked. Input validation loop displays an error message and asks user to
	// try again when invalis input occured.
	double hrsWorked[MAX_EMPL],
		   grossPay[MAX_EMPL],
		   tax[MAX_EMPL],
		   netPay[MAX_EMPL];
	cout << "Enter timecard information for each employee: " << endl;
	for (int i = 0; i<MAX_EMPL; i=i+1)
	{
		cout << "Hours worked for " << employees[i].emplName <<":";
		cin >>hrsWorked[i];
		while (hrsWorked[i]<0)
		{
			cout << "Invalid amount of hours. Try again." << endl;
			cout << "Hours worked for " << employees[i].emplName << ":";
			cin >> hrsWorked[i];
		}
	}
	
	// PART 4: Processing payroll. Perdorming calculation required to determine
	// each employee's gross and net pay and adds their values to total gross
	// and net pay accumulators.
	double totalGrossPay = 0.0,		// Total gross pay accumulator set to 0.0;
		   totalNetPay = 0.0;		// Total net pay accumulator set to 0.0
	
	cout << fixed << setprecision(2);
	cout << setw(4) << "ID" << setw(20) << "Name" << setw(14)
	<< "Gross Pay" << setw(10) << "Tax" << setw(10) << "Net Pay" << endl;
	for (int i =0; i<MAX_EMPL; i=i+1)
	{
		if (hrsWorked[i] <=40 && employees[i].emplType == 0)
		{
			grossPay[i] = hrsWorked[i]*employees[i].payRate;
			totalGrossPay = totalGrossPay + grossPay[i];
			tax[i] = grossPay[i]*INCOME_TAX;
			netPay[i] = grossPay[i]-tax[i];
			totalNetPay = totalNetPay + netPay[i];
		}
		else
		{
			grossPay[i] = hrsWorked[i]*employees[i].payRate;
			totalGrossPay = totalGrossPay + grossPay [i];
			tax[i] = grossPay[i]*INCOME_TAX;
			netPay[i]=grossPay[i]-tax[i];
			totalNetPay = totalNetPay + netPay[i];
		}
		cout << setw(4)<<employees[i].emplID << setw(20) <<employees[i].emplName
			 << setw(14) << grossPay[i] << setw(10) << tax[i] << setw(10) << netPay[i]
			 << endl;
	}
	
	// PART 5: Displaying total Gross and Net pay due for the week.
	cout << "Total Gross Pay For All Employees Combined: $" << totalGrossPay << endl;
	cout << "Total Net Pay For All Employees Combined: $" << totalNetPay << endl;
	
	
	return 0;
}
