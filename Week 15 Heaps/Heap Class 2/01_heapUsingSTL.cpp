#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // create max-heap (max heap By default hota hai)
    priority_queue<int> pq;
    // create min-heap syntax
    priority_queue<int,vector<int>,greater<int>>mq;
    // insertion
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout << "Top Element of Heap: " << pq.top() << endl;

    pq.pop();
    cout << "Top Element of Heap After Pop(): " << pq.top() << endl;
    
    cout << "Size of Max Heap: " << pq.size() << endl;

    // Check if heap is empty or not
    if (pq.empty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }

    return 0;
}