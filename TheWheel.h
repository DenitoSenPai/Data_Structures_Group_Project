#pragma once
#ifndef THEWHEEL_H
#define THEWHEEL_H

using namespace std;

// The Wheel Class
// Shanice Facey
class WheelSection
{
private:
    int sectionID;
    int sectionValue;
    int sectionColor; // added with setters and getters
    string sectionType;
public:
    WheelSection()
    {
        sectionID = 0;
        sectionValue = 0;
        sectionType = "";
        sectionColor = 0;
    }
    WheelSection(int sectionID, int sectionValue, string sectionType, int sectionColor)
    {
        this->sectionID = sectionID;
        this->sectionValue = sectionValue;
        this->sectionType = sectionType;
        this->sectionColor = sectionColor;
    }
    WheelSection(const WheelSection& s)
    {
        this->sectionID = s.sectionID;
        this->sectionValue = s.sectionValue;
        this->sectionType = s.sectionType;
        this->sectionColor = s.sectionColor;
    }

    // Wheel Section Setters
    void setSectionColor (int sectionColor)
    {
        this->sectionColor = sectionColor;
    }
    void setSectionId(int sectionID)
    {
        this->sectionID = sectionID;
    }
    void setSectionValue(int sectionValue)
    {
        this->sectionValue = sectionValue;
    }
    void setSectionType(string sectionType)
    {
        this->sectionType = sectionType;
    }

    // Wheel Section Getters
    int getSectionColor( int sectionColor)
    {
        return sectionColor;
    }
    int getSectionId()
    {
        return sectionID;
    }
    int getSectionValue()
    {
        return sectionValue;
    }
    string getSectionType()
    {
        return sectionType;
    }

    // Wheel Section Display Method
    void displayWheelSection()
    {
        cout << "The Section ID is: " << getSectionId() << endl;
        cout << "The Section Value is: " << getSectionValue() << endl;
        cout << "The Section Type is: " << getSectionType() << endl;
        //cout <<" The color section is: "<< getSectionColor(int sectionColor)<< endl;
    }
    ~WheelSection()
    {}
};
class WheelNode
{
private:
    WheelSection sectionData;
    WheelNode * nextNode;
public:
    WheelNode()
    {
        nextNode = NULL;
    }
    WheelNode(WheelSection sectionData)
    {
        this->sectionData = sectionData;
    }
    WheelNode(WheelSection sectionData, WheelNode * nextNode)
    {
        sectionData = sectionData;
        this->nextNode = nextNode;
    }

    // The Wheel Node Getters
    WheelSection getSectionData()
    {
        return this->sectionData;
    }
    WheelNode * getNextNode()
    {
        return this->nextNode;
    }

    // The Wheel Node Setters
    void setNextNode(WheelNode* nextNode)
    {
        this->nextNode = nextNode;
    }
    void setData(WheelSection sectionData)
    {
        this->sectionData = sectionData;
    }

    // The Wheel Node Display.
    void display()
    {
        getSectionData().displayWheelSection();
    }
    ~WheelNode()
    {}
};

class WheelLinkedList
{
private:
    WheelNode* head;
    WheelNode* tail;
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
        WheelNode* temp = new WheelNode();
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
            while (current != tail)
            {
                current->getSectionData().displayWheelSection();
                current = current->getNextNode();
                cout << endl;
            }
            current->getSectionData().displayWheelSection();
        }
        else
            cout << "Nothing to Display here." << endl;
    }

    WheelNode* Search(int sectionID)
    {
        if (!isEmpty())
        {
            WheelNode* temp = head;
            while (temp != NULL) // Checks head first.
            {
                if (temp->getSectionData().getSectionId() == sectionID)
                    // Returns that section of the WheelSection to be displayed.
                    return temp;
                else
                    temp = temp->getNextNode();
            }
        }
        else
        {
            cout << "Incorrect Section ID || Nothing to search for." << endl;
        }
        return 0;
    }

    // Insert at Back to be added.
    void InsertIntoWheel(WheelSection NewNode)
    {
        WheelNode* temp = new WheelNode(NewNode);

        if (isEmpty())
        {
            head = temp;
            tail = temp;
            tail->setNextNode(head);
        }
        else if (!isFull())
        {
            temp->setNextNode(head);
            tail->setNextNode(temp);
            tail = temp;
        }
    }
    void destroyWheelSection()
    {
        if (!isEmpty())
        {
            WheelNode* temp = head;
            WheelNode* prevNode = head;
            while (temp != NULL)
            {
                prevNode = temp;
                temp = temp->getNextNode();
                delete prevNode;
            }
            head = NULL;
        }
        else
        {
            cout << "Nothing to delete, List is empty." << endl;
        }
    }
    ~WheelLinkedList()
    {
        destroyWheelSection();
    }
};

#endif // THEWHEEL_H
