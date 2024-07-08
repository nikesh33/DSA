#include <iostream>
#include <vector>
using namespace std;

// Insertion Sort
void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &v)
{
    int n = v.size();
    // i = 0,choad deta hu
    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        // Move Element of Array [0....i-1] that are greater than
        // key to one position ahead of there current position
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key; // insertion
    }
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    print(v);
    // Insertion Sort
    insertionSort(v);
    print(v);

    return 0;
}