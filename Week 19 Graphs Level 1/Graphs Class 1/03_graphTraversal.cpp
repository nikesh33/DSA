#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// class Graph
// // UNWEIGHTED
// {
// public:
//     unordered_map<int, list<int>> adjList;
//     void addEgde(int u, int v, bool direction)
//     {
//         // direction -> 0 -> undirected
//         // direction -> 1 -> directed
//         if (direction == 1)
//         {
//             // u se v ki taraf ek edge hai
//             // i.e => u-> v;
//             adjList[u].push_back(v);
//         }
//         else
//         {
//             // direction = 0
//             // u -- v
//             // u-> v
//             adjList[u].push_back(v);
//             // v -> u
//             adjList[v].push_back(u);
//         }
//         // For Understanding only not a logic
//         cout << endl
//              << "printing adjList" << endl;
//         printAdjList();
//         cout << endl;
//     }

//     // For Printing the Adjancency List
//     void printAdjList()
//     {
//         for (auto i : adjList)
//         {
//             // Node
//             cout << i.first << "-> {";
//             // Neighbour
//             for (auto neighbour : i.second)
//             {
//                 cout << neighbour << ", ";
//             }
//             cout << "}" << endl;
//         }
//     }
// };

//// ************** //
// class Graph
// // WEIGHTED GRAPH
// {
// public:
//     unordered_map<int, list<pair<int, int>>> adjList;

//     void addEdge(int u, int v, int wt, bool direction)
//     {
//         // Direction = 0 -> undirected
//         // Direction = 1 -> directed
//         if (direction == 1)
//         {
//             // u -> v
//             // can also make pair i.e => adjList[u].push_back(make_pair(v,wt));
//             adjList[u].push_back({v, wt});
//         }
//         else
//         {
//             // direction = 0
//             // u ---- v
//             // v -> u
//             // v -> u
//             adjList[u].push_back({v, wt});
//             adjList[v].push_back({u, wt});
//         }
//         printAdjList();
//         cout << endl;
//     }

//     void printAdjList()
//     {
//         for (auto i : adjList)
//         {
//             cout << i.first << ": { ";
//             for (pair<int, int> p : i.second)
//             {
//                 cout << "{" << p.first << ", " << p.second << "}, ";
//             }
//             cout << "}" << endl;
//         }
//     }
// };

// Generalized Code
//********* template <typename T> *********//
// A template is a simple yet very powerful tool in C++. The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types.
template <typename T>
class Graph
// WEIGHTED GRAPH
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int wt, bool direction)
    {
        // Direction = 0 -> undirected
        // Direction = 1 -> directed
        if (direction == 1)
        {
            // u -> v
            // can also make pair i.e => adjList[u].push_back(make_pair(v,wt));
            adjList[u].push_back({v, wt});
        }
        else
        {
            // direction = 0
            // u ---- v
            // v -> u
            // v -> u
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        // printAdjList();
        // cout << endl;
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << ": { ";
            for (pair<T, int> p : i.second)
            {
                cout << "{" << p.first << ", " << p.second << "}, ";
            }
            cout << "}" << endl;
        }
    }

    // BFS => Breadth First Search
    void bfsTraversal(T src, unordered_map<char, bool> &vis)
    {
        // adjList already data member me hai
        // Visited
        // unordered_map<T, bool> vis;
        // queue
        queue<T> q;

        // Initial State
        q.push(src);
        vis[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            //    go to neighbour
            for (auto nbr : adjList[frontNode])
            {
                T nbrData = nbr.first;

                if (!vis[nbrData])
                {
                    q.push(nbrData);
                    vis[nbrData] = true;
                }
            }
        }
    }

    // DFS => Depth First Search
    void dfs(T src, unordered_map<T, bool> &vis)
    {
        vis[src] = true;
        cout << src << " ";

        for (auto nbr : adjList[src])
        {
            T nbrData = nbr.first;
            if (!vis[nbrData])
            {
                dfs(nbrData, vis);
            }
        }
    }
};

int main()
{

    // // Generalized
    // Graph<char> g;
    // g.addEdge('a', 'b', 5, 1);
    // g.addEdge('a', 'c', 10, 1);
    // g.addEdge('b', 'c', 20, 1);
    // g.addEdge('c', 'd', 50, 1);
    // g.addEdge('c', 'e', 50, 1);
    // g.addEdge('e', 'f', 50, 1);

    // // BFS => Breadth First Search
    // // Yaha Galti Hoti hai kyuki agar Graph Disconnected raha tab saare nodes to print nahi ho payega isliye loop ka use karna padega sabke liye function call jayegi
    // // g.bfsTraversal('a');
    // Thats why iska use karna hoga
    // unordered_map<char, bool> vis;
    // for (char node = 'a'; node <= 'f'; node++)
    // {
    //     if (!vis[node])
    //     {
    //         g.bfsTraversal(node, vis);
    //     }
    // }

    // cout << endl;

    // DFS => Depth First Search
    Graph<char> g;
    g.addEdge('a', 'b', 5, 0);
    g.addEdge('a', 'c', 10, 0);
    g.addEdge('c', 'd', 20, 0);
    g.addEdge('c', 'e', 50, 0);
    g.addEdge('d', 'e', 50, 0);
    g.addEdge('e', 'f', 50, 0);

    unordered_map<char, bool> visited;
    // Yaha Galti Hoti hai kyuki agar Graph Disconnected raha tab saare nodes to print nahi ho payega isliye loop ka use karna padega sabke liye function call jayegi
    // g.dfs('a', visited);
    for (char node = 'a'; node <= 'f'; node++)
    {
        if (!visited[node])
        {
            g.dfs(node, visited);
        }
    }

    return 0;
}
