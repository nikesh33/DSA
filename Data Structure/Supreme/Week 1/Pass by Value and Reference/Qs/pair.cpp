#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30};
    int n = 3;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout<<arr[i]<<" "<<arr[j]<<endl;
        }
        
    }
    
}