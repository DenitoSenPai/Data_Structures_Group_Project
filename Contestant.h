#ifndef CONTESTANT_H
#define CONTESTANT_H
// Contestant Class 
class Contestant 
{
private: 
    int contestantNumber; 
    string contestantName; 
    float contestantGrandTotal; 
public: 
    // Contestant Default Constructor 
    Contestant ()
    {
        contestantNumber = 0; 
        contestantName = "DEFAULT"; 
        contestantGrandTotal = 0.0; 
    }
    // Contestant Primary Constructor 
    Contestant (int contestantNumber, string contestantName, float contestantGrantTotal)
    {
        this -> contestantNumber = contestantNumber; 
        this -> contestantName = contestantName; 
        this -> contestantGrandTotal = contestantGrandTotal; 
    }
    // Contestant Copy Constructor 
    Contestant (Contestant &copy)
    {
        this -> contestantNumber = copy.contestantNumber; 
        this -> contestantName = copy.contestantName; 
        this -> contestantGrandTotal = copy.contestantGrandTotal; 
    }

    // Contestant Setters 
    void setContestantNumber (int contestantNumber)
    { this -> contestantNumber = contestantNumber; }

    void setContestantName (string contestantName)
    { this -> contestantName = contestantName; }

    void setContestantGrandTotal (float contestantGrandTotal)
    { this -> contestantGrandTotal = contestantGrandTotal; }

    // Contestant Getters 
    int getContestantNumber () 
    { return this -> contestantNumber; }

    string getContestantName ()
    { return this -> contestantName; }

    float getContestantGrandTotal () 
    { return this -> contestantGrandTotal; }

    // Display Contestant Info 
    void DisplayContestant ()
    {
        cout << "Contestant Number: " << getContestantNumber() << endl; 
        cout << "Contestant Name: " << getContestantName() << endl; 
        cout << "Contestant Grand Total: " << getContestantGrandTotal() << endl; 
    }
    ~ Contestant ()
    {}
};

// Contestant ContestantNode Class 
class ContestantNode 
{
private:
    Contestant PlayerData; 
    ContestantNode * nextPlayer; 
public: 
    // Contestant ContestantNode Default Constructor 
    ContestantNode ()
    {
        nextPlayer = NULL; 
    }
    // Contestant ContestantNode Primary Constructor 
    ContestantNode (Contestant PlayerData)
    { this -> PlayerData = PlayerData; }

    // Contestant ContestantNode Setters 
    void setNextPlayer (ContestantNode * nextPlayer)
    { this -> nextPlayer = nextPlayer; }

    void setPlayerData (Contestant PlayerData)
    { this -> PlayerData = PlayerData; }

    // Contestant ContestantNode Getters
    ContestantNode * getPrevContestantNode ()
    { return this -> prevContestantNode; }

    ContestantNode * getNextPlayer () 
    { return this -> nextPlayer; }

    Contestant getPlayerData ()
    { return this -> PlayerData; }

    // Display Contestant ContestantNode Info
    void DisplayContestantNode () 
    {
        getPlayerData().DisplayContestant(); 
    }
    ~ ContestantNode ()
    {}
};
class ContestantLinkedList 
{
private:
	ContestantNode * head;
    ContestantNode * tail; 

public:
	ContestantLinkedList() 
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
		ContestantNode * temp = new ContestantNode();

		if (temp == NULL) 
			return true;
		else 
        {
			delete temp;
			return false;
		}
	}

	void insertAtBack(Contestant Player) 
    {
		if (isFull()) 
        {
			cout << "The Contestant list is full" << endl;
		} else 
        {
			ContestantNode * temp = new ContestantNode(Player);
			if (isEmpty()) 
            {
				head = temp;
                tail = temp; 
                tail -> setNextNode(head); 
			} else 
            {
				temp -> setNextPlayer(head);
                tail -> setNextPlayer(temp)
				tail = temp; 
			}
		}
	}
	
	ContestantNode search(int contestantNumber) 
    {
		if (!isEmpty())
		{
			ContestantNode * temp = head;
			while (temp != NULL) // Checks head first. 
			{
				if (temp -> getPlayerData().getContestantNumber() == contestantNumber) 
					// Returns that section of the WheelSection to be displayed.
					return temp; 
				else 
					temp = temp -> getnextNode();
			}
		}
		else 
			cout << "Nothing to seach here." << endl;
	}
	void display() {
		if (isEmpty()) {
			cout << "Contestant list is Empty" << endl;
		}
		else {
			head -> DisplayContestantNode();
			ContestantNode * temp = head -> getNextPlayer();
			while (temp -> getNextPlayer != head) 
            {
				temp -> DisplayContestantNode();
				temp = temp -> getNextPlayer();
			}
		}
	}
	void deleteContetantList() {
		if (isEmpty()) {
			cout << "There is nothing to remove" << endl;
		}
		else {
			ContestantNode * temp = head;
            ContestantNode * prev = head; 
			head = head -> getNextPlayer();
			head->setPrevContestantNode(null);
			temp = null;
			}
		}
	
void destroy() {
	while (!isEmpty()) {
		deleteContestantNode();
	}
	}
~ContestantLinkedList() {
	destroy();
}

};
#endif // CONTESTANT_H