//*************************************************************************
//  Account Balancing Program
//  Programmer: Ariadna Ayala
//  Completed: 09/13/2019
//  Status: Completed
//
//  This ia a revised version of Checkbook Balancing program (PA2). It performs the same operations
//  as its prototype. The program has been restructured and additional service fees were added.
//*************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;


double transacC (double startBalance, double totalServFees);
double transacD (double startBalance, double totalServFees);
double transacE (double startBalance, double totalServFees);

int main()
{
    // Part 1: Setting variables and collecting initial user input for
    // starting balance and displays commands options available for user.
    
    char transacType = ' ';                                         // User choice of transaction type.
    double  startBalance = 0.0,                                     // Initial balance of the account.
            totalServFees = 0.0;                                    // Total service fees accumulator.
    
    
    cout << fixed << showpoint << setprecision(2);                  // Setting floating point output format to
                                                                    // two decimal places.
    
    cout << "Welcome to Checkbook Balancing program" << endl;
    cout << "Commands: \nC - process a check;\n" <<
    "D - process a deposit;\n" <<
    "E - end of month processing and exit the program." << endl;
    cout << "><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << endl;
    
    // PART 2: Decision making based on user input. This part collects user's input for
    // a transaction type and executes an appropriate function that corresponds to the input.
    
    cout << "Enter your beginning balance and transaction type: ";
    cin >> startBalance >> transacType;
    
    while (transacType == 'e' || transacType != 'E')
    {
        
        
        if (transacType == 'c' || transacType == 'C')
        {
            transacC (startBalance, totalServFees);
            cout << "Enter transaction type: ";
            cin >> transacType;
        }
        
        else if (transacType == 'd' || transacType == 'D')
        {
            transacD (startBalance, totalServFees);
        }
        
        else if (transacType == 'e' || transacType == 'E')
        {
            transacE (startBalance, totalServFees);
            // BREAK???????
        }
        else
        {
            cout << "\nERROR! Invalid command entered. Please, try again.";
        }

    }
    return 0;
}
    
    // ********************************************************************************************************
    
    
double transacC (double startBalance,double totalServFees)
{
    const double CHECK_FEE = 0.35,
                 LOW_FEE = 10.00,
                 NEGATIVE_FEE = 30.00;
    double transactAmount = 0.0;
    int countNegative = 0,
        countCheckFee = 0,
        countLowBal = 0;
    
    
    cout << "Enter transaction amount: ";
    cin >> transactAmount;
    if (transactAmount <= 0)
    {
        cout << "ERROR! The amount cannot be negative or equal to zero. Please try again.\n";
        cout << "Enter transaction amount: ";
        cin >> transactAmount;
    }
    else
    {
        cout << "Processing check for $" << transactAmount << endl;
        cout << "Balance: $" << (startBalance -= transactAmount) << endl;

    }
    
    if (startBalance < 0)
    {
        cout << "Check processing fee: $" << CHECK_FEE << endl;
        cout << "Negative balance fee: $" << NEGATIVE_FEE << endl;
        cout << "Total service fees: $" << (totalServFees+=(CHECK_FEE + NEGATIVE_FEE)) << endl;
        countCheckFee++;
        countNegative++;
    }
    else if (startBalance <1000)
    {
        cout << "Check processing fee: $" << CHECK_FEE << endl;
        cout << "Low balance fee: $" << LOW_FEE << endl;
        cout << "Total service fees: $" << (totalServFees+=(CHECK_FEE + LOW_FEE)) << endl;
        countLowBal = 1;
        countCheckFee++;
    }
    else
    {
        cout << "Check processing fee: $" << CHECK_FEE << endl;
        cout << "Total service fees: $" << (totalServFees+=CHECK_FEE) << endl;
        countCheckFee++;
    }
    
    /////////////////////
    return startBalance,totalServFees;
    ////////////////////
}

//********************************************************************
double transacD (double startBalance, double totalServFees)
{
    double transactAmount = 0.0;
    cout << "Enter transaction amount: ";
    cin >> transactAmount;
    
    if (transactAmount < 0)
    {
        cout << "ERROR! The amount cannot be negative or equal to zero. Please try again.\n";
        cout << "Enter transaction amount: ";
        cin >> transactAmount;
    }
    else
    {
        cout << "Processing deposit for: $" << transactAmount << endl;
        startBalance+=transactAmount;
        cout << "Balance: " << startBalance << endl;
        cout << "Total service charges: $" << totalServFees << endl;
    }
    return startBalance, totalServFees;
}

double transacE (double startBalance, double totalServFees)
{
    cout << "Processing end of month:" << endl;
    cout << "Final fee this month: $" << totalServFees << endl;
    cout << "Final Balance: $" << (startBalance-totalServFees) << endl;
    
    return startBalance, totalServFees;
}

