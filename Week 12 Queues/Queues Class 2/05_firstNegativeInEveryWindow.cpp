#include <iostream>
#include <queue>
#include <deque>
using namespace std;

void printFirstNegative(int *arr, int n, int k)
{

    deque<int> dq;

    // process first k element - first window
    for (int index = 0; index < k; index++)
    {
        int element = arr[index];
        if (element < 0)
        {
            dq.push_back(index);
        }
    }

    // process remaining window -> removal & -> addition
    for (int index = k; index < n; index++)
    {
        //    aage badhne se pehle purani window ka ans nikal do
        if (dq.empty())
        {
            cout << "0 " << endl;
        }
        else
        {
            cout << arr[dq.front()] << " ";
        }

        // removal - jo bhi index out of range hai, usko queue me se remove kardo
        if (index - dq.front() >= k)
        {
            dq.pop_front();
        }
        // Addition
        if (arr[index] < 0)
        {
            dq.push_back(index);
        }
    }

    // last window ka answer print kardo
    if (dq.empty())
    {
        cout << "0 " << endl;
    }
    else
    {
        cout << arr[dq.front()] << " ";
    }
}

int main()
{
    // queue<int>q;
    // q.push(-2);
    // q.push(-5);
    // q.push(4);
    // q.push(-1);
    // q.push(-2);
    // q.push(0);
    // q.push(-5);

    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int size = 7;
    int k = 3;

    printFirstNegative(arr, size, k);

    // while (!q.empty())
    // {
    //     int element =   q.front();
    //     q.pop();
    //     cout<<element<<" ";
    // }
}