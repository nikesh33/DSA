#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
#include <limits.h>
using namespace std;

// directed and weighted
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction - 0 -> undirected
        //  direction - 1 -> directed
        if (direction == 1)
        {
            adj[u].push_back({v, wt});
        }
        else
        {
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " : { ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << " , " << j.second << "), ";
            }
            cout << "}" << endl;
        }
    }

    void topOrderDfs(int src, stack<int> &topo, unordered_map<int, bool> &visited)
    {
        visited[src] = true;

        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            // int nbrDist = nbrPair.second;
            if (!visited[nbrNode])
            {
                topOrderDfs(nbrNode, topo, visited);
            }
        }
        topo.push(src);
    }

    void shortestPathDfs(stack<int> &topoOrder, int n)
    {
        vector<int> dist(n, INT_MAX);

        // initially maintain src
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        // update nbr distance for this src node
        for (auto nbrPair : adj[src])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            if (dist[src] + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }

        // apply the same above concept for all the remaining node
        // int the topo ordering
        while (!topoOrder.empty())
        {
            int src = topoOrder.top();
            topoOrder.pop();

            for (auto nbrPair : adj[src])
            {
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if (dist[src] + nbrDist < dist[nbrDist])
                {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }
        // ab mera distance array ekdum tyaar hai
        cout << "Printing the distance array: " << endl;
        for (auto i : dist)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(4, 3, 1, 1);

    g.printAdjList();

    int src = 0;
    stack<int> topOrder;
    unordered_map<int, bool> visited;
    g.topOrderDfs(src, topOrder, visited);

    // cout << "Printing topo order" << endl;
    // while (!topOrder.empty())
    // {
    //     cout << topOrder.top() << " ";
    //     topOrder.pop();
    // }
    int n = 5;
    g.shortestPathDfs(topOrder, n);

    return 0;
}