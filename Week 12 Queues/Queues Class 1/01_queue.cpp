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
    bool getSize()
    {
        return rear - front + 1;
    }
};

int main()
{

    return 0;
}