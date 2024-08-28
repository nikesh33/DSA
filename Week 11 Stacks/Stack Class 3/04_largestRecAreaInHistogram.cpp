#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> arr)
    {

        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int curr = arr[i];
            // ans find karo curr ke liye
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr)
    {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < arr.size(); i++)
        {
            int curr = arr[i];
            // answer find karo curr ke liye
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> next = nextSmallerElement(heights);
        for (int i = 0; i < next.size(); i++)
        {
            if (next[i] == -1)
            {
                next[i] = heights.size();
            }
        }
        vector<int> prev = prevSmallerElement(heights);

        vector<int> area(next.size());
        for (int i = 0; i < next.size(); i++)
        {
            int width = next[i] - prev[i] - 1;
            int length = heights[i];
            int currArea = width * length;
            area[i] = currArea;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < area.size(); i++)
        {
            maxi = max(maxi, area[i]);
        }
        return maxi;
    }
};

int main()
{
    // Test case
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    // Create an object of the Solution class
    Solution sol;

    // Call the function
    int largestRectangle = sol.largestRectangleArea(heights);

    // Output the result
    cout << "The largest rectangle area in the histogram is: " << largestRectangle << endl;

    return 0;
}