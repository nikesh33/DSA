// In Vector we dont have to say size of vector(array)
// just keep inserting the data

#include <iostream>
#include <vector>
using namespace std;

// function for vector
void print(vector<int> v)
{
    int size = v.size();

    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    // // Vector array he hai
    // vector<int> v; // vector bana diya vector se <int type ka > uska name rakh diya v

    // 2nd way to initialize an vector  5 size ka vector banega aur 101 value hoga sab me
    vector<int> arr2(5, 101);
    // print(arr2);

    vector<int> arr3 = {1, 2, 3, 4, 5};
    // arr3.pop_back();
    // print(arr3);

    vector<int> arr4{1, 2, 3, 4, 5};
    // print(arr4);

    // // Insert
    // v.push_back(100);
    // v.push_back(200);
    // v.push_back(300);
    // v.push_back(400);
    // v.push_back(500);

    // // if we want to clear all the element in vector we can use clear() it will clear all but capacity will not be clear
    // v.clear();
    // print(v);

    // cout << endl;
    // v.pop_back();
    // v.pop_back();
    // print(v);

    // while (1)
    // {
    //     int d;
    //     cin >> d;
    //     v.push_back(d);
    //     cout << "Capacity: " << v.capacity() << " Size: " << v.size() << endl;
    // }

    // /******How to copy vector********/
    // vector<int> arr5 = {1, 2, 3, 4, 5};
    // vector<int> arr6(arr5);
    // print(arr6);

    /*******How to know front and end element?**********/
    // vector<char> v;
    // v.push_back('a');
    // v.push_back('b');
    // v.push_back('c');

    // // one way
    // cout << "First Element: " << v[0] << endl;

    // cout << "Last Element: " << v[v.size() - 1]<< endl;
    // // two way

    // cout << "First: " << v.front()<< endl;
    // cout << "Last: " << v.back()<< endl;

    /******Another Method 2 How to print the vector******/
    //   this is also called as for each loop
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    cout << "Printing vector method 2: " << endl;
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}