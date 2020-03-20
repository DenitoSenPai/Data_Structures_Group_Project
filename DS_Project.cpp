#include <iostream> 

using namespace std; 

// Function Declaration
int RandomNumber (int int);
int SpinWheelSection (); 
bool WheelSectionCreator (); 

class WheelSection
{
 private:
	int sectionID;
	int sectionValue;
	string sectionType;
 public:
	WheelSection()
	{
		sectionID = 0;
		sectionValue = 0;
		sectionType = " ";
	}
	WheelSection(int sectionID, int sectionValue, string sectionType)
	{
		this -> sectionID = sectionID;
		this -> sectionValue = sectionValue;
		this -> sectionType = sectionType;
	}
	WheelSection(const WheelSection &s)
	{
		this -> sectionID = s.sectionID;
		this -> sectionValue = s.sectionValue;
		this -> sectionType = s.sectionType;
	}
	
	// WheelSection Setters
	void setSectionId(int sectionID)
	{ this -> sectionID = sectionID; }

	void setSectionValue(int sectionValue)
	{ this -> sectionValue = sectionValue; }

	void setSectionType(string sectionType)
	{ this -> sectionType = sectionType; }

	// WheelSection Getters 
	int getSectionId()
	{ return sectionID; }
	
	int getSectionValue()
	{ return sectionValue; }

	string getSectionType()
	{ return sectionType; }

	void WheelSectionSectionDisplay()
	{
		cout << "The Section ID is: " << getSectionId() << endl;
		cout << "The Section Value is: " << getSectionValue() << endl;
		cout << "The Section Type is: " << getSectionType() << endl;
	}
	~WheelSection()
	{}
};
class WheelSectionNode 
{
 private:
	 WheelSection sectionData;
	 WheelSectionNode * nextNode;
 public:
	WheelSectionNode()
	{
		nextNode = NULL;
	}
	WheelSectionNode(WheelSection sectionData)
	{
		this -> sectionData = sectionData;
	}
	WheelSectionNode(WheelSection sectionData, WheelSectionNode * nextNode)
	{
		sectionData = sectionData;
		this -> nextNode = nextNode;
	}

	// The WheelSection Node Getters 
	WheelSection getSectionData()
	{ return this->sectionData; }

	WheelSectionNode* getNextNode()
	{ return this->nextNode; }

	// The WheelSection Node Setters 
	void setNextNode(WheelSectionNode * nextNode)
	{ this->nextNode = nextNode; }

	void setData(WheelSection sectionData)
	{ this->sectionData = sectionData; }

	void display()
	{
		cout << &nextNode << endl;
		cout << sectionData.Display() << endl;
	}
	~WheelSectionNode ()
    {}
};

class WheelLinkedList
{
private:
	WheelSectionNode * head;
    WheelSectionNode * tail; 
public:
	WheelLinkedList()
	{
		head = NULL;
        tail = NULL; 
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else 
			return false;
	}
	bool isFull()
	{
		WheelSectionNode * temp = new WheelSectionNode();
		if (temp == NULL)
			return true; 
		else
		{
			delete temp;
			return false;
		}
	}
	void displayWheel()
	{
		if (!isEmpty()) 
		{
			WheelSectionNode * current = head;
			while (current -> getNextNode != NULL) 
			{
				current -> getSectionData().WheelSectionSectionDisplay(); 
				current = current -> getNextNode();
			}
		}
		else 
			cout << "Nothing to Display here." << endl; 
	}

	WheelSectionNode * Search (int sectionID) 
	{
		if (!isEmpty())
		{
			WheelSectionNode * temp = head;
			while (temp != NULL) // Checks head first. 
			{
				if (temp -> getSectionData().getSectionId() == sectionID) 
					// Returns that section of the WheelSection to be displayed.
					return temp; 
				else 
					temp = temp -> getnextNode();
			}
		}
		else 
			cout << "Nothing to seach here." << endl; 
	}

	// Insert at Back to be added. 
    void InsertIntoWheel(WheelSection NewNode) 
    {
        WheelSectionNode * temp = new WheelSectionNode(NewNode);  

        if(isEmpty())
        {
            head = temp;
            tail = temp; 
            tail -> setNextNode(head);  
        }
        else if (!isFull()) 
        {
            temp -> setNextNode(head); 
            tail -> setNextNode (temp); 
            tail = temp; 
        }
    }
	void destroyWheelSection() 
	{
		if (!isEmpty()) 
		{
			WheelSectionNode * temp = head;
			WheelSectionNode * prevNode = head;
			while (temp != NULL) 
			{
				prevNode = temp;
				temp = temp->getnextNode();
				delete prevNode;
			}
			head = NULL;
		}
		else {
			cout << "Nothing to delete, List is empty." << endl;
		}
	}
	~WheelLinkedList()
	{
		destroy();
	}
};

int main ()
{
    // Class Instances
    // Driver Variables 
    // Get # of Players
    // Create The Wheel
    if (WheelSectionCreator())
    {
        // Game Begins 

    } else 
    {
        cout << "Wheel was unable to created." << endl; 
        cout << "You may not have enough memory." << endl; 
        return 0; 
    }
}

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
