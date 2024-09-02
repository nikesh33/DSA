#include <iostream>
#include <queue>
using namespace std;

void interLeaveQueue(queue<int> &first)
{
    queue<int> second;

    // Push First Half of first Queue In Second Queue
    int size = first.size();
    for (int i = 0; i < size / 2; i++)
    {
        int temp = first.front();
        first.pop();

        second.push(temp);
    }

    // Merge both the halves
    // into the original queue -> first
    for (int i = 0; i < size / 2; i++)
    {
        int temp = second.front();
        second.pop();

        first.push(temp);

        temp = first.front();
        first.pop();
        first.push(temp);
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30); 
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);

    interLeaveQueue(q);

    cout << "Printing Queue: " << endl;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cout << element << " ";
    }

    return 0;
}