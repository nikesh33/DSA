#include <iostream>
using namespace std;

int getQuotient(int divisor, int dividend)
{
    int s = 0;
    int e = dividend;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        // if == dividend
        if (mid * divisor == dividend)
        {
            return mid;
        }
        else if (mid * divisor < dividend)
        {
            // store ans
            ans = mid;
            // go to right
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int divisor = 7;
    int dividend = 56;

    int n = -5;
    // abs absolute me - dete h to ignore ho jata h
    // cout << abs(n) << endl;
    int ans = getQuotient(abs(divisor), abs(dividend));

    // now we have to decide k sign konsa lagye +ve ya negative
    // if ((divisor>0&&dividend>0)||(divisor<0&&dividend<0)){
    // koi change nhi positive he ayega
    // }
    if ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0))
    {
        ans = 0 - ans;
    }
    //  if (dividend == 0)
    // {
    //     ans = ans * 0;
    // }

    cout << "Final ans is: " << ans;
}