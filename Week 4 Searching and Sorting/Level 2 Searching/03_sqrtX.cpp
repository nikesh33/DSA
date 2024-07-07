#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int s = 0;
        // search space
        int e = x;
        // int mid = s + (e - s) / 2;

        // mid*mid karte hue kabhi kabhi value int ke bahar ja sakta hai
        // Isliye ye use kiya hai long long int
        long long int mid = s + (e - s) / 2;
        int ans = -1;

        while (s <= e)
        {

            // kya mid he to answer nahi hai?
            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid < x)
            {
                //  ans store
                // right me jao
                ans = mid;
                s = mid + 1;
            }
            else
            {
                // left me jana hai
                e = mid - 1;
            }
            // //    update mid
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};

int main()
{
    int x = 68;
    Solution sol;
    cout << "Sqrt of " << x << ": " << sol.mySqrt(x);
}