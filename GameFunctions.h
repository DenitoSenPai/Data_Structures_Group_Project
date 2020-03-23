#pragma once
#ifndef GAMEFUCNTIONS_H
#define GAMEFUCNTIONS_H

#include "TheWheel.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
// The single instance of The wheel class that will be used.
WheelLinkedList TheWheel;

// Function Declarations
int SectionIdentifier(int, int);
int SpinTheWheel();
void TheWheelCreator();
void NumberOfPlayers();

// Functions Used
int SectionIdentifier(int x, int y)
{
    /*Generates a random number inbetween
    two indicated values.*/
    srand(time(NULL));
    //return rand() % (y - x + 1) + x;
    return x + (rand()%y);
}
int SpinTheWheel()
{
    int i, sectionID;

    for (i=0; i <= SectionIdentifier(10, 20); i++)
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
    return i;
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
            WheelSection Section(i, 0, "Lose a turn");
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

void NumberOfPlayers ()
{
// Get the Number of Players.
// Assign Them Accordingly.
    cout << "Enter # of Contestant: " << endl;
    cin >> numPlayers;
    for (i = 1; i <= numPlayers; i++)
    {
        Contestant Player;
        Player.setContestantName();
        Player.setContestantGrandTotal(0);
        Player.setContestantNumber(i);
    }
    cout << "Players have been added..." << endl;
}
#endif // GAMEFUCNTIONS_H
