#include <iostream>
#include <deque>
using namespace std;

// STL
// int main()
// {
//     deque<int> dq;
//     dq.push_back(10);
//     dq.push_back(20);

//     dq.push_front(100);

//     // push front
//     cout << dq.front() << endl;
//     // push back
//     cout << dq.back() << endl;
//     // get size
//     cout << dq.size() << endl;
// }

class Dqueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    // Dqueue Constructor
    Dqueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    // 1. Functions of Dque
    // 2. with circular nature
    void pushBack(int val)
    {
        // overFlow
        // if (rear == size - 1)
        // maintaining circular nature with this below condition
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "OverFlow" << endl;
        }
        // empty case
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // circular nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        // normal case
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pushFront(int val)
    {
        // overFlow
        // if (front == 0)
        // circular case
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "Overflow" << endl;
        }
        // empty case
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[front] = val;
        }
        // circular case
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = val;
        }
        // normal case for push front
        else
        {
            front--;
            arr[front] = val;
        }
    }

    void popFront()
    {
        // Overflow
        if (front == -1 && rear == -1)
        {
            cout << "Queue UnderFlow" << endl;
            return;
        }
        //  single element
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // circular nature
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        // normal
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void popBack()
    {
        // underflow
        if (front == -1 && rear == -1)
        {
            cout << "Underflow" << endl;
        }

        // single element
        else if (front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        // circular case
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        // normal case
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }
};

// From Scratch

int main()
{
}