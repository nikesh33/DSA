#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> maxHeap;

        for (int i = 0; i < piles.size(); i++)
        {
            int element = piles[i];
            maxHeap.push(element);
        }

        while (k--)
        {
            int topElement = maxHeap.top();
            maxHeap.pop();

            topElement = topElement - floor(topElement / 2);

            maxHeap.push(topElement);
        }
        int sum = 0;
        while (!maxHeap.empty())
        {
            int top = maxHeap.top();
            sum += top;
            maxHeap.pop();
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> piles = {5, 4, 9}; // Example input
    int k = 2; // Example value of k

    int result = sol.minStoneSum(piles, k);

    cout << "Minimum possible sum of piles: " << result << endl;

    return 0;
}
