#include <iostream>
#include <limits.h>
using namespace std;

int findMin(int arr[], int size)
{
    int min = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int findMax(int arr[],int size){
int max = INT_MIN;

for (int i = 0; i < size; i++)
{
    if (arr[i]>max)
    {
        max = arr[i];
    }
    
}
return max;

}

int main()
{
    int arr[5] = {10, 99, 43, 9, 2};

    int size = 5;

  int min = findMin(arr,size);
  int max =   findMax(arr,size);
  cout<<"Min Number will be: "<<min;
  cout<<endl;
  cout<<"Max Number will be: "<<max;
}