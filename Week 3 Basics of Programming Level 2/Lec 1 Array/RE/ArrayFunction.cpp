#include <iostream>
using namespace std;

bool linear(int arr[], int size, int target)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}

// Driver Code
int main()
{
    int arr[5] = {20, 40, 10, 15, 55};
    int n = 5;
    int target = 55;

    int ans = linear(arr, n, target);
    if (ans==1)
    {
        cout<<"Present ";
    }
    else{
        cout<<"Absent ";
    }
    
}