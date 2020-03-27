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

    // Calls the wheel creating function to create the wheel.
    TheWheelCreator();
    ThePlayerBaseCreator();

    // Welcome Message
    // Game Begins

    // Call & Read from the .txt file.

    ifstream gameFile("Words_Phrases.txt");
    if (gameFile.is_open())
    {
        while (!gameFile.eof())
        {
            // Round Variables
            // Declared here so they can get reset each round.
            int currentPlayer = 1, lineSize = 0, spinResult = 0, wordGuessed = 0,
            letterOccurence = 0, flag = 0, numDash = 0;
            char sChar = ' ', guessedChar = ' ';
            string line;
            int sectionValue = 0, roundTotal = 0;

            // Read everything from the line into the string.
            getline(gameFile, line);
            // Create a character array of line size.
            char lineContent[line.size() + 1];
            lineSize = line.size();
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
            for (i = 0; i <= line.size(); i++)
            {
                lineCopy[i] = '-';
                if (lineContent[i] == ' ')
                    lineCopy[i] = ' ';
            }
            lineCopy[line.size()] = '\0';

            // Round Begins here.
            do
            {

                std::cout << "Round : " << roundNum << endl;
                std::cout << lineCopy << endl;

                std::cout << "Please enter a key to spin the wheel." << endl;
                system("pause");

                spinResult = SpinTheWheel();

                cout << "" << TheWheel.Search(spinResult)->getSectionData().getSectionType() << endl;
                sectionValue = TheWheel.Search(spinResult)->getSectionData().getSectionValue();

                switch (currentPlayer)
                {
                case 1:
                    if (sectionValue == 0)
                    {
                        if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Lose A Turn.")
                        {
                            std::cout << "Sorry, your turn has been lost." << endl;
                            break;
                        }
                        else if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Bankrupt")
                        {
                            std::cout << "Sorry, you have been Bankrupted." << endl;
                            PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(0);
                            break;
                        }
                    }
                    else
                        while (sectionValue > 0 && wordGuessed != 1)
                        {
                            std::cout << "Guess a letter." << endl;
                            std::cin >> guessedChar;

                            for (i = 0; i <= lineSize; i++)
                            {
                                if (lineContent[i] == guessedChar)
                                {
                                    lineCopy[i] = guessedChar;
                                    letterOccurence++;
                                }
                            }
                            roundTotal = PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() + (sectionValue * letterOccurence);
                            PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(roundTotal);

                            while (flag != 1)
                            {
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
                                            std::cout << "Sorry, your turn has been lost." << endl;
                                            flag = 1;
                                            break;
                                        }
                                        else if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Bankrupt")
                                        {
                                            std::cout << "Sorry, you have been Bankrupted." << endl;
                                            PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(0);
                                            flag = 1;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        std::cout << "Guess a letter." << endl;
                                        std::cin >> guessedChar;

                                        for (i = 0; i <= lineSize; i++)
                                        {
                                            if (lineContent[i] == guessedChar)
                                            {
                                                lineCopy[i] = guessedChar;
                                                letterOccurence++;
                                            }
                                            if (lineContent[i] != '-')
                                                numDash = 0;
                                        }
                                        roundTotal = PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() + (sectionValue * letterOccurence);
                                        PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(roundTotal);
                                    }
                                    break;

                                default:
                                    break;
                                }
                            }

                            break;
                        case 2:

                            break;

                        case 3:

                            break;

                        default:
                            break;
                        }
                }
                currentPlayer++;
                cout << "Player #" << currentPlayer << "s Turn." << endl;
            } while (wordGuessed != 1);
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

int GamePlayMenu()
{
    int playerOpt = 0;
    cout << "1. Spin The Wheel" << endl;
    cout << "2. Buy A Vowel" << endl;
    cout << "3. Guess the entire word." << endl;
    cin >> playerOpt;
    return playerOpt;
}