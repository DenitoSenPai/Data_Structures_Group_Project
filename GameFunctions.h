#pragma once
#ifndef GAMEFUCNTIONS_H
#define GAMEFUCNTIONS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

// Class Header Files
#include "GameFunctions.h"
#include "TheWheel.h"
#include "Contestant.h"
#include "Guessed_Queue.h"

using namespace std;
// The single instance of The wheel class that will be used.
WheelLinkedList TheWheel;
ContestantLinkedList PlayerBase;
Queue GuessedQ;

// Function Declarations
int SectionIdentifier(int, int);
int SpinTheWheel();
int GamePlayMenu();
int GameContinue();

void MemoryAllocator();
void TheWheelCreator();
void ThePlayerBaseCreator();

// Functions Used
int SectionIdentifier(int x, int y)
{
    /*Generates a random number inbetween
    two indicated values.*/
    srand(time(NULL));
    //return rand() % (y - x + 1) + x;
    return x + (rand() % y);
}
int SpinTheWheel()
{
    int i = 0, sectionID = 1;
    for (i = 0; i <= SectionIdentifier(10, 20); i++)
    {
        // Clear Screen
        system("cls");
        sectionID = SectionIdentifier(1, 23);

        // Call Search Method . Display Method
        cout << "---"
             << ""
             << TheWheel.Search(sectionID)->getSectionData().getSectionType()
             << "---"
             << endl;

        // Sleep for .5 seconds
        Sleep(0300);
    }
    return sectionID;
}

void TheWheelCreator()
{
    // Variables to make sure the correct amount of sections are created.
    int i, Bankrupt = 3, LoseATurn = 2,
           FiveHundred = 4, FiveFifty = 1,
           SixHundred = 4, SixFifty = 3, SevenHundred = 3,
           EightHundred = 1, EightFifty = 1, TwoThousandFive = 1;

    for (i = 1; i <= 23; i++)
    {
        if (Bankrupt != 0)
        {
            WheelSection Section(i, 0, "Bankrupt");
            TheWheel.InsertIntoWheel(Section);
            Bankrupt--;
        }
        else if (LoseATurn != 0)
        {
            WheelSection Section(i, 0, "Lose A Turn.");
            TheWheel.InsertIntoWheel(Section);
            LoseATurn--;
        }
        else if (FiveHundred != 0)
        {
            WheelSection Section(i, 500, "$500");
            TheWheel.InsertIntoWheel(Section);
            FiveHundred--;
        }
        else if (FiveFifty != 0)
        {
            WheelSection Section(i, 500, "$550");
            TheWheel.InsertIntoWheel(Section);
            FiveFifty--;
        }
        else if (SixHundred != 0)
        {
            WheelSection Section(i, 600, "$600");
            TheWheel.InsertIntoWheel(Section);
            SixHundred--;
        }
        else if (SixFifty != 0)
        {
            WheelSection Section(i, 650, "$650");
            TheWheel.InsertIntoWheel(Section);
            SixFifty--;
        }
        else if (SevenHundred != 0)
        {
            WheelSection Section(i, 700, "$700");
            TheWheel.InsertIntoWheel(Section);
            SevenHundred--;
        }
        else if (EightHundred != 0)
        {
            WheelSection Section(i, 800, "$800");
            TheWheel.InsertIntoWheel(Section);
            EightHundred--;
        }
        else if (EightFifty != 0)
        {
            WheelSection Section(i, 850, "$850");
            TheWheel.InsertIntoWheel(Section);
            EightFifty--;
        }
        else if (TwoThousandFive != 0)
        {
            WheelSection Section(i, 2500, "$2500");
            TheWheel.InsertIntoWheel(Section);
            TwoThousandFive--;
        }
    }
}

void ThePlayerBaseCreator()
{
    int i = 0;
    string playerName = "Default"; 
    for (i = 1; i <= 3; i++)
    {
        system("cls");

        cout << "Player #" << i << endl;
        cout << "Enter Player Name: "; 
        cin >> playerName; 

        Contestant Player;  
        Player.setContestantName(playerName); 
        Player.setContestantGrandTotal(0); 
        Player.setContestantNumber(i);

        PlayerBase.insertAtBack(Player);
    }
    cout << "Players have been added..." << endl;
}

int GamePlayMenu()
{
    int playerOpt, flag = 0;

    while (flag != 1)
    {
        playerOpt = 0;
        cout << "1. Spin The Wheel" << endl;
        cout << "2. Buy A Vowel ($150)." << endl;
        cout << "3. Guess the entire word." << endl;
        cin >> playerOpt;

        if (playerOpt == 1 || playerOpt == 2 || playerOpt == 3)
            flag = 1;

        system("cls");
    }

    return playerOpt;
}

int GameContinue()
{
    int playerOpt = 0, flag = 0;

    while (flag != 1)
    {
        cout << "Would you like to Play Again?" << endl;
        cout << "1. Yes" << endl; 
        cout << "2. No" << endl; 
        cin >> playerOpt;

        if(playerOpt == 1 || playerOpt == 2)
            flag = 1;

        system("cls");
    } 

    return playerOpt;
}

void MemoryAllocator()
{
    PlayerBase.~ContestantLinkedList();
    TheWheel.~WheelLinkedList();
}

#endif // GAMEFUCNTIONS_H
