//*************************************************************************
//  Robot Speed Estimator
//  Programmer: Ariadna Ayala
//  Completed: 09/28/2019
//  Status: Completed
//
//  This program collects user input for gear motor speed and wheel diamter and calculates estimated
//  speed of a robot based on the input. It will display a set of instructions first, if an input
//  is invalid, the program will display an error message. The program allows its user to exit whenever
//  they are ready to do so by intering an 'e' key.
//*************************************************************************

#include <iomanip>
#include <iostream>

using namespace std;

// Class contains private variables for the gear motor speed in revolutions per minute & the wheel diameter in inches,
// public constant for Pi and functions' prototypes.
class Robot
{
private:
    float gearRPM = 74.0;                       // Gear motor speed in rev/min
    float wheelDiameter = 1.0;                  // Wheel diameter on inches
    

public:
    const double PI = 3.14159;                  // Set constant value for Pi.
    
    
    void setRPM (double);
    void setDiameter (double);
    double getRPM();
    double getDiameter();
    double getSpeed();
};

// A mutator function that allows user to change gear motor speed.
void Robot::setRPM (double newRPM)
{
    gearRPM = newRPM;
}
// A mutator function that allows user to change wheels diameter.
void Robot::setDiameter(double newDiameter)
{
    wheelDiameter = newDiameter;
}
// A getter member function that returns the speed of gear motor in RPM.
double Robot::getRPM()
{
    return gearRPM;
}
// A getter member function that returns the wheels diameter.
double Robot::getDiameter()
{
    return wheelDiameter;
}
// A getter function that returns calculated speed using given formula.
double Robot::getSpeed()
{
    return (gearRPM * wheelDiameter * PI) / 12;
}

// Function collects user input for gear motor speed and wheels diameter and displays
// the robot's estimated speed in feet/minute. It will display an error message if an
// invalid input is entered. It will allow user to exit program whenevre they are done.
int main()
{
    Robot userDefined;
    double userRPM,                         // User input for Gear Motor Speed.
           userDiameter;                    // User input for Diameter.
    char again;                             // Loop control, used to exit program.
    
    cout << fixed <<showpoint << setprecision(2);
  
    cout << "Welcome to Robot's speed calculator!" << endl;
    cout << "\t\t\tUser Instructions:" << endl;
    cout << "1) Available gear motor speed options: 74, 190, and 265;"
         << "\n2) Available wheel diameter options: from 1 to 6 inches;"
    << "\n3) Enter 'e' to exit the program.\n" << endl;
        
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
                cout << "Speed of the gear motor: " << userDefined.getRPM()
                     << " RPM;" << endl;
                cout << "Wheel diameter: " << userDefined.getDiameter()
                     << " inch(es);" << endl;
                cout << "Estimated speed of the robot is: " << userDefined.getSpeed()
                     << " feet per minute."<< endl;
            }
            else
            {
                cout << "ERROR! Invalid wheel diameter value." << endl;
            }
        }
        cout << "Enter any key to try again, 'e' to exit: ";
        cin >> again;

        }

    cout << "You have exited the program. Thank you!\n";
    return 0;
}
