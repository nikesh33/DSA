#include <iostream>
using namespace std;

int solve(int number)
{
    number--;
    cout<<"in function: "<<number<<endl;
}

int main()
{
    int number = 1;
    solve(number);
    cout<<"in main: "<<number;
}