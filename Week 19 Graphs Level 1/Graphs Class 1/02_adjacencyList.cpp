#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEgde(int u, int v, bool direction)
    {
        // direction -> 0 -> undirected
        // direction -> 1 -> directed
        if (direction == 1)
        {
            // u se v ki taraf ek edge hai
            // i.e => u-> v;
            adjList[u].push_back(v);
        }
        else
        {
            // direction = 0
            // u -- v
            // u-> v
            adjList[u].push_back(v);
            // v -> u
            adjList[v].push_back(u);
        }
        // For Understanding only not a logic
        cout << endl
             << "printing adjList" << endl;
        printAdjList();
        cout << endl;
    }

    // For Printing the Adjancency List
    void printAdjList()
    {
        for (auto i : adjList)
        {
            // Node
            cout << i.first << "-> {";
            // Neighbour
            for (auto neighbour : i.second)
            {
                cout << neighbour << ", ";
            }
            cout << "}" << endl;
        }
    }
};

int main()
{
    Graph g;
    // // Directed
    // g.addEgde(0, 1, 1);
    // g.addEgde(1, 2, 1);
    // g.addEgde(1, 3, 1);
    // g.addEgde(2, 3, 1);

    // Undirected
    g.addEgde(0, 1, 0);
    g.addEgde(1, 2, 0);
    g.addEgde(1, 3, 0);
    g.addEgde(2, 3, 0);

    return 0;
}