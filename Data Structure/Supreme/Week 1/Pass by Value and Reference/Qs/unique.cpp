#include <iostream>
using namespace std;

int getUnique(int arr[],int n){
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans^arr[i];
    }
    return ans;
    
}

int main(){
    int arr[]={10,12,15,10,15};
    int n = 5;

    int finalAns = getUnique(arr,n);
    cout<<"Final Ans: "<<finalAns<<endl;
}