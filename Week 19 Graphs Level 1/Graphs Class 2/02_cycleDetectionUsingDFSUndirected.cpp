#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool solve(int src, unordered_map<int, bool> &visited, vector<vector<int>> adj)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adj[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if (visited[nbr] == true && nbr != parent[frontNode])
                {
                    // cycle present
                    return true;
                }
            }
        }
        // cycle not present
        return false;
    }

    bool isCycle(int V, vector<vector<int>> adj)
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool ans = solve(i, visited, adj);
                if (ans == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter the edges (format: u v for an edge between u and v):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming an undirected graph; for directed, remove this line
    }

    Solution obj;
    bool hasCycle = obj.isCycle(V, adj);

    if (hasCycle)
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
