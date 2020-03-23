#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <string>


// Class Header Files
#include "GameFunctions.h"
#include "TheWheel.h"
#include "Contestant.h"

using namespace std;

int main()
{
	// All the main game play variables. 
    int numPlayers=0, i=0, lineSize = 0, numLine = 0, flag = 0;
    char sChar = ' ', lineContent[50];
    //string line;
    std::vector<char> lineData;

    // Calls the wheel creating function to create the wheel.
    //TheWheelCreator();

    // Welcome Message

    // Game Begins

    // Call & Read from the .txt file.

    while (flag != 1)
    {
        ifstream gameFile ("Words_Phrases.txt");
        if  (gameFile.is_open())
        {
        	// Gameplay occurs until eof() = true. 
            while (!gameFile.eof())
            {
            	gameFile.get(sChar);
            	
				   while (sChar != '\n')
		        	{
		        		// Line Content array has been populated. 
		        		lineContent[i] = sChar; 
		        		i++;
						gameFile.get(sChar);
					}

        		
				if (sChar == '\n')
				{
					// Counts the amount of lines. 
					cout << "" << sChar; 
					numLine++;
				}
			}
                	
            cout << "Number of Characters: " << i << endl;
            cout << "Number of Lines: " << numLine-1 << endl; 
            for (i=0; i<=50; i++)
        		cout << lineContent[i];  
        }
        
         
    }
    cout << endl;


    // Put the word/phrase in an array to be analyzed.

    // Display the word/phrase on screen.

    // Ask player to spin the wheel.

    // If player gets a reward, have him/her guess a letter.

    // If wrong guess, move to other player.

    // When word is guessed, move to round two.

    // Ask each player (1 - numPlayers) to guess.

    //TheWheel.Search(SpinTheWheel());
    //cout << "Complete: " << SpinTheWheel() << endl;
    return 0;
}
