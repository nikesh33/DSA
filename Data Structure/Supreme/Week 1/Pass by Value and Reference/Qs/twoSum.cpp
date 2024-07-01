#include <iostream>
using namespace std;

// int twoSum(int arr[], int size, int target)
// {
    
// }

int main()
{
    int arr[] = {3,3};
    int size = 2;
    int target = 6;
    // twoSum(arr, size, target);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << i << " " <<j << endl;
                
            }
        }
    }
    
}