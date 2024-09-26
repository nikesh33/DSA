#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Custom Data Type banana hai
class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c)
    {
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b) { return a->data > b->data; }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<Info *, vector<Info *>, compare> pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        // process first k elements ko
        for (int i = 0; i < nums.size(); i++)
        {
            int element = nums[i][0];
            int row = i;
            int col = 0;
            Info *temp = new Info(element, row, col);
            pq.push(temp);
            maxi = max(maxi, element);
            mini = min(mini, element);
        }
        int ansStart = mini;
        int ansEnd = maxi;

        while (!pq.empty())
        {
            Info *topNode = pq.top();
            int topData = topNode->data;
            int topCol = topNode->colIndex;
            int topRow = topNode->rowIndex;

            pq.pop();

            mini = topNode->data;
            // maxi ki value pehle se padi hui
            // compare karlete hai for smaller range
            if ((maxi - mini) < (ansEnd - ansStart))
            {
                // update ans
                ansStart = mini;
                ansEnd = maxi;
            }
            // insertion wala step
            if (topCol + 1 < nums[topRow].size())
            {
                int newElement = nums[topRow][topCol + 1];
                maxi = max(maxi, newElement);
                Info *newInfo = new Info(newElement, topRow, topCol + 1);
                pq.push(newInfo);
            }
            else
            {
                // aage koi element nahi hai push karne ko
                break;
            }
        }
        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};

int main()
{
    Solution sol;

    // Example input: vector of sorted lists
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}};

    // Call the smallestRange function and store the result
    vector<int> result = sol.smallestRange(nums);

    // Print the result
    cout << "Smallest range is: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}