// DFS (Stack Data Structure)

/*
Let Graph Be

            0
           /
          2
         /
        1
       /
      3

DFS Call will be 0 -> 2 -> 1 -> 3
*/

#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    s.pop(); // popped starting vertex

    visited[sv] = true;

    for (int i = 0; i < n; ++i)
    {
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            s.push(i);
            printDFS(edges, n, s.top(), visited);
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter number of vertices & edges : " << endl;
    cin >> n >> e;

    // for storing we need to create 2d array
    int **edges = new int *[n]; // dynamic array for storing edges

    for (int i = 0; i < n; ++i)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; ++j)
            edges[i][j] = 0;
    }

    bool *visited = new bool[n]; // visited array

    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
    }

    for (int i = 0; i < e; ++i)
    {
        int f, s; // first vertex second vertex
        cout << "Enter edge from first vertex to second vertex " << endl;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int sv; // starting vertex

    cout << "Enter starting vertex " << endl;
    cin >> sv;

    s.push(sv); // pushing starting vertex

    cout << "DFS" << endl;
    printDFS(edges, n, sv, visited);

    delete[] visited; // free memory

    return 0;
}

/*
OUTPUT

PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph> cd "e:\DOCUMENTS\C-Plus-Plus-Programming\Graph\" ; if ($?) { g++ DFS_Stack.cpp -o DFS_Stack } ; if ($?) { .\DFS_Stack }
Enter number of vertices & edges :
4 3
Enter edge from first vertex to second vertex
0 2
Enter edge from first vertex to second vertex
2 1
Enter edge from first vertex to second vertex
1 3
Enter starting vertex
0
DFS
0 2 1 3
PS E:\DOCUMENTS\C-Plus-Plus-Programming\Graph>
*/