#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{

public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        vector<int> ans;
        int n = mat.size();

        //
        int oneCount = INT_MIN;
        int rowCount = -1;

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    count++;
                }
            }
            if (count > oneCount)
            {
                oneCount = count;
                rowCount = i;
            }
        }
        ans.push_back(rowCount);
        ans.push_back(oneCount);
        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 0, 0, 0},
                               {0, 1, 1, 0},
                               {0, 1, 1, 0},
                               {1, 1, 1, 0},
                               {0, 0, 1, 0}};

    Solution sol;
    vector<int> result = sol.rowAndMaximumOnes(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Row with maximum ones: " << result[0]<<endl << "Count: " << result[1] << endl;
    return 0;
}