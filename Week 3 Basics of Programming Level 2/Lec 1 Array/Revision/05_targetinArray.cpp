#include <iostream>
using namespace std;

// print function
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool linearSearch(int arr[], int size, int target)
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

int main()
{
    int arr[6] = {2, 4, 6, 8, 12};

    int size = 5;
    int target = 7;

    // using flag concept Linear Search in array
    //  int flag = 0;
    //  for (int i = 0; i < size; i++)
    //  {
    //      // yaha pe check ho rha hai kya i == target ke equal hai? agar hai to flag ko 1 kardo
    //      if (arr[i] == target)
    //      {
    //          flag = 1;
    //          break;
    //      }
    //  }

    // // agar flag 1 hogya hoga to target found else not found
    // if (flag == 1)
    // {
    //     cout << "Target found";
    // }

    // else
    // {
    //     cout << "Not Found" << endl;
    // }

    // way 2: without flag concept
    int ans = linearSearch(arr, size, target);
    if (ans == 1)
    {
        cout << "found";
    }
    else
    {
        cout << "Not Found";
    }

    // printArray(arr, size);
}