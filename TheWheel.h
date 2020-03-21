#ifndef THEWHEEL_H
#define THEWHEEL_H


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

#endif // THEWHEEL_H