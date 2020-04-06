#include <iostream>
#include <cstdio>
#include <time.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h> 

// Class Header Files
#include "GameFunctions.h"
#include "TheWheel.h"
#include "Contestant.h"
#include "Guessed_Queue.h"

/*
	Group Members: 
		Dinito Thompson 
		Shanice Facey 
		...
		...
	Task List: 
		...
*/

using namespace std; 

int main () 
{
	// Code: GameFunctions.h
	TheWheelCreator(); 
	ThePlayerBaseCreator();

	// Game Control Variables 
	int gameRound = 0, i = 0, playerOpt = 1, 
		currentPlayer = 1, lineSize = 0, spinResult = 0, 
		wordGuessed = 0, letterOccurence = 0, flag = 0, 
		numDash = 0, playerAccount = 0, sectionValue = 0, 
		roundTotal = 0, arrayCompare = 0;
		
	char availableVowel[10], purchaseVowel, sChar, guessedChar; 

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
				spinResult = 0, wordGuessed = 0, letterOccurence = 0, flag = 0, 
				numDash = 0, playerAccount = 0, sectionValue = 0, roundTotal = 0, 
				arrayCompare = 0;
				
				char availableVowel[10] = {'A','a','E','e','I','i','O','o','U','u'},
				purchaseVowel = ' ', sChar = ' ', guessedChar = ' '; 
				
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
					
                    // Display the copy array to be solved.
                    cout << "Round #" << gameRound << endl;
                    cout << lineCopy << endl;
                    cout << "Player Name: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantName() << endl;
                    cout << "Player #: " << currentPlayer << endl;
                    cout << "Player Grand Total: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() << endl;
					
					switch (GamePlayMenu())
					{
						//Spins the Wheel. 
						case 1: 
							system("cls");

							// Store the value returned from the Spin the wheel function.
							spinResult = SpinTheWheel();

							// Use the spinResult value to find & display the Wheel Section/Card type.
							cout << "" << TheWheel.Search(spinResult)->getSectionData().getSectionType() << endl;

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
									PlayerBase.Search(currentPlayer)->setPlayerDataGT(0);
									currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
									system("pause");
								}
							}
							// Reward (Cash) 
							else
							{
								cout << "Guess a letter." << endl;
								cin >> guessedChar;

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
									cout << "Sorry Incorrect Letter Guessed." << endl;
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
									
									// Player gets that roundTotal for that correct guessed. 
									PlayerBase.Search(currentPlayer)->setPlayerDataGT(roundTotal);
									
									cout << "Your Guess Was Correct." << endl;
									// Display the player reward. 
									cout << "Current Grand Total: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() << endl;
									
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
									cout << availableVowel[i] << " - ";
								
								cout << "\nEach Vowel Cost $150" << endl;
								cout << "Enter the Vowel you wish to purchase: " << endl;
								cin >> purchaseVowel;
								
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
											playerAccount = PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal();
											playerAccount = playerAccount - 150;
											PlayerBase.Search(currentPlayer)->setPlayerDataGT(playerAccount);
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
									cout << "Sorry, incorrect vowel entered" << endl; 
									system("pause"); 
								}
							}
							else 
							{
								// Player doesnt have enough money to purchase a vowel. 
								system("cls");
								cout << "Your Current Balance Is: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantGrandTotal() << endl;
								cout << "Try Giving The Wheel A Spin." << endl;
								system("pause");
							}
							break;
						
						// Guess the entire word/phrase for that round.
						case 3: 
							system("cls");
							
							cout << "Enter the entire Word/Phrase. " << endl;
							cout << "Ensure its Properly formated. " << endl;
							cin >> lineGuess;
							
							if (lineGuess == lineString)
							{
								system("cls"); 
								cout << "Congratulations, you attempt was succesfull." << endl;
								for (i = 0; i < lineSize; i++)
									lineCopy[i] = lineContent[i];
								system("pause"); 
							}
							else
							{
								system("cls"); 
								cout << "Sorry, your guess was incorrect." << endl;
								cout << "Moving to next player." << endl;
								currentPlayer = PlayerBase.Search(currentPlayer)->getNextPlayer()->getPlayerData().getContestantNumber();
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

				} while (arrayCompare != 1);
				
				// Word has been solved and Round is coming to a conclusion. 
				
				// Winner is awarded.
				system("cls");
                cout << "Winner of Round: " << gameRound << endl;
                cout << "Player Name: " << PlayerBase.Search(currentPlayer)->getPlayerData().getContestantName() << endl;
                PlayerBase.Search(currentPlayer)->setPlayerDataGT(roundTotal);
				
				// Increase Round. 
                gameRound++;
                system("pause");
				
				// Reset all the other players grandTotal. 
				for (i = 1; i <= 3; i++)
                    if (i != currentPlayer)
                        PlayerBase.Search(i)->setPlayerDataGT(0);
				
			}
			gameFile.close(); 
		} 
		playerOpt = GameContinue(); 
	} while (playerOpt == 1);
	
	system("cls"); 
	cout << "Thank You For Playing..." << endl; 
	MemoryAllocator(); 
	
return 0; 
}
