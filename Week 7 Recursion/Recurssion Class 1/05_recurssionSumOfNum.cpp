#include <iostream>
using namespace std;

int sumOf(int n)
{
    // base case
    if (n == 1)
        return 1;

    // recurssive call or relation
    int ans = n + sumOf(n - 1);
    return ans;
}

int main()
{
    cout << sumOf(5);
}