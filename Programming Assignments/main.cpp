//*************************************************************************
//  Account Balancing Program 2.0 (reviced)
//  Programmer: Ariadna Ayala
//  Completed: 09/22/2019
//  Status: Completed
//
//  This ia a revised version of Checkbook Balancing program (PA2). It performs the same operations
//  as its prototype. The program has been restructured and additional service fees were added.
//*************************************************************************

#include <iomanip>
#include <iostream>

using namespace std;


double transactC (double, const float,const float,const float, double, double, int);
double transactD (double, double, double, float const, int);
double transactE (double, double);


int main ()
{
    // Part 1: Setting variables and constants, collecting initial user input for balance,
    // and setting floating point output format for the function to two decimal places.
    
    double  balance,                        // Initial balance of the account.
            amount,                         // User input for transaction amount.
            totalServFee = 0.0;             // Service fee accumulator.
    char transacType = 0.0;                 // User input for transaction type.
    const float CHECK_FEE = 0.35,           // Constant for check processing fee.
                LOW_FEE = 10.00,            // Constant for low balance fee.
                NEGATIVE_FEE = 30.00;       // Constant for negative balance.
    int lowBalance = 0;                     // Low balance count variable.
    
    cout << fixed << showpoint << setprecision(2);
    
    
    cout << "Checkbook Balancing Program 2.0\n" << endl;
    cout << "Commands: \nC - process a check;\n" <<
    "D - process a deposit;\n" <<
    "E - end of month processing and exit the program." << endl;
    cout << "Enter the beginning balance: ";
    cin >> balance;
    
    // Part 2: Decision making based on user input for transaction type. Program determines
    // what function to deploy and collects user input for transaction amount. Here program
    // detects invalid user input and displays error messages accordingly.
    
    while (transacType != 'e' || transacType != 'E')
    {
        cout << "\nEnter a transaction: ";
        cin >> transacType;
        
        if (transacType == 'C' || transacType == 'c')
        {
            cin >> amount;
            if (amount >=0)
            {
            
                totalServFee += CHECK_FEE;
                balance = transactC(balance, CHECK_FEE, LOW_FEE, NEGATIVE_FEE, totalServFee, amount, lowBalance);
                if (balance < 1000 && lowBalance == 0)
                {
                    totalServFee += LOW_FEE;
                    lowBalance = 1;
                }
                if (balance < 0)
                    totalServFee +=NEGATIVE_FEE;
            }
            else
            {
                cout << "ERROR! The amount cannot be less than zero. Enter a valid transaction." << endl;
            }
        }
        
        else if (transacType == 'D' || transacType == 'd')
        {
            cin >> amount;
            if (amount < 0)
            {
                cout << "ERROR! The amount cannot be less than zero. Enter a valid transaction. \n";
            }
            else
            {
                balance = transactD(balance,totalServFee, amount, LOW_FEE,lowBalance);
                if (balance < 1000 && lowBalance == 0)
                {
                    totalServFee += LOW_FEE;
                    lowBalance = 1;
                }
            }
        }
        else if (transacType == 'E' || transacType == 'e')
        {
            cout << "Processing end of month" << endl;
            transactE(balance, totalServFee);
            break;
        }
        else
        {
            cout << "ERROR! Invalid command entered." << endl;
        }
    }
    return 0;
}


// This function performs all calculations necessary for transaction C:
// subtracts transaction amount from current balance and adds fees. Fees yet to be subtracted.
// Then it outputs the information about user's current balance and fees to be charged.


double transactC (double balance, const float CHECK_FEE, const float LOW_FEE, const float NEGATIVE_FEE, double totalServFee, double amount, int lowBalance)
{
    cout << fixed << showpoint << setprecision(2);
    
    cout << "Processing check for $" << amount << endl;
    balance -= amount;
    cout << "Balance: $" << balance << endl;
    cout << "Check processing fee: $" << CHECK_FEE << " for a check" << endl;
    if (balance < 1000 && lowBalance == 0)
    {
        cout << "Service charge: $10.00 balance below $1000.00." << endl;
        totalServFee += LOW_FEE;
    }
    if (balance < 0)
    {
        cout << "Service charge: $30.00 negative account balance."<< endl;
        totalServFee += NEGATIVE_FEE;
    }
    cout << "Total service charges: $" << totalServFee << endl;
    cout << "\n";
    return balance;
}


// This function performs all calculations necessary for transaction D:
// adds transaction amount to current balance and adds a low fee if the balance after deposit
// is still low. Then outputs the information about user's currect balance and fees to be charged.

double transactD (double balance, double totalServFee, double amount, const float LOW_FEE, int lowBalance)
{
    cout << fixed << showpoint << setprecision(2);                  // Setting floating point output format to
                                                                    // two decimal places.
    
    cout << "Processing deposit for $" << amount << endl;
    balance += amount;
    if (balance < 1000 && lowBalance == 0)
    {
        cout << "Service charge: $10.00 balance below $1000.00." << endl;
        totalServFee += LOW_FEE;
    }
    cout << "Balance: $" << balance << endl;
    cout << "Total service charges: $" << totalServFee << endl;

     return balance;
}

// This function subtracts accumulated fees from current balance and displays
// user's final balance and fees that were charged.

double transactE(double balance, double totalServFee)
{
    cout << fixed << showpoint << setprecision(2);                  // Setting floating point output format to
                                                                    // two decimal places.
    balance -= totalServFee;
    cout << "Final balance: $" << balance << endl;
    cout << "Total service charges: $" << totalServFee << endl;
    cout << "\nThank you and have a good day!" << endl;;
    
    return balance;
}
