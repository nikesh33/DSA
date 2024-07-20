#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

// Sieve of Eratosthenes <<<<<**********>>>>>
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0)
            return 0;

        vector<bool> prime(n, true); // sabko true mark kar diya
        prime[0] = prime[1] = false;

        int ans = 0;

        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                ans++;

                int j = 2 * i; // eg =>=>=>=> [2*2=>4, 2*3=>6, 2*4=>8, 2*5=>10...], [3*2=>6, 3*3=>9, 3*4=>12, 3*5=>15, 3*6=>18]
                while (j < n)
                {
                    prime[j] = false;
                    j += i; // adding to eg=> [4+2,6+2]
                }
            }
        }
        return ans;
    }
};

int main()
{
    // Sieve of Eratosthenes
    Solution sol;

    cout << sol.countPrimes(20);
}