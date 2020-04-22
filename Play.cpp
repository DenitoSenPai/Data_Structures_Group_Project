#include <iostream>
#include <cstdio>
#include <time.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <mmsystem.h>

// Class Header Files
#include "GameFunctions.h"
#include "TheWheel.h"
#include "Contestant.h"
#include "GuessedQueue.h"

// Letters Guessed Queue Instance
GuessedQueue GuessedQ;

/*
	Group Members:
		Dinito Thompson : 1801202
		Shanice Facey : 1701438
		Ricardo Johnson : 1702583
		Rojae Davis : 1608195
	See Documentation for task list.
*/

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
} // positions the cursor at x, y coordinates

int main ()
{

    //POSITIONS THE CURSOR AT THESE COORDINATES
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 13 | FOREGROUND_INTENSITY); // changes background color to blue
    gotoxy(50,0);

    cout << "Welcome to Young Lads Wheel of Fortune\n\n\n" << endl;
    system("pause");

    // Code: GameFunctions.h
    TheWheelCreator();
    SetConsoleTextAttribute(h,0| FOREGROUND_GREEN | BACKGROUND_RED | FOREGROUND_INTENSITY); // sets text color to green
    ThePlayerBaseCreator();



    // Game Control Variables
    int gameRound = 1, i = 0, playerOpt = 1,
        currentPlayer = 1, lineSize = 0, spinResult = 0,
        wordGuessed = 0, letterOccurence = 0, highestPlayer = 0,
        numDash = 0, sectionValue = 0, roundTotal = 0, arrayCompare = 0,
        highest = 0;

    char availableVowel[10], purchaseVowel, sChar, guessedChar;
    // Each player round total.
    int playerAccount[3];

    // Play the game until the user decides to exit.
    do
    {
        ifstream gameFile("Words_Phrases.txt");

        if (!gameFile.eof())
        {
            while (!gameFile.eof())
            {
                // Reset each variable to be used again per round.
                i = 0, playerOpt = 1, currentPlayer = 1, lineSize = 0,
                spinResult = 0, wordGuessed = 0, letterOccurence = 0,
                numDash = 0, sectionValue = 0, arrayCompare = 0;

                char availableVowel[10] = {'A','a','E','e','I','i','O','o','U','u'};
                purchaseVowel = ' ', sChar = ' ', guessedChar = ' ';

                int playerAccount[3] = {0,0,0};

                roundTotal = playerAccount[currentPlayer - 1];

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

                // Game Begins
                do
                {
                    fflush(stdin);
                    system("cls");
                    if (gameRound ==1)
                    {
                        // PlaySound(TEXT("Round 1.wav"),NULL,SND_ASYNC);
                    }
                    else if (gameRound == 2)
                    {
                        // PlaySound(TEXT("Round 2.wav"),NULL,SND_ASYNC);
                    }
                    else if (gameRound ==3)
                    {
                        // PlaySound(TEXT("Round 3.wav"),NULL,SND_ASYNC);
                    }
                    // Display the copy array to be solved.
                    cout << "Round #" << gameRound << endl;
                    cout << lineCopy << endl;
                    cout << endl;

                    cout << "Player Name: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantName() << endl;
                    cout << "Player #: " << currentPlayer << endl;
                    cout << endl;

                    cout << "Player Grand Total: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() << endl;
                    cout << "Guessed Attempts" << endl;
                    GuessedQ.Display();

                    switch (GamePlayMenu())
                    {
                    //Spins the Wheel.
                    case 1:
                        system("cls");

                        // Store the value returned from the Spin the wheel function.
                        spinResult = SpinTheWheel();

                        // Use the spinResult value to find & display the Wheel Section/Card type.
                        cout << "" << TheWheel.Search(spinResult)->getSectionData().getSectionType() << endl;
                        cout << endl;
                        // Store the value of that card/section to be analyzed.
                        sectionValue = TheWheel.Search(spinResult)->getSectionData().getSectionValue();

                        // Penalty (Bankrupt || Lose A Turn)
                        if (sectionValue == 0)
                        {
                            // Current Player is moved to the next player in the PlayerBase.
                            if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Lose A Turn.")
                            {
                                system("cls");
                                cout << "Sorry, your turn has been lost." << endl;
                                currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                                system("pause");
                            }
                            // Current Player's grandTotal is reduced to 0 and turn is moved to next player in the PlayerBase
                            else if (TheWheel.Search(spinResult)->getSectionData().getSectionType() == "Bankrupt")
                            {
                                system("cls");
                                cout << "Sorry, you have been Bankrupted." << endl;
                                playerAccount[currentPlayer - 1] = 0;
                                PlayerBase.Search(currentPlayer)->setPlayerDataGT(playerAccount[currentPlayer - 1]);
                                currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                                system("pause");
                            }
                        }
                        // Reward (Cash)
                        else
                        {
                            cout << "Guessed Attempts" << endl;
                            GuessedQ.Display();
                            cout << endl;

                            cout << "Guess a letter: ";
                            cin >> guessedChar;
                            GuessedQ.enqueue(guessedChar); // add guessed letter to queue

                            letterOccurence = 0;
                            for (i = 0; i < lineSize; i++)
                            {
                                // Checks how many occurence of the guessed letter is present.
                                if (lineContent[i] == guessedChar)
                                {
                                    // Counts the amount of time it occurs.
                                    lineCopy[i] = guessedChar;
                                    letterOccurence++;
                                }
                            }
                            if (letterOccurence == 0)
                            {
                                // If there are no occurences then its not in the array.
                                // As such, attempt was wrong and Current Player moves to next player.
                                system("cls");
                                cout << "Sorry Incorrect Letter Guessed," << endl;
                                cout << "Moving to next player..." << endl;
                                currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                                system("pause");
                            }
                            else
                            {
                                system("cls");

                                // There were X amount of occurences.
                                fflush(stdin);

                                // Round total is increased by X amount of occurences times Reward value.
                                roundTotal = roundTotal + (sectionValue * letterOccurence);
                                playerAccount[currentPlayer - 1] = roundTotal;

                                // Player gets that roundTotal for that correct guessed.
                                PlayerBase.Search(currentPlayer)->setPlayerDataGT(playerAccount[currentPlayer - 1]);

                                cout << "Your Guess Was Correct," << endl;
                                // Display the player reward.
                                cout << "Current Grand Total: $" << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() << endl;

                                system("pause");
                            }
                        }
                        break;

                    //Buy a Vowel
                    case 2:
                        system("cls");

                        fflush(stdin);

                        // Checks to see if the Player has enough money to purchase a vowel.
                        if (PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() >= 150)
                        {
                            system("cls");

                            // Displays the avaiable Vowels
                            for (i = 0; i <= 9; i++)
                                cout << "|" << availableVowel[i] << " | ";

                            cout << endl;
                            cout << endl
                                 << "Each Vowel Cost $150" << endl;
                            cout << "Enter The Vowel You Wish To Purchase: ";
                            cin >> purchaseVowel;

                            GuessedQ.enqueue(purchaseVowel);

                            // Checks to see if vowel entered was correct and/or Available Vowel.
                            int avaiableV = 0;
                            for (i = 0; i <= 9; i++)
                            {
                                if (availableVowel[i] == purchaseVowel)
                                {
                                    avaiableV = 1;
                                    break;
                                }
                            }

                            // If AvailableV = 1, then the vowel was in the vowel list.
                            if (avaiableV == 1)
                            {
                                for (i = 0; i <= 9; i++)
                                {
                                    // Updates the Available Vowel List.
                                    if (availableVowel[i] == purchaseVowel)
                                    {
                                        //List is updated.
                                        availableVowel[i] = '-';

                                        // Player Account is charged.
                                        playerAccount[currentPlayer - 1] = playerAccount[currentPlayer - 1] - 150;
                                        PlayerBase.Search(currentPlayer)->setPlayerDataGT(playerAccount[currentPlayer - 1]);
                                        break;
                                    }
                                }

                                // Updates the line copy array with the bought vowel.
                                letterOccurence = 0;
                                for (i = 0; i < lineSize; i++)
                                {
                                    // Checks how many occurence of the purchase vowel is present.
                                    if (lineContent[i] == purchaseVowel)
                                    {
                                        // Counts the amount of time it occurs.
                                        lineCopy[i] = purchaseVowel;
                                        letterOccurence++;
                                    }
                                }

                                if (letterOccurence == 0)
                                {
                                    system("cls");
                                    // The bought vowel is not present in the line.
                                    cout << "Sorry Incorrect Vowel Bought." << endl;
                                    cout << "Moving to next player." << endl;
                                    currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                                    system("pause");
                                }
                                else
                                {
                                    system("cls");
                                    // Vowel was present Player is rewarded.
                                    cout << "Your Vowel Was Correct." << endl;
                                    system("pause");
                                }
                            }
                            else
                            {
                                // Player enters the incorrect vowel/letter.
                                system("cls");
                                cout << "Sorry, Incorrect Vowel/Character Entered." << endl;
                                system("pause");
                            }
                        }
                        else
                        {
                            // Player doesnt have enough money to purchase a vowel.
                            system("cls");
                            cout << "Your Current Balance Is: $" << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() << endl;
                            cout << endl;
                            cout << "Try Giving The Wheel A Spin." << endl;
                            system("pause");
                        }
                        break;

                    // Guess the entire word/phrase for that round.
                    case 3:
                        system("cls");

                        fflush(stdin);

                        // Checks to see if the Player has enough money to purchase a vowel.
                        if (PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() > 0)
                        {
                            system("cls");

                            cout << "Guessed Attempts" << endl;
                            GuessedQ.Display();
                            cout << endl;

                            cout << "Please Ensure Your Attempt Is," << endl;
                            cout << "Properly formated. " << endl;
                            cout << endl;

                            cout << "Enter the entire Word/Phrase: ";

                            cin >> lineGuess;

                            if (lineGuess == lineString)
                            {
                                system("cls");
                                cout << "Congratulations, you attempt was succesfull." << endl;
                                cout << endl;
                                cout << "The Word/Phrase Was: " << lineString << endl;

                                for (i = 0; i < lineSize; i++)
                                    lineCopy[i] = lineContent[i];

                                system("pause");
                            }
                            else
                            {
                                system("cls");
                                cout << "Sorry, your guess was incorrect," << endl;
                                cout << "Moving to next player." << endl;
                                currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                                system("pause");
                            }
                        }
                        else
                        {
                            system ("cls");
                            cout << "Sorry, You Dont Have Any Money," << endl;
                            cout << "Try Giving The Wheel A Spin" << endl;
                            cout << endl;
                            system("pause");
                        }
                        break;

                    case 4:
                        // Guess another letter.
                        system("cls");

                        if (PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() > 0)
                        {
                            cout << "Guessed Attempts" << endl;
                            GuessedQ.Display();
                            cout << endl;

                            cout << "Guess a letter: ";
                            cin >> guessedChar;

                            // add guessed letter to queue
                            GuessedQ.enqueue(guessedChar);

                            letterOccurence = 0;
                            for (i = 0; i < lineSize; i++)
                            {
                                // Checks how many occurence of the guessed letter is present.
                                if (lineContent[i] == guessedChar)
                                {
                                    // Counts the amount of time it occurs.
                                    lineCopy[i] = guessedChar;
                                    letterOccurence++;
                                }
                            }
                            if (letterOccurence == 0)
                            {
                                // If there are no occurences then its not in the array.
                                // As such, attempt was wrong and Current Player moves to next player.
                                system("cls");
                                cout << "Sorry Incorrect Letter Guessed," << endl;
                                cout << "Moving to next player." << endl;
                                currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
                                system("pause");
                            }
                            else
                            {
                                system("cls");
                                // There were X amount of occurences.
                                fflush(stdin);

                                // Round total is increased by X amount of occurences times Reward value.
                                roundTotal = roundTotal + (sectionValue * letterOccurence);
                                playerAccount[currentPlayer - 1] = roundTotal;

                                // Player gets that roundTotal for that correct guessed.
                                PlayerBase.Search(currentPlayer)->setPlayerDataGT(playerAccount[currentPlayer - 1]);

                                cout << "Your Guess Was Correct." << endl;

                                // Display the player reward.
                                cout << "Current Grand Total: $" << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() << endl;

                                system("pause");
                            }
                        }
                        else
                        {
                            system ("cls");
                            cout << "Sorry, You Dont Have Any Money," << endl;
                            cout << "Try Giving The Wheel A Spin" << endl;
                            cout << endl;
                            system("pause");
                        }
                        break;

                    default:
                        system("cls");
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

                // Word has been solved and Round is coming to a conclusion.

                // Winner of that round is awarded.
                system("cls");

                fflush(stdin);
                cout << "Attempts Made: " << endl;
                GuessedQ.Display();
                cout << endl;

                cout << "Word/Phrase Is: " << lineString << endl;
                cout << "Winner of Round #" << gameRound << endl;
                cout << "Player Name: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantName() << endl;
                cout << endl;

                // Updates each player grand total.
                for (i = 1; i <= 3; i++)
                    PlayerBase.Search(i)->setPlayerDataGT(playerAccount[i - 1]);

                GuessedQ.destroy();

                // Increase Round.
                gameRound++;
                system("pause");

            }

            // Find the contestant with the highest Grand Total.
            fflush(stdin);
            for (i = 1; i <= 3; i++)
            {
                if (PlayerBase.Search(i)->getPlayerData().getContestantGrandTotal() > highest)
                {
                    highest = PlayerBase.Search(i)->getPlayerData().getContestantGrandTotal();
                    highestPlayer = PlayerBase.Search(i)->getPlayerData().getContestantNumber();
                }
            }


            // Contestant with the highest Grand total is declared the winner.
            fflush(stdin);
            system("cls");
            cout << "Game Winner: " << PlayerBase.Search(highestPlayer)->getPlayerData().getContestantName() << endl;
            cout << "Final Grand Total: " << highest << endl;
            system("pause");

            // Close Game File.
            gameFile.close();
        }

        // Check is players want to play again.
        playerOpt = GameContinue();
    }
    while (playerOpt == 1);
    system("cls");

    MemoryAllocator();

    gotoxy(50,0);
    // PlaySound(TEXT("Fatality.wav"),NULL,SND_ASYNC);// plays MK Fatality sound effect. (.wav file has to be in the same folder)
    for (int f =1; f < SectionIdentifier(1,5); f++)
    {
        fflush(stdin);
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),f | FOREGROUND_INTENSITY);
        gotoxy(50,0);
        cout << "Thank You For Playing..." << endl;
        Sleep(0200);
    }

    return 0;
}
// In order to play music select settings/compiler/Linker settings/Add/ then type in 'winmm' no quotations then click ok.
