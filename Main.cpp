#include <iostream>
#include <cstdio>
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
    ThePlayerBaseCreator();

    // Game Begins

    // Call & Read from the .txt file.

    ifstream gameFile("Words_Phrases.txt");

    if (gameFile.is_open())
    {
        while (!gameFile.eof() && roundNum != 4)
        {
            // Round Variables
            // Variables get reinitalize each lineString so they can be reused.
            int currentPlayer = 1, lineSize = 0, spinResult = 0, wordGuessed = 0,
                letterOccurence = 0, flag = 0, numDash = 0, playerAccount = 0,
                sectionValue = 0, roundTotal = 0, arrayCompare = 0;

            char sChar = ' ', guessedChar = ' ',
                 availableVowel[10] = {'A','a','E','e','I','i','O','o','U','u',}, purchaseVowel = ' ';
            string lineString = " ", lineGuess = " ";

            // Read everything from the lineString into a string.
            getline(gameFile, lineString);

            // Create a character array of lineString size.
            char lineContent[lineSize = (lineString.size() + 1)];

            // Copy the string from the lineString into the character array.
            copy(lineString.begin(), lineString.end(), lineContent);

            // Adds NULL character to the end of the char array.
            lineContent[lineString.size()] = '\0';

            // Create a copy of the original array.
            char lineCopy[lineSize];

            // Populate it with " - " accordingly.
            for (i = 0; i < lineSize; i++)
                if (lineContent[i] == ' ')
                    lineCopy[i] = ' ';
                else
                    lineCopy[i] = '-';

            // Adds NULL character to the end of the char array.
            lineCopy[lineString.size()] = '\0';

            // Compares both arrays to see if they are equal.

            // Anything in LineContent != LineCopy then the word/phrase isnt guessed.
            arrayCompare = 1;
            for (i = 0; i < lineSize; i++)
                if (lineContent[i] != lineCopy[i])
                    arrayCompare = 0;

            do
            {
                fflush(stdin);
                system("cls");
                // Display the copy array to be solved.
                cout << "Round #" << roundNum << endl;
                cout << lineCopy << endl;
                cout << "Player Name: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantName() << endl;
                cout << "Player #: " << currentPlayer << endl;

                switch (GamePlayMenu())
                {
                case 1:
                    /*Spin the wheel then ask the player to guess if they land on a reward,
                    else turn is passed and penalty is issued.
                    If guess is successful, round total is updated.*/
                    system("cls");

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
                            system("pause");
                        }
                        else if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Bankrupt")
                        {
                            cout << "Sorry, you have been Bankrupted." << endl;
                            PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(0);
                            currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                            system("pause");
                        }
                    }
                    else
                    {
                        cout << "Guess a letter." << endl;
                        cin >> guessedChar;

                        letterOccurence = 0;
                        for (i = 0; i < lineSize; i++)
                        {
                            if (lineContent[i] == guessedChar)
                            {
                                // Counts the amount of time it occurs.
                                lineCopy[i] = guessedChar;
                                letterOccurence++;
                            }
                        }

                        if (letterOccurence == 0)
                        {
                            // If there is no occurences then its not in the array. Moves to next player.
                            cout << "Sorry Incorrect Letter Guessed." << endl;
                            cout << "Moving to next player..." << endl;
                            currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                            system("pause");
                        }
                        else
                        {
                            fflush(stdin);
                            roundTotal = roundTotal + (sectionValue * letterOccurence);
                            PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(roundTotal);
                            cout << "" << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() << endl;
                            cout << "Your Guess Was Correct." << endl;
                            system("pause");
                        }
                    }
                    break;

                case 2:
                    /*Player is provided with a list of Vowels if they have at leasr 150$.
                    If the vowel guessed is correct then the Vowel guess is updated and that
                    vowel is tested. */
                    system("cls");
                    // Stores the current player Grand total into Player Account for easier manipulation.

                    fflush(stdin);
                    if (PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() >= 150)
                    {
                        system("cls");

                        // Prints the aviable vowels.
                        for (i = 0; i <= 9; i++)
                        {
                            cout << availableVowel[i];
                            cout << " - ";
                        }

                        cout << "\nEach Vowel Cost $150" << endl;
                        cout << "Enter the Vowel you wish to purchase: " << endl;
                        cin >> purchaseVowel;

                        // Checks to see if what the user entered was correct and/or an Avaiable Vowel.
                        int avaiableV = 0;
                        for (i = 0; i <= 9; i++)
                        {
                            if (availableVowel[i] == purchaseVowel)
                            {
                                avaiableV = 1;
                                break;
                            }
                        }
                        // If AvaiableV = 1, then the vowel was in the vowel list.
                        if (avaiableV == 1)
                        {
                            for (i = 0; i <= 9; i++)
                            {
                                if (availableVowel[i] == purchaseVowel)
                                {
                                    //List is updated.
                                    availableVowel[i] = '-';
                                    // Player Account is charged.
                                    playerAccount = PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal();
                                    playerAccount = playerAccount - 150;
                                    PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(playerAccount);
                                    break;
                                }
                            }

                            letterOccurence = 0;
                            for (i = 0; i < lineSize; i++)
                            {
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
                                cout << "Sorry Incorrect Vowel Bought." << endl;
                                cout << "Moving to next player." << endl;
                                currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                            }
                            else
                            {
                                roundTotal = roundTotal + (sectionValue * letterOccurence);
                                cout << "Your Vowel Was Correct." << endl;
                            }
                        }
                        else
                            cout << "Incorrect/Unavaiable Vowel Entered." << endl;
                    }
                    else
                    {
                        system("cls");
                        cout << "Your Current Balance Is: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() << endl;
                        cout << "Try Giving The Wheel A Spin." << endl;
                        system("pause");
                    }
                    break;

                case 3:
                    /*Request the entire word/phrase from the player,
                    Compares what the user enters to what was scanned
                    from the file.*/
                    system("cls");
                    cout << "Enter the entire Word/Phrase. " << endl;
                    cout << "Ensure its Properly formated. " << endl;
                    cin >> lineGuess;

                    if (lineGuess == lineString)
                    {
                        cout << "Congratulations, you attempt was succesfull." << endl;
                        for (i = 0; i < lineSize; i++)
                            lineCopy[i] = lineContent[i];
                    }
                    else
                    {
                        cout << "Sorry, your guess was incorrect." << endl;
                        cout << "Moving to next player." << endl;
                        currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                    }
                    break;

                default:
                    cout << "Please enter a valid option." << endl;
                    system("pause");
                    break;
                }

                // Checks to see if Puzzle is solved.
                arrayCompare = 1;
                for (i = 0; i < lineSize; i++)
                    if (lineContent[i] != lineCopy[i])
                        arrayCompare = 0;

            }
            while (arrayCompare != 1);

            /*Only the player that manages to exit the loop
            would have finally solved the puzzel get to keep
            the money they accumilated. Every other player will be reset*/
            for(i = 1; i <= 3; i++)
                if (i != currentPlayer)
                    PlayerBase.Search(i)->getPlayerData().setContestantGrandTotal(0);

            // Winner is awarded.
            cout << "Winner of Round: "<< roundNum << endl;
            cout << "Player Name: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantName() << endl;
            PlayerBase.Search(currentPlayer)->getPlayerData().setContestantGrandTotal(roundTotal);

            roundNum++;
            system("pause");
        }
        gameFile.close();
    }
    else
    {
        cout << "Sorry, file wasnt found." << endl;
    }

    //TheWheel.Search(SpinTheWheel());
    cout << "The code done." << endl;
    return 0;
}
