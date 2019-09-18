//*************************************************************************
//  Account Balancing Program
//  Programmer: Ariadna Ayala
//  Completed: 09/13/2019
//  Status: Completed
//
//  This program collects user's beginning balance and completes following transactions:
//  process checks(C), process deposots(D), and end of month processing and exit (E). The program
//  is not case sensetive. Error message is displayed when user enters invalid transaction type
//  and when the transaction amount is lesser than zero.
//*************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Part 1: Setting variables and collecting initial user input for
    // starting balance and displays commands options available for user.
    
    char transacType = ' ';                                         // User choice of transaction type.
    double  startBalance = 0.0,                                     // Initial balance of the account.
            checkFees = 0,                                          // Check fees accumulator.
            transactAmount;                                         // User unput fot transaction Amount.
    const double SERVICE_CHARGE = 0.35;                             // Service fee for check processing constant.
    
    
    cout << fixed << showpoint << setprecision(2);                  // Setting floating point output format to
                                                                    // two decimal places.
    
    
    cout << "Enter your beginning balance: ";
    cin >> startBalance;
    cout << "Commands: \nC - process a check;\n" <<
    "D - process a deposit;\n" <<
    "E - end of month processing and exit the program." << endl;
    

    // PART 2: Decision making based on user input. This part collects user's input for
    // a transaction type. The program determines which set of operations to perform and
    // collects user's input for transaction amount. This part will display an error message
    // for invalid input: invalid command type or negative transaction amount. The program
    // will display final statement, total fees and ending balance, then it will end.
    
    
    while (transacType != 'e' || transacType != 'E')
    {
        cout << "\nEnter transaction type: ";
        cin >> transacType;
        
        if (transacType == 'c' || transacType == 'C')
        {
            cout << "\nEnter transaction amount: ";
            cin >> transactAmount;
            if (transactAmount >= 0.00)
            {
                cout << "Processing check for $"<< transactAmount << endl;
                cout << "Balance: "<<(startBalance -= transactAmount) << endl;
                cout << "Service charge: $" << SERVICE_CHARGE << " for a check\n"
                << "Total service charges: $" << (checkFees += SERVICE_CHARGE) << endl;
                
            }
            else
            {
                cout << "\nERROR! The amount cannot be negative. Please try again.\n";
            }
        }
        
        
        else if (transacType == 'd' || transacType == 'D')
        {
            cout << "\nEnter transaction amount: ";
            cin >> transactAmount;
            if (transactAmount >= 0.00)
            {
                cout << "Processing deposit of " << transactAmount << endl;
                cout << "Balance: " << (startBalance += transactAmount) << endl;
                cout << "Accumlative fees this month: $" << checkFees << endl;
            }
            else
            {
                cout << "ERROR! The amount cannot be negative. Please try again.\n";
            }
        }
        
        
        else if (transacType == 'e' || transacType == 'E')
        {
            
            cout << "\nProcessing end of the month:\n";
            startBalance -= checkFees;
            cout << "Final fee this month: " << checkFees << endl;
            cout << "Final Balance: "<<startBalance <<endl;
            
            break;
        }
        
        else
        {
            cout << "\nERROR! Invalid command entered.";
        }
    }
    cout << "\nThank you and have a good day!" << endl;
    return 0;
}

