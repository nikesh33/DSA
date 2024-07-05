#include <iostream>
#include <vector>
#include <algorithm> //for reverse
using namespace std;

class Solution
{
public:
    // //  for own reverse function
    // void reverse(vector<int> &arr)
    // {
    //     int n = arr.size();
    //     int start = 0;
    //     int end = n - 1;

    //     while (start < end)
    //     {
    //         swap(arr[start], arr[end]);
    //         start++;
    //         end--;
    //     }
    // }

    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // transpose
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < matrix[i].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse
        for (int i = 0; i < n; i++)
        {
            // with prebuilt function
            reverse(matrix[i].begin(), matrix[i].end());

            // // with own reverse function
            // reverse(matrix[i]);
        }
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    /*{
     {7,4,1},
     {8,5,2},
     {9,6,3}
     } */
    int n = arr.size();
    Solution sol;
    sol.rotate(arr);

    // for printing
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}