#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// can also be written using switch cases for clean code
void solveForMedian(double &median, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int element)
{
    if (maxi.size() == mini.size())
    {
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else
        {
            maxi.push(element);
            median = maxi.top();
        }
    }
    else if (maxi.size() == mini.size() + 1)
    {
        if (element > median)
        {
            mini.push(element);
        }
        else
        {
            int maxTop = maxi.top();
            maxi.pop();
            mini.push(maxTop);
            maxi.push(element);
        }
        median = (mini.top() + maxi.top()) / 2.0;
    }
    else if (mini.size() == maxi.size() + 1)
    {
        if (element > median)
        {
            int minTop = mini.top();
            mini.pop();
            maxi.push(minTop);
            mini.push(element);
        }
        else
        {
            maxi.push(element);
        }

        median = (mini.top() + maxi.top()) / 2.0;
    }
}

int main()
{
    // 12 -> 12
    // 10 12 -> 11
    // 8 10 12 -> 10
    // 4 8 10 12 -> 9
    // 2 4 8 10 12 -> 8
    // 2 3 4 8 10 12 0 -> 6
    // 2 3 4 8 10 12 15 -> 8
    int arr[] = {12, 10, 8, 4, 2, 3, 15};
    int n = 7;

    double median = 0;

    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        solveForMedian(median, maxi, mini, element);
        cout << "Median Found: " << median << endl;
    }
}