#include <iostream>
#include <unordered_map>
#include <list>
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
        printAdjList();
        cout << endl;
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
};

int main()
{

    // UNWEIGHTED GRAPH
    // Graph g;
    // // // Directed
    // // g.addEgde(0, 1, 1);
    // // g.addEgde(1, 2, 1);
    // // g.addEgde(1, 3, 1);
    // // g.addEgde(2, 3, 1);

    // // Undirected
    // g.addEgde(0, 1, 0);
    // g.addEgde(1, 2, 0);
    // g.addEgde(1, 3, 0);
    // g.addEgde(2, 3, 0);

    // // WEIGHTED GRAPH
    // Graph g;
    // g.addEdge(0, 1, 5, 1);
    // g.addEdge(1, 2, 10, 1);
    // g.addEdge(1, 3, 20, 1);
    // g.addEdge(2, 3, 50, 1);

    // Generalized
    Graph<char> g;
    g.addEdge('a', 'b', 5, 1);
    g.addEdge('a', 'c', 10, 1);
    g.addEdge('a', 'd', 20, 1);
    g.addEdge('b', 'c', 50, 1);
    return 0;
}