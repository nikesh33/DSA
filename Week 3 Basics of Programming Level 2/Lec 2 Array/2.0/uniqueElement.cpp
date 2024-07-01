#include <iostream>
using namespace std;

int unique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[7] = {10, 20, 30, 10, 30, 40, 5};
    int size = 7;

    int finalAns = unique(arr, size);
    cout << "Final Answer is: " << finalAns;
}