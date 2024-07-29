#include <iostream>
using namespace std;

bool checkSorted(int arr[], int size, int index)
{
    // base condition
    if (index >= size)
    {
        return true;
    }

    // processing
    if (arr[index] > arr[index - 1])
    {
        //    aage check karna padega ab
        // ab recursion sambhalega
        // rc
        bool aageKaAns = checkSorted(arr, size, index + 1);
        return aageKaAns;
    }
    else
    {
        return false;
    }
}

int main()
{
    int arr[] = {10, 20, 30, 50, 60};
    int size = 5;
    int index = 0;

    bool ans = checkSorted(arr, size, index + 1);

    if (ans)
    {
        cout << "Array Is Sorted ";
    }
    else{
        cout<<"Array is not Sorted ";
    }
}