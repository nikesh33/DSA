#include <iostream>
using namespace std;

int fastExponentiation(int a, int b)
{
    // O(logb)
    int ans = 1;
    while (b > 0)
    {

        if (b & 1)
        {
            // odd
            ans = ans * a;
        }
        a = a * a;
        b >>= 1; // rightShift
    }
    return ans;
}

int slowExponentiation(int a, int b)
{
    // TC => O(b)
    int ans = 1;

    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    return ans;
}

int main()
{
    cout << slowExponentiation(5, 4) << endl; // 625
    cout << fastExponentiation(5, 4) << endl; // 625
    return 0;
}