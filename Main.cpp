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
                letterOccurence = 0, flag = 0, numDash = 0, playerAccount = 0;
            char sChar = ' ', guessedChar = ' ',
                 availableVowel[10] = {
                     'A',
                     'A',
                     'E',
                     'e',
                     'I',
                     'i',
                     'O',
                     'o',
                     'U',
                     'u',
                 },
                 purchaseVowel = ' ';
            string line = " ", lineGuess = " ";
            int sectionValue = 0, roundTotal = 0;

            // Read everything from the line into the string.
            getline(gameFile, line);

            // Create a character array of line size.
            char lineContent[lineSize = (line.size() + 1)];

            // Copy the string from the line into the character array.
            copy(line.begin(), line.end(), lineContent);

            // Adds NULL character
            lineContent[line.size()] = '\0';

            // Prints the array
            std::cout << lineContent << endl;
            std::cout << "Size of original: " << line.size() << endl;
            std::cout << "Line: #" << i++ << endl;

            // Create a copy of the original array.
            char lineCopy[lineSize];

            // Populate it with " - "
            // Display and update accordingly.
            for (i = 0; i <= lineSize; i++)
                if (lineContent[i] == ' ')
                    lineCopy[i] = ' ';
                else
                    lineCopy[i] = '-';

            lineCopy[line.size()] = '\0';

            // Round Begins here.
            do
            {
                std::cout << "Round #" << roundNum << endl;
                std::cout << "Player #" << currentPlayer << endl;
                std::cout << lineCopy << endl;

                std::cout << "Please enter a key to spin the wheel." << endl;
                system("pause");

                spinResult = SpinTheWheel();

                std::cout << "" << TheWheel.Search(spinResult)->getSectionData().getSectionType() << endl;
                sectionValue = TheWheel.Search(spinResult)->getSectionData().getSectionValue();

                if (sectionValue == 0)
                {
                    if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Lose A Turn.")
                    {
                        std::cout << "Sorry, your turn has been lost." << endl;
                    }
                    else if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Bankrupt")
                    {
                        std::cout << "Sorry, you have been Bankrupted." << endl;
                        PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(0);
                    }
                }
                else
                {
                    std::cout << "Guess a letter." << endl;
                    std::cin >> guessedChar;
                    while (sectionValue > 0 || wordGuessed != 1 || flag != 1)
                    {

                        for (i = 0; i <= lineSize; i++)
                        {
                            if (lineContent[i] == guessedChar)
                            {
                                lineCopy[i] = guessedChar;
                                letterOccurence++;
                            }
                        }
                        if (letterOccurence == 0)
                        {
                            std::cout << "Sorry Incorrect Letter Guessed." << endl;
                            std::cout << "Moving to next player." << endl;
                            currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                            flag = 1;
                        } 
                        else if (lineContent == lineCopy)
                        {
                            wordGuessed = 1;
                        }
                        else
                        {
                            roundTotal = PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() + (sectionValue * letterOccurence);
                            PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(roundTotal);

                            switch (GamePlayMenu())
                            {
                            case 1:
                                spinResult = SpinTheWheel();

                                std::cout << "" << TheWheel.Search(spinResult)->getSectionData().getSectionType() << endl;
                                sectionValue = TheWheel.Search(spinResult)->getSectionData().getSectionValue();

                                if (sectionValue == 0)
                                {
                                    if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Lose A Turn.")
                                    {
                                        std::cout << "Sorry, your turn has been lost." << endl;
                                        currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                                    }
                                    else if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Bankrupt")
                                    {
                                        std::cout << "Sorry, you have been Bankrupted." << endl;
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

                                    cout << "\n" << "Each Vowel Cost $150" << endl;
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
                                break;
                            }
                        }
                    }
                }


                std::cout << "Its Player #" << currentPlayer << "s Turn." << endl;
                system("pause");

            } while (wordGuessed != 1);
            PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(roundTotal);
        }
    }

    //TheWheel.Search(SpinTheWheel());
    //std::cout << "Complete: " << SpinTheWheel() << endl;
    return 0;
}

int GamePlayMenu()
{
    int playerOpt = 0;
    std::cout << "1. Spin The Wheel" << endl;
    std::cout << "2. Buy A Vowel." << endl;
    std::cout << "3. Guess the entire word." << endl;
    std::cin >> playerOpt;
    return playerOpt;
}
