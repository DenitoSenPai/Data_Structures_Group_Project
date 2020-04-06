#ifndef GUESSED_QUEUE_H
#define GUESSED_QUEUE_H
#define Size 50

// guessed letters queue
// Shanice Facey 

class Guessed_Queue
{
private:
    Guessed_Queue * Next;

public:
    Guessed_Queue()
    {
        Next = NULL;
    }
    Guessed_Queue(Guessed_Queue *Next)
    {
        this->Next = Next;
    }
    Guessed_Queue *getNext()
    {
        return this->Next;
    }
    void setNext(Guessed_Queue *Next)
    {
        this->Next = Next;
    }
    ~Guessed_Queue() {}
};
class Queue
{
public:
    char A[Size];
    int front = -1;
    int rear = -1;

    bool isempty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    void enqueue(char g)
    {
        if (rear == Size - 1)
        {
            cout << "QUEUE IS FULL" << endl;
        }
        else
        {
            if (front == -1)
                front = 0; 
            rear++;
            
            A[rear] = g;
        }
    }
    void dequeue()
    {
        if (isempty())
        {
            cout << "QUEUE IS Empty" << endl;
        }
        else
        {
            if (front == rear)
                front = rear = -1;
            else
                front++;
        }
    }
    void Display()
    {
        if (isempty())
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            for (int s = 0; s < rear; s++)
            {
                cout << A[s] << "|";
            }
        }
    }
    void destroy()
    {
        while (rear != front)
        {
            dequeue();
        }
        //delete rear;
        //delete front;
        rear = NULL;
        front = NULL;
    }
};
#endif // GUESSED_QUEUE_H
