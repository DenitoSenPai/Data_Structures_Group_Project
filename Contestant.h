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

// Contestant Node Class 
class ContestantNode 
{
private:
    Contestant playerData; 
    ContestantNode * nextNode; 
    ContestantNode * prevNode; 
public: 
    // Contestant Node Default Constructor 
    ContestantNode ()
    {
        nextNode = NULL; 
        prevNode = NULL; 
    }
    // Contestant Node Primary Constructor 
    ContestantNode (Contestant playerData)
    { this -> playerData = playerData; }

    // Contestant Node Setters 
    void setPrevNode (ContestantNode * prevNode)
    { this -> prevNode = prevNode; }

    void setNextNode (ContestantNode * nextNode)
    { this -> nextNode = nextNode; }

    void setPlayerData (Contestant playerData)
    { this -> playerData = playerData; }

    // Contestant Node Getters
    ContestantNode * getPrevNode ()
    { return this -> prevNode; }

    ContestantNode * getNextNode () 
    { return this -> nextNode; }

    Contestant getPlayerData ()
    { return this -> playerData; }

    // Display Contestant Node Info
    void DisplayContestantNode () 
    {
        getPlayerData().DisplayContestant(); 
    }
    ~ ContestantNode ()
    {}
};
