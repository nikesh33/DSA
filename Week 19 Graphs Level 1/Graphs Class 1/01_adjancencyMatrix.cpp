#include <iostream>
#include <vector>
using namespace std;

void Graph(vector<pair<int, int>> edgeList)
{
    int n = edgeList.size();

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    for (auto i : edgeList)
    {
        int n = i.first;
        int v = i.second;

        adjMatrix[n][v] = 1;
    }

    // Print the adjacency matrix for verification
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < adjMatrix.size(); i++)
    {
        for (int j = 0; j < adjMatrix[i].size(); j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Define an edge list for the graph (example: directed edges)
    vector<pair<int, int>> edgeList = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        {1, 3}};

    // Call the Graph function to create the adjacency matrix
    Graph(edgeList);

    return 0;
}