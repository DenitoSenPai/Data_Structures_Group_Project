#include <iostream>
#include <time.h>

// Class Header Files
#include "GameFunctions.h"
#include "TheWheel.h"
#include "Contestant.h"

using namespace std;

int main()
{
    int numPlayers, i;

    TheWheelCreator();

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

    //TheWheel.Search(SpinTheWheel());
    cout << "Complete: " << SpinTheWheel() << endl;
    return 0;
}
