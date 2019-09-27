//
//  main.cpp
//  Program4
//
//  Created by Ariadna on 9/27/19.
//  Copyright © 2019 Ariadna. All rights reserved.
//

#include <iostream>

using namespace std;

class Robot
{
private:
    float gearRPM = 74.0;                       // Gear motor speed in rev/min
    float wheelDiameter = 1.0;                  // Wheel diameter on inches
    
//******************************************************************************
public:
    void setRPM (double newRPM)
    {
        cout << "Enter new RPM value: ";
        cin >> newRPM;
        if (newRPM == 74 || newRPM == 190 || newRPM == 265)
        {
            gearRPM = newRPM;
        }
        else
        {
            cout << "ERROR! Invalid speed value. Please, try again." << endl;
            cout << "Enter new RPM value: ";
            cin >> newRPM;
        }
    }
//********************************************************************************
    
    
    void setDiameter (double newDiameter)
    {
        cout << "Enter new wheel diameter: ";
        cin >> newDiameter;
        if (newDiameter >= 1 && newDiameter <= 6)
        {
            wheelDiameter = newDiameter;
        }
        else
        {
            cout << "ERROR! Invalid wheel diameter value. Please, try again."<< endl;
            cout << "Enter new wheel diameter: ";
            cin >> newDiameter;
        }
    }
//************************************************************************************
    double getRPM()
    {
        return gearRPM;
    }
    double getDiameter()
    {
        return wheelDiameter;
    }
    double getSpeed (double robotSpeed)
    {
        return robotSpeed;
    }
};
 int main()
{
    
    return 0;
}
