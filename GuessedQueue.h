#ifndef GUESSED_QUEUE_H
#define GUESSED_QUEUE_H
#define Size 51

#include <iostream>

using namespace std;
// Guessed Letter Queue
// Shanice Facey
class GuessedQueue
{
public:
    char A[Size];
    int frontQ;
    int rearQ;

    GuessedQueue()
    {
        this->frontQ = -1;
        this->rearQ = -1;
        for (int i = 0; i <= (Size - 1); i++)
            this->A[i] = '-';
    }

    bool isempty()
    {
        if (frontQ == -1 && rearQ == -1)
            return true;
        else
            return false;
    }
    bool isRepeat(char g)
    {
        int i = 0;

        for (i = 0; i <= Size - 1; i++)
            if (g == this->A[i])
                return true;

        return false;
    }
    void enqueue(char g)
    {
        if (rearQ == Size - 1)
            cout << "QUEUE IS FULL" << endl;
        else
        {
            if (!isRepeat(g))
            {
                if (frontQ == -1)
                    frontQ = 0;
                rearQ++;
                A[rearQ] = g;
            }
        }
    }
    void dequeue()
    {
        if (!isempty())
        {
            if (frontQ == rearQ)
                frontQ = rearQ = -1;
            else
            {
                for (int i = rearQ; i >= 0; i--)
                    this->A[i] = '-';
                frontQ = rearQ;
            }
        }
    }
    void Display()
    {
        if (isempty())
        {
            for (int i = 0; i <= (rearQ + 1); i++)
                cout << "|" << this->A[i] << "|";
            cout << endl;
        }
        else
        {
            for (int i = 0; i < (rearQ + 1); i++)
                cout << "|" << this->A[i] << "|";
            cout << endl;
        }
    }
    void destroy()
    {
        while (rearQ != frontQ)
        {
            dequeue();
        }
        //delete rearQ;
        //delete frontQ;
        this->rearQ = -1;
        this->frontQ = -1;
    }
};

#endif // GUESSED_QUEUE_H
