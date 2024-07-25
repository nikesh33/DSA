#include <iostream>
using namespace std;

/*NOTE FOR ME :
// RECURSSION SPACE KHATA HAI COMPARED TO LOOP SO LOOP IS ACHAA
// BUT INFUTURE COMPLEX PROBLEM AAYEGA TO RECURSSION USE HOTA HAI LOOP USE KARNE SE PASEENE AA JAYENGE
*/

int factorial(int n)
{
    // base case
    if (n == 1)
        return 1;
    if (n == 0)
        return 1;

    // processing

    // recursive call

    // way 1
    // int ans = n * factorial(n - 1);
    // return ans;

    // way2
    int recursionKaAns = factorial(n - 1);

    // processing
    int finaalAns = n * recursionKaAns;
    return finaalAns;
}

int factAll(int n)
{

    // base case
    if (n == 0 || n == 1)
        return 1;

    // processing

    // recurssive call
    int recursionKaAns = factAll(n - 1);

    // procession
    int finalAns = n * recursionKaAns;
    return finalAns;
}

int main()
{
    // cout << factorial(5);
    cout << factAll(5);
    return 0;
}