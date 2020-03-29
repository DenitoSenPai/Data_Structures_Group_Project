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
    int roundNum = 1, i = 0;

    // Creates The Wheel with the various sections.
    TheWheelCreator();

    // Welcome Message
    // cout << "Welcome to Young Lads Wheel of Fortune" << endl;

    // Creates Three Players, that the user will enter.
    // ThePlayerBaseCreator();

    // Game Begins

    // Call & Read from the .txt file.

    ifstream gameFile("Words_Phrases.txt");
    if (gameFile.is_open())
    {
        while (!gameFile.eof())
        {
            // Round Variables
            // Variables get reinitalize each line so they can be reused.
            int currentPlayer = 1, lineSize = 0, spinResult = 0, wordGuessed = 0,
                letterOccurence = 0, flag = 0, numDash = 0, playerAccount = 0, 
                sectionValue = 0, roundTotal = 0;
            char sChar = ' ', guessedChar = ' ', availableVowel[10] = {
                                                     'A',
                                                     'a',
                                                     'E',
                                                     'e',
                                                     'I',
                                                     'i',
                                                     'O',
                                                     'o',
                                                     'U',
                                                     'u',
                                                 }, purchaseVowel = ' ';
            string line = " ", lineGuess = " ";

            // Read everything from the line into a string.
            getline(gameFile, line);

            // Create a character array of line size.
            char lineContent[lineSize = (line.size() + 1)];

            // Copy the string from the line into the character array.
            copy(line.begin(), line.end(), lineContent);

            // Adds NULL character to the end of the char array. 
            lineContent[line.size()] = '\0';

            // Prints the array
            cout << lineContent << endl;
            cout << "Size of original: " << line.size() << endl;
            cout << "Line: #" << i++ << endl;

            // Create a copy of the original array.
            char lineCopy[lineSize];

            // Populate it with " - "
            for (i = 0; i <= lineSize; i++)
                if (lineContent[i] == ' ')
                    lineCopy[i] = ' ';
                else
                    lineCopy[i] = '-';

            // Adds NULL character to the end of the char array. 
            lineCopy[line.size()] = '\0';

            // Round Begins here.
            do
            {
                // Display the copy array to be solved. 
                cout << lineCopy << endl;
                cout << "Round #" << roundNum << endl;
                cout << "Player #" << currentPlayer << endl;

                cout << "Please enter a key to spin the wheel." << endl;
                system("pause");

                // Store the value returned from the Spin the wheel function. 
                spinResult = SpinTheWheel();

                // Use the spinResult value to find the Wheel Section/Card. 
                cout << "" << TheWheel.Search(spinResult)->getSectionData().getSectionType() << endl;
                
                // Store the value of that card/section to be analyzed.  
                sectionValue = TheWheel.Search(spinResult)->getSectionData().getSectionValue();

                if (sectionValue == 0)
                {
                    if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Lose A Turn.")
                    {

                        cout << "Sorry, your turn has been lost." << endl;
                        currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                    }
                    else if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Bankrupt")
                    {
                        cout << "Sorry, you have been Bankrupted." << endl;
                        PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(0);
                        currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                    }
                }
                else if (sectionValue > 0)
                {
                    // Stores the value of the card/section. 
                    roundTotal = TheWheel.Search(spinResult)->getSectionData().getSectionValue(); 

                    cout << "Guess a letter." << endl;
                    cin >> guessedChar;

                    while (sectionValue > 0 || wordGuessed != 1 || flag != 1)
                    {
                        for (i = 0; i <= lineSize; i++)
                        {
                            // Compares each character in the array. 
                            if (lineContent[i] == guessedChar)
                            {
                                // Counts the amount of time it occurs.
                                lineCopy[i] = guessedChar;
                                letterOccurence++;
                            }
                        }
                        if (letterOccurence == 0)
                        {
                            // If there is no occurences then its not in the array. 
                            cout << "Sorry Incorrect Letter Guessed." << endl;
                            cout << "Moving to next player." << endl;
                            currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                            flag = 1;
                        }
                        else if (lineContent == lineCopy)
                        {
                            // There was X amount of occurence.
                            // Checking to see if the word was solved. 
                            roundTotal = PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() + (sectionValue * letterOccurence);

                            wordGuessed = 1;
                        }
                        else
                        {
                            roundTotal = PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() + (sectionValue * letterOccurence);

                            switch (GamePlayMenu())
                            {
                            case 1:
                                spinResult = SpinTheWheel();

                                cout << "" << TheWheel.Search(spinResult)->getSectionData().getSectionType() << endl;
                                sectionValue = TheWheel.Search(spinResult)->getSectionData().getSectionValue();

                                if (sectionValue == 0)
                                {
                                    if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Lose A Turn.")
                                    {
                                        cout << "Sorry, your turn has been lost." << endl;
                                        currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                                        
                                    }
                                    else if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Bankrupt")
                                    {
                                        cout << "Sorry, you have been Bankrupted." << endl;
                                        PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(0);
                                        currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                                    }
                                }
                                break;
                            case 2:
                                playerAccount = PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal();
                                if (playerAccount > 150)
                                {
                                    for (i = 0; i <= 10; i++)
                                    {
                                        cout << availableVowel[i];
                                        cout << " - ";
                                    }

                                    cout << "\n"
                                         << "Each Vowel Cost $150" << endl;
                                    cout << "Enter the Vowel you wish to purchase: " << endl;
                                    cin >> purchaseVowel;

                                    guessedChar = purchaseVowel;

                                    for (i = 0; i <= 10; i++)
                                    {
                                        if (availableVowel[i] == purchaseVowel)
                                        {
                                            availableVowel[i] = '-';
                                            i = 10;
                                        }
                                    }
                                    playerAccount = playerAccount - 150;
                                    PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(playerAccount);
                                }
                                break;
                            case 3:
                                cout << "Enter the entire Word/Phrase. " << endl;
                                cout << "Ensure its Properly formated." << endl;
                                cin >> lineGuess;
                                if (lineGuess == line)
                                {
                                    cout << "Congratulations, you guessed the word correctly." << endl;
                                    wordGuessed = 1;
                                }
                                else
                                {
                                    cout << "Sorry, your guess was incorrect." << endl;
                                    cout << "Moving to next player." << endl;
                                    currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                                }
                                break;
                            default:
                                cout << "You Entered the wrong option." << endl; 
                                break;
                            }
                        }
                    }
                }

                cout << "Its Player #" << currentPlayer << "s Turn." << endl;
                system("pause");

            } while (wordGuessed != 1);
            PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(roundTotal);
        }
    }

    //TheWheel.Search(SpinTheWheel());
    //cout << "Complete: " << SpinTheWheel() << endl;
    return 0;
}

int GamePlayMenu()
{
    int playerOpt = 0;
    cout << "1. Spin The Wheel" << endl;
    cout << "2. Buy A Vowel." << endl;
    cout << "3. Guess the entire word." << endl;
    cin >> playerOpt;
    return playerOpt;
}
