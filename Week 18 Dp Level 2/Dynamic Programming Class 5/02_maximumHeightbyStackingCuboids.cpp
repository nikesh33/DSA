#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &curr, vector<int> &prev)
    {
        // curr -> bade wala dabba
        // prev -> chote wala dabba
        if (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Space Optimisation
    int solveUsingTabulationSO(vector<vector<int>> &cuboids)
    {
        int n = cuboids.size();

        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr_index = n - 1; curr_index >= 0; curr_index--)
        {
            for (int prev_index = curr_index - 1; prev_index >= -1;
                 prev_index--)
            {
                int include = 0;
                if (prev_index == -1 ||
                    check(cuboids[curr_index], cuboids[prev_index]))
                {
                    int heightToAdd = cuboids[curr_index][2];
                    include =
                        heightToAdd + nextRow[curr_index + 1]; // index shifting
                }

                int exclude = 0 + nextRow[prev_index + 1]; // index shifting
                currRow[prev_index + 1] = max(include, exclude);
            }
            // Shifting
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &cuboid : cuboids)
        {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int ans = solveUsingTabulationSO(cuboids);
        return ans;
    }
};

int main()
{
    Solution solution;

    // Example test case with cuboids of dimensions [l, w, h]
    vector<vector<int>> cuboids = {
        {50, 45, 20},
        {95, 37, 53},
        {45, 23, 12}};

    // Call the maxHeight function to compute the maximum height
    int result = solution.maxHeight(cuboids);

    // Print the result
    cout << "The maximum height of stacked cuboids is: " << result << endl;

    return 0;
}
