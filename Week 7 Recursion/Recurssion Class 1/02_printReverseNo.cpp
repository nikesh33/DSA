#include <iostream>
using namespace std;

void printNum(int n)
{
    // // base case
    // if (n == 0)
    // {
    //     return;
    // }
    // OR
    if (n == 1)
    {
        cout << 1 <<" ";
        return;
    }

    // processing
    cout << n << " ";
    // recursive call
    printNum(n - 1);
    // processing
}

int main()
{
    int n = 5;
    printNum(n);
}