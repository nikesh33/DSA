#include <iostream>
#include <vector>
using namespace std;

void getDigits(int num, vector<int> &ans)
{

    // base case
    if (num == 0)
    {
        return;
    }

    // processing
    int digit = num % 10;
    //    update num
    num = num / 10;

    // rc
    getDigits(num, ans);

    //  processing
    // cout << digit << " ";
    ans.push_back(digit);
}

int main()
{
    int num;
    vector<int> ans;
    cout << "Enter Number: ";
    cin >> num;
    cout << "Digits: ";

    getDigits(num, ans);

    for (auto num : ans)
    {
        cout << num << " ";
    }
}