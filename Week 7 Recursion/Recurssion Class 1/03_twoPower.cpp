#include <iostream>
using namespace std;

int pow(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    // recursive relation
    int ans = 2 * pow(n - 1);
    return ans;
}

int main()
{
    cout << pow(4)<<endl; // 2^4 = 16; 2^10 = 1024;
    cout << pow(10)<<endl; // 2^4 = 16; 2^10 = 1024;
}