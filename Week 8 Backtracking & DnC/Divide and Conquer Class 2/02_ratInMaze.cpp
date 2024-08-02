#include <iostream>
using namespace std;

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output)
{
    // base case
    // destination cordinates are[row-1],[col-1]
    if (srcx == row - 1 && srcy == col - 1)
    {
        // reached destination
        cout << output << endl;
        return;
    }

    //   1 case solve karo baki recursion solve karega

    // UP
    

    // RIGHT

    // DOWN

    // LEFT
}

int main()
{
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1},
    };

    int row = 4;
    int col = 4;

    int srcx = 0;
    int srcy = 0;

    string output = "";
    printAllPath(maze, row, col, srcx, srcy, output);
}