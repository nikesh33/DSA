#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool checkCycle(int src, unordered_map<int, bool> &vis, int parent, vector<int> adj[])
    {
        vis[src] = true;

        for (auto nbr : adj[src])
        {
            if (!vis[nbr])
            {
                bool ans = checkCycle(nbr, vis, src, adj);

                if (ans == true)
                {
                    return true;
                }
            }
            else if (vis[nbr] == 1 && nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        unordered_map<int, bool> vis;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                int parent = -1;
                bool isCycle = checkCycle(i, vis, parent, adj);
                if (isCycle == true)
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
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    // Initialize adjacency list
    vector<int> adj[V];

    cout << "Enter edges (u v) format for each edge:" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Add edge u->v
        adj[v].push_back(u); // Since the graph is undirected, add edge v->u
    }

    // Create Solution object and check for cycle
    Solution obj;
    if (obj.isCycle(V, adj))
    {
        cout << "Graph contains a cycle" << endl;
    }
    else
    {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
