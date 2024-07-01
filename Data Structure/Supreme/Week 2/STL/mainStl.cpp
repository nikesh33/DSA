#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v)
{
    cout << endl;
    cout << "Printing Vector Method 1" << endl;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
}

void print2(vector<int> v)
{
    cout << "Printing Vector method 2 " << endl;
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    print2(v);
    // vector<char> v;
    // v.push_back('a');
    // v.push_back('b');
    // v.push_back('c');
    // v.push_back('d');
    // v.push_back('e');
    // // //1st Way: front and end
    // // cout << "Frontend Element: " << v[0] << endl;
    // // cout << "LastEnd Element: " << v[v.size() - 1] << endl;
    // // 2nd way : // front and end
    // cout << "Front Elemet: " << v.front() << endl;
    // cout << "Front Elemet: " << v.back() << endl;

    // // vector initialization
    // vector<int> arr; // default with no data, 0 size
    // vector<int> arr2(5, -1);
    // // arr2.push_back(16);
    // // print(arr2);
    // vector<int> arr3 = {1, 2, 3, 4, 5};
    // // arr3.pop_back();
    // // print(arr3);
    // vector<int>arr4{1,2,3,4,5};
    // // print(arr4);

    // // How to copy Vector
    // vector<int>arr5={1,2,3,4,5};
    // vector<int>arr6(arr5);
    // print(arr6);
    // print(arr5);

    // STL
    // in vector dont tell size of vector
    // just keep inserting i will manage the size
    // vector<int> v; // array he hai

    // while (1)
    // {
    //     int d;
    //     cin >> d;
    //     v.push_back(d);
    //     cout << "Capacity: " << v.capacity() << "size: " << v.size() << endl;
    // }

    // //  how to insert? this is how
    //     v.push_back(1);
    //     v.push_back(2);
    //     v.push_back(3);
    //     print(v);
    //     cout << endl;
    //     // pop -> delete -> end
    //     // 1 -> 2 -> 3

    //     v.pop_back();
    //     print(v);
    //  // 1 -> 2
    //     cout << endl;

    //     v.pop_back();
    //     print(v);
    //  // 1
    //     cout << endl;

    //     v.pop_back();
    //     print(v);
    // //
    //     cout << endl;

    //     v.pop_back();
    //     print(v);

    // insert in vector
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; ++i)
    // {
    //     int d;
    //     cin >> d;
    //     v.push_back(d);
    // }
    // print(v);
    // //if I want to clear the vector
    // v.clear();
    // v.push_back(250);
    // print(v);

    // // pop
    // v.pop_back();
    // print(v);
}