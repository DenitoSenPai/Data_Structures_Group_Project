#ifndef GAMEFUCNTIONS_H
#define GAMEFUCNTIONS_H

// Function Declaration
int RandomNumber (int int);
int SpinWheelSection (); 
bool WheelSectionCreator (); 

// Game Functions 
/* Creates The WheelSection using a for loop and 
various conditions. */
bool WheelSectionCreator ()
{
    int i, Penalty, Reward, Bankrupt; 
    
    Penalty = 5; 
    Bankrupt = 3; 
    LoseATurn = 2;
    
    Rewards = 18;
    FiveHundred = 4; 
    FiveFifty = 1; 
    SixHundred = 4; 
    SixFifty = 3; 
    SevenHundred = 3; 
    EightHundred = 1; 
    EightFifty = 1; 
    TwoThousandFive = 1; 

    for (i = 1, i <= 23, i++)
    {
        if (Penalty != 0)
        {
            if (Bankrupt != 0)
            {
                WheelSection = new WheelSection (); 
                WheelSection.setSectionId(i); 
                WheelSection.setSectionValue(0); 
                WheelSection.setSectionType("Bankrupt"); 
                WheelLinkedList.InsertIntoWheel(WheelSection);
                Bankrupt --; 
                Penalty --; 
            } else if (LoseATurn != 0)
            {
                WheelSection = new WheelSection (); 
                WheelSection.setSectionId(i); 
                WheelSection.setSectionValue(0); 
                WheelSection.setSectionType("Lose A Turn."); 
                WheelLinkedList.InsertIntoWheel(WheelSection);
                LoseATurn --; 
                Penalty --; 
            }
        } else if (Rewards != 0) 
        {
            if (FiveHundred != 0)
            {
                WheelSection = new WheelSection (); 
                WheelSection.setSectionId(i); 
                WheelSection.setSectionValue(500); 
                WheelSection.setSectionType("$ 500"); 
                WheelLinkedList.InsertIntoWheel(WheelSection);
                FiveHundred --; 
                Rewards --; 
            } else if (FiveFifty != 0)
            {
                WheelSection = new WheelSection (); 
                WheelSection.setSectionId(i); 
                WheelSection.setSectionValue(550); 
                WheelSection.setSectionType("$ 550"); 
                WheelLinkedList.InsertIntoWheel(WheelSection);
                FiveHundred --; 
                Rewards --;
            } else if (SixHundred != 0)
            {
                WheelSection = new WheelSection (); 
                WheelSection.setSectionId(i); 
                WheelSection.setSectionValue(600); 
                WheelSection.setSectionType("$ 600"); 
                WheelLinkedList.InsertIntoWheel(WheelSection);
                SixHundred --; 
                Rewards --;
            } else if (SixFifty != 0)
            {
                WheelSection = new WheelSection (); 
                WheelSection.setSectionId(i); 
                WheelSection.setSectionValue(650); 
                WheelSection.setSectionType("$ 650"); 
                WheelLinkedList.InsertIntoWheel(WheelSection);
                SixFifty --; 
                Rewards --;
            } else if (SevenHundred != 0)
            {
                WheelSection = new WheelSection (); 
                WheelSection.setSectionId(i); 
                WheelSection.setSectionValue(700); 
                WheelSection.setSectionType("$ 700"); 
                WheelLinkedList.InsertIntoWheel(WheelSection);
                SevenHundred --; 
                Rewards --;
            } else if (EightHundred != 0)
            {
                WheelSection = new WheelSection (); 
                WheelSection.setSectionId(i); 
                WheelSection.setSectionValue(800); 
                WheelSection.setSectionType("$ 800"); 
                WheelLinkedList.InsertIntoWheel(WheelSection);
                EightHundred --; 
                Rewards --;
            } else if (EightFifty != 0)
            {
                WheelSection = new WheelSection (); 
                WheelSection.setSectionId(i); 
                WheelSection.setSectionValue(850); 
                WheelSection.setSectionType("$ 850"); 
                WheelLinkedList.InsertIntoWheel(WheelSection);
                EightFifty --; 
                Rewards --;
            } else if (TwoThousandFive != 0)
            {
                WheelSection = new WheelSection (); 
                WheelSection.setSectionId(i); 
                WheelSection.setSectionValue(500); 
                WheelSection.setSectionType("$ 500"); 
                WheelLinkedList.InsertIntoWheel(WheelSection);
                FiveHundred --; 
                Rewards --;
            }
        }
    }
    if (i == 23)
        return true; 
    else 
        return false; 
}

/* Generates a random number 
inbetween 2 Indicated Numbers. */
int RandomNumber (int X, int Y) 
{ 
    return X + Srand () % Y; 
}

/* "Spins" the WheelSection X amount of times, 
then returns Y as the WheelSection section.*/
int SpinWheelSection ()
{
    int i, sectionID; 
    for (i=0, i = RandomNumber(10,21), i++)
    {
        // Clear Screen
        sectionID = RandomNumber(0,23);

        // Call Search Method . Display Method 
        WheelLinkedList.Search(sectionID).display(); 

        // Sleep for .5 seconds
        Sleep(5000);
    }
    return sectionID; 
}

/*Calls the deallocator for each Class, 
when the game is finished.*/
void Deallocator () 
{
    //...
}


#endif // GAMEFUCNTIONS_H