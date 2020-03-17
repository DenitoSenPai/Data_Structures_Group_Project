#include <iostream> 

using namespace std; 

// Function Declaration
int RandomNumber (int int);
int SpinWheel (); 

int main ()
{
    // Class Instances

    // Driver Variables 

    // Game Begins 
    return 0; 
}

// Game Functions 

/* Generates a random number 
inbetween 2 Indicated Numbers. */
int RandomNumber (int Num1, int Num2) 
{ return Num1 + Srand () % Num2; }

/* "Spins" the wheel X amount of times, 
then returns Y as the wheel section.*/
int SpinWheel ()
{
    int i, sectionID; 
    for (i=0, i = RandomNumber(10,21), i++)
    {
        // Clear Screen
        sectionID = RandomNumber(0,26);

        // Call Search Method . Display Method 
        
        // Sleep for .5 seconds
    }
    return sectionID; 
}

/*Calls the deallocator for each Class, 
when the game is finished.*/
void Deallocator () 
{
    //...
}
