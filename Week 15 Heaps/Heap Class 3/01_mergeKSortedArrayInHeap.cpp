#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Custom Data Type banana hai
class Info
{
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c)
    {
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

// Our Custom comparator likha kyuki humne custom data type banaya hai apna (Info)
// Normally Computers Knows int (eg- 1 bada hai ya 2 ya 10)an all those hum log ko batana nahi padta but
// kyuki humne apna khud ka data type banaya hai to hume batana padega kise hum bada manana chahte hai
class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        // in this hum keh rhe hai Info ki a badi mani jayegi Info b se
        // agar less < then kar deta to max heap ban jata
        // yaha pe min heap bana rahe hai  
        return a->data > b->data;
    }
};

void mergeKSortedArrays(int arr[][4], int n, int k, vector<int> &ans)
{
    priority_queue<Info *, vector<Info *>, compare> pq;

    // Step 1: process first k element
    for (int row = 0; row < k; row++)
    {
        // har array ki pehle element ki baat ho rahi hai yaha
        int element = arr[row][0];
        Info *temp = new Info(element, row, 0);
        pq.push(temp);
    }
    while (!pq.empty())
    {
        // fetch kiya hai
        Info *temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int topRow = temp->rowIndex;
        int topCol = temp->colIndex;

        // store in ans vector
        ans.push_back(topData);
        // next element for the same row, jisme se pop kia hai just abbhi
        // usee insert bhi toh karna hai
        if (topCol + 1 < n)
        {
            // iska matalab row me or element abhi present hai
            Info *newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
            // Heap me push kar rahe hai
            pq.push(newInfo);
        }
    }
}

int main()
{
    int arr[3][4] = {
        {1, 4, 8, 11},
        {2, 3, 6, 10},
        {5, 7, 11, 12}};

    int n = 4;
    int k = 3;

    vector<int> ans;
    mergeKSortedArrays(arr, n, k, ans);
    cout << "Printing Ans Array: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}