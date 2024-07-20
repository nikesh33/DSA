#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

// Given two positive integers a and b, find GCD of a and b.
// Note: Don't use the inbuilt gcd function
class Solution
{
public:
    int gcd(int A, int B)
    {
        if (A == 0)
            return B;

        if (B == 0)
            return A;

        while (A > 0 && B > 0)
        {
            if (A > B)
            {
                A = A - B;
            }
            else
            {
                B = B - A;
            }
        }
        return A == 0 ? B : A;
    }
};

int main()
{
    Solution sol;
    cout << sol.gcd(3, 6);
}