// Pass by Reference

#include <iostream>
using namespace std;

void solve(int &a, int &s)
{
    a++; // 6 increment hua
    s * 2;
    cout << "In Solve Function Incremental Values is: " << a << endl;
}

int main()
{
    int a = 5;
    int &k = a;
    k++; // yaha pe pehle wo 6 hua
    int s = 10;
    solve(a, s);
    cout << "In main function the value is: " << a << " For S: " << s << endl;
}