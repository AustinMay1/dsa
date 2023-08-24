#include <iostream>

using namespace std;

/* Queue using array */

class Queue
{
    private:
        int front;
        int rear;
        int size;
        int *Q;

    public:
       Queue()
       {
           front = rear = -1;
           size = 10;
           Q = new int[size];
       }

       Queue(int size) : size(size), Q(new int[size]) 
        {
            front=rear=-1;
        }

       void Enqueue(int x);
       int Dequeue();
       void Display();
};

void Queue::Enqueue(int x)
{
    if(rear == size - 1)
    {
        cout << "Queue is full!" << endl;
    }
    else 
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::Dequeue()
{
    int x = -1;

    if(front == rear)
    {
        cout << "Queue is empty!" << endl;
    }
    else 
    {
        front++; 
        x = Q[front];
    }

    return x;
}

void Queue::Display()
{
    for(int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << endl;
    }
}

int main(void)
{
    Queue *q = new Queue();

    q->Enqueue(10);
    q->Enqueue(20);
    q->Enqueue(30);
    q->Enqueue(40);
    q->Enqueue(50);
    q->Display();

    q->Dequeue();
    q->Dequeue();

    cout << "===Dequeue===" << endl;

    q->Display();

    return 0;
}
