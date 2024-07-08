#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// for 1D printing
// void print(vector<vector<int>> &v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

// for 2D printing
void print(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

// custom comparator for 1D array
bool myComp(int &a, int &b)
{
    // Increasig Order
    return a < b;
    // Decreasing Order
    return a > b;
}

// custom comparator 2 for 2D array
bool myComp2(vector<int> &a, vector<int> &b)
{
    // Increasig Order
    return a[1] < b[1];
    // Decreasing Order
    // return a[1] > b[1];
}

int main()
{
    // vector<int> v = {5, 4, 3, 2, 1};
    // for Matrix 2D
    vector<vector<int>> v = {{0, 55}, {0, 33}, {0, 22}};
    // print(v);

    // sort(v.begin(), v.end(), myComp); // third parameter is an custom function for which we can say what way we want

    //   for 2D matrix
    sort(v.begin(), v.end(), myComp2);
    print(v);

    return 0;
}