#include <iostream> 
#include "TheWheel.h"
#include "Contestant.h"
#include "GameFunctions.h"

using namespace std; 

int main ()
{
    // Class Instances
    // Driver Variables 
    // Get # of Players
    // Create The Wheel
    if (WheelSectionCreator())
    {
        // Game Begins 

    } else 
    {
        cout << "Wheel was unable to created." << endl; 
        cout << "You may not have enough memory." << endl; 
        return 0; 
    }
}

