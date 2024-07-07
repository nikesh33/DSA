#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row * col;

        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;

        while (s <= e)
        {
            int rowIndex = mid / col;
            int colIndex = mid % col;
            int currentIndex = matrix[rowIndex][colIndex];

            if (currentIndex == target)
            {
                return true;
            }
            else if (target > currentIndex)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{2, 4, 6, 8}, {10, 12, 14, 16}, {18, 20, 22, 24}, {28, 34, 40, 50}};
    int size = matrix.size();
    int target = 50;

    int ans = sol.searchMatrix(matrix, target);

    if (ans == 1)
    {
        cout << "Yes, It's Present In 2D Matrix" << endl;
    }
    else
    {
        cout << "No, the Given Target Is Not In a 2D Matrix";
    }
}