#include <iostream>
#include <queue>
using namespace std;

void reverse(queue<int> &q)
{
    // base case
    if (q.empty())
    {
        return;
    }

    int element = q.front();
    q.pop();

    // rc
    reverse(q);

    q.push(element);
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

    reverse(q);

    cout<<"Printing Queue: "<<endl;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cout<<element<<" ";
    }
    
    return 0;
}