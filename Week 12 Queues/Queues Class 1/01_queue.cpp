#include <iostream>
#include <queue>
using namespace std;

// Queue From Scratch

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        // check full
        if (rear == size - 1)
        {
            cout << "Queue OverFlow" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            // empty case
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            // normal case
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        // underFlow
        if (front == -1 && rear == -1)
        {
            cout << "Queue UnderFlow " << endl;
            return;
        }
        else if (front == rear)
        {
            // empty case -> Single Element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            // Normal Case
            arr[front] = -1;
            front++;
        }
    }

    // Empty Method
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // To get Size
    int getSize()
    {
        // bhul jata hoon
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        else
            return rear - front + 1;
    }

    // get front
    int getFront()
    {
        if (front == -1)
        {
            cout << "No Element in queue, cannot give front element" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    // get rear
    int getRear()
    {
        if (rear == -1)
        {
            cout << "No Element in queue, cannot give rear element" << endl;
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    void print()
    {
        cout << "Printing Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // creation
    Queue q(5);
    q.print();

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();

    q.push(40);
    q.print();

    q.push(50);
    q.print();

    // size
    cout << "Size of Queue: " << q.getSize() << endl;

    q.pop();
    q.print();

    // check if the Queue is Empty
    if (q.isEmpty() == true)
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }

    // rear se push hota hai front se nahi to kaise hoga overflow ho jayega
    // q.push(100);
    // q.print();

    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    return 0;
}