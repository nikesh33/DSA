#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int start, int end)
    {
      if(start >= end) return;
      int pivot = end;
      
      int i = start-1;
      int j = start;
      
      while(j<pivot){
          if(arr[j]<arr[pivot]){
              i++;
              swap(arr[i],arr[j]);
          }
          j++;
      }
      i++;
      swap(arr[i],arr[pivot]);
      quickSort(arr,start,i-1);
      quickSort(arr,i+1,end);
    }
    
    // public:
    // int partition (int arr[], int low, int high)
    // {
    //    // Your code here
    // //   Won't Use It
    // }
};

int main()
{
    Solution solution;
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    solution.quickSort(arr, 0, n-1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

// } Driver Code Ends