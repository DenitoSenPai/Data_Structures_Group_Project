#include <iostream>
#include <time.h>
#include <fstream>
#include <string>


// Class Header Files
#include "GameFunctions.h"
#include "TheWheel.h"
#include "Contestant.h"

using namespace std;

int main()
{
    int numPlayers=0, i=0, lineSize = 0;
    char sChar, lineContent[lineSize];
    string line;

    // Calls the wheel creating function to create the wheel.
    //TheWheelCreator();

    // Welcome Message



    // Game Begins

    // Call & Read from the .txt file.
    int flag = 0;

    while (flag != 1)
    {
        ifstream gameFile ("Words_Phrases.txt");
        if  (gameFile.is_open())
        {


            while (!gameFile.eof())
            {
                // Character
                gameFile.get(sChar);
                cout << "" << sChar;

                i++;
            }
            cout << "\n" << "Number of characters: " << i << endl;
        }
        flag = 1;
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
