
class Wheel
{
 private:
	int sectionID;
	int sectionValue;
	string sectionType;
 public:
	Wheel()
	{
		sectionID = 0;
		sectionValue = 0;
		sectionType = " ";
	}
	Wheel(int sectionID, int sectionValue, string sectionType)
	{
		this -> sectionID = sectionID;
		this -> sectionValue = sectionValue;
		this -> sectionType = sectionType;
	}
	Wheel(const Wheel &s)
	{
		this -> sectionID = s.sectionID;
		this -> sectionValue = s.sectionValue;
		this -> sectionType = s.sectionType;
	}
	
	// Wheel Setters
	void setSectionId(int sectionID)
	{ this -> sectionID = sectionID; }

	void setSectionValue(int sectionValue)
	{ this -> sectionValue = sectionValue; }

	void setSectionType(string sectionType)
	{ this -> sectionType = sectionType; }

	// Wheel Getters 
	int getSectionId()
	{ return sectionID; }
	
	int getSectionValue()
	{ return sectionValue; }

	string getSectionType()
	{ return sectionType; }

	void WheelSectionDisplay()
	{
		cout << "The Section ID is: " << getSectionId() << endl;
		cout << "The Section Value is: " << getSectionValue() << endl;
		cout << "The Section Type is: " << getSectionType() << endl;
	}
	~Wheel()
	{}
};
class WheelNode 
{
 private:
	 Wheel sectionData;
	 WheelNode * nextNode;
 public:
	WheelNode()
	{
		nextNode = NULL;
	}
	WheelNode(Wheel sectionData)
	{
		this -> sectionData = sectionData;
	}
	WheelNode(Wheel sectionData, WheelNode * nextNode)
	{
		sectionData = sectionData;
		this -> nextNode = nextNode;
	}

	// The Wheel Node Getters 
	Wheel getSectionData()
	{ return this->sectionData; }

	WheelNode* getNextNode()
	{ return this->nextNode; }

	// The Wheel Node Setters 
	void setNextNode(WheelNode * nextNode)
	{ this->nextNode = nextNode; }

	void setData(Wheel sectionData)
	{ this->sectionData = sectionData; }

	void display()
	{
		cout << &nextNode << endl;
		cout << sectionData.Display() << endl;
	}
	~WheelNode ()
    {}
};

class WheelLinkedList
{
private:
	WheelNode * head;
public:
	WheelLinkedList()
	{
		head = NULL;
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
		WheelNode * temp = new WheelNode();
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
			WheelNode * current = head;
			while (current -> getNextNode != NULL) 
			{
				current -> getSectionData().WheelSectionDisplay(); 
				current = current -> getNextNode();
			}
		}
		else 
			cout << "Nothing to Display here." << endl; 
	}

	Wheel * Search (int sectionID) 
	{
		if (!isEmpty())
		{
			WheelNode * temp = head;
			while (temp != NULL) // Checks head first. 
			{
				if (temp -> getSectionData().getSectionId() == sectionID) 
					// Returns that section of the wheel to be displayed.
					return temp; 
				else 
					temp = temp -> getnextNode();
			}
		}
		else 
			cout << "Nothing to seach here." << endl; 
	}

	// Insert at Back to be added. 

	void destroyWheel() 
	{
		if (!isEmpty()) 
		{
			WheelNode * temp = head;
			WheelNode * prevNode = head;
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

