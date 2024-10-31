#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction -> 0 undirected
        // direction -> 1 directed
        if (direction == 1)
        {
            adj[u].push_back(v);
        }
        else
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << ": {";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << "}" << endl;
        }
    }

    // BFS TOPO
    void topoSortBFS(int n, vector<int> &topoOrder)
    {

        queue<int> q;
        map<int, int> indegree;
        // initialise kardi indegree [kahn's algorithm]
        for (auto i : adj)
        {
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }
        //   push all zero indegree wali node into queue
        for (int node = 0; node < n; node++)
        {
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }

        // BFS chalate hai
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            topoOrder.push_back(frontNode);

            for (auto nbr : adj[frontNode])
            {
                indegree[nbr]--;

                // check for zero
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(4, 3, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);

    g.printAdjList();
    int n = 8;
    vector<int> topoOrder;
    g.topoSortBFS(n, topoOrder);

    cout << "Printing the topo Sort Orderding" << endl;
    for (auto i : topoOrder)
    {
        cout << i << endl;
    }

    if (topoOrder.size() == n)
    {
        cout << "No Cycle Detected" << endl;
    }
    else
    {
        cout << "Cycle Detected";
    }
}