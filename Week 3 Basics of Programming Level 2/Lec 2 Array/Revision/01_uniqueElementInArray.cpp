#include <iostream>
using namespace std;

int findUniqueElement(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = {2, 10, 11, 13, 13, 2, 15, 11, 15};
    int n = 9;

    int finalAns = findUniqueElement(arr, n);
    cout << "Final Ans: " << finalAns;
}
