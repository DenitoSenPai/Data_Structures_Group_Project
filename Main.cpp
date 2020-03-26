#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <algorithm>


// Class Header Files
#include "GameFunctions.h"
#include "TheWheel.h"
#include "Contestant.h"

using namespace std;

int main()
{
    int roundNum = 1;

    // Calls the wheel creating function to create the wheel.
    TheWheelCreator();

    // Welcome Message
    // Game Begins

    // Call & Read from the .txt file.

    ifstream gameFile ("Words_Phrases.txt");
    if  (gameFile.is_open())
    {
        while (!gameFile.eof())
        {
            // Round Variables
            // Declared here so they can get reset each round.
            int numPlayers = 0, i=0, lineSize = 0, spinSection = 0, wordGuessed = 0;
            char sChar = ' ', guessedChar = ' ';
            string line;
            float wheelValue = 0.0;


            // Read everything from the line into the string.
            getline(gameFile, line);
            // Create a character array of line size.
            char lineContent[line.size() + 1];
            // Copy the string from the line into the character array.
            std::copy(line.begin(), line.end(), lineContent);
            // Adds NULL character
            lineContent[line.size()] = '\0';
            // Prints the array
            std::cout << lineContent << endl;
            std::cout << "Size of original: " << line.size() << endl;
            std::cout << "Line: #" << i++ << endl;

            // Create a copy of the original array.
            char lineCopy[line.size() + 1];
            // Populate it with " - "
            // Display and update accordingly.
            for (i=0; i<=line.size(); i++)
            {
                lineCopy[i] = '-';
                if (lineContent[i] == ' ')
                    lineCopy[i] = ' ';
            }
            lineCopy[line.size()] = '\0';

            std::cout << "Round : " << roundNum << endl;
            std::cout << lineCopy << endl;

            std::cout << "Please enter a key to spin the wheel." << endl;
            system("pause");

            spinSection = SpinTheWheel();


            cout << "" << TheWheel.Search(spinSection)->getSectionData().getSectionType() << endl;
            wheelValue = TheWheel.Search(spinSection)->getSectionData().getSectionValue();

            if (wheelValue < 0)
                if (TheWheel.Search(spinSection)->getSectionData().getSectionType() == "Lose A Turn.")
                    std::cout << "Sorry, your turn has been lost." << endl;
                else
                    std::cout << "Sorry, you have been Bankrupted." << endl;
            else while (wheelValue > 0 && wordGuessed != 1)
            {
                std::cout << "Guess a letter." << endl;
                std::cin >> guessedChar;
            }

            system("pause");

        }
    }

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
