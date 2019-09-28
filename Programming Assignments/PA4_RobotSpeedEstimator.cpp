  
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
// 1) Return to initial input prompt (RPM) in case of error;
// 2) enable exit option;
// 3) add speed in inched per minute (???);
// 4) disclose input restrictions;
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
    double userRPM,
           userDiameter;
    char again;
    
    while (again != 'e' || again != 'E')
    {
        cout << "Enter new RPM value: ";
        cin >> userRPM;
    
        if (userRPM == 74 || userRPM == 190 || userRPM == 265)
        {
            userDefined.setRPM(userRPM);
        }
        else
        {
            cout << "ERROR! Invalid speed value. Please, try again." << endl;
        }
            cout << "Enter new wheel diameter: ";
        cin >> userDiameter;
        if (userDiameter >= 1 || userDiameter <= 6 )
        {
            userDefined.setDiameter(userDiameter);
        }
        else
        {
            cout << "ERROR! Invalid wheel diameter value. Please, try again." << endl;

        }
    
        cout << "\nHere is the data you intered: " << endl;
        cout << "Speed of the gear motor: " << userDefined.getRPM() <<
                " RPM;" << endl;
        cout << "Wheel diameter: " << userDefined.getDiameter() <<
        " inch(es);" << endl;
        cout << "Estimated speed of the robot is: " << userDefined.getSpeed() <<
                " feet per minute."<< endl;
        cout << "Enter any key to try again, e to exit: ";
    }

    return 0;
  
        \_/
     (* *)
    __)#(__
   ( )...( )(_)
   || |_| ||//
>==() | | ()/
    _(___)_
   [-]   [-]MJP
}
