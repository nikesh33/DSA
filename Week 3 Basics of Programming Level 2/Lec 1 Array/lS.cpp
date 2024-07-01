#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// found not

bool linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return 1;
        }
    }
    return false;
}

int main()
{
    int arr[5] = {180, 20, 30, 10, 50};
    int size = 5;
    int target = 10;

    bool ans = linearSearch(arr, size, target);
   if (ans ==1)
   {
    cout<<"found";

   }
   else{
    cout<<"not found";
   }
   
}