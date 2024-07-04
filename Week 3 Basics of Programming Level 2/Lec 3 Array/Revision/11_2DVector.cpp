#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 1D Vector
    // vector<int> arr;
    // vector<int> arr(5);
    // vector<int> arr(10, -1);

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // cout << "Size " << arr.size() << endl;
    // cout << "Capacity " << arr.capacity();

    // 2D array
    // int arr[3][4] = {{1, 2, 3, 4},
    //                  {5, 6, 7, 8},
    //                  {9, 10, 11, 12}};

    // ********************Vector 2D************************//

    // 1D => vector<int>arr;
    // 2D => vector<vector<int> >arr

    // vector<vector<int>> arr;

    // this will be used
    // 2D Array(Vector)
    vector<vector<int>> arr(5, vector<int>(10, 0));
    // row size => arr.size()
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr[i].size(); j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Jagged 2D array
    vector<vector<int>> brr;

    vector<int> vec1(10, 0);
    vector<int> vec2(5, 1);
    vector<int> vec3(7, 0);
    vector<int> vec4(8, 1);
    vector<int> vec5(20, 0);

    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);
    brr.push_back(vec5);

    for (int i = 0; i < brr.size(); i++)
    {
        for (int j = 0; j < brr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}