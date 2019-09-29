  
//*************************************************************************
//  Robot Speed Estimator
//  Programmer: Ariadna Ayala
//  Completed: 09/28/2019
//  Status: Incomplete.
//
//  This program collects user input for gear motor speed and wheel diamter and calculates estimated
//  speed of a robot based on the input. 
//*************************************************************************
//
//
//
// To Fix:
// 1) Fix infinite loop in case of char input to RMP
// 3) add speed in inches per minute (???);
//*************************************************************************

#include <iomanip>
#include <iostream>

using namespace std;

class Robot
{
private:
    float gearRPM = 74.0;                       // Gear motor speed in rev/min
    float wheelDiameter = 1.0;                  // Wheel diameter on inches
    

public:
    const double PI = 3.14159;
    
    
    void setRPM (double);
    void setDiameter (double);
    double getRPM();
    double getDiameter();
    double getSpeed();

};
//*********************************************************************************

void Robot::setRPM (double newRPM)
{
    gearRPM = newRPM;
}

void Robot::setDiameter(double newDiameter)
{
    wheelDiameter = newDiameter;
}

double Robot::getRPM()
{
    return gearRPM;
}
double Robot::getDiameter()
{
    return wheelDiameter;
}

// Function returns calculated speed.
double Robot::getSpeed()
{
    return (gearRPM * wheelDiameter * PI) / 12;
}


int main()
{
    Robot userDefined;
    double userRPM,                         // User input for Gear Motor Speed.
           userDiameter;                    // User input for Diameter.
    char again;                             // Loop control, used to exit program.
  
  
    cout << "User Instructions:" << endl;
    cout << "1) Enter your gear motor speed value first then wheel diameter;" 
         << "\n2) Available gear motor speed options: 74, 190, and 265;"
         << "\n3) Available wheel diameter options: from 1 to 6 inches;"
         << "\n4) Enter 'e' to exit the program.\n"
        
    while (again != 'e' && again !='E')
    {
        cout << "\nEnter new gear motor speed value: ";
        cin >> userRPM;
        if (userRPM != 265 && userRPM != 190 && userRPM != 74)
        {
            cout << "ERROR! Invalid speed value." << endl;
        }
        else
        {
            userDefined.setRPM(userRPM);
            cout << "Enter new wheel diameter: ";
            cin >> userDiameter;
            if (userDiameter >= 1 && userDiameter <= 6 )
            {
                userDefined.setDiameter(userDiameter);
                cout << "\nHere is the data you intered: " << endl;
                cout << "Speed of the gear motor: " << userDefined.getRPM() <<
                        " RPM;" << endl;
                cout << "Wheel diameter: " << userDefined.getDiameter() <<
                        " inch(es);" << endl;
                cout << "Estimated speed of the robot is: " << userDefined.getSpeed() <<
                        " feet per minute."<< endl;
            }
            else
            {
                cout << "ERROR! Invalid wheel diameter value." << endl;
            }
        }
        cout << "Enter any key to try again, e to exit: ";
        cin >> again;

        }

    cout << " You have exited the program.\n";
    return 0;
}

  
        \_/
     (* *)
    __)#(__
   ( )...( )(_)
   || |_| ||//
>==() | | ()/
    _(___)_
   [-]   [-]
