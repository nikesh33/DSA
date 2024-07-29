#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        if (n == 0)
        {
            return 0;
        }

        if (n < 0)
        {
            return INT_MIN;
        }

        //   x
        int option1 = 1 + maximizeTheCuts(n - x, x, y, z);

        // y
        int option2 = 1 + maximizeTheCuts(n - y, x, y, z);

        // z
        int option3 = 1 + maximizeTheCuts(n - z, x, y, z);
        int finalAns = max(option1, max(option2, option3));
        return finalAns;
    }
};

int main()
{
    // taking length of line segment
    int n;
    cout << "Enter N: ";
    cin >> n;

    // taking types of segments
    int x, y, z;
    cout << "Enter x y z: ";
    cin >> x >> y >> z;
    Solution obj;
    // calling function maximizeTheCuts()
    cout << obj.maximizeTheCuts(n, x, y, z) << endl;

    return 0;
} 